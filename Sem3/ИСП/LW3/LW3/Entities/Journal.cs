#nullable enable
using System;
using System.Collections.ObjectModel;

namespace LW3.Entities;

public class Journal
{
    
    private Collection<TicketLog> TicketAddingEvent { get; set; }
    private Collection<TariffLog> TariffAddingEvent { get; set; }
    private Collection<PassengerLog> PassengerAddingEvent { get; set; }

    public Journal()
    {
        TicketAddingEvent = new Collection<TicketLog>();
        TariffAddingEvent = new Collection<TariffLog>();
        PassengerAddingEvent = new Collection<PassengerLog>();
    }

    public void AddPassengerEvent(Passenger passenger)
    {
        var personEvent = new PassengerLog(passenger, DateTime.Now);
        PassengerAddingEvent.Add(personEvent);
        Console.WriteLine($"Adding passenger to journal\n{personEvent}\n");
    }

    public void AddTariffEvent(Tariff tariff)
    {
        var tariffEvent = new TariffLog(tariff, DateTime.Now);
        TariffAddingEvent.Add(tariffEvent);
        Console.WriteLine($"Adding tariff to journal\n{tariffEvent}\n");
    }
    
    public void AddTicketEvent(Ticket ticket)
    {
        var ticketEvent = new TicketLog(ticket, DateTime.Now);
        TicketAddingEvent.Add(ticketEvent);
        Console.WriteLine($"Adding ticket to journal\n{ticketEvent}\n");
    }
}