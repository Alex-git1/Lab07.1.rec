#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab07.1(rec)/Lab07.1(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int S = 0, k = 0;
			int** Z = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				Z[i] = new int[colCount];

			Z[0][0] = 10; Z[0][1] = 20; Z[0][2] = 30;
			Z[1][0] = 40; Z[1][1] = 50; Z[1][2] = 60;
			Z[2][0] = 70; Z[2][1] = 80; Z[2][2] = 90;

			Calc(Z, rowCount, colCount, S, k, 0, 0);

			Assert::AreEqual(200, S); 
			Assert::AreEqual(4, k);   
			Assert::AreEqual(0, Z[0][0]);
			Assert::AreEqual(0, Z[0][2]);
			Assert::AreEqual(0, Z[2][0]);
			Assert::AreEqual(0, Z[2][2]);

			for (int i = 0; i < rowCount; i++)
				delete[] Z[i];
			delete[] Z;
		}
	};
}
