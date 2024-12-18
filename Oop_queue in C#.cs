class Program
{
    static void Main(string[] args)
    {
        //Kiểu hàng đợi
        Queue<int> myQueue = new Queue<int>();
        myQueue.Enqueue(7);
        myQueue.Enqueue(3);
        myQueue.Enqueue(8);
        Console.WriteLine(myQueue.Dequeue());
        Console.WriteLine(myQueue.Dequeue());
        Console.WriteLine(myQueue.Dequeue());
    }
}
