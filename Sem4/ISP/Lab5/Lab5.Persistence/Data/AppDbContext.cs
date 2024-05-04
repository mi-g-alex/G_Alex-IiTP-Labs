using Lab5.Domain.Entities;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Storage;

namespace Persistence.Data;

public sealed class AppDbContext : DbContext
{
    DbSet<Work> Work { get; }
    DbSet<Brigade> Brigades { get; }

    public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
    {
        Database.EnsureCreated();
    }
}