namespace lab3.ground
{
    public class SpeedyCamel : GroundVeh
    {
        public SpeedyCamel()
        {
            name = "верблюд-быстроход";
            speed = 40;
            restInterval = 10;
            restDuration.first = 5;
            restDuration.second = 7;
            restDuration.allfollow = 8;
        }
    }
}