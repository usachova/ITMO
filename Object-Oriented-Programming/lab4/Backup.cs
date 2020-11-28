using System;
using System.Collections.Generic;
using System.Linq;

namespace lab4
{
    public class Backup
    {
        public class Limit
        {
            public enum LimitsType
            {
                number,
                date,
                size
            }

            private LimitsType type_;
            private int limit_value;
            
            public Limit(LimitsType type, int value)
            {
                type_ = type;
                limit_value = value;
            }

            public LimitsType GetLimitType()
            {
                return type_;
            }

            public int GetLimitValue()
            {
                return limit_value;
            }
        }
        
        private int id_;
        private uint time_;
        private int size_;
        private List<File> files_ = new List<File>();
        private List<RestorePoint> points_ = new List<RestorePoint>();
        private OptionsType opType_;
        private List<Limit> limits_ = new List<Limit>();

        public enum OptionsType
        {
            all,
            at_least_one
        }

        public Backup(int id, uint time, Limit.LimitsType ltype, int limit)
        {
            id_ = id;
            time_ = time;
            size_ = 0;
            opType_ = OptionsType.at_least_one;
            limits_.Add(new Limit(ltype, limit));
        }
        public Backup(int id, uint time, OptionsType type, List<Limit> limits)
        {
            id_ = id;
            time_ = time;
            size_ = 0;
            opType_ = type;
            limits_ = limits;
        }

        public int GetSize()
        {
            return size_;
        }

        public void ChangeFileSize(string name, int diff)
        {
            foreach (File file in files_)
            {
                if (file.GetName() == name)
                {
                    file.ChangeSize(file.GetSize() + diff);
                }
            }
        }

        public void Add(string name)
        {
            File file = new File(name);
            files_.Add(file);
            Console.WriteLine("Вы добавили файл с именем " + file.GetName() + " и размером " + file.GetSize());
        }

        public void CreatePoint(RestorePoint.PointType ptype, RestorePoint.PointSavingType stype, uint time)
        {
            switch (ptype)
            {
                case RestorePoint.PointType.full:
                    CreateFullPoint(stype, time);
                    break;
                case RestorePoint.PointType.increment:
                    CreateIncPoint(stype, time);
                    break;
            }
        }

        private void CreateFullPoint(RestorePoint.PointSavingType stype, uint time)
        {
            int size = 0;
            foreach (File file in files_)
            {
                size += file.GetSize();
            }
            points_.Add(new RestorePoint(time, size, files_, RestorePoint.PointType.full, stype));
            size_ += size;
            Console.WriteLine("Вы создали новую точку восстановления в бекапе " + id_ + " со следующими файлами:");
            foreach (File file in points_[^1].GetFiles())
            {
                Console.WriteLine("\t" + file.GetName() + " размером " + file.GetSize());
            }
        }

        private bool IsFileInFs(File file, List<File> files)
        {
            foreach (File f in files)
                if (f.GetName() == file.GetName())
                    return true;
            return false;
        }

        private void ChangeFileSize(File file, List<File> files)
        {
            foreach (File f in files)
                if (f.GetName() == file.GetName())
                    f.ChangeSize(f.GetSize() + file.GetSize());
        }

        private void CompareTwoArrays(List<File> files, List<File> files2)
        {
            foreach (File file in files)
            {
                if (IsFileInFs(file, files2))
                    ChangeFileSize(file, files2);
                else
                    files2.Add(file);
            }
        }

        private void CreateIncPoint(RestorePoint.PointSavingType stype, uint time)
        {
            int i;
            for (i = points_.Count - 1; i >= 0; i--)
            {
                if (points_[i].GetType() == RestorePoint.PointType.full)
                    break;
            }
            if (points_[i].GetType() != RestorePoint.PointType.full) return;
            List<File> files = points_[i].GetFiles();
            i++;
            for (; i < points_.Count; i++)
            {
                CompareTwoArrays(points_[i].GetFiles(), files);
            }
            CompareTwoArrays(files_, files);
            int size = 0;
            foreach (File file in files_)
            {
                size += file.GetSize();
            }
            points_.Add(new RestorePoint(time, size, files_, RestorePoint.PointType.increment, stype));
            size_ += size;
            Console.WriteLine("Вы создали новую точку восстановления в бекапе " + id_ + " со следующими файлами:");
            foreach (File file in points_[^1].GetFiles())
            {
                Console.WriteLine("\t" + file.GetName() + " размером " + file.GetSize());
            }
        }

        private int CheckNum(int cnt)
        {
            if (points_.Count > cnt)
                return points_.Count - cnt;
            return 0;
        }

        private int CheckDate(int date)
        {
            for (int i = points_.Count - 1; i >= 0; i--)
            {
                if (points_[i].GetDate() < date)
                    return i + 1;
            }

            return 0;
        }

        private int CheckSize(int size)
        {
            if (size_ < size) return 0;
            int sum = 0;
            for (int i = 0; i < points_.Count; i++)
            {
                sum += points_[i].GetSize();
                if (size_ - sum < size)
                    return i + 1;
            }
            return 0;
        }

        private int TryDelCnt(int cnt)
        {
            if (cnt > points_.Count) return 0;
            if (cnt < points_.Count && points_[cnt].GetType() == RestorePoint.PointType.increment)
            {
                Console.WriteLine("Предупреждение: придётся оставить точек сверх лимита.");
                while (points_[cnt].GetType() == RestorePoint.PointType.increment)
                    cnt--;
            }
            return cnt;
        }

        private void DeleteCnt(int cnt)
        {
            if (cnt <= 0) return;
            for (int i = 0; i < cnt; i++)
            {
                size_ -= points_[0].GetSize();
                points_.RemoveAt(0);
            }
            Console.WriteLine("Удалено " + cnt + " точек");
        }

        private int GetPointRangeToDelete(int[] arr)
        {
            return opType_ switch
            {
                OptionsType.all => arr.Min(),
                OptionsType.at_least_one => arr.Max()
            };
        }
        public void RemovePointsOverLimit()
        {
            var arr = limits_.Select(x =>
            {
                return x.GetLimitType() switch
                {
                    Limit.LimitsType.number => CheckNum(x.GetLimitValue()),
                    Limit.LimitsType.date => CheckDate(x.GetLimitValue()),
                    Limit.LimitsType.size => CheckSize(x.GetLimitValue())
                };
            }).ToArray();
            DeleteCnt(TryDelCnt(GetPointRangeToDelete(arr)));
            Console.WriteLine("Осталось " + points_.Count + " точек");
        }
    }
}
