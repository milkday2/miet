using System.ComponentModel;

namespace cs_lab4
{

    public enum TimeFrame
    {
        Year, TwoYears, Long
    }

    public class ResearchTeam : Team, INameAndCopy, INotifyPropertyChanged
    {
        private string theme;
        private TimeFrame duration;
        private List<Person> members;
        private List<Paper> publications;

        public event PropertyChangedEventHandler PropertyChanged;


        public ResearchTeam(string Theme, string OrgName, int RegNumber, TimeFrame Duration) : base(OrgName, RegNumber)
        {
            theme = Theme;
            duration = Duration;
            publications = new List<Paper>();
            members = new List<Person>();
        }


        public ResearchTeam() : this("theme", "orgName", 0, TimeFrame.Year) { }


        public string Theme
        {
            get { return theme; }
            set
            {
                theme = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Theme"));
            }
        }


        public TimeFrame Duration
        {
            get { return duration; }
            set
            {
                duration = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Duration"));
            }
        }


        public List<Person> Members
        {
            get { return members; }
            set { members = value; }
        }


        public List<Paper> Publications
        {
            get { return publications; }
            set { publications = value; }
        }


        public Paper? LatestPublication
        {
            get
            {
                if (publications.Count == 0)
                    return null;
                return publications.MaxBy(obj => obj.Date);
            }
        }


        public Team Base
        {
            get { return new Team(orgName, regNumber); }
            set
            {
                orgName = value.Name;
                regNumber = value.RegNumber;
            }
        }


        public bool this[TimeFrame index]
        {
            get
            {
                return index == duration;
            }
        }


        public void AddPapers(params Paper[] newPapers)
        {
            publications.AddRange(newPapers);
        }


        public void AddMembers(params Person[] newMembers)
        {
            members.AddRange(newMembers);
        }


        public override string ToString()
        {
            string result = $"Theme: {theme}; Organisation: {orgName}, {regNumber}; Duration: {duration};\nMembers: ";
            if (members.Count == 0)
                result += "No members";
            else
            {
                string memb = members[0].ToShortString();
                for (int i = 1; i < members.Count; i++)
                    memb += $", {members[i].ToShortString()}";
                result += memb;
            }

            result += "\nPublications: ";
            if (publications.Count == 0)
                return result += "No Publications";

            string papers = publications[0].Title;
            for (int i = 1; i < publications.Count; i++)
                papers += $", {publications[i].Title}";
            return result + papers;
        }


        public string ToShortString()
        {
            return $"Theme: {theme}; Organisation: {orgName}, {regNumber}; Duration: {duration}";
        }

        public override bool Equals(object? obj)
        {
            ResearchTeam? rtObj = obj as ResearchTeam;
            if (Object.ReferenceEquals(rtObj, null))
                return false;
            bool eql = Name.Equals(rtObj.Name) && RegNumber == rtObj.RegNumber && theme.Equals(rtObj.Theme) && duration == rtObj.Duration;
            if (!eql)
                return false;
            if (!(members.Count == rtObj.Members.Count && publications.Count == rtObj.Publications.Count))
                return false;
            for (int i = 0; i < members.Count; i++)
            {
                if (!members.ElementAt(i).Equals(rtObj.Members.ElementAt(i)))
                    return false;
            }
            for (int i = 0; i < publications.Count; i++)
            {
                if (!publications.ElementAt(i).Equals(rtObj.Publications.ElementAt(i)))
                    return false;
            }
            return true;
        }


        public override object DeepCopy()
        {
            ResearchTeam copy = new ResearchTeam(theme, orgName, regNumber, duration);
            copy.Members = new List<Person>(members.Count);
            copy.Publications = new List<Paper>(publications.Count);
            for (int i = 0; i < members.Count; i++)
                copy.Members[i] = (Person)members[i].DeepCopy();
            for (int i = 0; i < publications.Count; i++)
                copy.Publications[i] = (Paper)publications[i].DeepCopy();
            return copy;
        }

        public override int GetHashCode()
        {
            int hash = 13;
            hash = (hash * 7) + orgName.GetHashCode();
            hash = (hash * 7) + regNumber.GetHashCode();
            foreach (Person p in members)
                hash = (hash * 7) + p.GetHashCode();
            foreach (Paper p in publications)
                hash = (hash * 7) + p.GetHashCode();
            return hash;
        }


        public IEnumerable<Person> NoPublications()
        {
            bool noPublications;
            foreach (Person memb in members)
            {
                noPublications = true;
                foreach (Paper p in publications)
                    if (memb == p.Author) noPublications = false;
                if (noPublications) yield return memb;
            }
        }


        public IEnumerable<Paper> PublInYearRange(int yrs)
        {
            int days = yrs * 365;
            double timespan;
            DateTime now = DateTime.Now;
            foreach (Paper p in publications)
            {
                timespan = (now - p.Date).TotalDays;
                if (timespan > 0 && timespan < days)
                    yield return p;
            }
        }


        public void PublSortByDate()
        {
            publications.Sort();
        }

        public void PublSortByTitle()
        {
            publications.Sort(new Paper());
        }

        public void PublSortBySurname()
        {
            publications.Sort(new AuthorSurnameComparer());
        }
    }

}

