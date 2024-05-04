using Lab5.Domain.Abstractions;
using Lab5.Domain.Entities;
using Persistence.Data;
using Persistence.Repository;

namespace Persistence.UnitOfWork;

public class EfUnitOfWork(AppDbContext context) : IUnitOfWork
{
    private readonly Lazy<IRepository<Work>> _workRepository = new(() => new EfRepository<Work>(context));
    private readonly Lazy<IRepository<Brigade>> _brigadeRepository = new(() => new EfRepository<Brigade>(context));

    public IRepository<Work> WorkRepository => _workRepository.Value;
    public IRepository<Brigade> BrigadeRepository => _brigadeRepository.Value;

    public async Task SaveAllAsync() => await context.SaveChangesAsync();

    public async Task DeleteDataBaseAsync() => await context.Database.EnsureDeletedAsync();

    public async Task CreateDataBaseAsync() => await context.Database.EnsureCreatedAsync();
}