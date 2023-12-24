using System.Collections.Generic;
using Work.Domain.Models;

namespace Work.Domain.Interfaces;

public interface ISerializer
{
    IEnumerable<Factory> DeSerializeByLinq(string fileName);
    IEnumerable<Factory> DeSerializeXml(string fileName);
    IEnumerable<Factory> DeSerializeJson(string fileName);
    void SerializeByLinq(IEnumerable<Factory> xxx, string fileName);
    void SerializeXml(IEnumerable<Factory> xxx, string fileName);
    void SerializeJson(IEnumerable<Factory> xxx, string fileName);
}