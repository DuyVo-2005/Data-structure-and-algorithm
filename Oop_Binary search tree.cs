using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Cây_nhị_phân_tìm_kiếm;
using ElementType = System.Int32;

namespace Cây_nhị_phân_tìm_kiếm;
public static class Global
{
    public static Node CreateNode(ElementType x)
    {
        Node p = new Node();
        if (p == null) return null;
        p.info = x;
        p.pLeft = p.pRight = null;
        return p;
    }
    public static int NONE = -9999999;
}
public class Node
{
    public int info;
    public Node pLeft;
    public Node pRight;
}
public class Tree
{
    public Node root;
    public void InitTree()
    {
        this.root = null;
    }
    public int IsEmptyTree()
    {
        if (this.root == null) return 1;
        return 0;
    }
    public void InsertNode(ref Node root, Node newNode)
    {

        if (root == null) root = newNode;
        else
        {
            if (newNode.info < root.info) InsertNode(ref root.pLeft, newNode);
            else
            {
                if (newNode.info > root.info)
                    InsertNode(ref root.pRight, newNode);
            }
        }
    }
    public void ThayThe(ref Node p, ref Node T)
    {
        if (T.pLeft != null) ThayThe(ref p, ref T.pLeft);
        else
        {
            //tim nut phai nhat ben trai
            p.info = T.info;
            p = T;
            T = T.pRight;
        }
    }
    public void DeleteNode(ref Node root, ElementType node)
    {
        //co thi xoa, khong thi thoi
        if (root == null) return;//trung gia tri co roi thi bo qua
        if (root.info > node)//tim ben trai
            DeleteNode(ref root.pLeft, node);
        else
        {
            if (root.info < node)//tim ben phai
                DeleteNode(ref root.pRight, node);
            else// tim thay x trong cay
            {
                Node p = root;
                if (root.pLeft == null)// co 1 nut con tro den chinh no
                    root = root.pRight;// la nut con phai
                else
                {
                    if (root.pRight == null)
                        root = root.pLeft;//la nut con trai
                    else//TH co 2 nut con chon min ben phai
                        ThayThe(ref p, ref root.pRight);
                }
            }
        }
    }
    public Node SearchNode(Node root, ElementType x)
    {
        Node p = root;
        while (p != null)
        {
            if (x == p.info) return p;
            else
                if (x < p.info) p = p.pLeft;
            else p = p.pRight;
        }
        return null;
    }
    public void PrintTree_PreOrder(Node root)
    {
        if (root != null)
        {
            Console.WriteLine("\n" + root.info);
            PrintTree_PreOrder(root.pLeft);
            PrintTree_PreOrder(root.pRight);
        }
    }
    public void PrintTree_InOrder(Node root)
    {
        if (root != null)
        {
            PrintTree_InOrder(root.pLeft);
            Console.WriteLine("\n" + root.info);
            PrintTree_InOrder(root.pRight);
        }
    }
    public void PrintTree_PostOrder(Node root)
    {
        if (root != null)
        {
            PrintTree_PostOrder(root.pLeft);
            PrintTree_PostOrder(root.pRight);
            Console.WriteLine("\n" + root.info);
        }
    }
    public int HighTree(Node root)
    {

        if (root == null) return 0;
        int hl = HighTree(root.pLeft);
        int hr = HighTree(root.pRight);
        if (hl > hr)
            return (1 + hl);
        else
            return (1 + hr);
    }
    public int CountNode(Node root)
    {
        if (root == null) return 0;
        int nl = CountNode(root.pLeft);
        int nr = CountNode(root.pRight);
        return (1 + nl + nr);
    }
    public int CountNodeLeaf(Node root)
    {
        if (root == null) return 0;
        if (root.pLeft == null && root.pRight == null) return 1;
        int nll = CountNodeLeaf(root.pLeft);
        int nrl = CountNodeLeaf(root.pRight);
        return (nll + nrl);
    }
    public int CountBranchNode(Node root)
    {
        return CountNode(root) - CountNodeLeaf(root) - 1;
        //-1 node goc
    }
    
