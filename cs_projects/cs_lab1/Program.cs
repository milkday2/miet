using System.Diagnostics;
namespace cs_lab1
{
    class Program
    {

        public static void Main(string[] args)
        {
            if (args.Length == 0)
            {
                Console.WriteLine("invalid argument");
                return;
            }

            switch (Convert.ToInt16(args[0]))
            {
                // ResearchTeam test
                case 1:
                    ResearchTeam test = new ResearchTeam();
                    Console.WriteLine($"Default values: {test.ToShortString()}");
                    Console.Write("Theme: ");
                    test.Theme = Console.ReadLine();
                    Console.Write("Organisation: ");
                    test.OrgName = Console.ReadLine();
                    Console.Write("Registration number: ");
                    test.RegNumber = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Duration: ");
                    TimeFrame input;
                    Enum.TryParse(Console.ReadLine(), true, out input);
                    test.Duration = input;

                    Console.WriteLine(test.ToShortString());
                    Console.WriteLine($"year: {test[TimeFrame.Year]}, twoyears: {test[TimeFrame.TwoYears]}, long: {test[TimeFrame.Long]}");

                    Paper[] newPapers = new Paper[] { new Paper("paper1", new Person(), new DateOnly(1999, 10, 10)), new Paper("paper2", new Person(), new DateOnly(2002, 1, 12)) };
                    test.Publications = newPapers;
                    Console.WriteLine($"ToString(): {test.ToString()}");

                    test.AddPapers(new Paper("paper3", new Person(), new DateOnly(1945, 4, 5)), new Paper("paper4", new Person(), new DateOnly(2015, 11, 12)));
                    Console.WriteLine($"After AddPapers(): {test.ToString()}");

                    Console.WriteLine($"Latest publication: {test.LatestPaper.ToString()}");
                    break;

                // array time test
                case 2:
                    Console.Write("Number of rows then columns separated by (space,comma,; or /): ");
                    string[] strInp = Console.ReadLine().Split(new char[] { ' ', ',', ';', '/' }, 2);
                    int nrows = Convert.ToInt32(strInp[0]);
                    int ncolumns = Convert.ToInt32(strInp[1]);
                    Console.WriteLine($"Rows: {nrows} Columns: {ncolumns}");
                    Console.WriteLine($"{nrows * ncolumns} elements");

                    Paper[] array1D = new Paper[nrows * ncolumns];
                    for (int i = 0; i < nrows * ncolumns; i++)
                        array1D[i] = new Paper();
                    Paper[,] array2D = new Paper[nrows, ncolumns];
                    Paper[][] arrayJagged = new Paper[nrows][];
                    for (int i = 0; i < nrows; i++)
                        arrayJagged[i] = new Paper[ncolumns];
                    for (int i = 0; i < nrows; i++)
                        for (int j = 0; j < ncolumns; j++)
                        {
                            array2D[i, j] = new Paper();
                            arrayJagged[i][j] = new Paper();
                        }

                    Stopwatch timer=new Stopwatch();
                    int elementCount=nrows*ncolumns;
                    int k,l;

                    //1D array
                    timer.Start();
                    for (k= 0; k < elementCount; k++)
                    {
                        array1D[k].Title = "test";
                    }
                    timer.Stop();
                    Console.WriteLine($"1D array: {timer.Elapsed}");
                    timer.Reset();

                    //2D array
                    timer.Start();
                    for (k = 0; k < nrows; k++)
                        for (l = 0; l < ncolumns; l++)
                        {
                            array2D[k, l].Title = "test";
                        }
                    timer.Stop();
                    Console.WriteLine($"2D array: {timer.Elapsed}");
                    timer.Reset();

                    //Jagged array
                    timer.Start();
                    for (k = 0; k < nrows; k++)
                        for (l = 0; l < ncolumns; l++)
                        {
                            arrayJagged[k][l].Title = "test";
                        }
                    timer.Stop();
                    Console.WriteLine($"Jagged array: {timer.Elapsed}");
                    timer.Reset();

                    // Accessing last element
                    Console.WriteLine("\nAccessing last element:");
                    timer.Start();
                    array1D[nrows*ncolumns-1].Title="test2";
                    timer.Stop();
                    Console.WriteLine($"1D array: {timer.ElapsedTicks} ticks");
                    timer.Reset();

                    timer.Start();
                    array2D[nrows-1,ncolumns-1].Title="test2";
                    timer.Stop();
                    Console.WriteLine($"2D array: {timer.ElapsedTicks} ticks");
                    timer.Reset();

                    timer.Start();
                    arrayJagged[nrows-1][ncolumns-1].Title="test2";
                    timer.Stop();
                    Console.WriteLine($"Jagged array: {timer.ElapsedTicks} ticks");
                    timer.Reset();

                    break;

                default: Console.WriteLine("invalid argument"); break;
            }

        }

    }

}
