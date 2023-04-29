namespace cs_lab1
{
    public class Person
    {
        private string name;
        private string surname;
        private DateOnly birthday;

        public Person(string Name, string Surname, DateOnly Birthday)
        {
            name = LabUtils.NameFormat(Name);
            surname = LabUtils.NameFormat(Surname);
            birthday = Birthday;
        }

        public Person():this("-","-",new DateOnly()) {}

        public string Name
        {
            get { return name; }
            set
            {
                name = LabUtils.NameFormat(value);
            }
        }

        public string Surname
        {
            get { return surname; }
            set
            {
                surname = LabUtils.NameFormat(value);
            }
        }

        public DateOnly Birthday
        {
            get { return birthday; }
            set { birthday = value; }
        }

        public int BirthYear
        {
            get { return birthday.Year; }
            set
            {
                birthday = new DateOnly(value, birthday.Month, birthday.Day);
            }
        }

        public override string ToString()
        {
            return $"{name} {surname}, {birthday:d.M.yyyy}";
        }

        public string ToShortString()
        {
            return $"{name} {surname}";
        }
    }
}
