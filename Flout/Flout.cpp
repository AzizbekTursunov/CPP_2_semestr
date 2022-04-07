#include <iostream>

union fu { float f; unsigned int u; };

void binar(unsigned int a)
{
	int SIZE = 32;
	std::string ZERO = "0";
	std::string binnum;
	int flag = 1;

	binnum = "";
	for (int j = 0; j < SIZE; j++)
	{
		binnum.append(ZERO);
	}

	int i = 1;
	while (a > 0)
	{
		if (a & 1 == 1)
		{
			binnum[SIZE - i] = '1';

		}
		else
		{
			binnum[SIZE - i] = '0';
		}

		a = a >> 1;
		i++;
	}

	std::cout << binnum << std::endl;
}

int main()
{

	fu N;

	std::cout << "Your natural number:" << std::endl;
	std::cin >> N.f;
	std::cout << "Your binar number:" << std::endl;
	binar(N.u);

	return 0;
}