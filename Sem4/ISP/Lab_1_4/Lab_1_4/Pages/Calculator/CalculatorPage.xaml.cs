using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1_4;

public partial class CalculatorPage : ContentPage
{
    private static readonly string SeparatorChar = CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator;

    private double? _memoryValue = null;
    private double _currentValue = 0.0;
    private double? _prevValue = null;
    private string _currentText = "0";
    private string _prevText = "";
    private string _selectedSign = "";

    private bool _needResetInput = false;

    public CalculatorPage()
    {
        InitializeComponent();
        SeparatorButton.Text = SeparatorChar;
        ButtonMc.IsEnabled = false;
        ButtonMr.IsEnabled = false;
    }


    private void OnNumberButtonClicked(object sender, EventArgs e)
    {
        var btn = (Button)sender;

        if(_needResetInput)
        {
            _currentValue = 0.0;
            _currentText = "0";
            _needResetInput = false;
        }

        if (btn.Text == SeparatorChar)
        {
            if (_currentText.Contains(SeparatorChar)) return;
        }

        if (_currentText != "0" || btn.Text == SeparatorChar) _currentText += btn.Text;
        else _currentText = btn.Text;
        UpdateText();
    }


    private void OnMemoryClearButtonClicked(object sender, EventArgs e)
    {
        _memoryValue = null;
        UpdateMemoryText();
    }

    private void OnMemoryPasteButtonClicked(object sender, EventArgs e)
    {
        _currentValue = _memoryValue ?? 0;
        _currentText = FromDoubleToString(_currentValue);
        UpdateText();
        UpdateMemoryText();
    }

    private void OnMemoryPlusButtonClicked(object sender, EventArgs e)
    {
        _memoryValue = (_memoryValue ?? 0) + _currentValue;
        UpdateMemoryText();
    }

    private void OnMemoryMinusButtonClicked(object sender, EventArgs e)
    {
        _memoryValue = (_memoryValue ?? 0) - _currentValue;
        UpdateMemoryText();
    }

    private void OnMemorySaveButtonClicked(object sender, EventArgs e)
    {
        _memoryValue = _currentValue;
        UpdateMemoryText();
    }

    private void OnCleanButtonClicked(object sender, EventArgs e)
    {
        var btn = (Button)sender;
        switch (btn.Text)
        {
            case "CE":
                _currentText = "0";
                _currentValue = 0.0;
                break;
            case "C":
                _currentText = "0";
                _currentValue = 0.0;
                _prevText = "";
                _prevValue = null;
                break;
        }

        UpdateText();
    }

    private void OnDeleteClicked(object sender, EventArgs e)
    {
        if (_needResetInput)
        {
            _currentText = "0";
            _needResetInput = false;
        }
        else
        {
            if (_currentText.Length == 2 && _currentText[0] == '-') _currentText = "0";
            else _currentText = _currentText.Length > 1 ? _currentText.Remove(_currentText.Length - 1) : "0";
        }

        UpdateText();
    }


    private void OnReverseButtonClicked(object sender, EventArgs e)
    {
        if (_currentValue == 0)
        {
            if (Application.Current?.MainPage != null)
                Application.Current?.MainPage.DisplayAlert("Error", "Can't divide by 0", "OK");
        }
        else
        {
            _currentValue = 1 / _currentValue;
            _currentText = FromDoubleToString(_currentValue);
        }

        UpdateText();
    }

    private void UpdateText()
    {
        CurrentValue.Text = _currentText;
        LastResult.Text = _prevText + _selectedSign;
        _currentValue = FromStringToDouble(_currentText);
        if (_prevText != "") _prevValue = FromStringToDouble(_prevText);
    }

    private static double FromStringToDouble(string number)
    {
        return double.Parse(number);
    }

    private static string FromDoubleToString(double number)
    {
        var res = number.ToString(CultureInfo.InvariantCulture);
        return res;
    }

    private void OnSinClicked(object sender, EventArgs e)
    {
        _currentValue = Math.Sin(_currentValue / 180.0 * Math.PI);
        _currentText = FromDoubleToString(_currentValue);
        UpdateText();
    }

    private void OnWorkWithCurrentButtonClicked(object sender, EventArgs e)
    {
        var btn = (Button)sender;
        _needResetInput = btn.Text != "+/-" ;
        switch (btn.Text)
        {
            case "%":
                _currentValue /= 100;
                break;
            case "x\u00b2":
                _currentValue *= _currentValue;
                break;
            case "\u221ax":
                if (_currentValue < 0)
                {
                    if (Application.Current?.MainPage != null)
                        Application.Current?.MainPage.DisplayAlert("Warning!", "Can't take root for this number", "Ok");
                }
                else
                {
                    _currentValue = Math.Sqrt(_currentValue);
                }

                break;
            case "sin(x)":
                _currentValue = Math.Sin(_currentValue / 180.0 * Math.PI);
                break;
            case "+/-":
                _currentValue *= -1;
                break;
        }

        _currentText = FromDoubleToString(_currentValue);
        UpdateText();
    }

    private void UpdateMemoryText()
    {
        if (_memoryValue == null)
        {
            ButtonMc.IsEnabled = false;
            ButtonMr.IsEnabled = false;
            MemoryText.Text = "";
        }
        else
        {
            MemoryText.Text = FromDoubleToString((double)_memoryValue);
            ButtonMc.IsEnabled = true;
            ButtonMr.IsEnabled = true;
        }
    }


    private void OnWorkWithBothButtonClicked(object sender, EventArgs e)
    {
        var btn = (Button)sender;
        _prevValue = _currentValue;
        _prevText = _currentText;
        _selectedSign = btn.Text;
        _needResetInput = true;
        UpdateText();
    }

    private void EqualButtonClicked(object sender, EventArgs e)
    {
        _needResetInput = true;
        switch (_selectedSign)
        {
            case "+":
                _currentValue += _prevValue ?? 0;
                break;
            case "-":
                _currentValue = (_prevValue ?? _currentValue * 2) - _currentValue;
                break;
            case "/":
                if (_currentValue != 0)
                {
                    _currentValue = 1 / _currentValue;
                }
                else
                {
                    if (Application.Current?.MainPage != null)
                        Application.Current?.MainPage.DisplayAlert("Warning!", "Can't divide by 0", "Ok");
                }
                break;
            case "*":
                _currentValue *= _prevValue ?? 1;
                break;
        }

        _currentText = FromDoubleToString(_currentValue);
        _prevText = "";
        _prevValue = null;
        _selectedSign = "";
        UpdateText();

    }
}