#nullable enable
using System;
using LW2.Collections;
using LW2.Contracts;

namespace LW2.Entities;

public sealed class Airport : IAirport
{
    private readonly MyCustomCollection<Tariff> _tariffs = new();
    private readonly MyCustomCollection<Person> _people = new();

    public delegate void AddPersonHandler(Person person);

    public delegate void AddTariffHandler(Tariff tariff);

    public delegate void AddTicketHandler(Ticket ticket);

    public event AddPersonHandler? AddPersonEvent;
    public event AddTariffHandler? AddTariffEvent;
    public event AddTicketHandler? AddTicketEvent;

    public void AddTariff(string route, double coast)
    {
        _tariffs.Add(new Tariff(route, coast));
        OnAddTariffEvent(new Tariff(route, coast));
    }

    public void AddPerson(string name)
    {
        _people.Add(new Person(name));
        OnAddPersonEvent(new Person(name));
    }

    public void RegisterTicket(string name, string route, string date)
    {
        var count = _tariffs.Count;
        Tariff? tariff = null;
        Person? person = null;
        for (var i = 0; i < count; i++)
        {
            if (_tariffs[i].Name == route)
                tariff = _tariffs[i];
        }

        count = _people.Count;
        for (var i = 0; i < count; i++)
        {
            if (_people[i].Name == name)
                person = _people[i];
        }

        if (person != null && tariff != null)
        {
            person.Tickets.Add(
                new Ticket(
                    route: tariff.Name,
                    coast: tariff.Coast,
                    date: date
                )
            );
            OnAddTicketEvent(new Ticket(
                route: tariff.Name,
                coast: tariff.Coast,
                date: date)
            );
        }
        else Console.WriteLine("Not Found person or tariff");
    }

    public double GetSumOfTicketsByName(string name)
    {
        var count = _people.Count;
        var sum = 0.0;
        Person? person = null;
        for (var i = 0; i < count; i++)
        {
            if (_people[i].Name == name)
                person = _people[i];
        }

        if (person == null) return -1;

        var ticket = person.Tickets;
        ticket.Reset();
        while (ticket.Current() != default)
        {
            sum += ticket.Current()!.Coast;
            ticket.Next();
        }

        return sum;
    }

    public string GetListOfPeopleByDate(string date)
    {
        var count = _people.Count;
        var list = "";
        for (var i = 0; i < count; i++)
        {
            var ticket = _people[i].Tickets;
            ticket.Reset();
            while (ticket.Current() != null)
            {
                if (ticket.Current()?.Date == date)
                {
                    list += _people[i].Name + ", ";
                    break;
                }
            }
        }

        return "List: " + list;
    }

    private void OnAddPersonEvent(Person person)
    {
        AddPersonEvent?.Invoke(person);
    }

    private void OnAddTariffEvent(Tariff tariff)
    {
        AddTariffEvent?.Invoke(tariff);
    }

    private void OnAddTicketEvent(Ticket ticket)
    {
        AddTicketEvent?.Invoke(ticket);
    }
}