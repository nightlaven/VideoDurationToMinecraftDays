#include "pch.h"
#include "ResultPage.xaml.h"
#include "Models/Converter.h"
#if __has_include("ResultPage.g.cpp")
#include "ResultPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Utility;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::VideoDurationToMinecraftDays::implementation
{
    int32_t ResultPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ResultPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void ResultPage::InitializeComponent()
    {
        ResultPageT::InitializeComponent();

        ResultTxt().Text(GlobalConverter.GetInputConditionTxt());
    }
}
