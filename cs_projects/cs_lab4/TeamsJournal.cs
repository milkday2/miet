
namespace cs_lab4
{
    public class TeamsJournal
    {
        private List<TeamsJournalEntry> journal;

        public TeamsJournal(){
            journal = new List<TeamsJournalEntry>();
        }
        
        public void Subscribe<TKey>(ResearchTeamCollection<TKey> publisher){
            publisher.ResearchTeamsChanged += this.rtc_ResearchTeamsChanged;
        }

        public void rtc_ResearchTeamsChanged(Object sender, ResearchTeamsChangedEventArgs e)
        {
            journal.Add(new TeamsJournalEntry(e.CollectionName, e.EventCause, e.SourcePropertyName, e.SourceRegNumber));
        }

        public override string ToString()
        {
            string journalString = "";
            foreach (TeamsJournalEntry tj in journal)
                journalString += tj.ToString() + "\n";
            return journalString;
        }
    }
}
