
namespace cs_lab5
{
    class Program
    {
        public static void Main(string[] args)
        {
            ResearchTeam team1 = new ResearchTeam("theme", "org", 10, TimeFrame.Year);
            team1.AddPapers(new Paper("title", new Person("name", "surname", new DateTime(1999, 1, 1)), new DateTime(2020, 2, 2)));
            ResearchTeam copy = team1.DeepCopy();
            Console.WriteLine($"Original:\n{team1}");
            Console.WriteLine($"Copy:\n{copy}");


            ResearchTeam team2 = new ResearchTeam("theme2", "org2", 20, TimeFrame.TwoYears);
            Console.Write("\nInput filename:");
            string filename = Console.ReadLine();
            if (File.Exists(filename))
            {
                if (!team2.Load(filename))
                {
                    Console.WriteLine("Failed to load from " + filename);
                    return;
                }
                Console.WriteLine("\nLoaded object from " + filename + ":\n" + team2);
            }
            else
                Console.WriteLine("File doesn't exist. New file will be created");

            Console.WriteLine("\nInput a publication to add:");
            while (!team2.AddPaperFromConsole())
                Console.WriteLine("Try again");

            if (!team2.Save(filename))
            {
                Console.WriteLine("Failed to save to " + filename);
                return;
            }
            Console.WriteLine("\nSaved object to " + filename + ":\n" + team2);


            if (!ResearchTeam.Load(filename, team2))
            {
                Console.WriteLine("Failed to load using static method");
                return;
            }
            Console.WriteLine("\nLoaded object from " + filename + " using static method:\n" + team2);
            Console.WriteLine("\nInput a publication to add:");
            while (!team2.AddPaperFromConsole())
                Console.WriteLine("Try again");

            if (!ResearchTeam.Save(filename, team2))
            {
                Console.WriteLine("Failed to save using static method");
                return;
            }
            Console.WriteLine("\nSaved object to " + filename + " using static method:\n" + team2);
        }


    }
}
