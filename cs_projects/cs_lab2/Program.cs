using System;
using System.Collections.Generic;

namespace cs_lab2
{

    class Program
    {

        public static void Main(string[] args)
        {
            ResearchTeam sortTest = new ResearchTeam();
            Paper p1 = new Paper("Btitle", new Person("-", "Csurname", new DateTime()), new DateTime(2000, 10, 10));
            Paper p2 = new Paper("Ctitle", new Person("-", "Asurname", new DateTime()), new DateTime(2000, 5, 5));
            Paper p3 = new Paper("Atitle", new Person("-", "Bsurname", new DateTime()), new DateTime(1900, 5, 5));
            sortTest.AddPapers(p1, p2, p3);

            Console.WriteLine("#1");
            sortTest.PublSortByDate();
            foreach (Paper p in sortTest.Publications)
                Console.WriteLine(p);
            Console.WriteLine();

            sortTest.PublSortByTitle();
            foreach (Paper p in sortTest.Publications)
                Console.WriteLine(p);
            Console.WriteLine();

            sortTest.PublSortBySurname();
            foreach (Paper p in sortTest.Publications)
                Console.WriteLine(p);
            Console.WriteLine();


            KeySelector<string> selector = delegate (ResearchTeam rt)
            {
                return rt.GetHashCode().ToString();
            };

            Console.WriteLine("\n#2");
            ResearchTeamCollection<string> rtCollection = new ResearchTeamCollection<string>(selector);
            rtCollection.AddDefaults();
            ResearchTeam someRT = new ResearchTeam("someTheme", "someOrg", 15, TimeFrame.Long);
            someRT.AddPapers(new Paper("someTitle", new Person(), new DateTime(2000, 10, 1)));
            someRT.AddMembers(new Person("someName", "someSurname", new DateTime()));
            rtCollection.AddResearchTeams(sortTest, someRT);
            Console.WriteLine(rtCollection);

            Console.WriteLine("\n#3.1");
            Console.WriteLine(rtCollection.LatestPublication);

            Console.WriteLine("\n#3.2");
            foreach (var obj in rtCollection.TimeFrameGroup(TimeFrame.Year))
                Console.WriteLine($"Key:{obj.Key}; {obj.Value.ToShortString()}");


            Console.WriteLine("\n#3.3");
            foreach (var i in rtCollection.GroupByDuration)
            {
                foreach (var j in i)
                    Console.WriteLine($"{j.Key}: {j.Value.ToShortString()}");
                Console.WriteLine();
            }


            GenerateElement<Team, ResearchTeam> genetator = delegate (int j)
            {
                Team t = new Team($"{j}org", j);
                ResearchTeam rt = new ResearchTeam($"{j}theme", $"{j}org", j, TimeFrame.Year);
                return new KeyValuePair<Team, ResearchTeam>(t, rt);
            };

            Console.WriteLine("\n#4");
            int count;
            Console.Write("count: ");
            count = Convert.ToInt32(Console.ReadLine());
            TestCollections<Team, ResearchTeam> testCollections = new TestCollections<Team, ResearchTeam>(count, genetator);

            Console.WriteLine("(first,middle,last,non)");
            Console.WriteLine("\nList of keys:");
            testCollections.searchKeyList();
            Console.WriteLine("\nList of values as strings:");
            testCollections.searchStrValueList();
            Console.WriteLine("\n(Team:ResearchTeam) Dictionary by key:");
            testCollections.searchTDictByKey();
            Console.WriteLine("\n(String Team:ResearchTeam) Dictionary by key:");
            testCollections.searchStrKeyDictByKey();
            Console.WriteLine("\n(Team:ResearchTeam) Dictionary by value:");
            testCollections.searchTDictByValue();
        }

    }
}
