namespace Task1.classes;

public class Processor : ComputerComponent
{
    public int CoreCount { get; set; }
    public int ThreadCount { get; set; }

    public Processor(int coreCount, int threadCount, string manufacturer, string model, double price)
        : base(manufacturer, model, price)
    {
        CoreCount = coreCount;
        ThreadCount = threadCount;
    }

    public override void DisplayInfo()
    {
        Console.WriteLine(
            $"Processor:\t{Manufacturer} {Model}\n" +
            $"Cores:\t\t{CoreCount}\n" +
            $"Threads:\t{ThreadCount}\n" +
            $"Price:\t\t{Price}$");
    }

    protected override void PerformDiagnostic()
    {
        Console.WriteLine("Diagnosting Processor ...");
    }
}