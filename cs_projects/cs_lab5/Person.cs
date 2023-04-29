
namespace cs_lab5
{
    [Serializable]
    public class Person
    {
        private string name;
        private string surname;
        private DateTime birthday;


        public Person(string Name, string Surname, DateTime Birthday)
        {
            name = LabUtils.NameFormat(Name);
            surname = LabUtils.NameFormat(Surname);
            birthday = Birthday;
        }


        public Person() : this("-", "-", new DateTime()) { }


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


        public DateTime Birthday
        {
            get { return birthday; }
            set { birthday = value; }
        }


        public int BirthYear
        {
            get { return birthday.Year; }
            set
            {
                birthday = new DateTime(value, birthday.Month, birthday.Day);
            }
        }


        public override string ToString()
        {
            return $"{name} {surname} {birthday:d.M.yyyy}";
        }


        public string ToShortString()
        {
            return $"{name} {surname}";
        }


        public override bool Equals(object? obj)
        {
            Person? personObj = obj as Person;
            if (Object.ReferenceEquals(personObj, null))
                return false;
            return personObj.Name.Equals(name) && personObj.Surname.Equals(surname) && personObj.Birthday.Equals(birthday);
        }


        public static bool operator ==(Person left, Person right)
        {
            return left.Equals(right);
        }


        public static bool operator !=(Person left, Person right)
        {
            return !(left.Equals(right));
        }


        public override int GetHashCode()
        {
            return ((13 * 7 + name.GetHashCode()) * 7 + surname.GetHashCode()) * 7 + birthday.GetHashCode();
        }


        public virtual object DeepCopy()
        {
            return new Person(name, surname, birthday);
        }
    }
}

