using LW2.Collections;

namespace LW2.Entities;

public class Person
{
    public readonly string Name;
    public readonly MyCustomCollection<Ticket> Tickets = new();

    public Person(string name)
    {
        Name = name;
    }
}