using Lsb7.Circle;

var a = new Circle(0, 0, 15);
var b = new Circle(3, 4, 5);

Console.WriteLine("A " + a);
Console.WriteLine("B " + b);
Console.WriteLine("Length A " + a.Length());
Console.WriteLine("Length B " + b.Length());
Console.WriteLine("Area A " + a.Area());
Console.WriteLine("Area B " + b.Area());
if (a)
{
    a[0] = 1;
    a[1] = 2;
}

Console.WriteLine("A " + a);
a++;
Console.WriteLine("A " + a);
a--;
Console.WriteLine("A " + a);
a *= 2;
Console.WriteLine("A " + a);
a /= 2;
Console.WriteLine("A " + a);
a += 4;
Console.WriteLine("A " + a);
a -= 4;
Console.WriteLine("A " + a);
Console.WriteLine("B " + b);
Console.WriteLine("A == B " + (a == b));
Console.WriteLine("A != B " + (a != b));
Console.WriteLine("A < B " + (a < b));
Console.WriteLine("A > B " + (a > b));
Console.WriteLine("A <= B " + (a <= b));
Console.WriteLine("A >= B " + (a >= b));
Console.WriteLine("(double)A " + (double)a);
Console.WriteLine("(Circle)2" + (Circle)2);