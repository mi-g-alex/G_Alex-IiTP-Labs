using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.UI.Pages.TaskPages;

public partial class ViewWork : ContentPage
{
    public ViewWork(ViewModels.ViewWorkViewModel viewWorkViewModel)
    {
        InitializeComponent();
        BindingContext = viewWorkViewModel;
    }
}