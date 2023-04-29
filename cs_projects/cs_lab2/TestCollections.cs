using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;

namespace cs_lab2
{
    public delegate KeyValuePair<TKey, TValue> GenerateElement<TKey, TValue>(int j);

    public class TestCollections<TKey, TValue>
    {
        private List<TKey> keyList;
        private List<string> strValueList;
        private Dictionary<TKey, TValue> tDict;
        private Dictionary<string, TValue> strKeyDict;
        private GenerateElement<TKey, TValue> generate;
        private int count;

        public TestCollections(int count, GenerateElement<TKey, TValue> generateElement)
        {
            if (count <= 0)
                this.count = 1;
            this.count = count;
            keyList = new List<TKey>();
            strValueList = new List<string>();
            tDict = new Dictionary<TKey, TValue>();
            strKeyDict = new Dictionary<string, TValue>();
            generate = generateElement;
            KeyValuePair<TKey, TValue> generated;
            for (int i = 0; i < count; i++)
            {
                generated = generate(i);
                keyList.Add(generated.Key);
                strValueList.Add(generated.Value.ToString());
                tDict.Add(generated.Key, generated.Value);
                strKeyDict.Add(generated.Key.ToString(), generated.Value);
            }
        }


        public void searchKeyList()
        {
            TKey first = keyList.First();
            TKey middle = keyList[count / 2];
            TKey last = keyList.Last();
            TKey nonExist = generate(count + 1).Key;


            Stopwatch timer = new Stopwatch();
            //warmup
            keyList.Contains(first);
            timer.Start();
            timer.Stop();

            //measuring
            timer.Start();
            keyList.Contains(first);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            keyList.Contains(middle);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            keyList.Contains(last);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            keyList.Contains(nonExist);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
        }


        public void searchStrValueList()
        {
            string first = strValueList.First();
            string middle = strValueList[count / 2];
            string last = strValueList.Last();
            string nonExist = generate(count + 1).Value.ToString();


            Stopwatch timer = new Stopwatch();
            //warmup
            strValueList.Contains(first);
            timer.Start();
            timer.Stop();

            //measuring
            timer.Start();
            strValueList.Contains(first);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            strValueList.Contains(middle);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            strValueList.Contains(last);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            strValueList.Contains(nonExist);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
        }


        public void searchTDictByKey()
        {
            TKey first = tDict.Keys.ElementAt(0);
            TKey middle = tDict.Keys.ElementAt(count / 2);
            TKey last = tDict.Keys.ElementAt(count - 1);
            TKey nonExist = generate(count + 1).Key;


            Stopwatch timer = new Stopwatch();
            //warmup
            tDict.ContainsKey(first);
            timer.Start();
            timer.Stop();

            //measuring
            timer.Start();
            tDict.ContainsKey(first);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            tDict.ContainsKey(middle);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            tDict.ContainsKey(last);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            tDict.ContainsKey(nonExist);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
        }


        public void searchStrKeyDictByKey()
        {
            string first = strKeyDict.Keys.ElementAt(0);
            string middle = strKeyDict.Keys.ElementAt(count / 2);
            string last = strKeyDict.Keys.ElementAt(count - 1);
            string nonExist = generate(count + 1).Key.ToString();


            Stopwatch timer = new Stopwatch();
            //warmup
            strKeyDict.ContainsKey(first);
            timer.Start();
            timer.Stop();

            //measuring
            timer.Start();
            strKeyDict.ContainsKey(first);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            strKeyDict.ContainsKey(middle);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            strKeyDict.ContainsKey(last);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            strKeyDict.ContainsKey(nonExist);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
        }


        public void searchTDictByValue()
        {
            TValue first = tDict.Values.ElementAt(0);
            TValue middle = tDict.Values.ElementAt(count / 2);
            TValue last = tDict.Values.ElementAt(count - 1);
            TValue nonExist = generate(count + 1).Value;


            Stopwatch timer = new Stopwatch();
            //warmup
            tDict.ContainsValue(first);
            timer.Start();
            timer.Stop();

            //measuring
            timer.Start();
            tDict.ContainsValue(first);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            tDict.ContainsValue(middle);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            tDict.ContainsValue(last);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
            timer.Reset();

            timer.Start();
            tDict.ContainsValue(nonExist);
            timer.Stop();
            Console.WriteLine(timer.Elapsed);
        }


    }
}

