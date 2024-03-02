using System.ComponentModel.DataAnnotations;
using System.Text.Json.Serialization;

namespace Lab_1_4.Dto;

public class Rate
{
    [Key, JsonPropertyName("Cur_ID")] public int CurId { get; set; }

    [JsonPropertyName("Date")] public DateTime Date { get; set; }

    [JsonPropertyName("Cur_Abbreviation")] public string CurAbbreviation { get; set; }

    [JsonPropertyName("Cur_Scale")] public int CurScale { get; set; }

    [JsonPropertyName("Cur_Name")] public string CurName { get; set; }

    [JsonPropertyName("Cur_OfficialRate")] public decimal? CurOfficialRate { get; set; }
}