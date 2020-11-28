using System.Collections.Generic;

namespace lab3.races
{
    public class GroundRace : Race
    {
        public GroundRace(uint d)
        {
            dist = d;
            type = IVehicle.VehType.ground;
        }

        public override void addToRace(IVehicle veh)
        {
            if (veh.GetType() is IVehicle.VehType.ground)
                arrayOfVeh.Add(veh);
        }
        private class parGVeh
        {
            public IVehicle veh;
            public uint dist;
            public bool isGo;
            public uint cntRest;
            public uint timeToRest;
            public uint timeToGo;

            public parGVeh(IVehicle veh, uint dist, bool isGo, uint cntRest, uint timeToRest, uint timeToGo)
            {
                this.veh = veh;
                this.dist = dist;
                this.isGo = isGo;
                this.cntRest = cntRest;
                this.timeToRest = timeToRest;
                this.timeToGo = timeToGo;
            }
        }
        public override string startRace()
        {
            List<parGVeh> arr = new List<parGVeh>();
            foreach (IVehicle veh in arrayOfVeh)
            {
                parGVeh par = new parGVeh(veh, 0, true, 0, 0, 0);
                var gVeh = veh as GroundVeh;
                par.timeToRest = gVeh.GetRestInterval();
                arr.Add(par);
            }

            while (true)
            {
                foreach (parGVeh mash in arr)
                {
                    if (mash.isGo)
                    {
                        mash.dist += mash.veh.GetSpeed();
                        if (mash.dist >= dist) return mash.veh.GetName();
                        mash.timeToRest--;
                        if (mash.timeToRest == 0)
                        {
                            mash.isGo = false;
                            mash.cntRest++;
                            var gVeh = mash.veh as GroundVeh;
                            mash.timeToGo = gVeh.GetRestDur(mash.cntRest);
                        }
                    }
                    else
                    {
                        mash.timeToGo--;
                        if (mash.timeToGo == 0)
                        {
                            mash.isGo = true;
                            var gVeh = mash.veh as GroundVeh;
                            mash.timeToRest = gVeh.GetRestInterval(); 
                        }
                    }
                }
            }
        }
    }
}