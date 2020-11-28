using System;
using System.Collections.Generic;

namespace lab4
{
    public class Manager
    {
        private static Manager man;
        private uint daysShift;
        private List<Backup> backups_ = new List<Backup>();
        private Manager()
        {}

        public static Manager GetMan()
        {
            return man ??= new Manager();
        }

        
        public void CreateBackup(Backup.Limit.LimitsType ltype, int limit)
        {
            backups_.Add(new Backup(backups_.Count, daysShift, ltype, limit));
            Console.WriteLine("Создан новый бекап его id: " + (backups_.Count - 1));
        }

        public void CreateBackup(Backup.OptionsType type, List<Backup.Limit> limitsTypes)
        {
            backups_.Add(new Backup(backups_.Count, daysShift, type, limitsTypes));
            Console.WriteLine("Создан новый бекап его id: " + (backups_.Count - 1));
        }

        public int GetBackUpSize(int index)
        {
            return backups_[index].GetSize();
        }
        public void AddFileToBackUp(int index, string name)
        {
            backups_[index].Add(name);
        }
        
        public void CreateRPoint(int index, RestorePoint.PointType ptype, RestorePoint.PointSavingType stype)
        {
            backups_[index].CreatePoint(ptype, stype, daysShift);
        }

        public void ChangeDate(uint diff)
        {
            daysShift += diff;
        }

        public void RemovePointsOverLimit(int index)
        {
            backups_[index].RemovePointsOverLimit();
        }

        public void ChangeFSize(int index, string name, int diff)
        {
            backups_[index].ChangeFileSize(name, diff);
        }
    }
}