using StreamService;
using LoremNET;
using Painter;

namespace LW8;

internal abstract class Program
{
    public static async Task Main(string[] args)
    {
        var streamService = new StreamService<Painter.Painter>();

        List<Painter.Painter> painters = new();
        var stream = new MemoryStream();
        Progress<string> progress = new(Console.WriteLine);
        
        for (var i = 0; i < 1000; i++)
        {
            painters.Add(
                new Painter.Painter()
                {
                    Id=Convert.ToInt32(Lorem.Number(1, 1000000)),
                    Name=Lorem.Words(1),
                    PictureCount = Convert.ToInt32(Lorem.Number(7, 80))
                });
        }
        var task1 = streamService.WriteToStreamAsync(stream, painters, progress);
        await Task.Delay(100);
        var task2 = streamService.CopyFromStreamAsync(stream, "stream1.json", progress);
        Task.WaitAll(task1, task2);
        var result = streamService.GetStatisticsAsync("stream1.json", pntr => pntr.PictureCount > 60);
        Console.WriteLine(await result);
    }
}