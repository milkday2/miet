
namespace cs_lab4
{
    public class TeamsJournalEntry
    {
        public string CollectionName { get; set; }
        public Revision EventCause { get; set; }
        public string SourcePropertyName { get; set; }
        public int SourceRegNumber { get; set; }

        public TeamsJournalEntry(string collectionName, Revision cause, string sourcePropertyName, int sourceRegNumber)
        {
            CollectionName = collectionName;
            EventCause = cause;
            SourcePropertyName = sourcePropertyName;
            SourceRegNumber = sourceRegNumber;
        }


        public override string ToString()
        {
            return $"CollectionName: {CollectionName}, "
                + $"EventCause: {EventCause}, "
                + (EventCause == Revision.Property ? $"SourcePropertyName: {SourcePropertyName}, " : "")
                + $"SourceRegNumber: {SourceRegNumber}";
        }
    }
}
