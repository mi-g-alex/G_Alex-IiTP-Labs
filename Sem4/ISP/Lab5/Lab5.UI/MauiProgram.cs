using CommunityToolkit.Maui;
using Lab5.Application;
using Lab5.UI.Pages.TaskPages;
using Lab5.UI.ViewModels;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;
using Persistence;
using Persistence.Data;

namespace Lab5.UI;

public static class MauiProgram
{
    public static MauiApp CreateMauiApp()
    {
        var builder = MauiApp.CreateBuilder();
        builder
            .UseMauiApp<App>()
            .UseMauiCommunityToolkit()
            .ConfigureFonts(fonts =>
            {
                fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
                fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
            });

        var connStr = " Data Source = {0}sqlite.db";
        var dataDirectory = FileSystem.Current.AppDataDirectory + "/";
        connStr = string.Format(connStr, dataDirectory);
        var options = new DbContextOptionsBuilder<AppDbContext>()
            .UseSqlite(connStr)
            .Options;

        builder.Services
            .AddApplication()
            .AddPersistence(options)
            .RegisterPages()
            .RegisterViewModels();

#if DEBUG
        builder.Logging.AddDebug();
#endif

        return builder.Build();
    }
}