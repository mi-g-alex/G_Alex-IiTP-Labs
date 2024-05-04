using System.Linq.Expressions;
using Lab5.Domain.Abstractions;
using Lab5.Domain.Entities;

namespace Persistence.Repository;

public class FakeWorkRepository : IRepository<Work>
{
    private readonly List<Work> _works;

    public FakeWorkRepository()
    {
        _works = [];
        for (var i = 1; i <= 2; i++)
        {
            for (var j = 0; j < 5; j++)
            {
                _works.Add(new Work
                {
                    Name = $"Work {i * 5 - 5 + j + 1}",
                    Id = (i - 1) * 5 + j + 1,
                    Rating = i * 5 - j,
                    StartDate = new DateTime(2024, i, j + 1),
                    EndDate = new DateTime(2024, i + 1, j + 5),
                    BrigadeId = i,
                    ImageSrc = $"C:/ImagesMaui/{(i - 1) * 5 + j + 1}.jpg"
                });
            }
        }
    }

    public Task<Work> GetByIdAsync(int id, CancellationToken cancellationToken = default,
        params Expression<Func<Work, object>>[]? includesProperties)
    {
        throw new NotImplementedException();
    }

    public Task<IReadOnlyList<Work>> ListAllAsync(CancellationToken cancellationToken = default)
    {
        return Task.Run(() => _works as IReadOnlyList<Work>, cancellationToken);
    }

    public Task<IReadOnlyList<Work>> ListAsync(Expression<Func<Work, bool>>? filter,
        CancellationToken cancellationToken = default,
        params Expression<Func<Work, object>>[]? includesProperties)
    {
        return Task.Run(() => _works as IReadOnlyList<Work>, cancellationToken);
    }

    public async Task AddAsync(Work entity, CancellationToken cancellationToken = default)
    {
        _works.Add(entity);
    }

    public async Task UpdateAsync(Work entity, CancellationToken cancellationToken = default)
    {
        _works[_works.IndexOf(_works.First(s => s.Id == entity.Id))] = entity;
    }

    public async Task DeleteAsync(Work entity, CancellationToken cancellationToken = default)
    {
        _works.Remove(entity);
    }

    public async Task<Work> FirstOrDefaultAsync(Expression<Func<Work, bool>> filter,
        CancellationToken cancellationToken = default)
    {
        return _works.FirstOrDefault(filter.Compile());
    }
}