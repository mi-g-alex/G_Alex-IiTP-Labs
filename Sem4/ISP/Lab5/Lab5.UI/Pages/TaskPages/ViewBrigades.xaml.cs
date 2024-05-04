namespace Lab5.UI.Pages.TaskPages;

public partial class ViewBrigades : ContentPage
{
    public ViewBrigades(ViewModels.ViewBrigadesViewModel viewBrigadesViewModel)
    {
        InitializeComponent();
        BindingContext = viewBrigadesViewModel;
    }
}