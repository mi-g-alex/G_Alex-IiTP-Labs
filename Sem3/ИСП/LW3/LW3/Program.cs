using System;
using System.Globalization;
using System.Linq;
using LW3.Entities;

namespace LW3;

internal abstract class Program
{
    public static void Main(string[] args)
    {
        var journal = new Journal();
        var air = new Airport();
        air.AddTariffEvent += journal.AddTariffEvent;
        air.AddPassengerEvent += journal.AddPassengerEvent;
        air.AddTicketEvent += journal.AddTicketEvent;
        
        air.AddPassenger("Alex", "Pirsh", "AB123456");
        air.AddPassenger("Egor", "Azarov", "MK098765");
        air.AddPassenger("Alex", "Pirsh", "DS246801");
        air.AddPassenger("Alex", "Pirsh", "FG135792");
        air.AddTariff("MSK-PTR", 300.0);
        air.AddTariff("PTR-MSK", 310.0);
        air.AddTariff("MSK-STB", 200.0);
        air.AddTariff("STB-MSK", 250.0);
        air.AddTariff("QWE-ASD", 123.0);
        air.AddTariff("ASD-QWE", 140.5);
        air.AddTicket("AB123456", "MSK-PTR", new DateTime(12345678)); // 300
        air.AddTicket("AB123456", "PTR-MSK", new DateTime(12340678)); // 310
        air.AddTicket("AB123456", "PTR-MSK", new DateTime(13345678)); // 310
        air.AddTicket("AB123456", "MSK-STB", new DateTime(12445678)); // 200
        air.AddTicket("AB123456", "MSK-PTR", new DateTime(12945678)); // 300
        air.AddTicket("AB123456", "ASD-QWE", new DateTime(12245678)); // 140.5

        air.AddTicket("MK098765", "MSK-PTR", new DateTime(12345678));
        air.AddTicket("MK098765", "PTR-MSK", new DateTime(12340678));
        air.AddTicket("DS246801", "PTR-MSK", new DateTime(13345678));
        air.AddTicket("FG135792", "MSK-STB", new DateTime(12445678));
        air.AddTicket("FG135792", "QWE-ASD", new DateTime(12945678));
        air.AddTicket("DS246801", "ASD-QWE", new DateTime(12245678));

        var a1 = air.GetAllPassengerTicketsPriceSum("AB123456").ToString(CultureInfo.InvariantCulture);
        Console.WriteLine("AB123456: " + a1);
        a1 = air.GetAllPassengerTicketsPriceSum("MK098765").ToString(CultureInfo.InvariantCulture);
        Console.WriteLine("MK098765: " + a1);
        a1 = air.GetAllPassengerTicketsPriceSum("FG135792").ToString(CultureInfo.InvariantCulture);
        Console.WriteLine("FG135792: " + a1);
        a1 = air.GetAllPassengerTicketsPriceSum("DS246801").ToString(CultureInfo.InvariantCulture);
        Console.WriteLine("DS246801: " + a1);


        Console.WriteLine("\n" + air.GetAllTicketsPriceSum().ToString(CultureInfo.InvariantCulture));


        var ans = air.GetPassengerTariffPriceSum("FG135792");
        Console.WriteLine("\nFG135792:");
        foreach (var i in ans)
        {
            Console.WriteLine(i.Key.TariffName + " " + i.Value);
        }


        Console.WriteLine("\n" + air.NumberOfPassengerPayMoreThenX(400) + " pay >= then 400");

        Console.WriteLine("\n" + air.GetPassengerWithMaxTicketPriceSum().PassengerFirstName);

        var a2 = air.GetListOfTariffSortedByPrice();
        foreach (var i in a2)
        {
            Console.WriteLine(i);
        }
    }
}