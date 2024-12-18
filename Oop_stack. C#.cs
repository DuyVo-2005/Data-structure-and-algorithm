using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Generic_Demo
{
    class MyStack<T>
    {
        private T[] a = new T[10];//mang a
        private int top = -1;
        public void Push(T x)
        {
            this.a[top + 1] = x;
            this.top++;
        }
        public T Top()
        {
            return this.a[this.top];
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            MyStack<int> mySt = new MyStack<int>();
            mySt.Push(3);
            mySt.Push(4);
            mySt.Push(5);
            Console.WriteLine(mySt.Top());
            MyStack<string> mySt1 = new MyStack<string>();
            mySt1.Push("Binh");
            mySt1.Push("Hung");
            mySt1.Push("Nam");
            Console.WriteLine(mySt1.Top());
        }
    }
}
