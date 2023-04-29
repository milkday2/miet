
namespace cs_lab4
{
    interface INameAndCopy
    {
        string Name { get; set; }
        object DeepCopy();
    }
}
