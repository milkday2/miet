
namespace cs_lab5
{
    public enum Revision
    {
        Remove,
        Replace,
        Property
    }

    public class ResearchTeamsChangedEventArgs : EventArgs
    {
        public string CollectionName { get; set; }
        public Revision EventCause { get; set; }
        public string SourcePropertyName { get; set; }
        public int SourceRegNumber { get; set; }

        public ResearchTeamsChangedEventArgs(string collectionName, Revision cause, string sourcePropertyName, int sourceRegNumber)
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
                + $"{(EventCause == Revision.Property ? $"SourcePropertyName: {SourcePropertyName}, " : "")}"
                + $"SourceRegNumber: {SourceRegNumber}";
        }
    }
}
