using System;
using System.Collections.Generic;

namespace lab1 
{
    public class Section 
    {
        private string sect;
        private Dictionary<string, string> dict = new Dictionary<string, string>();
        
        public Section(string str) 
        {
            sect = str;
        }

        public void Add(string name, string value) 
        {
            dict[name] = value;
        }
        
        public T Get<T>(string key) 
        {
            return (T)Convert.ChangeType(dict[key], typeof(T));
        }

        public string this[string key] => Get<string>(key);
    }
}