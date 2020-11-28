namespace lab3
{
    public interface IVehicle
    {
        enum VehType
        {
            ground,
            air,
            mixed
        }
        public string GetName();
        public uint GetSpeed();
        public VehType GetType();
    } 
}