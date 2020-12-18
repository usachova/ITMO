using System;

namespace lab6
{
    public static class Manager
    {
        private static DateTime _date = DateTime.Today;
        private static Employees _employees = new Employees();
        private static TaskSystem _taskSystem = new TaskSystem();

        public static Employees GetEmployees()
        {
            return _employees;
        }
        
        public static Employee GetEmployeeByIndex(int index)
        {
            return _employees.Find(index);
        }

        public static TaskSystem GetTaskSystem()
        {
            return _taskSystem;
        }

        public static void MoveToTomorrow()
        {
            _date += TimeSpan.FromDays(1);
        }

        public static DateTime GetDate()
        {
            return _date;
        }
    }
}