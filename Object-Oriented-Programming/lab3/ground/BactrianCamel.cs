namespace lab3.ground
{
    public class BactrianCamel : GroundVeh
    {
        public BactrianCamel()
        {
            name = "двугорбый верблюд";
            speed = 10;
            restInterval = 30;
            restDuration.first = 5;
            restDuration.second = 8;
            restDuration.allfollow = 8;
        }
    }
}