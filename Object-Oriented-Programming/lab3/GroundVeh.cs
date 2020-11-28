namespace lab3
{
    public abstract class GroundVeh : IVehicle
    {
        protected string name;
        protected uint speed;
        protected IVehicle.VehType type = IVehicle.VehType.ground;
        protected uint restInterval;

        protected struct typeRestDuration
        {
            public uint first;
            public uint second;
            public uint allfollow;
        }

        protected typeRestDuration restDuration;

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

        public uint GetRestDur(uint cntRestDuration)
        {
            if (cntRestDuration == 1) return restDuration.first;
            if (cntRestDuration == 2) return restDuration.second;
            return restDuration.allfollow;
        }

        public uint GetRestInterval()
        {
            return restInterval;
        }

    }
}