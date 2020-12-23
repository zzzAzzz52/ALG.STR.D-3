#include "Header.h"
#include <iomanip>
#include <iostream>
#include <locale>
#include <chrono>

using namespace std;

void main()
{
	Heap H;

	H.insert(4);
	H.insert(65);
	H.insert(16);
	H.insert(24);
	H.insert(89);
	H.remove(16);
	cout << endl;

	Iterator* iter;

	iter = H.create_bft_iterator();
	while (iter->has_next())
		cout << iter->next() << " ";
	cout << endl;
	cout << endl;

	Iterator* Iter;
	Iter = H.create_dft_iterator();
	while (Iter->has_next())
		cout << Iter->next() << " ";
	cout << endl << endl;
}