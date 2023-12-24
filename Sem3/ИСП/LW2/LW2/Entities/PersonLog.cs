using System;

namespace LW2.Entities;

public class PersonLog : AirportLog
{
    private Person Person { get; set; }

    public PersonLog(Person person, DateTime date, string info = "") : base(date, info)
    {
        Person = person;
    }

    public override string ToString()
    {
        return $"{Date}\tNew person {Person.Name} ";
    }
}