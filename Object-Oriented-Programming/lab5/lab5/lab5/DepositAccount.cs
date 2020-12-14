using System;

namespace lab5
{
    public class DepositAccount : Account
    {
        public class DepositParameters : Parameters
        {
            public readonly TimeSpan _date;
            public readonly int _firstSum;
            public readonly int _secondSum;
            public readonly int _percentBefore;
            public readonly int _percentBetween;
            public readonly int _percentAfter;

            public DepositParameters(TimeSpan date, int firstSum, int secondSum, int percentBefore, int percentBetween, int percentAfter)
            {
                _date = date;
                _firstSum = firstSum;
                _secondSum = secondSum;
                _percentBefore = percentBefore;
                _percentBetween = percentBetween;
                _percentAfter = percentAfter;
            }
        }

        private int _percent;
        private int _percentSum = 0;
        private TimeSpan _finalDate;
        public DepositAccount(DepositParameters parameters, TimeSpan date, int sum)
        {
            _type = AccountType.deposit;
            _date = date;
            _finalDate = parameters._date;
            if (_sum < parameters._firstSum)
            {
                _percent = parameters._percentBefore;
            }
            else if (_sum < parameters._secondSum)
            {
                _percent = parameters._percentBetween;
            }
            else
            {
                _percent = parameters._percentAfter;
            }
            _sum = sum;
        }

        public override void Withdrawal(int value)
        {
            if (_date < _finalDate)
            {
                Console.WriteLine("Снятие наличных невозможно.");
                return;
            }
            if (_sum < value)
            {
                Console.WriteLine("Недостаточно средств.");
                return;
            }
            _sum -= value; 
            Console.WriteLine("Вы успешно сняли " + value + " рублей."); 
        }

        public override void Transfer(int value, Client client)
        {
            if (_date < _finalDate)
            {
                Console.WriteLine("Перевод невозможен.");
                return;
            }
            int rand = (new Random()).Next(0, 1);
            if (client.TryToTransfer(value) && rand == 1 && _sum > value)
            {
                _sum -= value;
                client.Replenishment(value, AccountType.any);
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
            if (_dateDiff.Days % 30 == 0)
            {
                _sum += _percentSum;
                _percentSum = 0;
            }
            _percentSum += (_sum * _percent) / 100 / 365; 
        }
    }
}