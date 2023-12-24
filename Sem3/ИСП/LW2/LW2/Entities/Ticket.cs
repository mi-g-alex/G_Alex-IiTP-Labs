namespace LW2.Entities;

public class Ticket
{
    public readonly string Route;
    public readonly double Coast;
    public readonly string Date;

    public Ticket(string route, double coast, string date)
    {
        Date = date;
        Coast = coast;
        Route = route;
    }
}