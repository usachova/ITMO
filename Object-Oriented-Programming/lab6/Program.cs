using System;
using System.Collections.Generic;

namespace lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            Manager.GetEmployees().CreateEmployee("Тейлор");
            Manager.GetEmployees().CreateEmployee("Даня", Manager.GetEmployees().GetTeamLeader());
            Manager.GetEmployees().CreateEmployee("Коля", Manager.GetEmployees().GetTeamLeader());
            Stage stage = new Stage(Manager.GetTaskSystem().GetNumberOfReports());
            List<Task> tasks = new List<Task>();
            tasks.Add(new Task(0, "задача", "описание задачи",Manager.GetEmployees().GetTeamLeader(), Manager.GetDate(), stage));
            TaskSystem.StageWithTasks stageWithTasks = new TaskSystem.StageWithTasks(stage, tasks);
            List<TaskSystem.StageWithTasks> newlist = new List<TaskSystem.StageWithTasks>();
            newlist.Add(stageWithTasks);
            Manager.GetTaskSystem().AddStages(newlist, Manager.GetDate());
        }
    }
}