using Lab_1_4.Entities;
using SQLite;

namespace Lab_1_4.Services;

public class SqLiteService : IDbService
{
    private SQLiteConnection _db;
    private readonly string _dbPath = Path.Combine(FileSystem.AppDataDirectory, "MyData.db");

    private static readonly Random Random = new();

    private static string RandomString(int length)
    {
        const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        return new string(Enumerable.Repeat(chars, length)
            .Select(s => s[Random.Next(s.Length)]).ToArray());
    }

    public void Init()
    {
        Console.WriteLine(_dbPath);
        if (File.Exists(_dbPath))
        {
            _db = new SQLiteConnection(_dbPath);
            return;
        }

        _db = new SQLiteConnection(_dbPath);
        _db.CreateTables<BrandEntity, CosmeticsItemEntity>();

        var newListName = new List<string>
        {
            "Brand " + Random.Next(0, 255),
            "Brand " + Random.Next(0, 255),
            "Brand " + Random.Next(0, 255),
            "Brand " + Random.Next(0, 255),
        };

        for (var i = 0; i < newListName.Count; i++)
        {
            _db.Insert(new BrandEntity { Name = newListName[i] });
            for (var j = 0; j < Random.Next(4, 11); j++)
            {
                _db.Insert(new CosmeticsItemEntity
                {
                    Name = "Item " + Random.Next(0, 1000), Desc = RandomString(Random.Next(15, 30)), BrandId = i + 1
                });
            }
        }
    }

    public IEnumerable<BrandEntity> GetAllBrands() =>
        _db.Table<BrandEntity>().ToList();

    public IEnumerable<CosmeticsItemEntity> GetCosmeticsById(int id) =>
        from s in _db.Table<CosmeticsItemEntity>().ToList()
        where s.BrandId == id
        select s;
}