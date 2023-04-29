using System;
using System.Collections.Generic;

namespace cs_lab2
{
    public class Paper : IComparable, IComparer<Paper>
    {
        public string Title { get; set; }
        public Person Author { get; set; }
        public DateTime Date { get; set; }


        public Paper(string Title, Person Author, DateTime Date)
        {
            this.Title = Title;
            this.Author = Author;
            this.Date = Date;
        }


        public Paper() : this("-", new Person(), new DateTime()) { }


        public override string ToString()
        {
            return $"{Title}, {Author.ToShortString()}, {Date:d.M.yyyy}";
        }


        public virtual object DeepCopy()
        {
            return new Paper(Title, (Person)Author.DeepCopy(), Date);
        }


        ///<summary>
        /// Compares by Date
        /// </summary>
        public int CompareTo(object? obj)
        {
            if (obj == null) return 1;
            Paper tmp = obj as Paper;
            if (Object.ReferenceEquals(tmp, null))
                throw new InvalidCastException("Cannot cast obj to Paper");
            else return Date.CompareTo(tmp.Date);
        }

        ///<summary>
        /// Compares by Title
        /// </summary>
        public int Compare(Paper? left, Paper? right)
        {
            bool leftIsNull = Object.ReferenceEquals(left, null);
            bool rightIsNull = Object.ReferenceEquals(right, null);
            if (leftIsNull && rightIsNull)
                return 0;
            if (leftIsNull ^ rightIsNull)
            {
                if (leftIsNull) return -1;
                else return 1;
            }

            return String.Compare(left.Title, right.Title);
        }

    }


    public class AuthorSurnameComparer : IComparer<Paper>
    {
        public int Compare(Paper? left, Paper? right)
        {
            bool leftIsNull = Object.ReferenceEquals(left, null);
            bool rightIsNull = Object.ReferenceEquals(right, null);
            if (leftIsNull && rightIsNull)
                return 0;
            if (leftIsNull ^ rightIsNull)
            {
                if (leftIsNull) return -1;
                else return 1;
            }

            return String.Compare(left.Author.Surname, right.Author.Surname);
        }
    }
}

