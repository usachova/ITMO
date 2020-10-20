using System;
using System.IO;

namespace lab1
{
    public class IniFile
    {
        private StreamReader file;
        private Container cont = new Container();

        public IniFile(StreamReader newfile) 
        {
            file = newfile;
            Parse();
        }

        ~IniFile()
        {
            file.Close();
        }
        
        private void Parse() 
        {
            try
            {
                var parser = new Parser(cont);
                string line;
                for (var i = 0; (line = file.ReadLine()) != null; i++)
                {
                    parser.ChangePos(i + 1);
                    parser.ParseLine(line);
                }
            }
            catch (BadSyntax ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public Section this[string sect] 
        {
            get {
                try {
                    return cont.Get(sect);
                }
                catch (PairDoesntExist ex) {
                    Console.WriteLine(ex.Message);
                    return null;
                }
            }
        }
    }
}