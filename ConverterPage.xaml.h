#pragma once

#include "ConverterPage.g.h"

namespace winrt::VideoDurationToMinecraftDays::implementation
{
    struct ConverterPage : ConverterPageT<ConverterPage>
    {
        ConverterPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        void InitializeComponent();
        void ConverterNumberBox_ValueChanged(winrt::Microsoft::UI::Xaml::Controls::NumberBox const& sender, winrt::Microsoft::UI::Xaml::Controls::NumberBoxValueChangedEventArgs const& args);
        void InputHandler(int value);
        void Convert();
    };
}

namespace winrt::VideoDurationToMinecraftDays::factory_implementation
{
    struct ConverterPage : ConverterPageT<ConverterPage, implementation::ConverterPage>
    {
    };
}
