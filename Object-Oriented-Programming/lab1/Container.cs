using System.Collections.Generic;
using System.Linq;

namespace lab1
{
    public class Container
    {
        private Dictionary<string, Section> cont = new Dictionary<string, Section>();

        public Section Get(string key)
        {
            if (cont.ContainsKey(key)) return cont[key];
            else throw new PairDoesntExist("Section does not exist");
        }

        public void Add(string key)
        {
            cont[key] = new Section(key);
        }
    }
}