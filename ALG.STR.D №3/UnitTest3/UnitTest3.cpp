#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../ALG3/Header.h"
#include "\Users\zzzAzzz\source\repos\ALG3\Funct.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		Heap H;

		TEST_METHOD(insert)
		{
			int test_arr[5] = { 4, 24, 16, 65, 89 };

			H.insert(4);
			H.insert(65);
			H.insert(16);
			H.insert(24);
			H.insert(89);

			Iterator* iter;
			iter = H.create_bft_iterator();

			for (int i = 0; i < 5; i++)
			{
				Assert::AreEqual(test_arr[i], iter->next());
			}
		}

		TEST_METHOD(remove)
		{
			int test_arr[4] = { 4, 24, 89, 65 };

			H.insert(4);
			H.insert(65);
			H.insert(16);
			H.insert(24);
			H.insert(89);
			H.remove(16);

			Iterator* iter;
			iter = H.create_bft_iterator();

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(test_arr[i], iter->next());
			}
		}

		TEST_METHOD(contains)
		{
			H.insert(4);
			H.insert(65);
			H.insert(16);
			H.insert(24);
			H.insert(89);

			for (int i = 0; i < 5; i++)
			{
				Assert::AreEqual(true, H.contains(16));
			}
		}
	};
}