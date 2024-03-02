using SQLite;

namespace Lab_1_4.Entities;

[Table("Brands")]
public class BrandEntity
{
    [PrimaryKey, AutoIncrement, Indexed]
    public int Id { get; set; }
    public string Name { get; set; }
}