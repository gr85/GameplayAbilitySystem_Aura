// Copyright Pa l'Ull


#include "AbilitySystem/Data/AttributeInfo.h"

FAuarAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag &AttributeTag, bool bLogNotFound) const
{
    for (const FAuarAttributeInfo& Info : AttributeInformation)
    {
        if (Info.AttributeTag.MatchesTagExact(AttributeTag))
        {
            return Info;
        }
    }

    if (bLogNotFound)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this));
    }

    return FAuarAttributeInfo();
}
