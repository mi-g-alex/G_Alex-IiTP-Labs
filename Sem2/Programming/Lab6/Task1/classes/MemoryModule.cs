namespace Task1.classes;

sealed class MemoryModule : ComputerComponent
{
    public int Capacity { get; set; }
    public string MemoryType { get; set; }

    public MemoryModule(int capacity, string memoryType, string manufacturer, string model, double price)
        : base(manufacturer, model, price)
    {
        Capacity = capacity;
        MemoryType = memoryType;
    }

    public override void DisplayInfo()
    {
        Console.WriteLine(
            $"Memory:\t\t{Manufacturer} {Model}\n" +
            $"Capacity:\t{Capacity}\n" +
            $"Memory Type:\t{MemoryType}\n" +
            $"Price:\t\t{Price}$");
    }
}