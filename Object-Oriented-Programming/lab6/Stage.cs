using System;
using System.Collections.Generic;

namespace lab6
{
    public class Stage
    {
        private int _id;
        private List<Task> _tasks = new List<Task>();

        public Stage(int id)
        {
            _id = id;
        }
        public void AddTasks(List<Task> tasks, DateTime date)
        {
            foreach (Task task in tasks)
            {
                _tasks.Add(task);
                task.GetEmployee().DelegateTask(task, date);
            }
        }

        public Task GetByIndex(int index)
        {
            return _tasks[index];
        }

        public List<Task> GetTasks()
        {
            return _tasks;
        }
    }
}