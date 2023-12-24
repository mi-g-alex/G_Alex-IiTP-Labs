using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using LW4.Services;

var directoryInfo = new DirectoryInfo("../../");
Console.WriteLine(directoryInfo.Name);
try
{
    directoryInfo.CreateSubdirectory("GORGUN_LAB4");
}
catch
{
    Console.WriteLine("Already exists");
}

var extensions = new List<string> { ".txt", ".rtf", ".dat", ".inf" };
for (var i = 0; i < 10; i++)
{
    var filename = "../../GORGUN_LAB4/" + Path.GetRandomFileName() + extensions[i % 4];
    File.Create(filename);
}

Console.WriteLine("All files:");
foreach (var f in directoryInfo.GetFiles("./GORGUN_LAB4/"))
{
    Console.WriteLine($"Имя файла: {f.Name} , расширение файла: {f.Extension}");
}

var workers = new List<Worker>
{
    new ("Bob", 20, true),
    new ("Egor", 30, true),
    new ("David", 35, true),
    new ("Ania", 40, false),
    new ("Sveta", 20, false),
    new ("Alex", 20, true),
};

var fileService = new FileService();

File.Create("../../GORGUN_LAB4/workers.txt").Dispose();
fileService.SaveData(workers, "../../GORGUN_LAB4/workers.txt");

File.Move("../../GORGUN_LAB4/workers.txt", "../../GORGUN_LAB4/old_workers.txt");
File.Delete("../../GORGUN_LAB4/workers.txt");

var newWorkers = new List<Worker>();

foreach(var w in fileService.ReadFile("../../GORGUN_LAB4/old_workers.txt"))
{
    Console.WriteLine($"Worker: {w.WorkerName}, age: {w.WorkerAge}, Male?: {w.IsWorkerMale}");
    newWorkers.Add(w);
}

var orderedByName = newWorkers.OrderBy(w => w, new MyCustomComparer());

Console.WriteLine("After sorting by Name:");
foreach(var w in orderedByName)
{
    Console.WriteLine($"Worker: {w.WorkerName}, age: {w.WorkerAge}, Male?: {w.IsWorkerMale}");
}

var orderedByAge = newWorkers.OrderBy(w1 => w1.WorkerAge);
Console.WriteLine("After sorting by age:");
foreach(var w in orderedByAge)
{
    Console.WriteLine($"Worker: {w.WorkerName}, age: {w.WorkerAge}, Male?: {w.IsWorkerMale}");
}

