using System;
using System.Collections.Generic;

namespace lab4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("---Test 1---");
            Manager.GetMan().CreateBackup(Backup.Limit.LimitsType.number, 1);
            Manager.GetMan().AddFileToBackUp(0, "1-1.txt");
            Manager.GetMan().AddFileToBackUp(0, "1-2.txt");
            Manager.GetMan().CreateRPoint(0, RestorePoint.PointType.full, RestorePoint.PointSavingType.directory);
            Manager.GetMan().RemovePointsOverLimit(0);
            Console.WriteLine();
            
            Console.WriteLine("---Test 2---");
            List<Backup.Limit> list2 = new List<Backup.Limit>();
            list2.Add(new Backup.Limit(Backup.Limit.LimitsType.size, 200));
            list2.Add(new Backup.Limit(Backup.Limit.LimitsType.number, 5));
            Manager.GetMan().CreateBackup(Backup.OptionsType.all, list2);
            Manager.GetMan().AddFileToBackUp(1, "2-1.txt");
            Manager.GetMan().AddFileToBackUp(1, "2-2.txt");
            Manager.GetMan().CreateRPoint(1, RestorePoint.PointType.full, RestorePoint.PointSavingType.directory);
            Manager.GetMan().CreateRPoint(1, RestorePoint.PointType.full, RestorePoint.PointSavingType.directory);
            Console.WriteLine("Размер бекапа: " + Manager.GetMan().GetBackUpSize(1));
            Manager.GetMan().RemovePointsOverLimit(1);
            Console.WriteLine("Новый размер бекапа: " + Manager.GetMan().GetBackUpSize(1));
            Console.WriteLine();
        }
    }
}