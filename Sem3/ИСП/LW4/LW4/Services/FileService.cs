using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using LW4.Interfaces;

namespace LW4.Services;

public class FileService : IFileService<Worker>
{
    public void SaveData(IEnumerable<Worker> data, string fileName)
    {
        using var f = File.OpenWrite(fileName);
        using var binWriter = new BinaryWriter(f);
        foreach (var i in data)
        {
            try
            {
                binWriter.Write(i.WorkerName);
                binWriter.Write(i.WorkerAge);
                binWriter.Write(i.IsWorkerMale);
            }
            catch
            {
                Console.WriteLine("Couldn't write to file");
            }
        }
        binWriter.Close();
        f.Close();
    }

    public IEnumerable<Worker> ReadFile(string fileName)
    {
        using var f = File.OpenRead(fileName);
        using var binReader = new BinaryReader(f);
        var name = "";
        var age = 0;
        var isMale = false;
        while (binReader.PeekChar() != -1)
        {
            try
            {
                name = binReader.ReadString();
                age = binReader.ReadInt32();
                isMale = binReader.ReadBoolean();
            }
            catch
            {
                Console.WriteLine("Couldn't read file");
            }
            yield return new Worker(name, age, isMale);
        }
        binReader.Close();
        f.Close();
    }
}