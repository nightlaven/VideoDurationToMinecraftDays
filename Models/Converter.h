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
		   int minutes = 0;
		   int daysResult = 0;
		   int minutesResult = 0;

		   InputCondition inputCondition = InputCondition::Hours;

	public:const int MinutesPerDay = 20;
		  const int MinutesPerHour = 60;

		  const int GetMinutes() const {
			  return minutes;
		  }
		  const int GetHours() const {
			  return hours;
		  }
		  const int GetDaysResult() const {
			  return daysResult;
		  }
		  const int GetMinutesResult() const {
			  return minutesResult;
		  }
		  const hstring GetInputConditionTxt() const {
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
		  const InputCondition GetInputCondition() const
		  {
			  return inputCondition;
		  }

		  void SetMinutes(int value);
		  void SetHours(int value);
		  void SetInputConditon(InputCondition value);
		  void DaysResultIncrement();
		  void SetMinutesResult(int value);
		  void ClearValues();
	};

	extern Converter GlobalConverter;
}

