using Lab_1_4.Services;

namespace Lab_1_4.Pages.CosmeticsBrand;

public class CosmeticsBrandViewModel
{
    public readonly IDbService DbService;

    public CosmeticsBrandViewModel(IDbService dbService)
    {
        DbService = dbService;
    }
}