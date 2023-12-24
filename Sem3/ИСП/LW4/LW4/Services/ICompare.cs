using System;
using System.Collections.Generic;

namespace LW4.Services;

public class MyCustomComparer : IComparer<Worker>
{
    public int Compare(Worker x, Worker y) =>
         string.Compare(x?.WorkerName, y?.WorkerName, StringComparison.Ordinal);
}