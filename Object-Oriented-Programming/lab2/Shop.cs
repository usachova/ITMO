using System;
using System.Collections.Generic;

namespace lab2
{
    public class Shop : Manager
    {
        private int code_;
        private string name_;
        private string address_;
        private List<Product.Prod> products = new List<Product.Prod>();

        public Shop(int code, string name, string address)
        {
            code_ = code;
            name_ = name;
            address_ = address;
        }
        
        public int GetCode()
        {
            return code_;
        }
        
        public string GetName()
        {
            return name_;
        }
        
        public string GetAddress()
        {
            return address_;
        }

        public void Add(List<Product.Prod> prods)
        {
            foreach (Product.Prod prod in prods)
            {
                int flag = 0;
                foreach (Product.Prod pr in products)
                {
                    if (pr.prodId == prod.prodId)
                    {
                        products.Add(new Product.Prod(pr.prodId, prod.price, pr.cnt + prod.cnt));
                        flag = 1;
                        products.Remove(pr);
                    }
                }
                if (flag == 0) products.Add(prod);
            }
        }

        public Product.Prod GetCntProd(int prod)
        {
            foreach (Product.Prod prod0 in products)
            {
                if (prod == prod0.prodId)
                {
                    return prod0;
                }
            }
            return new Product.Prod(-1, -1,-1);
        }

        public void DelCntProd(int prod, int cnt)
        {
            Product.Prod tmp = null;
            foreach (Product.Prod prod0 in products)
            {
                if (prod == prod0.prodId)
                {
                    tmp = prod0;
                    break;
                }
            }
            Product.Prod pr = new Product.Prod(prod, tmp.price, tmp.cnt - cnt);
            products.Add(pr);
            products.Remove(tmp);
        }
        
        public int CanIBuy(List<Product.Prod> list)
        {
            int price = 0;
            foreach (Product.Prod prod in list)
            {
                Product.Prod tmp = GetCntProd(prod.prodId);
                if (tmp.cnt >= prod.cnt)
                {
                    price += prod.cnt * tmp.price;
                }
                else
                    return -1;
            }
            return price;
        }

        public int Buy(List<Product.Prod> list)
        {
            int price = CanIBuy(list);
            if (price != -1)
            {
                foreach (Product.Prod prod in list)
                {
                    DelCntProd(prod.prodId, prod.cnt);
                }
            }
            return price;
        }

        public List<Product.Prod> GetProdList()
        {
            return products;
        }
    }
}