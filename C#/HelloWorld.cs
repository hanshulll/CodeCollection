using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Please input your name: ");
            var name = Console.ReadLine();

            if (string.IsNullOrEmpty(name))
                return;

            Console.WriteLine($"Hello '{name}'!");

            Console.WriteLine("Hit a key to end...");
            Console.ReadKey();
        }
    }
}
