using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack_LinkedList
{
    class Node
    {
        public int data;
        public Node next;

        public Node(int value)
        {
            data = value;
            next = null;
        }
    }

    class Stack
    {
        private Node top = null;
        private Node bottom = null;
        private int length = 0;

        public void Push(int value)
        {
            if (top == null)
            {
                Node newNode = new Node(value);
                top = newNode;
                bottom = newNode;
                length++;
            }
            else
            {
                Node newNode = new Node(value);
                newNode.next = top;
                top = newNode;
                length++;
            }
        }

        public void Pop()
        {
            if (top == null)
                Console.WriteLine("Stack is empty");
            else
            {
                Node temp = top;
                top = temp.next;
                temp.next = null;
                length--;
            }

            Console.WriteLine("Popped the top most element");
        }

        public void Peek()
        {
            if (top == null)
                Console.WriteLine("Stack is empty");
            else
                Console.WriteLine("The top most element is {0}", top.data);
        }

        public void isEmpty()
        {
            if (top == null)
                Console.WriteLine(true);
            else
                Console.WriteLine(false);
        }

        public void PrintStack()
        {
            Node current = top;
            while (current != null)
            {
                Console.WriteLine(current.data);
                current = current.next;
            }
            Console.WriteLine("The length of the stack is " + length);
        }
    }

    class Program
    {
        static void Main()
        {
            Stack stack = new Stack();
            stack.Push(3);
            stack.Push(8);
            stack.Push(5);
            stack.Push(4);
            stack.Peek();
            stack.Pop();
            stack.PrintStack();

            Console.Read();
        }
    }
}
