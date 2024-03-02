using System.Diagnostics;
using Lab_1_4.Dto;
using Lab_1_4.Services;

namespace Lab_1_4.Pages.Currencies;

public partial class CurrenciesPage : ContentPage
{

    public CurrenciesPage(CurrenciesViewModel viewModel)
    {
        InitializeComponent();
        BindingContext = viewModel;
    }
}