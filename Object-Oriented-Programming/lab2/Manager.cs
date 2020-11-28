using System;
using System.Collections.Generic;

namespace lab2
{
    public class Manager
    {
        private List<Shop> shops = new List<Shop>();
        private List<Product> products = new List<Product>();
        private List<Product.Prod> consignment = new List<Product.Prod>();

        public Product GetProd(int index)
        {
            return products[index];
        }

        public Shop GetShop(int index)
        {
            return shops[index];
        }
        public void CreateNewShop(string name, string address)
        {
            shops.Add(new Shop(shops.Count, name, address));
        }

        public void CreateNewProduct(string name)
        {
            products.Add(new Product(products.Count, name));
        }

        public void AddToCons(int id, int price, int cnt)
        {
            consignment.Add(new Product.Prod(id, price, cnt));
        }

        public void AddToShop(Shop shop)
        {
            shop.Add(consignment);
        }

        public string ShopWithMin(Product prod)
        {
            string ans  = "";
            int minprice = -1;
            List<Product.Prod> list = new List<Product.Prod>();
            list.Add(new Product.Prod(prod.GetCode(), -1, 1));
            foreach (Shop shop in shops)
            {
                int price = shop.CanIBuy(list);
                if (ans != "") 
                {
                    if (price < minprice)
                    {
                        ans = shop.GetName(); 
                        minprice = price;
                    }
                }
                else
                {
                    ans = shop.GetName();
                    minprice = price;
                }
            }
            return ans;
        }

        public void WhatICanBye(int money, Shop shop)
        {
            foreach (Product.Prod prod in shop.GetProdList())
            {
                Product.Prod tmp = shop.GetCntProd(prod.prodId);
                int cnt = money / tmp.price;
                if (cnt > tmp.cnt) cnt = tmp.cnt;
                if (cnt != 0) 
                    Console.WriteLine("ты можешь купить " + cnt + " товаров с названием " + products[prod.prodId].GetName());
            }
        }

        public int ByeInShop(Shop shop, List<Product.Prod> list)
        {
            return shop.Buy(list);
        }

        public string ShopWithMinSum(List<Product.Prod> list)
        {
            int minsum = -1;
            Shop ans = null;
            foreach (Shop shop in shops)
            {
                int sum = shop.CanIBuy(list);
                if (minsum == -1 || minsum > sum)
                {
                    minsum = sum;
                    ans = shop;
                }
            }
            return ans.GetName();
        }

        public void ClearCons()
        {
            consignment.Clear();
        }
    }
}