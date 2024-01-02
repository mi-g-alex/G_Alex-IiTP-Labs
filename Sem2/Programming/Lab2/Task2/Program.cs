while (true)
{
    var x = Convert.ToDouble(Console.ReadLine());
    var y = Convert.ToDouble(Console.ReadLine());
    if (y < 0)
    {
        var s = x * x + y * y;
        if (((x + y == 0 || (x - y == 0)) && s <= 625) ||
            ((x + y < 0) && (x - y > 0) && s == 625))
            Console.WriteLine("On Border");
        else if ((x + y < 0) && (x - y > 0) && s < 625) Console.WriteLine("Yes");
        else Console.WriteLine("No");
    }
    else
    {
        if (x == 0 && y == 0)
        {
            Console.WriteLine("On Border");
        }
        else
        {
            Console.WriteLine("No");
        }
    }

    Console.WriteLine("Continue?\n1 - Yes; Other - No");
    var q = Console.ReadLine();
    switch (q)
    {
        case "1": break;
        default: return 0;
    }
}