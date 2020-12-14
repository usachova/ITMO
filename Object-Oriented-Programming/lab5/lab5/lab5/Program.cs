using System;

namespace lab5
{
    class Program
    {
        private static Client _getClient;

        static void Main(string[] args)
        {
            Manager.AddBank("Сбербанк", new DebitAccount.DebitParameters(4), 
                                      new DepositAccount.DepositParameters(TimeSpan.FromDays(100), 5000, 10000, 3, 4, 5), 
                                      new CreditAccount.CreditParameters(30000, 50), 1000);
            Bank bank = Manager.GetBank(0);
            bank.AddClient("Дим", "Димыч");
            _getClient = bank.GetClient(0);
            Client sliceofkekus = _getClient;
            sliceofkekus.AddAddress("Тачка");
            Console.WriteLine(sliceofkekus.GetAddress());
            bank.AddClient("Данька", "Наш").AddPassport("1234560");
            _getClient = bank.GetClient(1);
            Client danyaffff = _getClient;
            sliceofkekus.AddAccount(Account.AccountType.debit, bank.GetDebitParameters(), 0);
            sliceofkekus.Replenishment(2000, Account.AccountType.debit);
            danyaffff.AddAccount(Account.AccountType.credit, bank.GetDCreditParameters(), 1000);
            sliceofkekus.Withdrawal(1500, Account.AccountType.debit);
            sliceofkekus.Transfer(500, Account.AccountType.debit, danyaffff);
        }
    }
}  