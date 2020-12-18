using System;

namespace lab6
{
    public abstract class Report
    {
        private ReportData _reportData;
        public Report(int id, DateTime date, Employee employee)
        {
            _reportData = new ReportData(id, date, employee);
        }

        public DayReport AsDayReport()
        {
            return this as DayReport;
        }

        public StageReport AsStageReport()
        {
            return this as StageReport;
        }

        public void Close()
        {
            if (_reportData.GetState() == ReportData.ReportState.open)
            {
                _reportData.SetState(ReportData.ReportState.close);
                _reportData.GetCreator()._report = null;
                _reportData.GetCreator()._reports.Add(this);
                switch (_reportData.GetType())
                {
                    case ReportData.ReportType.day:
                        Manager.GetTaskSystem().AddToDayReports(this as DayReport);
                        break;
                    case ReportData.ReportType.stage:
                        Manager.GetTaskSystem().AddToStageReports(this as StageReport);
                        break;
                }
            }
        }
    }
}