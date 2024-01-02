namespace Task1.classes;

public class Tariff
{
    public string Name { get; }
    public double Coast { get; }

    public Tariff(string name, double coast)
    {
        Name = name;
        Coast = coast;
    }
}