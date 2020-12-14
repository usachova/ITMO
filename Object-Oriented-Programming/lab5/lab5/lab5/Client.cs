using System;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;

namespace lab5
{
    public class Client
    {
        private int _id;
        private string _name;
        private string _surname;
        private string _address;
        private string _passport;
        private DebitAccount _debitAccount = null;
        private DepositAccount _depositAccount = null;
        private CreditAccount _creditAccount = null;
        private TimeSpan _date;
        private bool _subordinate = true;
        private int _subordinateLimitSum;

        public Client(int id, TimeSpan date, int subordinateLimitSum, string name, string surname)
        {
            _id = id;
            _date = date;
            _subordinateLimitSum = subordinateLimitSum;
            _name = name;
            _surname = surname;
        }
        
        public void AddAddress(string address)
        {
            _subordinate = false;
            _address = address;
        }
        
        public void AddPassport(string passport)
        {
            _subordinate = false;
            _passport = passport;
        }

        public string GetName()
        {
            return _name;
        }
        
        public string GetSurname()
        {
            return _surname;
        }
        
        public string GetAddress()
        {
            return _address;
        }

        public void AddAccount(Account.AccountType type, Account.Parameters parameters, int sum)
        {
            switch (type)
            {
                case Account.AccountType.debit:
                    if (_debitAccount == null)
                    {
                        var parD = parameters as DebitAccount.DebitParameters;
                        _debitAccount = new DebitAccount(parD, _date, sum);
                    }
                    else
                    {
                        Console.WriteLine("Счёт уже существует");
                    }
                    break;
                case Account.AccountType.deposit:
                    if (_depositAccount == null)
                    {
                        var parDep= parameters as DepositAccount.DepositParameters;
                        _depositAccount = new DepositAccount(parDep, _date, sum);
                    }
                    else
                    {
                        Console.WriteLine("Счёт уже существует");
                    }
                    break;
                case Account.AccountType.credit:
                    if (_creditAccount == null)
                    {
                        var parC = parameters as CreditAccount.CreditParameters;
                        _creditAccount = new CreditAccount(parC, _date, sum);
                    }
                    else
                    {
                        Console.WriteLine("Счёт уже существует");
                    }
                    break;
            }
        }

        public bool TryToTransfer(int value)
        {
            if (_debitAccount != null || _depositAccount != null || _creditAccount != null)
            {
                return true;
            }
            return false;
        }

        public void MoveInTime()
        {
            _debitAccount?.MoveInTime();
            _depositAccount?.MoveInTime();
            _creditAccount?.MoveInTime();
        }

        public void Withdrawal(int value, Account.AccountType accountType)
        {
            if (_subordinate && value > _subordinateLimitSum)
            {
                Console.WriteLine("Операция отклонена.");
                return;
            }
            switch (accountType)
            {
                case Account.AccountType.debit:
                    _debitAccount?.Withdrawal(value);
                    break;
                case Account.AccountType.deposit:
                    _depositAccount?.Withdrawal(value);
                    break;
                case Account.AccountType.credit:
                    _creditAccount?.Withdrawal(value);
                    break;
            }
        }
        public void Replenishment(int value, Account.AccountType accountType) 
        {
            switch (accountType)
            {
                case Account.AccountType.debit:
                    _debitAccount?.Replenishment(value);
                    break;
                case Account.AccountType.deposit:
                    _depositAccount?.Replenishment(value);
                    break;
                case Account.AccountType.credit:
                    _creditAccount?.Replenishment(value);
                    break;
                case Account.AccountType.any:
                    if (_debitAccount != null)
                    {
                        _debitAccount.Replenishment(value);
                    }
                    else if (_depositAccount != null)
                    {
                        _depositAccount.Replenishment(value);
                    }
                    else _creditAccount.Replenishment(value);
                    break;
            }
        }

        public void Transfer(int value, Account.AccountType accountType, Client client)
        {
            if (_subordinate && value > _subordinateLimitSum)
            {
                Console.WriteLine("Операция отклонена.");
                return;
            }
            switch (accountType)
            {
                case Account.AccountType.debit:
                    _debitAccount?.Transfer(value, client);
                    break;
                case Account.AccountType.deposit:
                    _depositAccount?.Transfer(value, client);
                    break;
                case Account.AccountType.credit:
                    _creditAccount?.Transfer(value, client);
                    break;
            }
        }
    }
}