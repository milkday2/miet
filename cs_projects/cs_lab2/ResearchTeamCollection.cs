using System;
using System.Collections.Generic;
using System.Linq;

namespace cs_lab2
{

    public delegate TKey KeySelector<TKey>(ResearchTeam rt);

    public class ResearchTeamCollection<TKey>
    {
        private Dictionary<TKey, ResearchTeam> researchTeams;
        private KeySelector<TKey> keySelector;


        public ResearchTeamCollection(KeySelector<TKey> selector)
        {
            researchTeams = new Dictionary<TKey, ResearchTeam>();
            keySelector = selector;
        }


        public void AddDefaults()
        {
            ResearchTeam team1 = new ResearchTeam("def. theme 1", "def. organisation 1", 1, TimeFrame.Year);
            ResearchTeam team2 = new ResearchTeam("def. theme 2", "def. organisation 2", 2, TimeFrame.TwoYears);
            ResearchTeam team3 = new ResearchTeam("def. theme 3", "def. organisation 3", 3, TimeFrame.Long);
            researchTeams.Add(keySelector(team1), team1);
            researchTeams.Add(keySelector(team2), team2);
            researchTeams.Add(keySelector(team3), team3);
        }


        public void AddResearchTeams(params ResearchTeam[] teams)
        {
            foreach (ResearchTeam team in teams)
            {
                researchTeams.Add(keySelector(team), team);
            }
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


