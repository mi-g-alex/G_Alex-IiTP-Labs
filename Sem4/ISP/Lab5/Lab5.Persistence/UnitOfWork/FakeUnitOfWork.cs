using Lab5.Domain.Abstractions;
using Lab5.Domain.Entities;
using Persistence.Repository;

namespace Persistence.UnitOfWork;

public class FakeUnitOfWork : IUnitOfWork
{
    private readonly FakeBrigadeRepository _fakeBrigadeRepository = new();
    private readonly FakeWorkRepository _fakeWorkRepository = new();

    public IRepository<Work> WorkRepository => _fakeWorkRepository;
    public IRepository<Brigade> BrigadeRepository => _fakeBrigadeRepository;

    public async Task SaveAllAsync()
    {

    }

    public Task DeleteDataBaseAsync()
    {
        throw new NotImplementedException();
    }

    public Task CreateDataBaseAsync()
    {
        throw new NotImplementedException();
    }
}