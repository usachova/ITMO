using System;

namespace lab6
{
    public class ReportData
    {
        protected int _id;
        protected DateTime creationDate;
        protected Employee creator;

        public enum ReportState
        {
            open,
            close
        }

        protected ReportState _state;

        public enum ReportType
        {
            day,
            stage
        }

        protected ReportType _type;
        
        public ReportData(int id, DateTime date, Employee employee)
        {
            _id = id;
            creationDate = date;
            creator = employee;
        }
        
        public Employee GetCreator()
        {
            return creator;
        }

        public ReportState GetState()
        {
            return _state;
        }

        public void SetState(ReportState newstate)
        {
            _state = newstate;
        }

        public ReportType GetType()
        {
            return _type;
        }
    }
}