// Copyright Pa l'Ull

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// = 0 -> means that function is set to abstract automatically and must be implemented in a derived class
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};