using System;
using System.Collections.Generic;

namespace lab2
{
    class Program
    {
        static void Main(string[] args)
        {
            Manager man = new Manager();

            man.CreateNewShop("Пятёрочка", "Полюстровский пр, 3");
            man.CreateNewShop("Четвёрочка", "пр Маршала Блюхера, 14");
            man.CreateNewShop("Выгодный", "Кантемировская ул, 42");

            man.CreateNewProduct("Шоколад");
            man.CreateNewProduct("Киндер буэно");
            man.CreateNewProduct("Рис");
            man.CreateNewProduct("Греча");
            man.CreateNewProduct("Помидор");
            man.CreateNewProduct("Огурец");
            man.CreateNewProduct("Корм для котят");
            man.CreateNewProduct("Яблоко");
            man.CreateNewProduct("Болгарский перец жёлтый");
            man.CreateNewProduct("Болгарский перец красный");

            man.AddToCons(1, 6, 23);
            man.AddToCons(0, 1, 50);
            man.AddToCons(9, 1, 4);
            man.AddToCons(8, 12, 6);
            man.AddToShop(man.GetShop(0));
            man.ClearCons();

            man.AddToCons(1, 53, 230);
            man.AddToCons(0, 40, 500);
            man.AddToCons(9, 80, 40);
            man.AddToCons(8, 100, 60);
            man.AddToShop(man.GetShop(1));
            man.ClearCons();

            man.AddToCons(1, 5200, 250);
            man.AddToCons(0, 38, 500);
            man.AddToCons(9, 79, 400);
            man.AddToCons(8, 101, 600);
            man.AddToCons(7, 32, 100);
            man.AddToShop(man.GetShop(2));
            man.ClearCons();

            Console.WriteLine("Магазин с самым дешёвым " + man.GetProd(1).GetName() + ": " +
                              man.ShopWithMin(man.GetProd(1)));
            Console.WriteLine();

            int sum = 1000;
            Console.WriteLine("В магазине " + man.GetShop(1).GetName() + " на сумму " + sum + ":");
            man.WhatICanBye(sum, man.GetShop(1));
            Console.WriteLine();

            List<Product.Prod> mylist = new List<Product.Prod>();
            mylist.Add(new Product.Prod(7, -1, 10));
            mylist.Add(new Product.Prod(8, -1, 5));
            mylist.Add(new Product.Prod(9, -1, 5));
            Console.WriteLine("Вы хотите купить в магазине " + man.GetShop(2).GetName() + ":");
            foreach (Product.Prod x in mylist)
            {
                Console.WriteLine(man.GetProd(x.prodId).GetName() + " " + x.cnt + " штук");
            }
            int ans = man.ByeInShop(man.GetShop(2), mylist);
            if (ans != -1) 
                Console.WriteLine("С Вас " + ans + " денег");
            else
                Console.WriteLine("Такой список товаров приобрести здесь невозможно :(");
            Console.WriteLine();
            
            Console.WriteLine("Вы хотите купить в магазине " + man.GetShop(1).GetName() + " тот же набор:");
            ans = man.ByeInShop(man.GetShop(1), mylist);
            if (ans != -1) 
                Console.WriteLine("С Вас " + ans + " денег");
            else
                Console.WriteLine("Такой список товаров приобрести здесь невозможно :(");
            Console.WriteLine();
            
            List<Product.Prod> mylist2 = new List<Product.Prod>();
            mylist2.Add(new Product.Prod(8, -1, 3));
            mylist2.Add(new Product.Prod(1, -1, 2));
            mylist2.Add(new Product.Prod(0, -1, 1));
            Console.WriteLine("Вы хотите понять в каком магазине дешевле купить этот список продуктов:");
            foreach (Product.Prod x in mylist2)
            {
                Console.WriteLine(man.GetProd(x.prodId).GetName() + " " + x.cnt + " штук");
            }
            Console.WriteLine("Ответ: " + man.ShopWithMinSum(mylist2));
        }

    }
}