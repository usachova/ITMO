using System;
using System.IO;

namespace lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new IniFile(new StreamReader((@"/Users/usachova/study/ITMO/3 semester/object-oriented programming/lab1/lab1/lab1/test.ini")));
            Console.WriteLine("Tests:");
            Console.WriteLine($"Get value from LEGACY_XML->ListenTcpPort: {file["LEGACY_XML"].Get<int>("ListenTcpPort")}");
            Console.WriteLine($"Get value from ADC_DEV->BufferLenSeconds: {file["ADC_DEV"]["BufferLenSeconds"]}");
            Console.WriteLine($"Get value from COMMON->DiskCachePath: {file["COMMON"]["DiskCachePath"]}");
        }
    }
}