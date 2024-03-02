using SQLite;

namespace Lab_1_4.Entities;

[Table("Cosmetics")]
public class CosmeticsItemEntity
{
    [PrimaryKey, AutoIncrement, Indexed]
    public int Id { get; set; }
    public string Name { get; set; }
    public string Desc { get; set; }
    [Indexed]
    public int BrandId { get; set; }
}