namespace LW8_Gorgun.Utils;

public class CompIndicator
{
    private long _prevProgressVal = -1;

    public void IndicatorProc(int id, long progress)
    {
        if (progress - _prevProgressVal < 1) return;
        _prevProgressVal = progress;
        var progressBar = $"Thread {id}:[";
        var iters = (int)(progress) / 5;
        for (var i = 0; i < iters; i++)
        {
            progressBar += "=";
        }

        progressBar += ">";
        for (var i = iters; i < 20; i++)
        {
            progressBar += ' ';
        }

        progressBar += $"]{(int)(progress)}%";
        Console.WriteLine(progressBar);
    }

    public void IndicateFinish(int id, long time, double res)
    {
        Console.WriteLine($"Thread {id}: has been finished with result: {res}");
        Console.WriteLine($"Thread {id}: was processing {time} mcr sec");
    }
}