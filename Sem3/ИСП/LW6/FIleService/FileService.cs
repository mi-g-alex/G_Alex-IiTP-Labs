using System.Text.Json;
using LW6.Entities;
using LW6.Interfaces;

namespace FileService;

public class FileService<T> : IFileServices<T> where T:class
{
    public IEnumerable<T> ReadFile(string fileName)
    {
        using var fs = new FileStream(fileName, FileMode.OpenOrCreate);
        return JsonSerializer.Deserialize<IEnumerable<T>>(fs)!;
    }

    public void SaveData(IEnumerable<T> data, string fileName)
    {
        using var fs = new FileStream(fileName, FileMode.OpenOrCreate);
        JsonSerializer.Serialize(fs, data);
    }
}