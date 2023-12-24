using System;

namespace LW3.Entities;

public class PassengerLog : AirportLog
{
    private Passenger Passenger { get; set; }

    public PassengerLog(Passenger passenger, DateTime date, string info = "") : base(date, info)
    {
        Passenger = passenger;
    }

    public override string ToString()
    {
        return
            $"{Date}\tNew Passenger {Passenger.PassengerFirstName + " " + Passenger.PassengerSecondName +
                                     " " + Passenger.PassengerPassportId} ";
    }
}