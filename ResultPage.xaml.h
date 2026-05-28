#pragma once

#include "ResultPage.g.h"

namespace winrt::VideoDurationToMinecraftDays::implementation
{
    struct ResultPage : ResultPageT<ResultPage>
    {
        ResultPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        void InitializeComponent();
    };
}

namespace winrt::VideoDurationToMinecraftDays::factory_implementation
{
    struct ResultPage : ResultPageT<ResultPage, implementation::ResultPage>
    {
    };
}
