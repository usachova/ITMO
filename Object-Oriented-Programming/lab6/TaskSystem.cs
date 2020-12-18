using System;
using System.Collections.Generic;
using System.Linq;

namespace lab6
{
    public class TaskSystem
    {
        private List<Stage> _stages = new List<Stage>();
        private Stage? _stage = null;
        private List<DayReport> _dayReports = new List<DayReport>();
        private List<StageReport> _stageReports = new List<StageReport>();
        private int numberOfReports = 0;

        public struct StageWithTasks
        {
            public Stage _stage;
            public List<Task> _tasks;

            public StageWithTasks(Stage stage, List<Task> tasks)
            {
                _stage = stage;
                _tasks = tasks;
            }
        }
        
        public void AddStages(List<StageWithTasks> stages, DateTime date)
        {
            if (_stages.Count == 0)
            {
                foreach (StageWithTasks stage in stages)
                {
                    Stage newStage = new Stage(_stages.Count);
                    newStage.AddTasks(stage._tasks, date);
                    _stages.Add(newStage);
                }
            }
        }

        public void AddToDayReports(DayReport report)
        {
            _dayReports.Add(report);
        }
        
        public void AddToStageReports(StageReport report)
        {
            _stageReports.Add(report);
        }

        public List<DayReport> GetDayReports()
        {
            return _dayReports;
        }

        public Task SearchById(int stageIndex, int taskIndex)
        {
            return _stages[stageIndex].GetByIndex(taskIndex);
        }

        public List<Task> SearchByCreationDate(DateTime date)
        {
            List<Task> tasks = new List<Task>();
            foreach (Stage stage in _stages)
            {
                tasks.AddRange(stage.GetTasks().Where(u => u.GetCreationTime() == date).ToList());
            }
            return tasks;
        }
        
        public List<Task> SearchByLastChangeDate(DateTime date)
        {
            List<Task> tasks = new List<Task>();
            foreach (Stage stage in _stages)
            {
                tasks.AddRange(stage.GetTasks().Where(u => u.GetLastChangeTime() == date).ToList());
            }
            return tasks;
        }

        public List<Task> SearchEmployeeTasks(Employee employee)
        {
            List<Task> tasks = new List<Task>();
            foreach (Stage stage in _stages)
            {
                tasks.AddRange(stage.GetTasks().Where(u => u.GetEmployee() == employee).ToList());
            }
            return tasks;
        }
        
        public List<Task> SearchTasksByEmployeeChanges(Employee employee)
        {
            List<Task> tasks = new List<Task>();
            foreach (Stage stage in _stages)
            {
                tasks.AddRange(stage.GetTasks().Where(u => u.GetChanges().Any(v => v._employee == employee)).ToList());
            }
            return tasks;
        }
        
        public List<Task> SearchTasksByBossEmployee(Employee employee)
        {
            List<Task> tasks = new List<Task>();
            foreach (Employee subordinate in employee.GetSubordinates())
            {
                tasks.AddRange(subordinate.GetTasks());
            }
            return tasks;
        }

        public int GetNumberOfReports()
        {
            return numberOfReports;
        }
    }
}