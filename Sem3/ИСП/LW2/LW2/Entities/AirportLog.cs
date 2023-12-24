using System;

namespace LW2.Entities;

public class AirportLog
{
    protected AirportLog(DateTime date, string info = "")
    {
        Info = info;
        Date = date;
    }

    protected DateTime Date{get; set;}
    public string Info{get; protected set;}
}