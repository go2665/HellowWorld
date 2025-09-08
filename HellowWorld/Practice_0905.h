#pragma once

template<typename T>
T Clamp(T Value, T Min, T Max)
{
	if (Value < Min)
		return Min;
	else if (Value > Max)
		return Max;
	else
		return Value;
	
}

void Practice0905_01_05();
void Practice0905_02_05();