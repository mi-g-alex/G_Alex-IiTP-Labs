namespace Task1.Classes;

public class Tariff
{
    public double CostOfTariff { get; private set; }

    public Tariff(double costOfTariff)
    {
        CostOfTariff = costOfTariff;
    }

    public void UpCost(double a)
    {
        CostOfTariff += a;
    }

    public void DownCost(double a)
    {
        if (CostOfTariff > a)
            CostOfTariff -= a;
    }
}