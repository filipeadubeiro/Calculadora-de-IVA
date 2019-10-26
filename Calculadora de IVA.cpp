#include <iostream>
#include <windows.h>

float roundto(float var)
{
	float value = (int)(var * 100 + .5);
	return (float)value / 100;
}

int titulo()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 3);
	std::cout << "..................." << std::endl;
	SetConsoleTextAttribute(color, 6);
	std::cout << ". Calculadora IVA ." << std::endl;
	SetConsoleTextAttribute(color, 3);
	std::cout << "...................";
	SetConsoleTextAttribute(color, 7);
	std::cout << std::endl
		<< std::endl;
	return 0;
}

float BaseIva()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Calcular Base e Iva" << std::endl
		<< std::endl;
	std::cout << " Perc. IVA:";
	float Perc_iva;
	SetConsoleTextAttribute(color, 14);
	std::cout << " % ";
	std::cin >> Perc_iva;

	float PercPlus100 = Perc_iva + 100;
	std::cout << std::endl;

	SetConsoleTextAttribute(color, 7);
	std::cout << " TOTAL: ";
	float Total;

	SetConsoleTextAttribute(color, 14);
	SetConsoleOutputCP(1252); // Set console to output symbols
	std::cout << "\u20AC"; // Euro symbol
	std::cin >> Total;
	std::cout << std::endl;

	float Iva = roundto((Total * Perc_iva) / PercPlus100);

	float Base = Total - Iva;
	SetConsoleTextAttribute(color, 2);
	std::cout << " Base = "
		<< "\u20AC" << Base << std::endl;
	SetConsoleTextAttribute(color, 12);
	std::cout << " IVA  = "
		<< "\u20AC" << Iva << std::endl;

	SetConsoleTextAttribute(color, 7);

	std::cout << std::endl
		<< "---------------------" << std::endl;
	return 0;
}

float TotalIva()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Calcular Total e Iva" << std::endl
		<< std::endl;
	std::cout << " Perc. IVA:";
	float Perc_iva;
	SetConsoleTextAttribute(color, 14);
	std::cout << " % ";
	std::cin >> Perc_iva;

	std::cout << std::endl;

	SetConsoleTextAttribute(color, 7);
	std::cout << " Base: ";
	float Base;

	SetConsoleTextAttribute(color, 14);
	SetConsoleOutputCP(1252); // Set console to output symbols
	std::cout << "\u20AC"; // Euro symbol
	std::cin >> Base;
	std::cout << std::endl;

	float Iva = roundto(Base * (Perc_iva / 100));

	float Total = Base + Iva;
	SetConsoleTextAttribute(color, 2);
	std::cout << " Total = "
		<< "\u20AC" << Total << std::endl;
	SetConsoleTextAttribute(color, 12);
	std::cout << " Iva  = "
		<< "\u20AC" << Iva << std::endl;

	SetConsoleTextAttribute(color, 7);

	std::cout << std::endl
		<< "---------------------" << std::endl;
	return 0;
}

float Combustivel()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	std::cout << "Calcular Base/IVA Combustivel" << std::endl
		<< std::endl;

	int Perc_iva = 23;
	float PercPlus100 = Perc_iva + 100;
	std::cout << std::endl;

	SetConsoleTextAttribute(color, 7);
	std::cout << " TOTAL: ";
	float Total;

	SetConsoleTextAttribute(color, 14);
	SetConsoleOutputCP(1252); // Set console to output symbols
	std::cout << "\u20AC"; // Euro symbol
	std::cin >> Total;
	std::cout << std::endl;

	float Iva = roundto((Total * Perc_iva) / PercPlus100);

	float Base = Total - Iva;

	float mIVA = roundto(Iva / 2);

	float nBase = Total - mIVA;

	SetConsoleTextAttribute(color, 2);
	std::cout << " Base =    "
		<< "\u20AC" << nBase << std::endl;
	SetConsoleTextAttribute(color, 12);
	std::cout << " Iva 50% = "
		<< "\u20AC" << mIVA << std::endl;

	SetConsoleTextAttribute(color, 7);

	std::cout << std::endl
		<< "---------------------" << std::endl;
	return 0;
}

int main()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true) {
		titulo();

		std::cout << "O que quer calcular?" << std::endl
			<< std::endl;
		std::cout << "1 - Base e IVA" << std::endl
			<< "2 - Total e Iva" << std::endl
			<< "3 - Base/IVA Combustivel" << std::endl
			<< std::endl
			<< std::endl;
		int option;
		std::cin >> option;
		system("CLS");

		titulo();

		switch (option) {
		case 1:
			BaseIva();
			break;
		case 2:
			TotalIva();
			break;
		case 3:
			Combustivel();
			break;
		}
	}
	return 0;
}