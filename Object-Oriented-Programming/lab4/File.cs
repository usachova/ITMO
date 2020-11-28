using System;

namespace lab4
{
    public class File
    {
        private string name_;
        private int size_;

        public File(string name)
        {
            name_ = name;
            size_ = (new Random()).Next(20, 100);
        }

        public int GetSize()
        {
            return size_;
        }
        
        public void ChangeSize(int value)
        {
            size_ = value;
        }

        public string GetName()
        {
            return name_;
        }
    }
}