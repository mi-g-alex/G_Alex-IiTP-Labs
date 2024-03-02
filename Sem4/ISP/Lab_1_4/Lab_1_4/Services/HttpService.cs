using System.Diagnostics;
using System.Net.Http.Json;
using System.Text.Json;
using Lab_1_4.Dto;

namespace Lab_1_4.Services;

public class HttpService : IRateService
{
    private readonly HttpClient _client;
    private readonly JsonSerializerOptions _serializerOptions = new();

    private IEnumerable<Rate> Items { get; set; }

    public HttpService(IHttpClientFactory httpClientFactory)
    {
        _client = httpClientFactory.CreateClient("NB RB");
    }

     public async Task<IEnumerable<Rate>> GetRates(DateTime date)
     {
         try

         {
             var response = await _client.GetFromJsonAsync<IEnumerable<Rate>>($"?ondate={date:yyyy-MM-dd}&periodicity=0");
             return response;
             // if (response.IsSuccessStatusCode)
             // {
             //     var content = await response.Content.ReadFromJsonAsync<IEnumerable<Rate>>();
             //     //var items = JsonSerializer.Deserialize<IEnumerable<Rate>>(content);
             //     return content;
             // }
         }
         catch (Exception ex)
         {
             Console.WriteLine("TEST_ERR" + ex.Message);
         }

         return Items;
     }

}