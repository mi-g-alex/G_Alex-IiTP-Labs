namespace LW3.Entities;

public class Passenger
{
    public readonly string PassengerFirstName;
    public readonly string PassengerSecondName;
    public readonly string PassengerPassportId;

    public Passenger(string passengerFirstName, string passengerSecondName, string passengerPassportId)
    {
        PassengerFirstName = passengerFirstName;
        PassengerSecondName = passengerSecondName;
        PassengerPassportId = passengerPassportId;
    }
}