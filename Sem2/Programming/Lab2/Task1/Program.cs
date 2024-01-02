while (true)
{
    var a = Convert.ToInt64(Console.ReadLine());
    if (a > 99 || a < 10)
    {
        Console.WriteLine("Error");
    }
    else
    {
        var a1 = a / 10;
        var a2 = a % 10;
        Console.WriteLine((a1 + a2) % 2 == 1 ? "Yes, Odd" : "No, Even");
    }
    
    Console.WriteLine("Continue?\n1 - Yes; Other - No");
    var q = Console.ReadLine();
    switch (q)
    {
        case "1": break;
        default: return 0;
    }
}