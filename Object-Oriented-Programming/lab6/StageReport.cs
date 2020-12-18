using System;
using System.Collections.Generic;
using System.Linq;

namespace lab6
{
    public class StageReport : Report
    {
        public enum StageReportType
        {
            employee,
            command
        }

        private StageReportData _stageReportData;

        public void Synchronize(StageReportType type)
        {
            if (_stageReportData.GetState() == ReportData.ReportState.open)
            {
                switch (type)
                {
                    case StageReportType.employee:
                        foreach (DayReport report in Manager.GetTaskSystem().GetDayReports().Where(u => u.GetCreator() == _stageReportData.GetCreator()).ToList())
                        {
                            if (!_stageReportData.AnyReports(report))
                            {
                                _stageReportData.AddReport(report);
                            }
                        }
                        break;
                    case StageReportType.command:
                        foreach (DayReport report in Manager.GetTaskSystem().GetDayReports())
                        {
                            if (!_stageReportData.AnyReportsAndCr(report))
                            {
                                _stageReportData.AddReport(report);
                            }
                        }
                        break;
                }
            }
        }

        public StageReport(int id, DateTime date, Employee employee, ReportData.ReportType type) : base(id, date, employee)
        {
            _stageReportData = new StageReportData(id, date, employee);
        }
    }
}