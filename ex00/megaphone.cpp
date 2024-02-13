//$>./megaphone "shhhhh... I think the students are asleep..."
//SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
//$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
//DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
//$>./megaphone
//* LOUD AND UNBEARABLE FEEDBACK NOISE *
//$>

#include <iostream>
#include <cctype>
#include <string>

/*
구조체 vs 클래스
- 구조체 = 기본적으로 모든게 public
- 클래스 = private

struct test
{
// public:
	int a;
};

class MyClass
{
// private:
	int a;
};
*/

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int ac = 1; argv[ac] != NULL; ac++)
	{
		std::string str = argv[ac]; // "Damnit"
		for (int index = 0; str[index] != '\0';/*index <  str.length();*/ index++)
		{
			std::cout << (char)std::toupper(argv[ac][index]);
		}
	}
	std::cout << std::endl;
	return 0;
}
