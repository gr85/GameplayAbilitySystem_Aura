// Copyright Pa l'Ull

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


// FORWARD DECLARATION to avoid importing header file if we don't need to access to any function
// Add "EnhanceInput" to "Aura.Build.cs"
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Constructor
	AAuraPlayerController();

protected:
	// We Override BeginPlay Function
	virtual void BeginPlay() override;
	// We override this method
	virtual void SetupInputComponent() override;

private:
	// Pointer to player controller object
	// UPROPERTY exposes variable to UE5 editor (Blueprint)
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	
	// Callback function to move the player
	// & -> means pass by reference
	void Move(const FInputActionValue& InputActionValue);
};
