#pragma once

using namespace std;
using namespace winrt;

namespace Utility 
{
	enum class InputCondition
	{
		Hours, Minutes, Result
	};

	class Converter
	{
	private:int hours = 0;
	private:int minutes = 0;
	private:int daysResult = 0;
	private:int minutesResult = 0;

	private:InputCondition inputCondition = InputCondition::Hours;

	public:const int MinutesPerDay = 20;
	public:const int MinutesPerHour = 60;

	public:const int GetMinutes() const {
		return minutes;
	}

	public:const int GetHours() const {
		return hours;
	}

	public:const int GetDaysResult() const {
		return daysResult;
	}

	public:const int GetMinutesResult() const {
		return minutesResult;
	}

	public:const hstring GetInputConditionTxt() const {
		switch (inputCondition) {
		case InputCondition::Hours:
			return L"Enter a Hours";
		case InputCondition::Minutes:
			return L"Enter a Minutes";
		case  InputCondition::Result:
			wstring results;
			results = L"Result: " + to_wstring(daysResult) + L" Days, " + to_wstring(minutes) + L" Minutes";
			hstring convertedResults{ results };
			return convertedResults;
		};
	}

	public:const InputCondition GetInputCondition() const
	{
		return inputCondition;
	}

	public:void SetMinutes(int value);
	public:void SetHours(int value);
	public:void SetInputConditon(InputCondition value);
    public:void DaysResultIncrement();
    public:void SetMinutesResult(int value);
	public:void ClearValues();
	};

	extern Converter GlobalConverter;
}

