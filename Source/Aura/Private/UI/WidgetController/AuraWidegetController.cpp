// Copyright Pa l'Ull


#include "UI/WidgetController/AuraWidegetController.h"

void UAuraWidegetController::SetWidgetControllerParams(const FWidgetControllerParams WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

// Only used by classes which derives from it
void UAuraWidegetController::BroadCastInitialValues()
{
}

// Only used by classes which derives from it
void UAuraWidegetController::BindCallbacksToDependencies()
{
}
