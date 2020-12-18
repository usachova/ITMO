#nullable enable
using System;
using System.Collections.Generic;
using System.Linq;

namespace lab6
{
    public class Employee
    {
        private int _id { get;  }
        private string _name { get; }
        private Employee? head { get; set; }
        private List<Employee> _subordinates = new List<Employee>();
        
        private List<Task> _tasks = new List<Task>();

        public struct Change
        {
            public int _id;
            public Task _task;
            
            public enum ChangeType
            {
                employee,
                state,
                comment
            }
            
            public ChangeType _type;
            public DateTime _date;
            
            public Change(int id, Task task, ChangeType type, DateTime date)
            {
                _id = id;
                _task = task;
                _type = type;
                _date = date;
            }

        }
        public List<Change> _changes = new List<Change>();
        private int _dist { get; set; } 
        public Report _report = null;
        private StageReport subordinatesReport = null;
        public List<Report> _reports = new List<Report>();

        public Employee(int id, string name, Employee? employee)
        {
            _id = id;
            _name = name;
            head = employee;
            if (employee != null) _dist = employee._dist + 1;
            else _dist = 0;
        }

        public void ChangeHead(Employee employee)
        {
            head = employee;
            _dist = employee._dist + 1;
        }

        public void AddSubordinate(Employee employee)
        {
            _subordinates.Add(employee);
            employee.ChangeHead(this);
        }

        public int GetCountSubordinates()
        {
            return _subordinates.Count;
        }

        public void PrintName()
        {
            Console.WriteLine(_name);
        }

        public void PrintEmployeeWithSubordinates()
        {
            PrintName();
            foreach (Employee subordinate in _subordinates)
            {
                subordinate.PrintName();
            }
        }

        public void AddToStage(Stage stage, List<Task> tasks, DateTime date)
        {
            stage.AddTasks(tasks, date);

            foreach (Task task in tasks)
            {
                _changes.Add(new Change(_changes.Count, task, Change.ChangeType.state, date));
            }
        }

        private void RemoveTask(Task task)
        {
            if (_tasks.Contains(task))
                _tasks.Remove(task);
        }

        public void DelegateTask(Task task, DateTime date)
        {
            if (_tasks.Contains(task))
                return;
            
            _tasks.Add(task);
            if (task.GetEmployee() != this)
            {
                task.GetEmployee().RemoveTask(task);
            }
            
            task.ChangeEmployee(this, date);
            _changes.Add(new Change(_changes.Count, task, Change.ChangeType.state, date));
        }

        public void ActivateTask(DateTime date, int? index = null)
        {
            if (_tasks.Any(u => u.GetState() == Task.TaskState.active))
                return;
            if (index == null)
            {
                _tasks.Find(u => u.GetState() == Task.TaskState.open)?.ChangeState(Task.TaskState.active, date);
            }
            else
            {
                if (_tasks.Any(u => u.GetID() == index))
                {
                    _tasks[(int) index].ChangeState(Task.TaskState.active, date);
                }
            }
        }

        public void CompleteTask(DateTime date)
        {
            if (_tasks.Any(u => u.GetState() == Task.TaskState.active))
                _tasks.Find(u => u.GetState() == Task.TaskState.active)!.ChangeState(Task.TaskState.resolved, date);
        }

        public bool IsSubordinate(Employee employee)
        {
            if (head == null)
                return false;

            if (head == employee)
                return true;
            
            return head.IsSubordinate(employee);
        }

        public List<Employee> GetSubordinates()
        {
            return _subordinates;
        }

        public List<Task> GetTasks()
        {
            return _tasks;
        }
    }
}