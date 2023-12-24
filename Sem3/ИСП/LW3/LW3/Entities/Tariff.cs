using System;

namespace LW3.Entities;

public class Tariff
{
    public readonly string TariffName;
    public readonly double TariffPrice;

    public Tariff(string tariffName, double tariffPrice)
    {
        TariffName = tariffName;
        TariffPrice = tariffPrice;
    }
}