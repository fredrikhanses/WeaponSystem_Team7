#include "UIColor.h"

UUIColor::UUIColor()
{

}

void UUIColor::SetTextColor(FSlateColor InTextColor)
{
	TextColor = InTextColor;
}

FSlateColor UUIColor::GetTextColor()
{
	return TextColor;
}