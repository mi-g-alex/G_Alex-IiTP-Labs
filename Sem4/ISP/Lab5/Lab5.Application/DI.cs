using Microsoft.Extensions.DependencyInjection;

namespace Lab5.Application;

public static class DI
{
    public static IServiceCollection AddApplication(this
        IServiceCollection services)
    {
        services.AddMediatR(conf =>
            conf.RegisterServicesFromAssembly(typeof(DI).Assembly));
        return services;
    }
}