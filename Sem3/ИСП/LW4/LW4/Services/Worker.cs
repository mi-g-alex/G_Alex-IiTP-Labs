using LW4.Interfaces;

namespace LW4.Services;

public class Worker : IWorker
{
    public string WorkerName { get; set; }
    public int WorkerAge { get; set; }
    public bool IsWorkerMale { get; set; }

    public Worker(string workerName, int workerAge, bool isWorkerMale)
    {
        WorkerName = workerName;
        WorkerAge = workerAge;
        IsWorkerMale = isWorkerMale;
    }
}