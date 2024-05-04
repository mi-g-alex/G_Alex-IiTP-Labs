using Lab5.UI.Pages.TaskPages;

namespace Lab5.UI;

public partial class AppShell : Shell
{
    public AppShell()
    {
        InitializeComponent();
        Routing.RegisterRoute(nameof(ViewWork), typeof(ViewWork));
        Routing.RegisterRoute(nameof(AddOrEditBrigade), typeof(AddOrEditBrigade));
        Routing.RegisterRoute(nameof(AddOrEditWork), typeof(AddOrEditWork));
    }
}