namespace cs_lab1
{
    public class Paper
    {
        public string Title { get; set; }
        public Person Author { get; set; }
        public DateOnly Date { get; set; }

        public Paper(string Title, Person Author, DateOnly Date)
        {
            this.Title = Title;
            this.Author = Author;
            this.Date = Date;
        }

        public Paper() : this("-", new Person(), new DateOnly()) { }

        public override string ToString()
        {
            return $"{Title}, {Author.ToShortString()}, {Date:d.M.yyyy}";
        }
    }
}
