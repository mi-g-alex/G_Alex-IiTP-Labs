using System.Reflection;
using LW6.Entities;
using LW6.Interfaces;

var employees = new List<Employee>
{
    new() { Name = "Egor", Age = 18, IsMale = true },
    new() { Name = "Danik", Age = 18, IsMale = true },
    new() { Name = "Nikita", Age = 18, IsMale = true },
    new() { Name = "Marat", Age = 19, IsMale = true },
    new() { Name = "Uliana", Age = 18, IsMale = false },
    new() { Name = "Vika", Age = 22, IsMale = false }
};
var s = Path.DirectorySeparatorChar;
var asm = Assembly.LoadFrom($"..{s}FIleService{s}bin{s}Debug{s}net7.0{s}FIleService.dll");
var fileServiceType = asm.GetType("FileService.FileService`1")?.MakeGenericType(typeof(Employee));
var fileService = Activator.CreateInstance(fileServiceType!) as IFileServices<Employee>;


var path = $"..{s}data{s}";
fileService?.SaveData(employees, $"{path}employees.json");
Console.WriteLine("Employees added to json");

var readEmployees = fileService?.ReadFile($"{path}employees.json");
Console.WriteLine("Employees from data/employees.json...");
foreach(var e in readEmployees!)
{
    Console.WriteLine($"Employee: Name: {e.Name}, Age: {e.Age}, IsMale: {e.IsMale}");
}