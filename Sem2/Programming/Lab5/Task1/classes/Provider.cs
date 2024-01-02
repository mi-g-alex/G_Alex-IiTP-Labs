using System.Globalization;

namespace Task1.classes;

public class Provider
{
    private string Name { get; }

    public Provider(string name)
    {
        Name = name;
        _listOfTariffs = new List<Tariff>();
        _listOfUsers = new List<User>();
    }

    private readonly List<User> _listOfUsers;
    private readonly List<Tariff> _listOfTariffs;

    public string AddUser(string? username, string? tariffName)
    {
        foreach (var a in _listOfTariffs.Where(a => a.Name == tariffName))
        {
            if (username == null) continue;
            _listOfUsers.Add(new User(username, a));
            return "Ok";
        }

        return "Tariff Not Found";
    }

    public string AddTariff(string? tariffName, double coast)
    {
        if (_listOfTariffs.Any(a => a.Name == tariffName))
        {
            return "Founded tariff with same name";
        }

        if (tariffName != null) _listOfTariffs.Add(new Tariff(tariffName, coast));
        return "Ok";
    }

    public string GetAllUsers()
    {
        /*return _listOfUsers.Aggregate("", (current, a) => current + (a.Name + "|"));*/
        var s = "";
        foreach (var a in _listOfUsers)
        {
            s += a.Name + "|";
        }

        return s;
    }

    public string GetAllTariffs()
    {
        /*return _listOfTariffs.Aggregate("", (current, a) => current + (a.Name + "|"));*/
        var s = "";
        foreach (var a in _listOfTariffs)
        {
            s += a.Name + "|";
        }

        return s;
    }

    public void SetCount(string? userName, double usageCount)
    {
        if (usageCount < 0) usageCount = 0;
        foreach (var a in _listOfUsers.Where(a => a.Name == userName))
        {
            a.Used = usageCount;
        }
    }

    public double GetSum(string userName)
    {
        return _listOfUsers
            .Where(a => a.Name == userName)
            .Select(a => a.Used * a.UserTariff.Coast)
            .FirstOrDefault();
    }

    public string SearchMax()
    {
        double max = 0;
        var name = "";
        foreach (var a in _listOfUsers)
        {
            var tmp = GetSum(a.Name);
            if (max > tmp) continue;
            max = tmp;
            name = a.Name;
        }

        return name + " : " + Convert.ToString(max, CultureInfo.InvariantCulture);
    }

    public double SumForTariff(string tariffName)
        => _listOfUsers.Where(a => a.UserTariff.Name == tariffName).Sum(a => a.UserTariff.Coast * a.Used);
}