using System.Collections.Generic;
using System.Xml.Linq;
using Work.Domain.Models;

namespace SerializerLib
{
    public class Serializer : ISerializer
    {
        public IEnumerable<Factory> DeSerializeByLinq(string fileName)
        {
            var doc = XDocument.
        }

        public IEnumerable<Factory> DeSerializeXml(string fileName)
        {
            throw new System.NotImplementedException();
        }

        public IEnumerable<Factory> DeSerializeJson(string fileName)
        {
            throw new System.NotImplementedException();
        }

        public void SerializeByLinq(IEnumerable<Factory> xxx, string fileName)
        {
            throw new System.NotImplementedException();
        }

        public void SerializeXml(IEnumerable<Factory> xxx, string fileName)
        {
            throw new System.NotImplementedException();
        }

        public void SerializeJson(IEnumerable<Factory> xxx, string fileName)
        {
            throw new System.NotImplementedException();
        }
    }
}