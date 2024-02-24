#include <iostream>
#include <string>
#include <cctype> //isspace

int	main()
{
	int	num;


	while (true)
	{
		std::cin >> num;
		if (std::cin.fail())
		{
			std::cout << "NEED NUMBER" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::clearerr(stdin);
			continue ;
		}
		std::cout << "NUM: " << num << std::endl;
	}
}