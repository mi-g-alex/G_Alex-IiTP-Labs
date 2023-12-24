namespace LW2.Entities;

public class Tariff
{
    public readonly string Name;
    public readonly double Coast;

    public Tariff(string name, double coast)
    {
        Coast = coast;
        Name = name;
    }
}