using Task1.classes;

var provider = new Provider("Provider");

while (true)
{
    Console.WriteLine("1. Add User");
    Console.WriteLine("2. Add Tariff");
    Console.WriteLine("3. Get Max");
    Console.WriteLine("4. Set count for user");
    Console.WriteLine("5. Get All sum for tariff");
    var a = Console.ReadLine();
    switch (a)
    {
        case "1":
            Console.WriteLine(provider.GetAllTariffs());
            Console.WriteLine("User name");
            var tmpName = Console.ReadLine();
            Console.WriteLine("Tariff name");
            var tmpTariffName = Console.ReadLine();
            Console.WriteLine(provider.AddUser(tmpName, tmpTariffName));
            break;
        case "2":
            Console.WriteLine("Tariff name");
            var tmpAddTariffName = Console.ReadLine();
            Console.WriteLine("Tariff Coast");
            var tmpAddCoast = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine(provider.AddTariff(tmpAddTariffName, tmpAddCoast));
            break;
        case "3":
            Console.WriteLine(provider.SearchMax());
            break;
        case "4":
            Console.WriteLine(provider.GetAllUsers());
            Console.WriteLine("User name");
            var tmpSetName = Console.ReadLine();
            Console.WriteLine("Count");
            var count = Convert.ToDouble(Console.ReadLine());
            provider.SetCount(tmpSetName, count);
            Console.WriteLine(provider.GetSum(tmpSetName));
            break;
        case "5":
            Console.WriteLine(provider.GetAllTariffs());
            Console.WriteLine("Tariff name");
            var tmpGetAllTariffName = Console.ReadLine();
            Console.WriteLine(provider.SumForTariff(tmpGetAllTariffName));
            break;
    }
}