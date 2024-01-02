namespace Task1.classes;

public class User
{
    public string Name { get; }
    public double Used { get; set; }
    public Tariff UserTariff { get; }

    public User(string name, Tariff tariff)
    {
        Name = name;
        UserTariff = tariff;
        Used = 0;
    }
}