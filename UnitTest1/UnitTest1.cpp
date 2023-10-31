#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.4r/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const vector<double>& array = { 1,4,-3,6,-5 };
			int index = 0;

			calculateNegativeProductRecursive(array, index);
			Assert::AreEqual(3, 3);
		}
	};
}
