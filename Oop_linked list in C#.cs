using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        LinkedList<int> myList = new LinkedList<int>();
        //Thêm phần tử vào danh sách
        myList.AddFirst(new LinkedListNode<int>(2));
        myList.AddFirst(new LinkedListNode<int>(6));
        myList.AddLast(new LinkedListNode<int>(7));
        LinkedListNode<int> p = myList.First;
        Console.WriteLine(p.Value);
        LinkedListNode<int> q = p.Next;
        Console.WriteLine(q.Value);
        LinkedListNode<int> f = q.Next;
        Console.WriteLine(f.Value);
    }
}
