using System;

namespace Work.Domain.Models
{
    public class Factory : IEquatable<Factory>
    {
        public Store FStore { get; set; }
        public string FName { get; set; }
        public int FCategory { get; set; }

        public bool Equals(Factory? factory)
            => FStore.Equals(factory?.FStore) && FName == factory.FName && FCategory == factory.FCategory;
    }
}