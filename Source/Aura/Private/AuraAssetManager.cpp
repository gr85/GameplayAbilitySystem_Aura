// Copyright Pa l'Ull


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"
#include "AbilitySystemGlobals.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
    check(GEngine);

    UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);

    return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();
    FAuraGameplayTags::InitializeNativeGameplayTags();

    // Required to use custom Ability Tasks or Target Data!
    UAbilitySystemGlobals::Get().InitGlobalData();
}
