using System;
using System.Collections.Generic;

namespace lab3
{
    public abstract class Race
    {
        protected List<IVehicle> arrayOfVeh = new List<IVehicle>();
        protected uint dist;
        protected IVehicle.VehType type;

        public void chType(IVehicle.VehType t)
        {
            type = t;
        }
        
        public abstract void addToRace(IVehicle veh);

        public void delRace()
        {
            arrayOfVeh.Clear();
        }

        public void printArr()
        {
            foreach (IVehicle veh in arrayOfVeh)
            {
                Console.WriteLine(veh.GetName());
            }
        }
        public abstract string startRace();
    }
}