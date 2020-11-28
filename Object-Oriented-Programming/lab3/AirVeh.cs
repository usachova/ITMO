using System;

namespace lab3
{
    public abstract class AirVeh : IVehicle
    {
        protected string name;
        protected  uint speed;
        protected IVehicle.VehType type = IVehicle.VehType.air;
        protected  uint DistanceReducer = 0;

        public string GetName()
        {
            return name;
        }

        public uint GetSpeed()
        {
            return speed;
        }

        public IVehicle.VehType GetType()
        {
            return type;
        }

        public uint GetDistReducer(uint d)
        {
            if (name == "ковёр-самолёт")
            {
                if (d < 1000 ) DistanceReducer = 0;
                else if (d >= 1000 && d < 5000) DistanceReducer = 3;
                else if (d >= 5000 && d < 10000) DistanceReducer = 10;
                else DistanceReducer = 5;
            }
            else if (name == "ступа")
            {
                DistanceReducer = 6;
            }
            else if (name == "метла")
            {
                DistanceReducer = d / 1000;
                if (DistanceReducer > 100) DistanceReducer = 100;
            }
            return (100 - DistanceReducer) * d / 100;
        }
    }
}