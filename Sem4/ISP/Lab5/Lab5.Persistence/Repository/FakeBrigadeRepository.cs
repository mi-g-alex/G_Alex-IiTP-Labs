using System.Linq.Expressions;
using Lab5.Domain.Abstractions;
using Lab5.Domain.Entities;

namespace Persistence.Repository;

public class FakeBrigadeRepository : IRepository<Brigade>
{
    private readonly List<Brigade> _brigade;

    public FakeBrigadeRepository()
    {
        _brigade = new List<Brigade>
        {
            new()
            {
                Id = 1,
                Name = "Brigade 1",
                WorksType = "The Best Brigade",
                CompanyName = "Company One",
                Works = []
            },
            new()
            {
                Id = 2,
                Name = "Brigade 2",
                WorksType = "The fastest",
                CompanyName = "Company Two",
                Works = []
            }
        };
    }

    public Task<Brigade> GetByIdAsync(int id, CancellationToken cancellationToken = default,
        params Expression<Func<Brigade, object>>[]? includesProperties)
    {
        throw new NotImplementedException();
    }

    public Task<IReadOnlyList<Brigade>> ListAllAsync(CancellationToken cancellationToken = default)
    {
        return Task.Run(() => _brigade as IReadOnlyList<Brigade>, cancellationToken);
    }

    public Task<IReadOnlyList<Brigade>> ListAsync(Expression<Func<Brigade, bool>>? filter,
        CancellationToken cancellationToken = default,
        params Expression<Func<Brigade, object>>[]? includesProperties)
    {
        throw new NotImplementedException();
    }

    public async Task AddAsync(Brigade entity, CancellationToken cancellationToken = default)
    {
        _brigade.Add(entity);
    }

    public async Task UpdateAsync(Brigade entity, CancellationToken cancellationToken = default)
    {
        _brigade[_brigade.IndexOf(_brigade.First(s => s.Id == entity.Id))] = entity;
    }

    public async Task DeleteAsync(Brigade entity, CancellationToken cancellationToken = default)
    {
        _brigade.Remove(entity);
    }

    public Task<Brigade> FirstOrDefaultAsync(Expression<Func<Brigade, bool>> filter,
        CancellationToken cancellationToken = default)
    {
        throw new NotImplementedException();
    }
}