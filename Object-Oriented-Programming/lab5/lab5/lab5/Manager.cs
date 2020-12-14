using System;
using System.Collections.Generic;

namespace lab5
{
    public static class Manager
    {
        private static TimeSpan _date = new TimeSpan(0, 0, 0, 0);
        private static List<Bank> _banks = new List<Bank>();

        public static void AddBank(string name, 
                            DebitAccount.DebitParameters debitParameters, 
                            DepositAccount.DepositParameters depositParameters, 
                            CreditAccount.CreditParameters creditParameters, 
                            int dubiousLimitSum)
        {
            _banks.Add(new Bank( _banks.Count, name, _date, debitParameters, depositParameters, 
                                      creditParameters, dubiousLimitSum));
        }

        public static Bank GetBank(int index)
        {
            return _banks[index];
        }
        
        public static void MoveInTime(int diffDate)
        {
            _date += TimeSpan.FromDays(diffDate);
            for (int i = 0; i < diffDate; i++)
            {
                foreach (Bank bank in _banks)
                {
                    bank.MoveInTime();
                }
            }
        }
    }
}