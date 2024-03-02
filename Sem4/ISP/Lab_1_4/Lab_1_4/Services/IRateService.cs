using Lab_1_4.Dto;

namespace Lab_1_4.Services;

public interface IRateService
{
    Task<IEnumerable<Rate>> GetRates(DateTime date);
}