#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    // return left child of `A[i]`
    int LEFT(int i)
    {
        return (2 * i + 1);
    }

    // return right child of `A[i]`
    int RIGHT(int i)
    {
        return (2 * i + 2);
    }

    // Recursive heapify-down algorithm
    // the node at index `i` and its two direct children
    // violates the heap property
    void heapify(vector<int> &A, int i, int size)
    {
        // get left and right child of node at index `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        // compare `A[i]` with its left and right child
        // and find the largest value
        if (left < size && A[left] > A[i])
        {
            largest = left;
        }

        if (right < size && A[right] > A[largest])
        {
            largest = right;
        }

        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != i)
        {
            swap(A[i], A[largest]);
            heapify(A, largest, size);
        }
    }

public:
    // Constructor (Build-Heap)
    PriorityQueue(vector<int> &A, int n)
    {
        // call heapify starting from the last internal node all the
        // way up to the root node
        int i = (n - 2) / 2;
        while (i >= 0)
        {
            heapify(A, i--, n);
        }
    }

    // Function to remove an element with the highest priority (present at the root)
    int pop(vector<int> &A, int size)
    {
        // if the heap has no elements
        if (size <= 0)
        {
            return -1;
        }

        int top = A[0];

        // replace the root of the heap with the last element
        // of the array
        A[0] = A[size - 1];

        // call heapify-down on the root node
        heapify(A, 0, size - 1);

        return top;
    }
};

// Function to perform heapsort on array `A` of size `n`
void heapsort(vector<int> &A, int n)
{
    // build a priority queue and initialize it by the given array
    PriorityQueue pq(A, n);

    // repeatedly pop from the heap till it becomes empty
    while (n > 0)
    {
        A[n - 1] = pq.pop(A, n);
        n--;
    }
}

// Heapsort algorithm implementation in C++
int main()
{
    vector<int> A;
    int n, k;
    cout << "Enter number of elements";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        A.push_back(k);
    }

    // perform heapsort on the array
    heapsort(A, n);

    // print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}