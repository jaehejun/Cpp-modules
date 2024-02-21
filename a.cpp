// std::cin 은 표준 라이브러리에서 미리 정의해놓은 전역 객체. 사용자가 별도로 생성하지 않아도 됨.
// std::istream은 추상 클래스로, 직접 인스턴스화 할 수 없다. 부모 클래스로서의 역할을 하며 이를 상속받아 구현된 객체 중 한나가 std::cin이다.
// std::cin을 사용하면 std::istream에서 제공하는 기본적인 입력 기능 외에 사용자로부터 표준 입력을 받아오는 기능을 사용할 수 있다.
// std::cin은 std::istream 클래스의 객체. 오류가 발생하면 스트림 객체 내부(std::cin)에 오류 플래그가 설정된다
			

#include <iostream>
#include <string>
#include <cctype> //isspace
#include <cstdio>

bool	isallspace(std::string str)
{
	for (size_t index = 0; index < str.length(); index++)
	{
		if (!std::isspace(str[index]))
			return false;
	}
	return true;
}

int	main()
{
	std::string str;

	//std::cout << std::numeric_limits<std::streamsize>::max() << std::endl;
	
	while (true)
	{
		std::getline(std::cin, str); 
		if (std::cin.fail()) // fail시 true 반환
		{
			std::cerr << "GETLINE failed" << std::endl;
			if (std::cin.eof()) // eof시 true 반환
			{
				std::cerr << "EOF entered" << std::endl;
			}
			std::cin.clear(); // c++ stream 객체(cin)의 오류 플래그 초기화(eofbit, failbit, badbit):반환값 false로 되돌림
			std::clearerr(stdin); // stdin 파일 스트림의 오류와 eof 초기화
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
			std::cout << std::endl;
			continue;
		}
		if (str.empty())
		{
			std::cerr << "EMPTY LINE" << std::endl;
		}
		if (isallspace(str))
		{
			std::cerr << "ALL ISSPACE!" << std::endl;
		}
		std::cout << str << std::endl;
	}
}
