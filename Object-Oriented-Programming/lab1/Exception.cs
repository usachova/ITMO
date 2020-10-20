namespace lab1
{
    public class FileDoesntExist: System.Exception
    {
        public FileDoesntExist(string error) : base (error)
        {
            
        }
    }
    
    public class BadSyntax: System.Exception
    {
        public BadSyntax(string error) : base (error)
        {
            
        }
    }
    public class WrongFileFormat: System.Exception
    {
        public WrongFileFormat(string error) : base (error)
        {
            
        }
    }
    
    public class BadCast: System.Exception
    {
        public BadCast(string error) : base (error)
        {
            
        }
    }
    
    public class PairDoesntExist: System.Exception
    {
        public PairDoesntExist(string error) : base (error)
        {
            
        }
    }
}