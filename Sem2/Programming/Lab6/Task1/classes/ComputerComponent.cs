namespace Task1.classes;

public abstract class ComputerComponent
{
    protected string Manufacturer { get; set; }
    public string Model { get; set; }
    public double Price { get; set; }
    

    protected ComputerComponent(string manufacturer, string model, double price)
    {
        Console.WriteLine("Тут был вызван конструктор");
        Manufacturer = manufacturer;
        Model = model;
        Price = price;
    }

    public abstract void DisplayInfo();

    public void PrintInfo()
    {
        Console.WriteLine(GetType().Name);
    }

    protected virtual void PerformDiagnostic()
    {
        Console.WriteLine("Diagnosting component...");
    }
}