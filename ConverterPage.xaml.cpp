#include "pch.h"
#include "ConverterPage.xaml.h"
#include "Converter.h"
#if __has_include("ConverterPage.g.cpp")
#include "ConverterPage.g.cpp"
#endif
#include <winrt/Windows.UI.Xaml.Interop.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Utility;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::VideoDurationToMinecraftDays::implementation
{
	int32_t ConverterPage::MyProperty()
	{
		throw hresult_not_implemented();
	}

	void ConverterPage::MyProperty(int32_t /* value */)
	{
		throw hresult_not_implemented();
	}

	void ConverterPage::InitializeComponent()
	{
		ConverterPageT::InitializeComponent();

		ConverterNumberBox().Header(box_value(GlobalConverter.GetInputConditionTxt()));
	}
}

void winrt::VideoDurationToMinecraftDays::implementation::ConverterPage::ConverterNumberBox_ValueChanged(winrt::Microsoft::UI::Xaml::Controls::NumberBox const& sender, winrt::Microsoft::UI::Xaml::Controls::NumberBoxValueChangedEventArgs const& args)
{
    int inputValue = ConverterNumberBox().Value();
    InputHandler(inputValue);
}

void winrt::VideoDurationToMinecraftDays::implementation::ConverterPage::InputHandler(int value)
{
	switch (GlobalConverter.GetInputCondition())
	{
	case InputCondition::Hours:
		GlobalConverter.SetHours(value);
		GlobalConverter.SetInputConditon(InputCondition::Minutes);
		ConverterNumberBox().Header(box_value(GlobalConverter.GetInputConditionTxt()));
		ConverterNumberBox().Text(L" ");
		return;
	case InputCondition::Minutes:
		GlobalConverter.SetMinutes(value);
		Convert();
		return;
	}
}

void winrt::VideoDurationToMinecraftDays::implementation::ConverterPage::Convert()
{
	int minuteTotal = 0;
	minuteTotal += GlobalConverter.GetHours() * GlobalConverter.MinutesPerHour;
	minuteTotal += GlobalConverter.GetMinutes();

	do
	{
		GlobalConverter.DaysResultIncrement();

		minuteTotal -= GlobalConverter.MinutesPerDay;

		if (minuteTotal < GlobalConverter.MinutesPerDay)
		{
			GlobalConverter.SetMinutesResult(minuteTotal);
			GlobalConverter.SetInputConditon(InputCondition::Result);
			ConverterNumberBox().Text(L" ");

			this->Frame().Navigate(xaml_typename<ResultPage>());
		}
	} while (minuteTotal >= GlobalConverter.MinutesPerDay);
}
