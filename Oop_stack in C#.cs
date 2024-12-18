using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
class Program
{
    static void Main(string[] args)
    {
        //Kiểu ngăn xếp
        Stack<int> myStack = new Stack<int>();
        myStack.Push(2);
        myStack.Push(5);
        myStack.Push(6);
        Console.WriteLine(myStack.Pop());
        Console.WriteLine(myStack.Pop());
        Console.WriteLine(myStack.Pop());
    }
}
