namespace cs_lab1
{

    public static class LabUtils
    {
        public static string NameFormat(string name)
        {
            if (name.Length == 0)
                return name;
            char[] n = name.ToLower().ToCharArray();
            n[0] = char.ToUpper(n[0]);
            for (int i = 1; i < n.Length; i++)
            {
                if (!char.IsLetter(n[i - 1]) && char.IsLetter(n[i]))
                    n[i] = char.ToUpper(n[i]);
            }

            return new string(n);
        }


        public static T[] AddToArray<T>(T[] source, params T[] newElements)where T:new()
        {
            int slen = source.Length;
            int nlen = newElements.Length;
            T[] newArray = new T[slen + nlen];

            int i = 0;
            foreach (T e in source)
                newArray[i++] = e;
            i = slen;
            foreach (T e in newElements)
                newArray[i++] = e;

            return newArray;

        }
    }
}

