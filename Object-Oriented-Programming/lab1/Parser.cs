using System;
using System.Linq;

namespace lab1
{
    public class Parser
    {
        private string str;
        private string curname;
        private int pos = -1;
        private Container cont;
        
        public Parser(Container container) 
        {
            cont = container;
        }
        
        public void ChangePos(int new_pos)
        {
            pos = new_pos;
        }
        
        public void ParseLine(string line) {
            str = line.Trim();
            var ind = str.IndexOf(';');
            if (ind != -1) str = str.Remove(ind).Trim();
            if (str == "") return;
            if (str.StartsWith('[') && str.EndsWith(']')) 
            {
                str = str.Remove(0,1).Remove(str.Length - 2, 1);
                curname = str;
                cont.Add(curname);
                return;
            }
            if (curname == null) 
            {
                throw new BadSyntax("INI file should start with a name of section");
            }
            var arr = str.Split("=");
            if (arr.Count() < 2 || arr.Count() > 2) 
            {
                throw new BadSyntax("There must be one = per line");
            }
            cont.Get(curname).Add(arr[0].Trim(), arr[1].Trim(' ', '"'));
        }
    }
}