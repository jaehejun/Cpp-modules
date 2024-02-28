#include <fstream>
#include <iostream>

void replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream originalFile(filename);
    std::ofstream replaceFile((filename + ".replace"));
    std::string line;

    if (!originalFile.is_open() || !replaceFile.is_open())
    {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    while (std::getline(originalFile, line))
    {
        std::string::size_type pos = 0;
		// line.find(s1, pos) : line에서 s1을 찾고, 그 위치를 반환한다. 찾지 못하면 std::string::npos를 반환한다
		// std::string::npos 는 std::string::size_type 의 특수한 값으로 size_type의 최대 가능 값인 -1과 같다.
		// std::string::size_type이 양의 정수 타입이므로, -1은 이 타입의 최대 값으로 자동 변환된다.
		// 문자열의 위치(std::string::size_type pos)는 항상 0 이상의 값이기에 -1로 위치를 찾지 못했음을 나타내는 것이 가능함
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
			// pos 부터 s1.length() 개의 문자 제거(lenght()번째 문자까지)
            line.erase(pos, s1.length());
			// pos 위치에 s2 삽입
            line.insert(pos, s2);
			// pos 위치를 s2.lenght()만큼 더해서 뒤로 밀어줌
            pos += s2.length();
        }
		// 새로 만들 파일에 line을 출력하고, getline()함수가 건너뛰는 개행문자까지 입력
        replaceFile << line << '\n';
    }

    originalFile.close();
    replaceFile.close();
}

int main(int argc, char **argv)
{
    if (argc == 4)
        replace(argv[1], argv[2], argv[3]);
    else
        std::cerr << "Error: Invalid arguments." << std::endl;
    return 0;
}
