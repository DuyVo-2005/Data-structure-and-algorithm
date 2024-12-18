using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ElementType = System.Int32;//define
public static class GlobalVariable
{
    public static int None = -99999999;
    public static int MAX = 100;
}
namespace Generic_Demo
{
    class MyStack<T>
    {

        private T[] a;
        private int top;
        public void InitStack()
        {
            this.a = new T[GlobalVariable.MAX];//mang a khoi tao 100 phan tu
            this.top = -1;
        }
        public int IsEmptyStack()
        {
            if (this.top == -1) return 1;
            return 0;
        }

        public int IsFullStack()
        {
            if (this.top == GlobalVariable.MAX - 1) return 1;
            return 0;
        }
        public T Pop()
        {
            this.top--;
            return this.a[this.top + 1];
        }
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
            mySt.InitStack();//khong init -> loi
            if(mySt.IsFullStack() == 0)
                mySt.Push(3);
            if (mySt.IsFullStack() == 0)
                mySt.Push(4);
            if (mySt.IsFullStack() == 0)
                mySt.Push(5);
            Console.WriteLine(mySt.Top());
            MyStack<string> mySt1 = new MyStack<string>();
            mySt1.InitStack();
            if (mySt1.IsFullStack() == 0)
                mySt1.Push("Binh");
            if (mySt1.IsFullStack() == 0)
                mySt1.Push("Hung");
            if (mySt1.IsFullStack() == 0)
                mySt1.Push("Nam");
            Console.WriteLine(mySt1.Top());
            if (mySt1.IsEmptyStack() == 0)
                mySt1.Pop();
            Console.WriteLine(mySt1.Top());
        }
    }
}
