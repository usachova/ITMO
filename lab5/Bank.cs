using System;
using System.Collections.Generic;

namespace lab5
{
    public class Bank
    {
        private int _id;
        private string _name;
        private DateTime _date;

        private DebitAccount.DebitParameters _debitParameters;
        private DepositAccount.DepositParameters _depositParameters;
        private CreditAccount.CreditParameters _creditParameters;
        private int _subordinateLimitSum;
        
        private List<Client> _clients = new List<Client>();
        private Client _addClient;

        public Bank(int id, string name, DateTime date, 
                    DebitAccount.DebitParameters debitParameters, 
                    DepositAccount.DepositParameters depositParameters, 
                    CreditAccount.CreditParameters creditParameters, 
                    int subordinateLimitSum)
        {
            _id = id;
            _name = name;
            _date = date;
            _debitParameters = debitParameters;
            _depositParameters = depositParameters;
            _creditParameters = creditParameters;
            _subordinateLimitSum = subordinateLimitSum;
        }

        public string GetName()
        {
            return _name;
        }

        public DebitAccount.DebitParameters GetDebitParameters()
        {
            return _debitParameters;
        }

        public DepositAccount.DepositParameters GetDepositParameters()
        {
            return _depositParameters;
        }
        
        public CreditAccount.CreditParameters GetDCreditParameters()
        {
            return _creditParameters;
        }
        
        public Client AddClient(string name, string surname)
        {
            _clients.Add(new Client( _clients.Count, _date, _subordinateLimitSum, name, surname));
            return _clients[^1];
        }

        public Client GetClient(int index)
        {
            return _clients[index];
        }

        public void MoveInTime()
        {
            _date += TimeSpan.FromDays(1);
            foreach (Client client in _clients)
            {
                client.MoveInTime();
            }
        }
    }
}