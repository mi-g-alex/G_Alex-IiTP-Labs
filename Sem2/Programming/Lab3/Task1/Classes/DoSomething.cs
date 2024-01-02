namespace Lab3.classes;

public static class DoSomething
{
    public
        static int Replace(int x)
    {
        return x is < 10 or > 99 ? x : x % 10 * 10 + x / 10;
    }
}