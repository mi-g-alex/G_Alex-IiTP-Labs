namespace Task1.classes;

public class GraphicsCard : ComputerComponent
{
    public int Memory { get; set; }
    public int MinimumSystemPower { get; set; }

    public GraphicsCard(int memory, int minimumSystemPower, string manufacturer, string model, double price)
        : base(manufacturer, model, price)
    {
        Memory = memory;
        MinimumSystemPower = minimumSystemPower;
    }

    public override void DisplayInfo()
    {
        Console.WriteLine(
            $"Graphic Card:\t{Manufacturer} {Model}\n" +
            $"Memory:\t\t{Memory}\n" +
            $"MSP:\t\t{MinimumSystemPower}\n" +
            $"Price:\t\t{Price}$");
    }
    
    public new void PerformDiagnostic()
    {
        Console.WriteLine("Diag GraphicCard...");
        Console.WriteLine("Calling base class function:");
        base.PerformDiagnostic();
    }
}