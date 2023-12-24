#nullable enable
using System.Collections.Generic;

namespace LW2.Interfaces;

public interface ICustomCollection<T> : IEnumerable<T>
{
    T this[int index] { get; set; }

    void Reset();

    void Next();

    T? Current();

    int Count { get; }

    void Add(T item);

    void Remove(T item);

    T RemoveCurrent();
}