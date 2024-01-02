namespace Task3.Classes;

public static class DoSomething
{
    public static string GetDay(string dat)
    {
        var dateTime = DateTime.ParseExact(dat, "dd.MM.yyyy", System.Globalization.CultureInfo.InvariantCulture);
        return dateTime.DayOfWeek.ToString();
    }

    public static double GetDaysSpan(int day, int month, int year) =>
        (new DateTime(year, month, day) - DateTime.Today.AddDays(0)).Days;
}