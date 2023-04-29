using System.ComponentModel;

namespace cs_lab4
{

    public delegate TKey KeySelector<TKey>(ResearchTeam rt);
    public delegate void ResearchTeamsChangedHandler(object source, ResearchTeamsChangedEventArgs args);

    public class ResearchTeamCollection<TKey>
    {
        private Dictionary<TKey, ResearchTeam> researchTeams;
        private KeySelector<TKey> keySelector;
        public event ResearchTeamsChangedHandler ResearchTeamsChanged;
        public string CollectionName { get; set; }

        public Dictionary<TKey, ResearchTeam> teamsDictionary { get { return researchTeams; } }


        public ResearchTeamCollection(KeySelector<TKey> selector)
        {
            researchTeams = new Dictionary<TKey, ResearchTeam>();
            keySelector = selector;
        }


        public void AddResearchTeams(params ResearchTeam[] teams)
        {
            TKey key;
            foreach (ResearchTeam team in teams)
            {
                key = keySelector(team);
                researchTeams.Add(key, team);
                researchTeams[key].PropertyChanged += this.rt_PropertyChanged;
            }
        }

        public void rt_PropertyChanged(Object sender, PropertyChangedEventArgs e)
        {
            ResearchTeam rt_sender = sender as ResearchTeam;
            ResearchTeamsChanged?.Invoke(this, new ResearchTeamsChangedEventArgs(this.CollectionName, Revision.Property, e.PropertyName, rt_sender.RegNumber));
        }


        public bool Remove(ResearchTeam rt)
        {
            bool removed = false;
            foreach (KeyValuePair<TKey, ResearchTeam> kv in researchTeams)
            {
                if (kv.Value.Equals(rt))
                {
                    researchTeams[kv.Key].PropertyChanged -= this.rt_PropertyChanged;
                    researchTeams.Remove(kv.Key);
                    ResearchTeamsChanged?.Invoke(this, new ResearchTeamsChangedEventArgs(this.CollectionName, Revision.Remove, "", rt.RegNumber));
                    removed = true;
                }
            }
            return removed;
        }


        public bool Replace(ResearchTeam rtold, ResearchTeam rtnew)
        {
            bool replaced = false;
            foreach (KeyValuePair<TKey, ResearchTeam> kv in researchTeams)
            {
                if (kv.Value.Equals(rtold))
                {
                    researchTeams[kv.Key].PropertyChanged -= this.rt_PropertyChanged;
                    researchTeams[kv.Key] = rtnew;
                    researchTeams[kv.Key].PropertyChanged += this.rt_PropertyChanged;
                    ResearchTeamsChanged?.Invoke(this, new ResearchTeamsChangedEventArgs(this.CollectionName, Revision.Replace, "", rtold.RegNumber));
                    replaced = true;
                }
            }
            return replaced;
        }


        public override string ToString()
        {
            string result = "";
            foreach (KeyValuePair<TKey, ResearchTeam> entry in researchTeams)
                result += $"Key: {entry.Key}; {entry.Value.ToString()}\n";
            return result;
        }


        public string ToShortString()
        {
            string result = "";
            foreach (KeyValuePair<TKey, ResearchTeam> entry in researchTeams)
            {
                ResearchTeam tmp = entry.Value;
                result += $"Key: {entry.Key}; {tmp.ToShortString()}; Number of members: {tmp.Members.Count}; Number of publications: {tmp.Publications.Count}\n";
            }
            return result;
        }


        public DateTime LatestPublication
        {
            get
            {
                if (researchTeams.Count == 0)
                    return new DateTime();
                return researchTeams.Values.Where(obj => !Object.ReferenceEquals(obj.LatestPublication, null)).Max(obj => obj.LatestPublication.Date);
            }
        }


        public IEnumerable<KeyValuePair<TKey, ResearchTeam>> TimeFrameGroup(TimeFrame value)
        {
            return researchTeams.Where(obj => obj.Value.Duration == value);
        }


        public IEnumerable<IGrouping<TimeFrame, KeyValuePair<TKey, ResearchTeam>>> GroupByDuration
        {
            get
            {
                return researchTeams.GroupBy(obj => obj.Value.Duration);
            }
        }
    }
}


