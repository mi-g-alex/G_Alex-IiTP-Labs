using System.Text.Json;

namespace StreamService;

public class StreamService<T>
{
    private readonly JsonSerializerOptions _jsonOptions = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase
    };
    
    private readonly AutoResetEvent _waitHandler = new (true);  
    
    public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data, IProgress<string> progress)
    {
        _waitHandler.WaitOne();
        var threadId = Environment.CurrentManagedThreadId;
        progress.Report($"Thread '{threadId}': Starting write to the stream");
        await JsonSerializer.SerializeAsync(stream, data, _jsonOptions);
        for (var i = 0; i < 100; i++)
        {
            await Task.Delay(50);
            progress.Report($"Thread '{threadId}': {i / 99.0f * 100.0f}%");
        }

        progress.Report($"Thread '{threadId}': Writing finished");
        _waitHandler.Set();
    }

    public async Task CopyFromStreamAsync(Stream stream, string fileName, IProgress<string> progress)
    {
        _waitHandler.WaitOne();
        var threadId = Environment.CurrentManagedThreadId;
        progress.Report($"Thread '{threadId}': Starting copy to the filestream");
        
        await using var destinationStream = new FileStream(fileName, FileMode.Create);
        stream.Seek(0, SeekOrigin.Begin);
        await stream.CopyToAsync(destinationStream);
        
        progress.Report($"Thread '{threadId}': Copy finished");
        _waitHandler.Set();
    }

    public async Task<int> GetStatisticsAsync(string fileName, Func<T, bool> filter)
    {
        await using var sourceStream = new FileStream(fileName, FileMode.Open);
        var data = await JsonSerializer.DeserializeAsync<List<T>>(sourceStream, _jsonOptions);
        return data!.Where(filter).Count();
    }
}