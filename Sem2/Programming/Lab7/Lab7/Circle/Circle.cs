namespace Lsb7.Circle;

public class Circle
{
    private double _x, _y, _r;

    public Circle(double x, double y, double r)
    {
        if (r <= 0)
        {
            throw new ArgumentException("R должен быть больше 0");
        }

        _x = x;
        _y = y;
        _r = r;
    }

    public double X
    {
        get => _x;
        set => _x = value;
    }

    public double Y
    {
        get => _y;
        set => _y = value;
    }

    private double R
    {
        get => _r;
        set
        {
            if (value <= 0)
            {
                throw new ArgumentException("R должен быть больше 0");
            }

            _r = value;
        }
    }

    public double Length()
    {
        return 2 * Math.PI * _r;
    }

    public double Area()
    {
        return Math.PI * _r * _r;
    }

    public override string ToString()
    {
        return $"X = {_x}\tY = {_y}\tR = {_r}";
    }

    public double this[int i]
    {
        get
        {
            switch (i)
            {
                case 0:
                    return _x;
                case 1:
                    return _y;
                case 2:
                    return _r;
                default:
                    throw new IndexOutOfRangeException("0, 1, 2, не больше не меньше");
            }
        }
        set
        {
            switch (i)
            {
                case 0:
                    _x = value;
                    break;
                case 1:
                    _y = value;
                    break;
                case 2:
                    if (value > 0)
                    {
                        _r = value;
                    }
                    else
                    {
                        throw new ArgumentException("R должен быть больше 0");
                    }

                    break;
                default:
                    throw new IndexOutOfRangeException("0, 1, 2, не больше не меньше");
            }
        }
    }

    public static Circle operator ++(Circle c)
    {
        c.R++;
        return c;
    }

    public static Circle operator --(Circle c)
    {
        c.R++;
        return c;
    }   

    public static Circle operator *(Circle c, double value)
    {
        return new Circle(c.X, c.Y, c.R * value);
    }

    public static Circle operator /(Circle c, double value)
    {
        return new Circle(c.X, c.Y, c.R / value);
    }

    public static Circle operator +(Circle c, double value)
    {
        return new Circle(c.X, c.Y, c.R + value);
    }

    public static Circle operator -(Circle c, double value)
    {
        return new Circle(c.X, c.Y, c.R - value);
    }

    public static bool operator ==(Circle c1, Circle c2)
    {
        return c1.Area() == c2.Area();
    }

    public static bool operator !=(Circle c1, Circle c2)
    {
        return !(c1 == c2);
    }

    public static bool operator <(Circle c1, Circle c2)
    {
        return c1.Area() < c2.Area();
    }

    public static bool operator >(Circle c1, Circle c2)
    {
        return c1.Area() > c2.Area();
    }

    public static bool operator <=(Circle c1, Circle c2)
    {
        return c1.Area() <= c2.Area();
    }

    public static bool operator >=(Circle c1, Circle c2)
    {
        return c1.Area() >= c2.Area();
    }

    public static implicit operator Circle(double r)
    {
        return new Circle(0, 0, r);
    }

    public static explicit operator double(Circle c)
    {
        return c.R;
    }

    public static bool operator true(Circle c)
    {
        return c.X != 0 || c.Y != 0;
    }

    public static bool operator false(Circle c)
    {
        return c.X == 0 && c.Y == 0;
    }
}