#include "pch.h"
#include "MainWindow.xaml.h"
#include "Converter.h"
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Windows.Graphics.h>
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::Graphics;
using namespace Microsoft::UI::Windowing;
using namespace Utility;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::VideoDurationToMinecraftDays::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::InitializeComponent()
    {
        MainWindowT::InitializeComponent();

        ExtendsContentIntoTitleBar(true);
        SetTitleBar(AppTitleBar());

        auto appWindow = this->AppWindow();
        HandleWindow(appWindow);
    }

    void MainWindow::HandleWindow(auto appWindow)
    {
        appWindow.Resize(
            SizeInt32(425, 250)
        );

        auto area = DisplayArea::GetFromWindowId(appWindow.Id(), DisplayAreaFallback::Nearest);
        if (area == nullptr) return;

        int x = (area.WorkArea().Width - appWindow.Size().Width) / 2;
        int y = (area.WorkArea().Height - appWindow.Size().Height) / 2;

        appWindow.Move(PointInt32{ x, y });
    }
}

void winrt::VideoDurationToMinecraftDays::implementation::MainWindow::AppTitleBar_BackRequested
(winrt::Microsoft::UI::Xaml::Controls::TitleBar const& sender, winrt::Windows::Foundation::IInspectable const& args)
{
    if (rootFrame().CanGoBack())
    {
        GlobalConverter.ClearValues();
        rootFrame().GoBack();
    }

}
