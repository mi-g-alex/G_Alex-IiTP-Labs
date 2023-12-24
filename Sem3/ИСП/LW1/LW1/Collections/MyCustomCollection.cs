#nullable enable
using System;
using LW1.Interfaces;

namespace LW1.Collections;

internal class Node<T>
{
    public Node(T item)
    {
        Item = item;
    }

    public T Item { get; set; }
    public Node<T>? Next { get; set; }
}

public class MyCustomCollection<T> : ICustomCollection<T>
{
    private Node<T>? _start;
    private Node<T>? _end;
    private Node<T>? _cursor;

    public T this[int index]
    {
        get
        {
            var t = index;
            var cur = _start;
            while (t-- > 0)
            {
                cur = cur!.Next;
            }

            if (cur != null) return cur.Item;
            throw new IndexOutOfRangeException();
        }
        set
        {
            if (index >= Count) throw new IndexOutOfRangeException();
            var t = index;
            var cur = _start;
            while (t-- > 0)
            {
                cur = cur!.Next;
            }

            if (cur != null) cur.Item = value;
            else throw new IndexOutOfRangeException();
        }
    }

    public void Reset()
    {
        _cursor = _start;
    }

    public void Next()
    {
        _cursor = _cursor?.Next;
    }

    public T? Current()
    {
        if (_cursor != null) return _cursor.Item;
        return default;
    }

    public int Count { get; private set; }

    public void Add(T item)
    {
        var node = new Node<T>(item);
        if (_start == null)
        {
            _start = node;
            _cursor = _start;
        }
        else
        {
            _end!.Next = node;
        }

        _end = node;
        Count++;
    }

    public void Remove(T item)
    {
        var current = _start;
        Node<T>? prev = null;

        while (current != null && current.Item != null)
        {
            if (current.Item.Equals(item))
            {
                if (prev != null)
                {
                    prev.Next = current.Next;

                    if (current.Next == null)
                    {
                        _end = prev;
                    }
                }
                else
                {
                    _start = _start?.Next;

                    if (_start == null) _end = null;
                }

                Count--;
                return;
            }

            prev = current;
            current = current.Next;
        }
    }

    public T RemoveCurrent()
    {
        var t = _cursor!.Item;
        Remove(_cursor!.Item);
        return t;
    }
}