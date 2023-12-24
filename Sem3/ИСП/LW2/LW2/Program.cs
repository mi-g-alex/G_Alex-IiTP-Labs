using System;
using LW2.Collections;
using LW2.Entities;

namespace LW2;

internal abstract class Program
{
    public static void Main(string[] args)
    {
        var airport = new Airport();
        var journal = new Journal();
        var a = new MyCustomCollection<string>();
        airport.AddTariffEvent += journal.AddTariffEvent;
        airport.AddPersonEvent += delegate(Person person) { journal.AddPersonEvent(person); };
        airport.AddTicketEvent += (Ticket ticket) =>
        {
            var purchaseEvent = new TicketLog(ticket, DateTime.Now);
            Console.WriteLine(purchaseEvent);
        };
        a.Add("1");
            
        airport.AddPerson("Egor");
        airport.AddPerson("Sasha");
        airport.AddTariff("Minsk-Moscow", 10);
        airport.AddTariff("Minsk-Piter", 5);
        airport.RegisterTicket("Egor", "Minsk-Moscow", "21.12.2022");
        airport.RegisterTicket("Sasha", "Minsk-Moscow", "21.12.2022");
        airport.RegisterTicket("Egor", "Minsk-Piter", "23.12.2022");
        var dates = airport.GetListOfPeopleByDate("21.12.2022");
        Console.WriteLine(dates);
        var sasha = airport.GetSumOfTicketsByName("Sasha");
        Console.WriteLine("Coast for Sasha: " + sasha);
        var egor = airport.GetSumOfTicketsByName("Egor");
        Console.WriteLine("Coast for Egor: " + egor);
            
        try
        {
            var rate = a[2];
        }
        catch (IndexOutOfRangeException ex)
        {
            Console.WriteLine($"Exception!!! {ex.Data}");
        }

        try
        {
            a.Remove("123");
        }
        catch (MyException ex)
        {
            Console.WriteLine($"MyException!!! {ex.Data}");
        }
    }
}