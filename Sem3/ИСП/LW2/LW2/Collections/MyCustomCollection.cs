#nullable enable
using System;
using System.Collections;
using System.Collections.Generic;
using LW2.Interfaces;

namespace LW2.Collections;

public class MyCustomCollection<T> : ICustomCollection<T>
{
    public class Node
    {
        public Node(T item)
        {
            Item = item;
        }

        public T Item { get; set; }
        public Node? Next { get; set; }
    }

    private class MyCustomCollectionEnum : IEnumerator<T>
    {
        private readonly Node? _start;
        private Node? _current;

        public MyCustomCollectionEnum(Node? start)
        {
            _start = start;
            _current = _start;
        }

        public bool MoveNext()
        {
            _current = _current?.Next;
            return _current?.Next != null;
        }

        public void Reset()
        {
            _current = _start;
        }

        T IEnumerator<T>.Current => _current!.Item;

        object IEnumerator.Current
        {
            get
            {
                if (_current != null && _current.Item != null) return _current.Item;
                return default!;
            }
        }

        public void Dispose()
        {
        }
    }

    private Node? _start;
    private Node? _end;
    private Node? _cursor;

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }

    public IEnumerator<T> GetEnumerator()
    {
        return new MyCustomCollectionEnum(_start);
    }

    public T this[int index]
    {
        get
        {
            var t = index;
            var cur = _start;
            while (t-- > 0)
            {
                if (cur != null)
                    cur = cur!.Next;
                else break;
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
        var node = new Node(item);
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
        Node? prev = null;

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

        throw new MyException();
    }

    public T RemoveCurrent()
    {
        var t = _cursor!.Item;
        Remove(_cursor!.Item);
        return t;
    }
}