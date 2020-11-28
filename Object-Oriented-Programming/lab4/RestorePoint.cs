using System.Collections.Generic;

namespace lab4
{
    public class RestorePoint
    {
        private uint date_;
        private int size_;
        private List<File> files_ = new List<File>();

        public enum PointType
        {
            full,
            increment
        }

        public enum PointSavingType
        {
            archive,
            directory
        }

        private PointType type_;
        private PointSavingType stype_;
        
        public RestorePoint(uint date, int size, List<File> files, PointType type, PointSavingType stype)
        {
            date_ = date;
            size_ = size;
            files_ = files;
            type_ = type;
            stype_ = stype;
        }
        
        public PointType GetType()
        {
            return type_;
        }
        
        public uint GetDate()
        {
            return date_;
        }
        
        public int GetSize()
        {
            return size_;
        }

        public List<File> GetFiles()
        {
            return files_;
        }
    }
}