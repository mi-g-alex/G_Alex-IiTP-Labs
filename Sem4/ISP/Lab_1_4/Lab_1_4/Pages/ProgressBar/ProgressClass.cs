using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace Lab_1_4.Pages.ProgressBar;

public sealed class ProgressClass : INotifyPropertyChanged
{
    private double _progress;

    public double Progress
    {
        get => _progress;
        set => SetField( ref _progress, value);
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