
namespace cs_lab5
{
    interface INameAndCopy
    {
        string Name { get; set; }
        object DeepCopy();
    }
}
