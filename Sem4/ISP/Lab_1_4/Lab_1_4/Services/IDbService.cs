using Lab_1_4.Entities;

namespace Lab_1_4.Services;

public interface IDbService
{
    IEnumerable<BrandEntity> GetAllBrands();
    IEnumerable<CosmeticsItemEntity> GetCosmeticsById(int id);
    void Init();
}