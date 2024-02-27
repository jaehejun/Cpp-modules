//file open -> 다읽고 find() 로 s1 찾음
//s1 -> s2로 바꿈

//반드시 open() 후 close()

//getlin()쓰면 개행붙여줘야대서 std::cin으로 해야한다?(여민도치)

//파일을 한글자씩 읽는 방법이 이씀 (서쏜)

//s2로 바꿨는데, 또 바꾸는 실수가 날 수 있다.

//aa -> a 로 바꾸고싶은데
//aaaa -> aa -> a 이렇게 되면 틀린다 (바꾼 후에 포시션 수정해야함?)
//pointer 밀듯이..?

//실수를 처리하는 두가지 방법
//부동 소수점 - floating point 붕붕 떠다닌다
//고정 소수점 에 관한게 c02


#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid arguments" << std::endl;
		return -1;
	}

	std::string filename, s1, s2;

	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	// open(filename);
	// filename의 모든 s1을 s2로 대체
	// filename.replace 라는 새 파일에 복사

	

	return 0;
}