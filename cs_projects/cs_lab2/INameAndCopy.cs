namespace cs_lab2
{
    interface INameAndCopy
    {
        string Name { get; set; }
        object DeepCopy();
    }
}
