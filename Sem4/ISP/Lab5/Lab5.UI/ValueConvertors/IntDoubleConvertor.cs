using System.Globalization;

namespace Lab5.UI.ValueConvertors;

public class IntDoubleConvertor : IValueConverter
{
    public object? Convert(object? value, Type targetType, object? parameter, CultureInfo culture)
    {
        return System.Convert.ToDouble(value);
    }

    public object? ConvertBack(object? value, Type targetType, object? parameter, CultureInfo culture)
    {
        return System.Convert.ToInt32(value);
    }
}