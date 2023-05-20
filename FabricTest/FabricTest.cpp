#include "pch.h"
#include "CppUnitTest.h"
#include "..\trpo6-7.3\trpo6-7.3.cpp"
#include <string>
#include <cassert>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FabricTest
{
	TEST_CLASS(FabricTest)
	{
	public:
		
		TEST_METHOD(TestSnikers)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			Snikers snikers;
			snikers.releaseShoes();
			std::string expectedOutput = "Кроссовки\n";
			Assert::AreEqual(expectedOutput, output.str());

			std::cout.rdbuf(originalCout);
		}

		TEST_METHOD(TestClassicShoes)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			ClassicShoes classicShoes;
			classicShoes.releaseShoes();
			std::string expectedOutput = "Туфли\n";
			Assert::AreEqual(expectedOutput, output.str());

			std::cout.rdbuf(originalCout);
		}

		TEST_METHOD(TestSportBag)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			sportBag sportBag;
			sportBag.releaseBag();
			std::string expectedOutput = "Спортивная сумка, ";
			Assert::AreEqual(expectedOutput, output.str());

			std::cout.rdbuf(originalCout);
		}

		TEST_METHOD(TestClassicBag)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			classicBag classicBag;
			classicBag.releaseBag();
			std::string expectedOutput = "Классическая сумка, ";
			Assert::AreEqual(expectedOutput, output.str());

			std::cout.rdbuf(originalCout);
		}

		TEST_METHOD(TestSportSuit)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			SportSuit sportSuit;
			sportBag sportBag;
			Snikers snikers;

			sportSuit.releaseSuit(&sportBag, &snikers);
			std::string expectedOutput = "Спортивный костюм очень хорошо подходит для повседневного использования, в комплекте прекрасно смотрятся: Спортивная сумка, Кроссовки\n";
			Assert::AreEqual(expectedOutput, output.str());

			std::cout.rdbuf(originalCout);
		}

		TEST_METHOD(TestSmoking)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			Smoking smoking;
			classicBag classicBag;
			ClassicShoes classicShoes;

			smoking.releaseSuit(&classicBag, &classicShoes);
			std::string expectedOutput = "Смокинг выглядит великолепно, к нему отлично подходят: Классическая сумка, Туфли\n";
			Assert::AreEqual(expectedOutput, output.str());

			std::cout.rdbuf(originalCout);
		}

		TEST_METHOD(TestSportCostume)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			SportCostume sportCostume;

			Shoes* shoes = sportCostume.createShoes();
			Suit* suit = sportCostume.createSuit();
			Bag* bag = sportCostume.createBag();

			suit->releaseSuit(bag, shoes);
			std::string expectedOutput = "Спортивный костюм очень хорошо подходит для повседневного использования, в комплекте прекрасно смотрятся: Спортивная сумка, Кроссовки\n";
			Assert::AreEqual(expectedOutput, output.str());

			delete shoes;
			delete suit;
			delete bag;

			std::cout.rdbuf(originalCout);
		}

		TEST_METHOD(TestClassicCostume)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			ClassicCostume classicCostume;

			Shoes* shoes = classicCostume.createShoes();
			Suit* suit = classicCostume.createSuit();
			Bag* bag = classicCostume.createBag();

			suit->releaseSuit(bag, shoes);
			std::string expectedOutput = "Смокинг выглядит великолепно, к нему отлично подходят: Классическая сумка, Туфли\n";
			Assert::AreEqual(expectedOutput, output.str());

			delete shoes;
			delete suit;
			delete bag;

			std::cout.rdbuf(originalCout);
		}

		TEST_METHOD(TestDailyCostume)
		{
			std::stringstream output;
			std::streambuf* originalCout = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			DailyCostume dailyCostume;

			Shoes* shoes = dailyCostume.createShoes();
			Suit* suit = dailyCostume.createSuit();
			Bag* bag = dailyCostume.createBag();

			suit->releaseSuit(bag, shoes);
			std::string expectedOutput = "Спортивный костюм очень хорошо подходит для повседневного использования, в комплекте прекрасно смотрятся: Классическая сумка, Туфли\n";
			Assert::AreEqual(expectedOutput, output.str());

			delete shoes;
			delete suit;
			delete bag;

			std::cout.rdbuf(originalCout);
		}
	};
}
