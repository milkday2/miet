namespace cs_lab1
{

    public enum TimeFrame
    {
        Year, TwoYears, Long
    }

    public class ResearchTeam
    {
        string theme;
        string orgName;
        int regNumber;
        TimeFrame duration;
        Paper[] publications;

        public ResearchTeam(string Theme, string OrgName, int RegNumber, TimeFrame Duration)
        {
            theme = Theme;
            orgName = OrgName;
            regNumber = RegNumber;
            duration = Duration;
            publications = new Paper[0];
        }

        public ResearchTeam() : this("-", "-", 0, TimeFrame.Long) { }

        public string Theme
        {
            get { return theme; }
            set { theme = value; }
        }

        public string OrgName
        {
            get { return orgName; }
            set { orgName = value; }
        }

        public int RegNumber
        {
            get { return regNumber; }
            set { regNumber = value; }
        }

        public TimeFrame Duration
        {
            get { return duration; }
            set { duration = value; }
        }

        public Paper[] Publications
        {
            get { return publications; }
            set { publications = value; }
        }

        public Paper? LatestPaper
        {
            get
            {
                int plen = publications.Length;
                if (plen == 0)
                    return null;
                Paper latest = publications[0];
                for (int i = 1; i < plen; i++)
                    if (publications[i].Date.CompareTo(publications[i - 1].Date) > 0)
                        latest = publications[i];
                return latest;
            }
        }

        public bool this[TimeFrame index]
        {
            get
            {
                if (index == duration)
                    return true;
                return false;
            }
        }

        public void AddPapers(params Paper[] newPapers)
        {
            publications = LabUtils.AddToArray<Paper>(publications, newPapers);
        }

        public override string ToString()
        {
            string result = $"Theme: {theme}; Organisation: {orgName}, {regNumber}; Duration: {duration}; Publications: ";
            if (publications.Length == 0)
                return $"{result}No publications";

            string papers = publications[0].Title;
            for (int i = 1; i < publications.Length; i++)
                papers += ", " + publications[i].Title;
            return result + papers;
        }
        public string ToShortString()
        {
            return $"Theme: {theme}; Organisation: {orgName}, {regNumber}; Duration: {duration}";
        }
    }
}
