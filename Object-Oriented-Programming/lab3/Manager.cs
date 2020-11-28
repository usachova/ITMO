using System;
using System.Collections.Generic;
using lab3.races;

namespace lab3
{
    public class Manager
    {
        private List<IVehicle> arrayOfVeh = new List<IVehicle>();
        private Race race;
        
        public void AddToArr(IVehicle veh)
        {
            arrayOfVeh.Add(veh);
        }

        public IVehicle GetVeh(int index)
        {
            return arrayOfVeh[index];
        }

        public void createRace(uint dist, IVehicle.VehType type)
        {
            if (type is IVehicle.VehType.ground) race = new GroundRace(dist);
            else if (type is IVehicle.VehType.air) race = new AirRace(dist);
            else race = new MixedRace(dist);
            race.chType(type);
        }

        public void deleteRace()
        {
            race.delRace();
        }

        public void registrToRace(IVehicle veh)
        {
            race.addToRace(veh);
        }

        public void printVehInRace()
        {
            Console.WriteLine("Транспорт участвующий в гонке:");
            race.printArr();
        }

        public string startRace()
        {
            return race.startRace();
        }
    }
}