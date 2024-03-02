using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace Lab_1_4.Pages.Currencies;

public sealed class ResultClass : INotifyPropertyChanged
{
    private double _result;

    public double Result
    {
        get => _result;
        set => SetField( ref _result, value);
    }

    public event PropertyChangedEventHandler PropertyChanged;

    private void OnPropertyChanged([CallerMemberName] string propertyName = null)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    private void SetField<T>(ref T field, T value, [CallerMemberName] string propertyName = null)
    {
        if (EqualityComparer<T>.Default.Equals(field, value)) return;
        field = value;
        OnPropertyChanged(propertyName);
    }
}