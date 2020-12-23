#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};

class Heap
{
	static const int SIZE = 100;
	int* h;
	size_t HeapSize;
	Iterator* bftiterator;
	Iterator* dftiterator;
public:
	Heap() //constructor
	{
		h = new int[SIZE];
		HeapSize = 0;
		bftiterator = NULL;
		dftiterator = NULL;
	}
	~Heap() //destructor
	{
		delete[] h;
	}
	void siftDown(int); //sifting the element down
	void siftUp(int); //sifting the element up
	void insert(int); //adds an element to the heap
	void print(); //element output
	bool contains(int); //check for element presence
	void remove(int); //delete element

	class bft_iterator : public Iterator
	{
		size_t curr;
		Heap* heap;
	public:
		bft_iterator(size_t begin, Heap* HEAP);//constructor

		int next() override // gets next heap element
		{
			if (!has_next())
			{
				throw out_of_range("no more elements\n");
			}
			curr++;
			return heap->h[curr - 1];
		}
		bool has_next() override //checking for the existence of the next element
		{ 
			if (curr == heap->HeapSize)
			{
				return false;
			}
			else return true;
		}
	};

	Iterator* create_bft_iterator()//create iterator
	{
		bftiterator = new bft_iterator(0, this);
		return bftiterator;
	}


	class dft_iterator : public Iterator
	{
		size_t curr;
		Heap* heap;
		bool* visited;

	public:
		dft_iterator(size_t begin, Heap* HEAP); //constructor

		int next() override	// gets next heap element
		{
			if (!has_next())
			{
				throw out_of_range("no more elements\n");
			}
			size_t prev = curr;
			visited[prev] = 1;
			if (!has_next())
			{
				return heap->h[prev];
			}
			size_t left, right;
			while (1)
			{
				left = curr * 2 + 1;
				right = curr * 2 + 2;
				if (left < heap->HeapSize)
				{
					if (!visited[left])
					{
						curr = left;
						break;
					}
				}
				if (right < heap->HeapSize)
				{
					if (!visited[right])
					{
						curr = right;
						break;
					}
				}
				curr = (curr - 1) / 2;
			}
			return heap->h[prev];
		}

		bool has_next() override //checking for the existence of the next element
		{
			if (heap->HeapSize == 0)
			{
				return false;
			}
			size_t next_index = curr;
			size_t left, right;
			while (1)
			{
				left = (next_index * 2) + 1;
				right = (next_index * 2) + 2;
				if (left < heap->HeapSize)
				{
					if (!visited[left])
					{
						return true;
					}
				}
				if (right < heap->HeapSize)
				{
					if (!visited[right])
					{
						return true;
					}
				}
				if (next_index != 0)
				{
					next_index = (next_index - 1) / 2;
				}
				else if (!visited[next_index])
				{
					return true;
				}
				else return false;
			}
		}

		~dft_iterator()//destructor
		{
			delete[] visited;
		}
	};

	Iterator* create_dft_iterator()//create iterator
	{
		if (dftiterator != nullptr)
		{
			delete dftiterator;
		}
		dftiterator = new dft_iterator(0, this);
		return dftiterator;
	}

};