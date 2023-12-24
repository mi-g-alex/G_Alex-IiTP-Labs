using System.Collections.Generic;
using System.Text.Json;
using System.Xml.Linq;
using System.Xml.Serialization;
using Work.Domain.Interfaces;
using Work.Domain.Models;

namespace SerializerLib;

public class Serializer : ISerializer
{
    public IEnumerable<Factory> DeSerializeByLinq(string fileName)
    {
        var doc = XDocument.Load(fileName);
        var el = doc.Element("ArrayOfFactory");
        foreach (var i in el!.Elements("factory"))
        {
            var fName = i.Attribute("fName")!.Value;
            var fCategory = i.Attribute("fCategory")!.Value;
            var fStorage = i.Element("fStore");

            var sName = fStorage!.Attribute("sName")!.Value;
            var sCount = fStorage!.Attribute("sCount")!.Value;
            var sSquare = fStorage!.Attribute("sSquare")!.Value;

            yield return new Factory
            {
                FStore = new Store
                {
                    Name = sName,
                    Count = int.Parse(sCount),
                    Square = double.Parse(sSquare)
                },
                FName = fName,
                FCategory = int.Parse(fCategory)
            };
        }
    }

    public IEnumerable<Factory> DeSerializeXml(string fileName)
    {
        var xmlSerializer = new XmlSerializer(typeof(List<Factory>));

        using var fs = new FileStream(fileName, FileMode.OpenOrCreate);
        var factories = xmlSerializer.Deserialize(fs) as IEnumerable<Factory>;
        return factories!;
    }

    public IEnumerable<Factory> DeSerializeJson(string fileName)
    {
        using var fs = new FileStream(fileName, FileMode.OpenOrCreate);
        var factories = JsonSerializer.Deserialize<IEnumerable<Factory>>(fs);
        return factories!;
    }

    public void SerializeByLinq(IEnumerable<Factory> factories, string fileName)
    {
        var doc = new XDocument();
        var el = new XElement("ArrayOfFactory");

        foreach (var f in factories)
        {
            var factory = new XElement("factory");
            factory.Add(new XAttribute("fName", f.FName));
            factory.Add(new XAttribute("fCategory", f.FCategory));
            factory.Add(new XElement("fStore",
                new XAttribute("sName", f.FStore.Name),
                new XAttribute("sCount", f.FStore.Count),
                new XAttribute("sSquare", f.FStore.Square)
            ));
            el.Add(factory);
        }

        doc.Add(el);
        doc.Save(fileName);
    }

    public void SerializeXml(IEnumerable<Factory> factories, string fileName)
    {
        var xmlSerializer = new XmlSerializer(factories.GetType());
        using var fs = new FileStream(fileName, FileMode.OpenOrCreate);
        xmlSerializer.Serialize(fs, factories);
    }

    public void SerializeJson(IEnumerable<Factory> factories, string fileName)
    {
        using var fs = new FileStream(fileName, FileMode.OpenOrCreate);
        JsonSerializer.Serialize(fs, factories);
    }
}