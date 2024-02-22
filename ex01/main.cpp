#include "Contact.hpp"
#include "PhoneBook.hpp"

//키보드입력 -> 입력 버퍼에 저장 -> std::cin(stream 객체) 가 입력 버퍼에서 데이터를 읽어서 command에 저장

// ctlr+d -> cin.fail -> continue
// a + ctrl+d -> else -> continue -> LOOP -> cin.fail -> continue -> LOOP
// ADD + ctrl+d -> ADD로 인식 -> getinfo == false -> return -> LOOP 

// cin.ignore로 입력 버퍼 비운 뒤(clear->clearerr->ignore)
// ctrl+d -> cin.fail -> 입력 기다림, Enter command 출력 안됨
// ADD + ctrl+d -> ADD로 인식 -> INFO FAIL -> return -> LOOP

// ignore->clear->clearerr
// ctrl+d -> cin.fail -> enter command 출력됨
int main()
{
    PhoneBook myPhoneBook;

    while (true)
    {
        std::cout << "Enter commands(ADD, SEARCH, EXIT)" << std::endl;
        std::string command;

        std::getline(std::cin, command);
        if (std::cin.fail())
        {
            std::cin.clear();
			//c++ stream객체(cin)의 오류 플래그 초기화(eofbit,failbit,badbit):반환값 true->false로 초기화
            std::clearerr(stdin);
			//stdin 파일 스트림의 오류와 eof 초기화
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//입력 버퍼 비우기
            continue;
        }
        if (command == "EXIT")
            break;
        else if (command == "ADD")
        {
            myPhoneBook.saveNewContact();
        }
        else if (command == "SEARCH")
        {
            myPhoneBook.displayContact();
        }
        else
            continue;
    }
    return 0;
}