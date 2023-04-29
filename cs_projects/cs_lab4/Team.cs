
namespace cs_lab4
{
    public class Team : INameAndCopy
    {
        protected string orgName;
        protected int regNumber;


        public Team(string OrgName, int RegNumber)
        {
            orgName = OrgName;
            regNumber = RegNumber;
        }


        public Team() : this("orgName", 0) { }


        public string Name
        {
            get { return orgName; }
            set { orgName = value; }
        }


        public int RegNumber
        {
            get { return regNumber; }
            set
            {
                if (value <= 0)
                    throw new ArgumentException("Registration number must be a positive integer");
                regNumber = value;
            }
        }


        public virtual object DeepCopy()
        {
            return new Team(orgName, regNumber);
        }


        public override bool Equals(object? obj)
        {
            Team? teamObj = obj as Team;
            if (Object.ReferenceEquals(teamObj, null))
                return false;
            return teamObj.Name.Equals(orgName) && teamObj.RegNumber == regNumber;
        }


        public static bool operator ==(Team left, Team right)
        {
            return left.Equals(right);
        }


        public static bool operator !=(Team left, Team right)
        {
            return !(left.Equals(right));
        }


        public override int GetHashCode()
        {
            return orgName.GetHashCode() + regNumber;
        }


        public override string ToString()
        {
            return $"{orgName}, {regNumber}";
        }
    }
}
