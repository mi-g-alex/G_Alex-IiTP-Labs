using System;

namespace LW2.Entities;

public class TicketLog : AirportLog
{
    private Ticket Ticket { get; set; }

    public TicketLog(Ticket ticket, DateTime date, string info = "") : base(date, info)
    {
        Ticket = ticket;
    }

    public override string ToString()
    {
        return $"New ticket registered\n{Date}\t{Ticket.Date} {Ticket.Coast} {Ticket.Route}\n";
    }
}