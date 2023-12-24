using System;

namespace LW3.Entities;

public class Ticket
{
    public readonly Passenger TicketPassenger;
    public readonly Tariff TicketTariff;
    public readonly DateTime TicketDateTime;

    public Ticket(Passenger ticketPassenger, Tariff ticketTariff, DateTime ticketDateTime)
    {
        TicketPassenger = ticketPassenger;
        TicketTariff = ticketTariff;
        TicketDateTime = ticketDateTime;
    }
    
    
}