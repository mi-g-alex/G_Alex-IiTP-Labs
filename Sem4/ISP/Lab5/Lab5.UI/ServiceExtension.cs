using Lab5.UI.Pages.TaskPages;
using Lab5.UI.ViewModels;

namespace Lab5.UI;

public static class ServiceExtension
{
    public static IServiceCollection RegisterPages(this IServiceCollection services)
    {
        services
            .AddSingleton<ViewBrigades>()
            .AddTransient<ViewWork>()
            .AddTransient<AddOrEditBrigade>()
            .AddTransient<AddOrEditWork>();

        return services;
    }

    public static IServiceCollection RegisterViewModels(this IServiceCollection services)
    {
        services
            .AddSingleton<ViewBrigadesViewModel>()
            .AddTransient<ViewWorkViewModel>()
            .AddTransient<AddOrEditBrigadeViewModel>()
            .AddTransient<AddOrEditWorkViewModel>();
        return services;
    }
}