#include "pch.h"
#include "Converter.h"

namespace Utility
{
	Converter GlobalConverter;

	void Converter::SetMinutes(int value)
	{
		minutes = value;
	}

	void Converter::SetHours(int value)
	{
		hours = value;
	}

	void Converter::SetInputConditon(InputCondition value)
	{
		inputCondition = value;
	}

	void Converter::DaysResultIncrement()
	{
		daysResult++;
	}

	void Converter::SetMinutesResult(int value)
	{
		minutes = value;
	}

	void Converter::ClearValues()
	{
		hours = 0;
		minutes = 0;
		daysResult = 0;
		minutesResult = 0;

		inputCondition = InputCondition::Hours;
	}
}
