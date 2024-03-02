using System.Collections.ObjectModel;
using Lab_1_4.Entities;
using Lab_1_4.Services;

namespace Lab_1_4.Pages.CosmeticsBrand;

public partial class CosmeticsBrandPage : ContentPage
{
    private readonly IDbService _sqLiteService;
    private List<CosmeticsItemEntity> _items = new();

    public CosmeticsBrandPage(CosmeticsBrandViewModel viewModel)
    {
        InitializeComponent();
        _sqLiteService = viewModel.DbService;
        _sqLiteService.Init();
    }

    private void BrandPicker_OnSelectedIndexChanged(object sender, EventArgs e)
    {
        _items = _sqLiteService.GetCosmeticsById(((BrandEntity)BrandPicker.SelectedItem).Id).ToList();
        CollectionViewItem.ItemsSource = _items;
    }

    private void BrandPicker_OnLoaded(object sender, EventArgs e)
    {
        var brands = new ObservableCollection<BrandEntity>(_sqLiteService.GetAllBrands());
        BrandPicker.ItemsSource = brands;
    }
}