using System;

namespace LW3.Entities;

public class TariffLog : AirportLog
{
    private Tariff Tariff { get; set; }

    public TariffLog(Tariff tariff, DateTime date, string info = "") : base(date, info)
    {
        Tariff = tariff;
    }

    public override string ToString()
    {
        return $"{Date}\tNew tariff {Tariff.TariffName} {Tariff.TariffPrice}";
    }
}