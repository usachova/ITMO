using System;
using System.Collections.Generic;
using System.Linq;

namespace lab6
{
    public class StageReportData : ReportData
    {
        private List<DayReport> _reports = new List<DayReport>();

        public StageReportData(int id, DateTime date, Employee employee) : base(id, date, employee)
        {
            _type = ReportData.ReportType.stage;
        }

        public void AddReport(DayReport report)
        {
            _reports.Add(report);
        }

        public bool AnyReports(DayReport report)
        {
            return _reports.Any(u => u == report);
        }
        
        public bool AnyReportsAndCr(DayReport report)
        {
            return _reports.Any(u => u == report && report.GetCreator().IsSubordinate(creator));
        }
    }
}