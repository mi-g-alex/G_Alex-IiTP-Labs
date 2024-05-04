using System.Globalization;

namespace Lab5.UI.ValueConvertors;

public class DateToStringConvertor: IValueConverter
{
    public object? Convert(object? value, Type targetType, object? parameter, CultureInfo culture)
    {
        var date = (DateTime)(value ?? new DateTime().Date);
        return date.ToString("dd MMM yyyy");
    }

    public object? ConvertBack(object? value, Type targetType, object? parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
}