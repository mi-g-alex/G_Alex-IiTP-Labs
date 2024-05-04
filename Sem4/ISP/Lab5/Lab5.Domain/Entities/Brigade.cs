namespace Lab5.Domain.Entities;

public class Brigade : Entity
{
    public string Name { get; set; }

    public string WorksType { get; set; }

    public string CompanyName { get; set; }

    public List<Work> Works { get; set; }
}