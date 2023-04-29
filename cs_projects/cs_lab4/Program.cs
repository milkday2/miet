
namespace cs_lab4
{
    class Program
    {
        public static void Main(string[] args)
        {
            KeySelector<string> selector = delegate (ResearchTeam rt)
            {
                return rt.GetHashCode().ToString();
            };

            ResearchTeamCollection<string> teams1 = new ResearchTeamCollection<string>(selector);
            ResearchTeamCollection<string> teams2 = new ResearchTeamCollection<string>(selector);
            teams1.CollectionName = "collection 1";
            teams2.CollectionName = "collection 2";

            TeamsJournal journal = new TeamsJournal();
            journal.Subscribe<string>(teams1);
            journal.Subscribe<string>(teams2);

            ResearchTeam rt1 = new ResearchTeam("theme1","org1",1,TimeFrame.Year);
            ResearchTeam rt2 = new ResearchTeam("theme2","org1",2,TimeFrame.TwoYears);
            teams1.AddResearchTeams(rt1);
            teams2.AddResearchTeams(rt2);

            rt1.Theme = "new theme 1";
            rt2.Duration = TimeFrame.Long;

            teams1.Remove(rt1);
            rt1.Theme = "another theme 1";
            rt1.Duration = TimeFrame.TwoYears;

            teams2.Replace(rt2,new ResearchTeam());
            rt2.Theme = "new theme 2";
            rt2.Duration = TimeFrame.Year;
            Console.WriteLine(journal);

        }


    }
}
