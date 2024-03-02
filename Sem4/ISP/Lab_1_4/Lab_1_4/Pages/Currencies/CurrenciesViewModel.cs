using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Runtime.CompilerServices;
using CommunityToolkit.Mvvm.Input;
using System.Text.Json;
using CommunityToolkit.Mvvm.ComponentModel;
using Lab_1_4.Dto;
using Lab_1_4.Services;

namespace Lab_1_4.Pages.Currencies;

public partial class CurrenciesViewModel(IRateService r) : ObservableObject
{
    public ObservableCollection<string> Currs { get; } = ["BYN", "USD", "EUR", "RUB", "CNY", "CHF", "GBP"];
    public List<Rate> ListOfCur { get; } = [];
    public string LastValue { get; set; }

    public string FirstSelected { get; set; } = "";
    public string SecondSelected { get; set; } = "";

    [ObservableProperty] private string result;

    // public string Result
    // {
    //     get => _result;
    //     set => SetField(ref _result, value);
    // }


    [RelayCommand]
    private void UpdateFirstSelected(string selected)
    {
        FirstSelected = selected;
        UpdateCourse(LastValue);
    }

    [RelayCommand]
    private void UpdateSecondSelected(string selected)
    {
        SecondSelected = selected;
        UpdateCourse(LastValue);
    }

    [RelayCommand]
    private void UpdateCourse(string value)
    {
        LastValue = value;
        if (FirstSelected == "" || SecondSelected == "" || ListOfCur.Count == 0) return;
        var a = 0.0;
        try
        {
            if (value != "") a = double.Parse(value);
            var firstRate = ListOfCur.First(it => it.CurAbbreviation == FirstSelected);
            var secondRate = ListOfCur.First(it => it.CurAbbreviation == SecondSelected);
            if (firstRate.CurOfficialRate != null && secondRate.CurOfficialRate != null)
            {
                var resultt = a * ((double)firstRate.CurOfficialRate / firstRate.CurScale) /
                             ((double)secondRate.CurOfficialRate / secondRate.CurScale);
                Result = double.Round(resultt, 4).ToString(CultureInfo.InvariantCulture);
            }
            else
            {
                Result = "Error to convert";
            }
        }
        catch (Exception e)
        {
            Result = "Error to convert";
            Console.WriteLine(e);
        }
    }


    [RelayCommand]
    private async Task DatePickerSelected(DateTime dateTime)
    {
        var neededList = new List<string> { "RUB", "EUR", "USD", "CHF", "CNY", "GBP" };
        var a = await r.GetRates(dateTime.Date);
        var rowList = new List<Rate>(a);
        if (rowList.Count < 6) return;
        ListOfCur.Clear();
        var list = new List<Rate>(neededList.Select(i => rowList.First(it => it.CurAbbreviation == i)));

        foreach (var tmp in list)
        {
            Debug.WriteLine(tmp.CurAbbreviation);
            ListOfCur.Add(tmp);
        }

        var byn = new Rate
        {
            CurAbbreviation = "BYN",
            CurName = "Белорусский рубль",
            CurScale = 1,
            CurOfficialRate = 1,
            CurId = 0
        };
        ListOfCur.Add(byn);
        UpdateCourse(LastValue);
    }
}