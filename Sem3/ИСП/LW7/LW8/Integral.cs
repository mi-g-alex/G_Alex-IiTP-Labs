namespace LW8;

public class Integral
{
    private static Semaphore _semaphore = new Semaphore(2, 5); // #4 task
    public event Action<int, long>? OnCalcEvent;
    public event Action<int, long, double>? OnFinishEvent;
    private const double Step = 1e-8;
    private long TimeCompute { get; set; } = 0;

    public double GetIntegralSin()
    {
        _semaphore.WaitOne(); // #4 task
        double x = 1;
        var startTime = DateTime.Now;
        double sum = 0;
        double it = 0;
        const int steps = (int)(1d / Step);
        for (var i = 0; i < steps; i++)
        {
            sum += Step * Math.Sin(it);
            it += Step;
            for (var j = 0; j < 100; j++)
            {
                var a = j * j;
            }

            if (i % 1000 == 0)
                OnCalcEvent?.Invoke(Thread.CurrentThread.ManagedThreadId, (long)(it * 100 / x));
        }
        var endTime = DateTime.Now;
        TimeCompute = (endTime - startTime).Microseconds;
        OnFinishEvent?.Invoke(Thread.CurrentThread.ManagedThreadId, TimeCompute, sum);
        _semaphore.Release();
        return sum;
    }

    public long StopWatch()
    {
        return TimeCompute;
    }
}