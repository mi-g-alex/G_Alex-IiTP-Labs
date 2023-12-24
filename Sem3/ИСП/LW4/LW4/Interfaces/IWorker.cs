namespace LW4.Interfaces;

public interface IWorker
{
    public string WorkerName { get; set; }
    public int WorkerAge { get; set; }
    public bool IsWorkerMale { get; set; }
}