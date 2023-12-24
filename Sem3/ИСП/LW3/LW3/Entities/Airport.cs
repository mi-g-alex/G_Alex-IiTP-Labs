#nullable enable
using System;
using System.Collections.Generic;
using System.Linq;
using LW3.Contracts;

namespace LW3.Entities;

public class Airport : IAirport
{
    private readonly Dictionary<string, Tariff> _tariffs = new();
    private readonly List<Passenger> _passengers = new();
    private readonly List<Ticket> _tickets = new();
    
    public delegate void AddPassengerHandler(Passenger passenger);
    public delegate void AddTariffHandler(Tariff tariff);
    public delegate void AddTicketHandler(Ticket ticket);
    public event AddPassengerHandler? AddPassengerEvent;
    public event AddTariffHandler? AddTariffEvent;
    public event AddTicketHandler? AddTicketEvent;

    public void AddTariff(string name, double price)
    {
        if (_tariffs.Any(tariff => tariff.Key == name) == false)
        {
            _tariffs.Add(name, new Tariff(name, price));
            OnAddTariffEvent(new Tariff(name, price));
        }
    }

    public void AddPassenger(string firstName, string secondName, string passportId)
    {
        if (_passengers.Any(passenger => passenger.PassengerPassportId == passportId) == false)
        {
            _passengers.Add(new Passenger(firstName, secondName, passportId));
            OnAddPassengerEvent(new Passenger(firstName, secondName, passportId));
        }
    }

    public void AddTicket(string passengerName, string tariffName, DateTime dateTime)
    {
        var passenger = _passengers.Find(a => a.PassengerPassportId == passengerName); 
        var tariff = _tariffs[tariffName]; 

        if (_tickets.Any(ticket => ticket.TicketPassenger.Equals(passenger)
                                   && ticket.TicketTariff.Equals(tariff)
                                   && ticket.TicketDateTime.Equals(dateTime)) == false)
        {
            _tickets.Add(new Ticket(passenger, tariff, dateTime));
            OnAddTicketEvent(new Ticket(passenger, tariff, dateTime));
        }
    }

    public List<string> GetListOfTariffSortedByPrice() =>
        (from entry in _tariffs orderby entry.Value.TariffPrice select entry.Key).ToList();


    public double GetAllTicketsPriceSum() =>
        _tickets.Sum(a => a.TicketTariff.TariffPrice);


    public double GetAllPassengerTicketsPriceSum(string passportId)
    {
        var passenger = _passengers.Find(a => a.PassengerPassportId == passportId); 
        return _tickets.Where(a => a.TicketPassenger.Equals(passenger))
            .Sum(a => a.TicketTariff.TariffPrice);
    }

    public Passenger GetPassengerWithMaxTicketPriceSum()
    {
        var maxPass = _passengers[0];
        var maxSum = 0.0;
        foreach (var curPass in _passengers)
        {
            var currSum = GetAllPassengerTicketsPriceSum(curPass.PassengerPassportId);
            if (!(currSum > maxSum)) continue;
            maxPass = curPass;
            maxSum = currSum;
        }
        return maxPass;
    }

    public int NumberOfPassengerPayMoreThenX(double sum)
        => _passengers.Aggregate(0, (x, a) => GetAllPassengerTicketsPriceSum(a.PassengerPassportId) > sum ? x + 1 : x);


    public Dictionary<Tariff, double> GetPassengerTariffPriceSum(string passportId)
    {
        var passenger = _passengers.Find(a => a.PassengerPassportId == passportId); 
        var b = _tickets.Where(it => it.TicketPassenger.Equals(passenger))
            .GroupBy(it => it.TicketTariff);
        return b.ToDictionary(g => g.Key, g => g.Sum(it => it.TicketTariff.TariffPrice));
    }

    protected virtual void OnAddTariffEvent(Tariff tariff)
    {
        AddTariffEvent?.Invoke(tariff);
    }

    protected virtual void OnAddTicketEvent(Ticket ticket)
    {
        AddTicketEvent?.Invoke(ticket);
    }

    protected virtual void OnAddPassengerEvent(Passenger passenger)
    {
        AddPassengerEvent?.Invoke(passenger);
    }
}