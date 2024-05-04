using Lab5.Domain.Abstractions;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using Persistence.Data;
using Persistence.UnitOfWork;

namespace Persistence;

public static class Di
{
    public static IServiceCollection AddPersistence(this IServiceCollection services)
    {
        services.AddSingleton<IUnitOfWork, EfUnitOfWork>();
        return services;
    }
    public static IServiceCollection AddPersistence(this IServiceCollection services,
        DbContextOptions options)
    {
        services.AddPersistence()
            .AddSingleton(
                new AppDbContext((DbContextOptions<AppDbContext>) options));
        return services;
    }
}