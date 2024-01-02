namespace Task2.Services;

public static class DoSomething
{
    public static void GetResult(double z, double b)
    {
        double x;
        if (z <= 0)
        {
            x = Math.Pow(z, b) + Math.Abs(b / 2);
            Console.WriteLine("Path: 1");
        }
        else
        {
            x = Math.Sqrt(z);
            Console.WriteLine("Path: 2");
        }
        var y = 1 / Math.Cos(x) + Math.Log(Math.Tan(x / 2));
        Console.WriteLine("Res: " + y);
    }
}   