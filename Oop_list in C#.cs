using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
class Program
{
    static void Main(string[] args)
    {
        List<int> myList = new List<int>();
        //Thêm phần tử vào danh sách
        myList.Add(2);
        myList.Add(5);
        myList.Add(3);
        myList.Add(6);
        myList.Add(1);
        myList.Add(0);
        myList.Add(6);
        //Xuất danh sách
        for (int i = 0; i < myList.Count; i++)
        {
            Console.Write(" " + myList[i]);
        }
        //Xóa phần tử
        myList.Remove(3);
        //Xuất danh sách
        Console.WriteLine();
        for (int i = 0; i < myList.Count; i++)
        {
            Console.Write(" " + myList[i]);
        }
    }
}
