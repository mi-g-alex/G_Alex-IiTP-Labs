using System;
using System.Collections.Generic;
using LW3.Entities;

namespace LW3.Contracts;

public interface IAirport
{
    void AddTariff(string name, double price); // 

    void AddPassenger(string firstName, string secondName, string passportId); // 

    void AddTicket(string passengerName, string tariffName, DateTime dateTime); // 

    List<string> GetListOfTariffSortedByPrice(); // 

    double GetAllTicketsPriceSum(); // 

    double GetAllPassengerTicketsPriceSum(string passenger); // 

    Passenger GetPassengerWithMaxTicketPriceSum(); // 

    int NumberOfPassengerPayMoreThenX(double sum); // 

    Dictionary<Tariff, double> GetPassengerTariffPriceSum(string passenger); //

}