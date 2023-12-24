using SerializerLib;
using Work.Domain.Models;

var factories = new List<Factory>
{
    new()
    {
        FStore = new Store { Name = "phones", Count = 200, Square = 12345.5 }, FName = "Name1", FCategory = 1
    },
    new()
    {
        FStore = new Store { Name = "tv", Count = 100, Square = 876543.2 }, FName = "fsdfgfsd", FCategory = 3
    },
    new()
    {
        FStore = new Store { Name = "tablet", Count = 150, Square = 564563543.3 }, FName = "dastbts", FCategory = 2
    },
    new()
    {
        FStore = new Store { Name = "smartphone", Count = 300, Square = 2345.6 }, FName = "hhdf hdgf", FCategory = 11
    },
    new()
    {
        FStore = new Store { Name = "noteboot", Count = 250, Square = 745564.3 }, FName = "sdfhssvg", FCategory = 17
    },
    new()
    {
        FStore = new Store { Name = "macs", Count = 278, Square = 6353.3 }, FName = "bsrtsgsfd", FCategory = 51
    }
};

var del = Path.DirectorySeparatorChar;
var path = $"..{del}..{del}..{del}data{del}";

var serializer = new Serializer();
Console.WriteLine(path);
serializer.SerializeByLinq(factories, $"{path}FactoriesLINQ.xml");
serializer.SerializeXml(factories, $"{path}Factories.xml");
serializer.SerializeJson(factories, $"{path}Factories.json");
Console.WriteLine("End");

var factoriesJson = serializer.DeSerializeJson($"{path}Factories.json");
Console.WriteLine("Checking serializing objects JSON...");

using var jsonEnum = factoriesJson.GetEnumerator();
foreach (var f in factories)
{
    jsonEnum.MoveNext();
    if (f.Equals(jsonEnum.Current))
        Console.WriteLine("OK");
    else
        Console.WriteLine("Wrong");
}

var factoriesXml = serializer.DeSerializeXml($"{path}Factories.xml");
Console.WriteLine("Checking serializing objects in XML...");

using var xmlEnum = factoriesXml.GetEnumerator();
foreach (var f in factories)
{
    xmlEnum.MoveNext();
    if (f.Equals(xmlEnum.Current))
        Console.WriteLine("OK");
    else
        Console.WriteLine("Wrong");
}

var deSerializeByLinq = serializer.DeSerializeByLinq($"{path}FactoriesLINQ.xml");
Console.WriteLine("Checking serializing objects with LINQ to XML...");

using var linqEnum = deSerializeByLinq.GetEnumerator();
foreach (var f in factories)
{
    linqEnum.MoveNext();
    if (f.Equals(linqEnum.Current))
        Console.WriteLine("OK");
    else
        Console.WriteLine("Wrong");
}