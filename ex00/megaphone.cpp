#include <cctype>
#include <iostream>
#include <string>

 int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int ac = 1; ac != argc; ac++)
		{
			std::string str = argv[ac];
			for (size_t index = 0; index != str.length(); index++)
				std::cout << static_cast<char>(std::toupper(str[index]));
		}
	}
	std::cout << std::endl;
	return 0;
 }

//int main(int argc, char **argv)
//{
//    if (argc == 1)
//    {
//        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
//    }
//    else
//    {
//        for (int ac = 1; ac != argc; ac++)
//        {
//            std::string str = argv[ac];
//            for (std::string::iterator it = str.begin(); it != str.end(); ++it)
//                *it = std::toupper(*it);
//			std::cout << str;
//        }
//    }
//    std::cout << std::endl;
//    return 0;
//}