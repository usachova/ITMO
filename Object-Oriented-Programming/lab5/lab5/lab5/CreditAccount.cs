using System;

namespace lab5
{
    public class CreditAccount : Account
    {
        public class CreditParameters : Parameters
        {
            public readonly int _limit;
            public readonly int _commission;

            public CreditParameters(int limit, int commission)
            {
                _limit = limit;
                _commission = commission;
            }
        }
        
        private CreditParameters _parameters;
        public CreditAccount(CreditParameters parameters, TimeSpan date, int sum)
        {
            _type = AccountType.credit;
            _date = date;
            _parameters = parameters;
            _sum = sum;
        }

        public override void Withdrawal(int value)
        {
            int commission = (_sum - value < 0) ? _parameters._commission : 0;
            if (_sum + _parameters._limit >= value + commission)
            {
                _sum -= value + commission;
                Console.WriteLine("Вы успешно сняли " + value + " рублей. Комиссия составила " + commission + " рублей.");
            }
            else
            {
                Console.WriteLine("Недостаточно средств.");
            }
        }

        public override void Transfer(int value, Client client)
        {
            int commission = (_sum - value < 0) ? _parameters._commission : 0;
            int rand = (new Random()).Next(0, 1);
            if (client.TryToTransfer(value) && rand == 1 && _sum + _parameters._limit >= value + commission)
            {
                _sum -= value + commission;
                Console.WriteLine("Вы успешно перевели деньги на счёт " + client.GetName() + " " + client.GetSurname() + ".");
            }
            else
            {
                Console.WriteLine("Перевод отклонён");
            }
        }

        public override void MoveInTime()
        {
            _date += TimeSpan.FromDays(1);
            _dateDiff += TimeSpan.FromDays(1);
        }
    }
}