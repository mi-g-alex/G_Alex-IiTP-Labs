using System.Diagnostics.CodeAnalysis;

namespace Task1.Classes;

public class Operator
{
    private static Operator? _operator;
    private string? _name;
    private readonly int _numberOfUsers;
    private readonly Tariff _tariff;

    private Operator(int numberOfUsers, string? name, double cost): this(numberOfUsers, cost)
    {
        _name = name;
    }
    
    private Operator(int numberOfUsers, double cost)
    {
        _numberOfUsers = numberOfUsers;
        _tariff = new Tariff(cost);
    }

    public double CalculatingSum() =>
        _numberOfUsers * _tariff.CostOfTariff;


    public void UpCost(double a) =>
        _tariff.UpCost(a);


    public void DownCost(double a) =>
        _tariff.DownCost(a);


    public static Operator GetInstance(int numberOfUsers, string? name, double cost) =>
        _operator ??= new Operator(numberOfUsers, name, cost);
    
    public static Operator GetInstance(int numberOfUsers, double cost) =>
        _operator ??= new Operator(numberOfUsers, cost);
}