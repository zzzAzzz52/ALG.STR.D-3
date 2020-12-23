#include "Header.h"
#include <iomanip>
#include <iostream>
#include <locale>

using namespace std;

void Heap::siftDown(int i) 
{
    int tmp;
    while (2 * i + 1 < HeapSize) 
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;

        if (right < HeapSize && h[right] < h[left])
        {
            j = right;
        }

        if (h[i] <= h[j]) 
        {
            break;
        }

        tmp = h[i];
        h[i] = h[j];
        h[j] = tmp;
        i = j;
    }
}

void Heap::siftUp(int i) 
{
    int tmp;
    while (h[i] < h[(i - 1) / 2]) 
    {
        tmp = h[i];
        h[i] = h[(i - 1) / 2];
        h[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

void Heap::insert(int key) //2
{
    if (HeapSize >= SIZE) 
    {
        cout << "Heap is full." << endl;
    }
    else 
    {
        HeapSize++;
        h[HeapSize - 1] = key;
        siftUp(HeapSize - 1);
    }
}

void Heap::print() 
{
    for (int i = 0; i < HeapSize; i++) 
    {
        cout << h[i] << " ";
    }
    cout << endl;
}

bool Heap::contains(int check) //1
{
    for (int i = 0; i < HeapSize; i++)
    {
        if (h[i] == check)
        {
            return true;
        }
    }
    return false;
}

void Heap::remove(int check) //3
{
    for (int i = 0; i < HeapSize; i++)
    {
        if (h[i] == check)
        {
            h[i] = h[HeapSize - 1];
            siftUp(h[i]);
            HeapSize--;
            break;
        }
    }
    cout << "Element " << check << " deleted" << endl;
}

Heap::bft_iterator::bft_iterator(size_t begin, Heap* HEAP)
{
    curr = begin;
    heap = HEAP;
}

Heap::dft_iterator::dft_iterator(size_t begin, Heap* HEAP)
{
    curr = begin;
    heap = HEAP;
    visited = new bool[heap->HeapSize];
    for (int i = 0; i < heap->HeapSize; i++) { visited[i] = false; }
}
