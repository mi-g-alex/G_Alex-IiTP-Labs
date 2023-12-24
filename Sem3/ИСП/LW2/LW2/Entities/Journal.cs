#nullable enable
using System;
using LW2.Collections;

namespace LW2.Entities;

public class Journal
{
    public delegate void AddPersonDelegate(Person person);

    public AddPersonDelegate? PersonDelegate;
    private MyCustomCollection<PersonLog> PersonAddingEvent { get; set; }
    private MyCustomCollection<TariffLog> TariffAddingEvent { get; set; }

    public Journal()
    {
        PersonAddingEvent = new MyCustomCollection<PersonLog>();
        TariffAddingEvent = new MyCustomCollection<TariffLog>();
        PersonDelegate += AddPersonEvent;
    }

    public void AddPersonEvent(Person person)
    {
        var personEvent = new PersonLog(person, DateTime.Now);
        PersonAddingEvent.Add(personEvent);
        Console.WriteLine($"Adding person to journal\n{personEvent}\n");
    }

    public void AddTariffEvent(Tariff tariff)
    {
        var tariffEvent = new TariffLog(tariff, DateTime.Now);
        TariffAddingEvent.Add(tariffEvent);
        Console.WriteLine($"Adding tariff to journal\n{tariffEvent}\n");
    }
}