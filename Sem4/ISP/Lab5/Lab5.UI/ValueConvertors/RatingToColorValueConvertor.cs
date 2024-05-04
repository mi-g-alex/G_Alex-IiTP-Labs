using System.Globalization;

namespace Lab5.UI.ValueConvertors;

internal class RatingToColorValueConvertor : IValueConverter
{
    public object? Convert(object? value, Type targetType, object? parameter, CultureInfo culture)
    {
        return (int)(value ?? 0) < 7 ? Colors.LightPink : Colors.White;
    }

    public object ConvertBack(object? value, Type targetType, object? parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
}