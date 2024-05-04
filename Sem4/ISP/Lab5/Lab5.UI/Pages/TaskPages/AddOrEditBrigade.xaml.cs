using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab5.UI.ViewModels;

namespace Lab5.UI.Pages.TaskPages;

public partial class AddOrEditBrigade : ContentPage
{
    public AddOrEditBrigade(AddOrEditBrigadeViewModel viewModel)
    {
        InitializeComponent();
        BindingContext = viewModel;
    }
}