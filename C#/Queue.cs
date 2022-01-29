using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queue_Implementation
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

    class Queue
    {
        private Node first;
        private Node last;
        private int length;

        public void Enqueue(int value)
        {
            Node newNode = new Node(value);
            length++;

            if (first == null)
            {
                first = newNode;
                last = newNode;
            }
            else
            {
                last.next = newNode;
                last = newNode;
            }
        }

        public void Dequeue()
        {
            if (first == null)
                Console.WriteLine("Queue is empty");
            else
            {
                Node temp = first;
                first = first.next;
                temp.next = null;
                length--;
            }

            Console.WriteLine("Removed an element");
        }

        public void Peek()
        {
            if (first == null)
                Console.WriteLine("Queue is empty");
            else
                Console.WriteLine("The top most element is " + first.data);
        }

        public void PrintQueue()
        {
            Node current = first;
            while (current != null)
            {
                Console.WriteLine(current.data);
                current = current.next;
            }
            Console.WriteLine("The length of the queue is " + length);
        }
    }

    class Program
    {
        static void Main()
        {
            Queue queue = new Queue();
            queue.Enqueue(1);
            queue.Enqueue(6);
            queue.Enqueue(9);
            queue.Enqueue(4);
            queue.PrintQueue();
            queue.Peek();
            queue.Dequeue();
            queue.Dequeue();
            queue.PrintQueue();

            Console.Read();
        }
    }
}
