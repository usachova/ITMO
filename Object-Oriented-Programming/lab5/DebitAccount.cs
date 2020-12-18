using System;

namespace lab5
{
    public class DebitAccount : Account
    {
        public class DebitParameters : Parameters
        {
            public readonly int _percent;

            public DebitParameters(int percent)
            {
                _percent = percent;
            }
        }

        private int _percent;
        private int _percentSum = 0;
        public DebitAccount(DebitParameters parameters, DateTime date, int sum)
        {
            _type = AccountType.debit;
            _date = date;
            _percent = parameters._percent;
            _sum = sum;
        }

        public override void Withdrawal(int value)
        {
            if (_sum >= value)
            {
                _sum -= value;
                Console.WriteLine("Вы успешно сняли " + value + " рублей.");
            }
            else
            {
                Console.WriteLine("Недостаточно средств.");
            }
        }

        public override void Transfer(int value, Client client)
        {
            int rand = (new Random()).Next(0, 1);
            if (client.TryToTransfer(value) && rand == 1 && _sum > value)
            {
                _sum -= value;
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
            if (_date.Day == DateTime.DaysInMonth(_date.Year, _date.Month))
            {
                _sum += _percentSum;
                _percentSum = 0;
                
            }
            _percentSum += (_sum * _percent) / 100 / 365;
        }
    }
}