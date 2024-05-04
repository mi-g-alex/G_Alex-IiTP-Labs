namespace Lab5.Domain.Entities;

public class Work
    : Entity
{
    public string Name { get; set; }

    public int Rating { get; set; }

    public DateTime StartDate { get; set; }

    public DateTime EndDate { get; set; }

    public int BrigadeId { get; set; }

    public string ImageSrc { get; set; }
}