using System;
using System.Collections.Generic;
using System.Linq;

namespace lab6
{
    public class DayReportData : ReportData
    {
        private List<Employee.Change> _changes = new List<Employee.Change>();
        
        public DayReportData(int id, DateTime date, Employee employee) : base(id, date, employee)
        {
            _type = ReportType.day;
        }
        
        public void AddChange(Employee.Change change)
        {
            _changes.Add(change);
        }
        
        public bool AnyChanges(Employee.Change change)
        {
            return _changes.Any(u => u._id == change._id);
        }
    }
}