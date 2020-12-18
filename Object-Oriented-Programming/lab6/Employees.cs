using System.Collections.Generic;

namespace lab6
{
    public class Employees
    {
        private List<Employee> _employees = new List<Employee>();
        private Employee _teamLeader = null;

        public void CreateEmployee(string name, Employee? head = null) 
        {
            if (_employees.Count == 0)
            {
                _employees.Add(new Employee(0, name, null));
                _teamLeader = _employees[0];
            }
            else
            {
                _employees.Add(new Employee(_employees.Count, name, head));
            }
        }

        public Employee GetTeamLeader()
        {
            return _teamLeader;
        }

        public Employee Find(int index)
        {
            return _employees[index];
        }
    }
}