namespace Painter;

public class Painter
{
    public int Id { get; set; }
    public string? Name { get; set; }
    public int PictureCount { get; set; }

    public override string ToString()
    {
        return $"Id: {Id.ToString()}, Name: {Name}, {PictureCount}";
    }
}