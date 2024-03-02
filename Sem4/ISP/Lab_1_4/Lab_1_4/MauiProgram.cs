using CommunityToolkit.Maui;
using Lab_1_4.Pages.CosmeticsBrand;
using Lab_1_4.Pages.Currencies;
using Lab_1_4.Services;
using Microsoft.Extensions.Logging;

namespace Lab_1_4;

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

        builder.Services.AddTransient<IDbService, SqLiteService>();
        builder.Services.AddSingleton<CosmeticsBrandViewModel>();
        builder.Services.AddSingleton<CosmeticsBrandPage>();
        builder.Services.AddTransient<IRateService, HttpService>();
        builder.Services.AddHttpClient("NB RB", opt =>
            opt.BaseAddress = new Uri("https://www.nbrb.by/api/exrates/rates"));
        builder.Services.AddSingleton<CurrenciesViewModel>();
        builder.Services.AddSingleton<CurrenciesPage>();


#if DEBUG
        builder.Logging.AddDebug();
#endif

        return builder.Build();
    }
}