using System.ComponentModel;
using System.Runtime.Serialization.Formatters.Binary;
using System.Globalization;

namespace cs_lab5
{
    [Serializable]
    public enum TimeFrame
    {
        Year, TwoYears, Long
    }

    [Serializable]
    public class ResearchTeam : Team, INotifyPropertyChanged
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


        public void AddPapers(params Paper[] newPapers)
        {
            publications.AddRange(newPapers);
        }


        public void AddMembers(params Person[] newMembers)
        {
            members.AddRange(newMembers);
        }

        public void CopyFrom(ResearchTeam source)
        {
            this.theme = source.Theme;
            this.orgName = source.Name;
            this.regNumber = source.RegNumber;
            this.duration = source.Duration;
            this.members = new List<Person>();
            this.publications = new List<Paper>();
            foreach (Person p in source.Members)
                this.members.Add((Person)p.DeepCopy());
            foreach (Paper p in source.Publications)
                this.publications.Add((Paper)p.DeepCopy());
        }

        public override ResearchTeam DeepCopy()
        {
            MemoryStream mstream = new MemoryStream();
            BinaryFormatter formatter = new BinaryFormatter();
            formatter.Serialize(mstream, this);
            mstream.Position = 0;
            ResearchTeam copy = (ResearchTeam)formatter.Deserialize(mstream);
            return copy;
        }

        public bool Save(string filename)
        {
            try
            {
                using (Stream file = File.Open(filename, FileMode.Create, FileAccess.Write))
                {
                    BinaryFormatter formatter = new BinaryFormatter();
                    formatter.Serialize(file, this);
                }
            }
            catch
            {
                return false;
            }
            return true;
        }

        public bool Load(string filename)
        {
            ResearchTeam temp;
            try
            {
                using (Stream file = File.Open(filename, FileMode.Open, FileAccess.Read))
                {
                    BinaryFormatter formatter = new BinaryFormatter();
                    temp = (ResearchTeam)formatter.Deserialize(file);
                }
            }
            catch
            {
                return false;
            }
            this.CopyFrom(temp);
            return true;
        }

        public static bool Save(string filename, ResearchTeam source)
        {
            try
            {
                using (Stream file = File.Open(filename, FileMode.Create, FileAccess.Write))
                {
                    BinaryFormatter formatter = new BinaryFormatter();
                    formatter.Serialize(file, source);
                }
            }
            catch
            {
                return false;
            }
            return true;
        }

        public static bool Load(string filename, ResearchTeam destination)
        {
            ResearchTeam temp;
            try
            {
                using (Stream file = File.Open(filename, FileMode.Open, FileAccess.Read))
                {
                    BinaryFormatter formatter = new BinaryFormatter();
                    temp = (ResearchTeam)formatter.Deserialize(file);
                }
            }
            catch
            {
                return false;
            }
            destination.CopyFrom(temp);
            return true;
        }

        public bool AddPaperFromConsole()
        {
            Console.WriteLine("Format:\n"
                    + "[title] [day/month/year of publication] [author name] [author surname] [day/month/year author's birthday]");
            DateTime birthday;
            DateTime date;
            string[] input = Console.ReadLine().Split(' ');
            if (input.Count() != 5)
            {
                Console.WriteLine("Incorrect number of arguments");
                return false;
            }
            string[] dateFormats = { "d/M/yyyy", "dd/M/yyyy", "d/MM/yyyy", "dd/MM/yyyy" };
            if (!DateTime.TryParseExact(input[1], dateFormats, CultureInfo.InvariantCulture, DateTimeStyles.None, out date))
            {
                Console.WriteLine("Invalid date format");
                return false;
            }
            if (!DateTime.TryParseExact(input[4], dateFormats, CultureInfo.InvariantCulture, DateTimeStyles.None, out birthday))
            {
                Console.WriteLine("Invalid date format");
                return false;
            }
            this.Publications.Add(new Paper(input[0], new Person(input[2], input[3], birthday), date));
            return true;
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

        public override string ToString()
        {
            string result = $"Theme: {theme}; Organisation: {orgName}, {regNumber}; Duration: {duration};\nMembers: ";
            if (members.Count == 0)
                result += "No members";
            else
            {
                string memb = members[0].ToString();
                for (int i = 1; i < members.Count; i++)
                    memb += $"; {members[i].ToString()}";
                result += memb;
            }

            result += "\nPublications: ";
            if (publications.Count == 0)
                return result += "No Publications";

            string papers = publications[0].ToString();
            for (int i = 1; i < publications.Count; i++)
                papers += $"; {publications[i].ToString()}";
            return result + papers;
        }


        public string ToShortString()
        {
            return $"Theme: {theme}; Organisation: {orgName}, {regNumber}; Duration: {duration}";
        }
    }

}

