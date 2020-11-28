using System;
using System.Collections.Generic;

namespace lab3.races
{
    public class AirRace : Race
    {
        public AirRace(uint d)
        {
            dist = d;
            type = IVehicle.VehType.air;
        }

        public override void addToRace(IVehicle veh)
        {
            if (veh.GetType() is IVehicle.VehType.air)
                arrayOfVeh.Add(veh);
        }
        private class parAVeh
        {
            public IVehicle veh;
            public uint dist;
            public uint newDist;

            public parAVeh(IVehicle veh, uint dist, uint newDist)
            {
                this.veh = veh;
                this.dist = dist;
                this.newDist = newDist;
            }
        }
        public override string startRace()
        {
            List<parAVeh> arr = new List<parAVeh>();
            foreach (IVehicle veh in arrayOfVeh)
            {
                parAVeh par = new parAVeh(veh, 0, 0);
                var aVeh = veh as AirVeh;
                par.newDist = aVeh.GetDistReducer(dist);
                arr.Add(par);
            }
            while (true)
            {
                foreach (parAVeh mash in arr)
                {
                    mash.dist += mash.veh.GetSpeed();
                    if (mash.dist >= mash.newDist) return mash.veh.GetName();
                }
            }
        }
    }
}