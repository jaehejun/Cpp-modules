#include <fstream>
#include <iostream>
#include <string>

// int main()
//{
//	std::ifstream in("test.txt");
//	std::string s;

//	if (in.is_open())
//	{
//		in >> s;
//		std::cout << "입력받은 문자열: " << s << std::endl;
//	}
//	else
//	{
//		std::cout << "파일을 찾을 수 없습니다" << std::endl;
//	}
//	return 0;
//}

// int main()
//{
//     // 파일 읽기 준비
//     std::ifstream in("test.txt");
//     std::string s;

//    if (in.is_open())
//    {
//        in >> s;
//        std::cout << "입력 받은 문자열 :: " << s << std::endl;
//    }
//    else
//    {
//        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
//    }

//    in.close();
//    in.open("other.txt");

//    if (in.is_open())
//    {
//        in >> s;
//        std::cout << "입력 받은 문자열 :: " << s << std::endl;
//    }
//    else
//    {
//        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
//    }

//    return 0;
//}

// int main()
//{
//     // 파일 읽기 준비
//     std::ifstream in("test.txt");
//     std::string s;

//    if (in.is_open())
//    {
//        // 위치 지정자를 파일 끝으로 옮긴다.
//		// 위치 지정자를 파일의 끝에서 0만큼 떨어진 것(파일의 끝)으로 이동시킨다
//        in.seekg(0, std::ios::end);

//        // 그리고 그 위치를 읽는다. (파일의 크기)
//		// tellg()는 위치 지정자의 위치(시작 지점으로부터의)를 반환한다
//        int size = in.tellg();

//        // 그 크기의 문자열을 할당한다.
//        s.resize(size);

//        // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
//        in.seekg(0, std::ios::beg);

//        // 파일 전체 내용을 읽어서 문자열에 저장한다.
//        in.read(&s[0], size);
//        std::cout << s << std::endl;
//    }
//    else
//    {
//        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
//    }

//    return 0;
//}

// #include <fstream>
// #include <iostream>
// #include <string>

// int main()
//{
//     // 파일 쓰기 준비
//	// ofstream은 열려는 파일이 존재하지 않으면 해당 파일을 생성 후 연다
//	// 해당 파일이 이미 존재한다면, 특별한 설정을 하지 않는다면 해당 파일 내용을 새로운 내용으로 덮어쓴다
//     std::ofstream out("test2.txt");

//    std::string s;
//    if (out.is_open())
//    {
//        out << "이걸 쓰자~~";
//    }

//    return 0;
//}

//#include <fstream>
//#include <iostream>
//#include <string>

//int main()
//{
//    // 파일 쓰기준비
//	// 옵션으로 app을 주게 되면 파일에 스트림을 연결할 때 기존 내용 뒤에 새로운 내용을 붙여 쓴다
//    std::ofstream out("test.txt", std::ios::app);

//    std::string s;
//    if (out.is_open())
//    {
//        out << "덧붙이기";
//    }

//    return 0;
//}

//int main() {
//  // 두 파일에는 모두 abc 라고 써 있었습니다.
//  std::ofstream out("test.txt", std::ios::app);
//  std::ofstream out2("test2.txt", std::ios::ate);

//  out.seekp(3, std::ios::beg);
//  out2.seekp(3, std::ios::beg);

//  out << "추가";
//  out2 << "추가";

//  return 0;
//}

#include <iostream>
#include <fstream>
#include <sstream>

void    replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream   ifs(filename);
    std::ofstream   ofs(filename + ".replace");
    std::string     line;
    
    if (ifs.is_open() && ofs.is_open())
    {
        while (getline(ifs, line))
        {
            while (line.find(s1) != std::string::npos)
                line = line.substr(0, line.find(s1)) + s2 + line.substr(line.find(s1) + s1.length(), line.length());
            ofs << line << std::endl;
        }
    }
    else
        std::cerr << "Error: Could not open file." << std::endl;
    ifs.close();
    ofs.close();
}

int main(int argc, char **argv)
{
    if (argc == 4)
        replace(argv[1], argv[2], argv[3]);
    else
        std::cerr << "Error: Invalid arguments." << std::endl;
    return (0);
}
