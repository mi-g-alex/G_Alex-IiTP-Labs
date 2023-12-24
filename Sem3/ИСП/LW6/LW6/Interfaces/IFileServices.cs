namespace LW6.Interfaces;

public interface IFileServices<T> where T:class
{
    IEnumerable<T> ReadFile(string fileName);
    void SaveData(IEnumerable<T> data, string fileName);
}