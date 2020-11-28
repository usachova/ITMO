namespace lab3.ground
{
    public class Boots : GroundVeh
    {
        public Boots()
        {
            name = "ботинки-вездеходы";
            speed = 6;
            restInterval = 60;
            restDuration.first = 10;
            restDuration.second = 5;
            restDuration.allfollow = 5;
        }
    }
}