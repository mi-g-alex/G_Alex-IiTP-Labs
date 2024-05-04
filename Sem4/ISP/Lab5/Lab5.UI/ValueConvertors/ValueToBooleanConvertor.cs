using System.Globalization;

namespace Lab5.UI.ValueConvertors;

internal class ValueToBooleanConvertor: IValueConverter
{
    public object? Convert(object? value, Type targetType, object? parameter, CultureInfo culture)
    {
        return value is not null;
    }

    public object? ConvertBack(object? value, Type targetType, object? parameter, CultureInfo culture)
    {
        return value is null;
    }
}