    public int CountEvenElement(Node root)
    {
        if (root == null) return 0;
        if (root.info % 2 == 0)
            return CountEvenElement(root.pRight) + CountEvenElement(root.pLeft) + 1;
        else
            return CountEvenElement(root.pRight) + CountEvenElement(root.pLeft);
    }
    public int SumNodeKey(Node root)
    {
        if (root == null) return 0;
        return root.info + SumNodeKey(root.pLeft) + SumNodeKey(root.pRight);
    }
 
    public int FindMaxElement(Node root)
    {
        if (root == null) return Global.NONE;
        Node p = root;
        while (p.pRight != null) p = p.pRight;
        return p.info;
    }
    public int FindMinElement(Node root)
    {
        if (root == null) return Global.NONE;
        Node p = root;
        while (p.pLeft != null) p = p.pLeft;
        return p.info;
    }
    public int FindMaxNegativeElement(Node root)
    {
        if (root == null) return Global.NONE;
        if (root.info < 0)
        {   //return root->key;
            Node p = root;
            while (p.pRight.info < 0)
                p = p.pRight;
            return p.info;
        }
        else
        {
            //key >= 0
            Node p = root.pLeft;
            while (p.info >= 0) p = p.pLeft;
            if (p != null) return p.info;
            return Global.NONE;
        }
    }
    public int CountNumberOfElementInTree(Node root)
    {
        if (root == null) return 0;
        return CountNumberOfElementInTree(root.pLeft) + CountNumberOfElementInTree(root.pRight) + 1;
    }
    public void CountNumberOfElementOfKeyInTree(Node root)
    {
        if (root != null)
        {
            CountNumberOfElementOfKeyInTree(root.pLeft);
            //Trong cay nhi phan khong cho phep trung lap gia tri
            Console.WriteLine("\n" + root.info + " xuat hien 1 lan");
            CountNumberOfElementOfKeyInTree(root.pRight);
        }
    }
}
public static class Program
{
    public static void Main()
    {
        Tree t = new Tree();
        t.InitTree();
        t.InsertNode(ref t.root, Global.CreateNode(5));
        t.InsertNode(ref t.root, Global.CreateNode(1));
        t.InsertNode(ref t.root, Global.CreateNode(3));
        t.InsertNode(ref t.root, Global.CreateNode(-5));
        t.InsertNode(ref t.root, Global.CreateNode(-1));
        t.InsertNode(ref t.root, Global.CreateNode(-3));
        t.InsertNode(ref t.root, Global.CreateNode(15));
        t.InsertNode(ref t.root, Global.CreateNode(11));
        t.InsertNode(ref t.root, Global.CreateNode(13));
        t.PrintTree_InOrder(t.root);
        t.DeleteNode(ref t.root, 5);
        Console.WriteLine("\n- - - - - - - - - - - - - - -");
        t.PrintTree_InOrder(t.root);
        if (t.SearchNode(t.root, 5) != null)
            Console.WriteLine("Tim thay!");
        else
            Console.WriteLine("Khong tim thay!");
        if (t.SearchNode(t.root, 15) != null)
            Console.WriteLine("Tim thay!");
        else
            Console.WriteLine("Khong tim thay!");
        Console.WriteLine("\nChieu cao cua cay: " + t.HighTree(t.root));
        Console.WriteLine("\nSo node nhanh cua cay: " + t.CountBranchNode(t.root));
        Console.WriteLine("\nSo node la cua cay: " + t.CountNodeLeaf(t.root));
        Console.WriteLine("\nTong cac gia tri nguyen cua cay: " + t.SumNodeKey(t.root));
        Console.WriteLine("\nSo luong phan tu chan trong cay: " + t.CountEvenElement(t.root));
        Console.WriteLine("\nGia tri nguyen lon nhat: " + t.FindMaxElement(t.root) + "\nGia tri nguyen be nhat: " + t.FindMinElement(t.root));
        Console.WriteLine("\nMax am cua cay: " + t.FindMaxNegativeElement(t.root));
        Console.WriteLine("\nSo luong gia tri phan biet trong cay: " + t.CountNumberOfElementInTree(t.root));
        Console.WriteLine("\nSo luong phan tu moi gia tri phan biet: ");
        t.CountNumberOfElementOfKeyInTree(t.root);
    }
}
