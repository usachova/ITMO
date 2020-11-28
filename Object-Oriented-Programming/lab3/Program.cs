using System;
using lab3.air;
using lab3.ground;

namespace lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Manager man = new Manager();
            
            man.AddToArr(new BactrianCamel());
            man.AddToArr(new SpeedyCamel());
            man.AddToArr(new Centaur());
            man.AddToArr(new Boots());
            
            man.AddToArr(new MagicCarpet());
            man.AddToArr(new Stupa());
            man.AddToArr(new Metla());
            
            man.createRace(2000, IVehicle.VehType.mixed);
            man.registrToRace(man.GetVeh(0));
            man.registrToRace(man.GetVeh(1));
            man.registrToRace(man.GetVeh(3));
            man.registrToRace(man.GetVeh(5));
            man.registrToRace(man.GetVeh(6));
            man.printVehInRace();
            Console.WriteLine("Победитель: " + man.startRace());
        }
    }
}