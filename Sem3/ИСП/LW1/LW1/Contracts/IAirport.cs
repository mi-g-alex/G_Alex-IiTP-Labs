namespace LW1.Contracts;

public interface IAirport
{
    void AddTariff(string route, double coast);

    void AddPerson(string name);

    void RegisterTicket(string name, string route, string date);

    double GetSumOfTicketsByName(string name);

    string GetListOfPeopleByDate(string date);

}