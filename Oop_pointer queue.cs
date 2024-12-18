using System;
using System.Collections;
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

public class Queue
{
    public Node pHead;
    public Node pTail;
    public void InitQueue()
    {
        this.pHead = null;
        this.pTail = null;
    }
    public void EnQueue(Node x)
    {
        if(x == null)
        {
            Console.WriteLine("Node chen vao la null nen khong chen duoc!");
            return;
        }
        else
        {
            if (this.IsEmptyQueue() == 1)
            {
                //queue rong luc chua chen
                this.pHead = x;
                this.pTail = x;
            }
            else
            {
                //queue dang co 1 phan tu tro len 
                this.pTail.pNext = x;
                this.pTail = x;
            }
        }
    }
    public Node DeQueue()
    {
        if (this.IsEmptyQueue() == 1)
        {
            Console.WriteLine("Queue rong khong DeQueue duoc!");
            return null;
        }
        else
        {
            //trong c# khong can giai phong vung nho con tro->do no tu dong gom rac
            Node res = Global.CreateNode(this.pHead.info);
            this.pHead = this.pHead.pNext;
            if (this.pHead == null) this.pTail = null;
            return res;
        }
    }
    public int IsEmptyQueue()
    {
        if (this.pHead == null)
        {
            return 1;
        }
        return 0;
    }

    public ElementType Front()
    {
        if (this.IsEmptyQueue() == 1)
        {
            return Global.None;
        }
        return this.pHead.info;
    }
    public void PrintQueue()
    {
        for (Node p = this.pHead; p != null; p = p.pNext)
        {
            Console.Write(p.info + ", ");
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        Queue q = new Queue();
        q.InitQueue();
        q.EnQueue(Global.CreateNode(1));
        q.EnQueue(Global.CreateNode(2));
        q.EnQueue(Global.CreateNode(3));
        q.PrintQueue();
        Console.WriteLine();
        Console.WriteLine(q.Front());
        q.DeQueue();
        Console.WriteLine();
        q.PrintQueue();
    }
}
