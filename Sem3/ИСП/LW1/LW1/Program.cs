using System;
using LW1.Entities;

namespace LW1
{
    internal abstract class Program
    {
        public static void Main(string[] args)
        {
            Airport airport = new();
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
        }
    }
}