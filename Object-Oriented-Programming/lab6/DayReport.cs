using System;
using System.Collections.Generic;
using System.Linq;

namespace lab6
{
    public class DayReport : Report
    {

        private DayReportData _dayReportData;
        
        public void Synchronize()
        {
            if (_dayReportData.GetState() == ReportData.ReportState.open)
            {
                foreach (Employee.Change change in _dayReportData.GetCreator()._changes)
                {
                    if (!_dayReportData.AnyChanges(change))
                    {
                        _dayReportData.AddChange(change);
                    }
                }
            }
        }

        public DayReport(int id, DateTime date, Employee employee) : base(id, date, employee)
        {
            _dayReportData = new DayReportData(id, date, employee);
        }

        public Employee GetCreator()
        {
            return _dayReportData.GetCreator();
        }
    }
}