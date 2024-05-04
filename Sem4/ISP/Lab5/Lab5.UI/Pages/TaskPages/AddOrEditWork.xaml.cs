using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab5.UI.ViewModels;

namespace Lab5.UI.Pages.TaskPages;

public partial class AddOrEditWork : ContentPage
{
    public AddOrEditWork(AddOrEditWorkViewModel viewModel)
    {
        InitializeComponent();
        BindingContext = viewModel;
    }
}