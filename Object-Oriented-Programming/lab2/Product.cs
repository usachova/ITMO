namespace lab2
{
    public class Product
    {
        private int code_;
        private string name_;

        public Product(int code, string name)
        {
            code_ = code;
            name_ = name;
        }

        public int GetCode()
        {
            return code_;
        }

        public string GetName()
        {
            return name_;
        }
        
        public class Prod
        {
            public int prodId;
            public int price;
            public int cnt;

            public Prod(int prId, int pri, int cn)
            {
                prodId = prId;
                price = pri;
                cnt = cn;
            }
        }
    }
}