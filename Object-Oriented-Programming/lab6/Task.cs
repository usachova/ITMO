using System;
using System.Collections.Generic;

namespace lab6
{
    public class Task
    {
        private int _id;
        private string _name;
        private string _description;
        private List<Change> _changes = new List<Change>();
        private string _comments = "";
        private Employee _employee;

        public struct Change
        {
            public enum ChangeType
            {
                employee,
                state,
                comment
            }
            
            public ChangeType _type;
            public DateTime _date;
            public Employee _employee;

            public Change(ChangeType type, DateTime date, Employee employee)
            {
                _type = type;
                _date = date;
                _employee = employee;
            }
        }
        public enum TaskState
        {
            open,
            active,
            resolved
        }

        private TaskState _state;
        private DateTime _openDate;
        private DateTime _lastChangeDate;
        private Stage _stage;

        public Task(int id, string name, string description, Employee employee, DateTime date, Stage stage)
        {
            _id = id;
            _name = name;
            _description = description;
            _employee = employee;
            _state = TaskState.open;
            _openDate = date;
            _stage = stage;
        }

        public void ChangeState(TaskState newState, DateTime date)
        {
            if (newState != TaskState.open && _state != TaskState.resolved)
            {
                _state = newState;
                _lastChangeDate = date;
                _lastChangeDate = date;
                _changes.Add(new Change(Change.ChangeType.state, date, _employee));
            }
        }

        public void AddComment(string comment, DateTime date)
        {
            if (_state != TaskState.resolved)
            {
                _comments += comment + "\n";
                _state = TaskState.active;
                _lastChangeDate = date;
                _changes.Add(new Change(Change.ChangeType.comment, date, _employee));
            }
        }

        public void ChangeEmployee(Employee newEmployee, DateTime date)
        {
            if (_state != TaskState.resolved)
            {
                _changes.Add(new Change(Change.ChangeType.employee, date, _employee));
                _lastChangeDate = date;
                _employee = newEmployee;
            }
        }

        public Employee GetEmployee()
        {
            return _employee;
        }

        public TaskState GetState()
        {
            return _state;
        }

        public int GetID()
        {
            return _id;
        }

        public DateTime GetCreationTime()
        {
            return _openDate;
        }

        public DateTime GetLastChangeTime()
        {
            return _lastChangeDate;
        }

        public List<Change> GetChanges()
        {
            return _changes;
        }
    }
}