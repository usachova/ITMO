using System;

namespace lab5
{
    public abstract class Account
    {
        public abstract class Parameters {}
        public enum AccountType
        {
            debit,
            deposit,
            credit,
            any
        }

        protected AccountType _type;
        protected int _sum = 0;
        protected TimeSpan _date;
        protected TimeSpan _dateDiff = new TimeSpan(0);

        public AccountType GetAccountType()
        {
            return _type;
        }

        public int GetSum()
        {
            return _sum;
        }

        public abstract void Withdrawal(int value);
        public void Replenishment(int value) 
        {
            _sum += value;
            Console.WriteLine("Вы успешно пополнили счёт.");
        }
        public abstract void Transfer(int value, Client client);
        public abstract void MoveInTime();
    }
}