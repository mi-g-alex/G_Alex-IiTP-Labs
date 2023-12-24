#nullable enable
using System;
using LW1.Collections;
using LW1.Contracts;

namespace LW1.Entities;

internal class Person
{
    public readonly string Name;
    public readonly MyCustomCollection<Ticket?> Tickets = new();

    public Person(string name)
    {
        Name = name;
    }
}

internal class Ticket
{
    public string Route;
    public readonly double Coast;
    public readonly string Date;

    public Ticket(string route, double coast, string date)
    {
        Date = date;
        Coast = coast;
        Route = route;
    }
}

internal class Tariff
{
    public readonly string Name;
    public readonly double Coast;

    public Tariff(string name, double coast)
    {
        Coast = coast;
        Name = name;
    }
}

public class Airport : IAirport
{
    private readonly MyCustomCollection<Tariff> _tariffs = new();
    private readonly MyCustomCollection<Person> _people = new();

    public void AddTariff(string route, double coast)
    {
        _tariffs.Add(new Tariff(route, coast));
    }

    public void AddPerson(string name)
    {
        _people.Add(new Person(name));
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
            person.Tickets.Add(
                new Ticket(
                    route: tariff.Name,
                    coast: tariff.Coast,
                    date: date
                )
            );
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
}