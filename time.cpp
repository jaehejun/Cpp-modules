#include <iostream>
#include <ctime>
#include <iomanip>

int	main()
{
	std::time_t time = std::time(nullptr);
	struct tm *now = std::localtime(&time);

	std::cout << "[";
	std::cout << now->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << now->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << now->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << now->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << now->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";

	return 0;
}