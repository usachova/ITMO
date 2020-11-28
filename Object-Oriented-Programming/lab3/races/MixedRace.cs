using System.Collections.Generic;

namespace lab3.races
{
    public class MixedRace : Race
    {
        public MixedRace(uint d)
        {
            dist = d;
        }

        public override void addToRace(IVehicle veh)
        {
            arrayOfVeh.Add(veh);
        }
        private class parVeh
        {
            public IVehicle veh;
            public uint dist;
            public bool isGo;
            public uint cntRest;
            public uint timeToRest;
            public uint timeToGo;
            public uint newDist;
        }
        public override string startRace()
        {
            List<parVeh> arr = new List<parVeh>();
            foreach (IVehicle veh in arrayOfVeh)
            {
                parVeh par = new parVeh();
                par.veh = veh;
                par.dist = 0;
                if (veh.GetType() == IVehicle.VehType.ground)
                {
                    par.isGo = true;
                    par.cntRest = 0;
                    par.timeToGo = 0;
                    var gVeh = veh as GroundVeh;
                    par.timeToRest = gVeh.GetRestInterval();
                }
                else
                {
                    var aVeh = veh as AirVeh;
                    par.newDist = aVeh.GetDistReducer(dist);
                }
                arr.Add(par);
            }
            while (true) 
            {
                foreach (parVeh mash in arr)
                {
                    if (mash.veh.GetType() == IVehicle.VehType.ground)
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
                    else
                    {
                        mash.dist += mash.veh.GetSpeed();
                        if (mash.dist >= mash.newDist) return mash.veh.GetName();
                    }
                }
            }
        }
    }
}