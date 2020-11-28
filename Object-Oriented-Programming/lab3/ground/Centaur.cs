namespace lab3.ground
{
    public class Centaur : GroundVeh
    {
        public Centaur()
        {
            name = "кентавр";
            speed = 15;
            restInterval = 8;
            restDuration.first = 2;
            restDuration.second = 2;
            restDuration.allfollow = 2;
        }
    }
}