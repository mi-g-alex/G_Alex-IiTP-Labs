using System;

namespace Work.Domain.Models;

public class Store : IEquatable<Store>
{
    public string Name { get; set; } = "";
    public int Count { get; set; } = 0;
    public double Square { get; set; } = 0.0;

    public bool Equals(Store? store) =>
        Name == store?.Name && Count == store?.Count && Equals(Square, store.Square);
}