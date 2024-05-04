using Lab5.Domain.Entities;

namespace Lab5.Domain.Abstractions;

public interface IUnitOfWork
{
    IRepository<Work> WorkRepository { get; }
    IRepository<Brigade> BrigadeRepository { get; }

    public Task SaveAllAsync();
    public Task DeleteDataBaseAsync();
    public Task CreateDataBaseAsync();
}