// Copyright Pa l'Ull


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"
#include "Actor/AuraProjectile.h"
#include "Interaction/CombatInterface.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Aura/Public/AuraGameplayTags.h"

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, 
    const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    
}

void UAuraProjectileSpell::SpawnProjectile(const FVector& ProjectileTargetLocation)
{
    // Spawn the projectile only on the server. It will be replicated to owning client
    const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
    if (!bIsServer) return;

    ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
    if (CombatInterface)
    {
        const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
        FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
        // Set this to allow projectiles fly parallel to the ground
        Rotation.Pitch = 0.f;

        FTransform SpawnTransform;
        SpawnTransform.SetLocation(SocketLocation);
        SpawnTransform.SetRotation(Rotation.Quaternion());

        AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(ProjectileClass, SpawnTransform, GetOwningActorFromActorInfo(), 
            Cast<APawn>(GetOwningActorFromActorInfo()), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
        
        // Give the Projectile a Gameplay Effect Spec for causing Damage.
        const UAbilitySystemComponent* SourceASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
        const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(DamageEffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());

        /**
         * Begin setup properties to use "Set by Caller" gameplay effect option
        */
        const FAuraGameplayTags GameplayTags = FAuraGameplayTags::Get();
        const float ScaledDamage = Damage.GetValueAtLevel(GetAbilityLevel());
        UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Damage, ScaledDamage);
        /** END SETUP*/

        Projectile->DamageEffectSpedHandle = SpecHandle;

        Projectile->FinishSpawning(SpawnTransform);
    }
}
