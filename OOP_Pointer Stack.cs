using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ElementType = System.Int32;
public static class Global
{
    public static int None = -99999999;
    public static Node CreateNode(ElementType x)
    {
        Node p = new Node();
        p.info = x;
        p.pNext = null;
        return p;
    }
}
public class Node
{
    public ElementType info;
    public Node pNext;
}

public class Stack
{
    public Node pTop;
    
    public void InitStack()
    {
        this.pTop = null;
    }
    public void Push(Node x) {
        if (this.IsEmptyStack() == 1) this.pTop = x;
        else
        {
            x.pNext = this.pTop;
            this.pTop = x;
        }
    }
    public Node Pop()
    {
        if(this.IsEmptyStack() == 1)
        {
            return null;
        }
        else
        {
            //trong c# khong can giai phong vung nho con tro->do no tu dong gom rac
            Node res = Global.CreateNode(this.pTop.info);
            this.pTop = this.pTop.pNext;
            return res;
        }
    }
    public int IsEmptyStack()
    {
        if (this.pTop == null)
        {
            return 1;
        }
        return 0;
    }
        
    public Node Top()
    {
        return this.pTop;
    }
    public void PrintStack()
    {
        for (Node p = this.pTop; p != null; p = p.pNext)
        {
            Console.Write(p.info + ", ");
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        Stack s = new Stack();
        s.InitStack();
        s.Push(Global.CreateNode(1));
        s.Push(Global.CreateNode(2));
        s.Push(Global.CreateNode(3));
        s.PrintStack();
        Console.WriteLine();
        Console.WriteLine(s.Top().info);
        s.Pop();
        Console.WriteLine();
        s.PrintStack();
    }
}
