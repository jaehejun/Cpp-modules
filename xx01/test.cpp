// #include <iostream>
// #include <string>

// class Contact
//{
//   private:
//     std::string _firstName;
//     std::string _lastName;
//     std::string _nickname;
//     std::string _phoneNumber;
//     std::string _darkestSecret;

//  public:
//    // setter 함수
//    void setFirstName(std::string firstName)
//    {
//        this->_firstName = firstName;
//    }
//    void setLastName(std::string lastName)
//    {
//        this->_lastName = lastName;
//    }
//    void setNickname(std::string nickname)
//    {
//        this->_nickname = nickname;
//    }
//    void setPhoneNumber(std::string phoneNumber)
//    {
//        this->_phoneNumber = phoneNumber;
//    }
//    void setDarkestSecret(std::string darkestSecret)
//    {
//        this->_darkestSecret = darkestSecret;
//    }

//    // getter 함수
//    std::string getFirstName()
//    {
//        return this->_firstName;
//    }
//    std::string getLastName()
//    {
//        return this->_lastName;
//    }
//    std::string getNickname()
//    {
//        return this->_nickname;
//    }
//    std::string getPhoneNumber()
//    {
//        return this->_phoneNumber;
//    }
//    std::string getDarkestSecret()
//    {
//        return this->_darkestSecret;
//    }
//};

// class PhoneBook
//{
//   private:
//     Contact contacts[8]; // 최대 8개의 연락처 저장
//     int currentContact;  // 현재 연락처 수
//   public:
//     PhoneBook() : currentContact(0)
//     {
//     } // 생성자에서 currentContact를 0으로 초기화

//    // 연락처 추가 함수
//    void addContact(Contact contact)
//    {
//        if (currentContact < 8)
//        {
//            contacts[currentContact] = contact;
//            currentContact++;
//        }
//        else
//        { // 8개 이상의 연락처를 추가하려는 경우, 가장 오래된 연락처를 대체
//            for (int i = 0; i < 7; i++)
//                contacts[i] = contacts[i + 1];
//            contacts[7] = contact;
//        }
//    }

//    // 연락처 검색 함수
//    Contact *searchContact(int index)
//    {
//        if (index < 0 || index >= currentContact) // 인덱스 범위 확인
//            return NULL;
//        return &contacts[index];
//    }
//};

// int main()
//{
//     PhoneBook phoneBook;
//     std::string command;

//    while (true)
//    {
//        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
//        std::cin >> command;

//        if (command == "ADD")
//        {
//            Contact newContact;
//            std::string input;

//            std::cout << "Enter first name: ";
//            std::cin >> input;
//            newContact.setFirstName(input);

//            std::cout << "Enter last name: ";
//            std::cin >> input;
//            newContact.setLastName(input);

//            std::cout << "Enter nickname: ";
//            std::cin >> input;
//            newContact.setNickname(input);

//            std::cout << "Enter phone number: ";
//            std::cin >> input;
//            newContact.setPhoneNumber(input);

//            std::cout << "Enter darkest secret: ";
//            std::cin >> input;
//            newContact.setDarkestSecret(input);

//            // 연락처 정보 입력
//            // 각 필드에 대해 입력을 받아 newContact의 setter 함수를 호출하여 값을 설정
//            // 이 과정에서 string 라이브러리를 사용할 것

//            phoneBook.addContact(newContact);
//        }
//        else if (command == "SEARCH")
//        {
//            int index;
//            std::cout << "Enter index: ";
//            std::cin >> index;
//            Contact *contact = phoneBook.searchContact(index);

//            if (contact)
//            {   // 또는 if (contact != NULL)
//                // contact가 가리키는 Contact 객체의 getter 함수를 호출하여 값을 출력
//                // 이 때, iomanip 라이브러리의 setw, setfill, right 등을 사용하여 출력 형태를 조정
//                std::cout << "First Name: " << contact->getFirstName() << std::endl;
//                std::cout << "Last Name: " << contact->getLastName() << std::endl;
//                std::cout << "Nickname: " << contact->getNickname() << std::endl;
//                std::cout << "Phone Number: " << contact->getPhoneNumber() << std::endl;
//                std::cout << "Darkest Secret: " << contact->getDarkestSecret() << std::endl;
//            }
//            else
//            {
//                std::cout << "Invalid index\n";
//            }
//        }
//        else if (command == "EXIT")
//        {
//            break;
//        }
//    }

//    return 0;
//}

#include <iomanip>
#include <iostream>
#include <string>

class Contact
{
  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

  public:
    void setFirstName(std::string firstName)
    {
        _firstName = firstName;
    }
    void setLastName(std::string lastName)
    {
        _lastName = lastName;
    }
    void setNickname(std::string nickname)
    {
        _nickname = nickname;
    }
    void setPhoneNumber(std::string phoneNumber)
    {
        _phoneNumber = phoneNumber;
    }
    void setDarkestSecret(std::string darkestSecret)
    {
        _darkestSecret = darkestSecret;
    }

    std::string getFirstName()
    {
        return _firstName;
    }
    std::string getLastName()
    {
        return _lastName;
    }
    std::string getNickname()
    {
        return _nickname;
    }
    std::string getPhoneNumber()
    {
        return _phoneNumber;
    }
    std::string getDarkestSecret()
    {
        return _darkestSecret;
    }
};

class PhoneBook
{
  private:
    Contact contacts[8];
    int _size;
    int _oldest;

  public:
    PhoneBook() : _size(0), _oldest(0)
    {
    }

    void addContact(Contact newContact)
    {
        if (_size < 8)
        {
            contacts[_size] = newContact;
            _size++;
        }
        else
        {
            contacts[_oldest] = newContact;
            _oldest++;
            if (_oldest == 8)
                _oldest = 0;
        }
    }

    Contact *getContact(int index)
    {
        if (index < 0 || index >= _size)
        {
            return nullptr;
        }
        else
        {
            return &contacts[index];
        }
    }

    int getSize()
    {
        return _size;
    }
};

std::string formatContactField(std::string field)
{
    if (field.length() > 10)
    {
        return field.substr(0, 9) + ".";
    }
    else
    {
        return field;
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command(ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (std::cin.fail())
        {
            std::cout << "Input error or EOF detected." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        if (command == "EXIT")
        {
            break;
        }
        else if (command == "ADD")
        {
            Contact newContact;
            std::string input;

            std::cout << "Enter first name: ";
            std::cin >> input;
            newContact.setFirstName(input);

            std::cout << "Enter last name: ";
            std::cin >> input;
            newContact.setLastName(input);

            std::cout << "Enter nickname: ";
            std::cin >> input;
            newContact.setNickname(input);

            std::cout << "Enter phone number: ";
            std::cin >> input;
            newContact.setPhoneNumber(input);

            std::cout << "Enter darkest secret: ";
            std::cin >> input;
            newContact.setDarkestSecret(input);

            phoneBook.addContact(newContact);
        }
        else if (command == "SEARCH")
        {
            for (int i = 0; i < phoneBook.getSize(); i++)
            {
                Contact *contact = phoneBook.getContact(i);
                std::cout << std::setw(10) << i << "|";
                std::cout << std::setw(10) << formatContactField(contact->getFirstName()) << "|";
                std::cout << std::setw(10) << formatContactField(contact->getLastName()) << "|";
                std::cout << std::setw(10) << formatContactField(contact->getNickname()) << std::endl;
            }

            int index;
            std::cout << "Enter index: ";
            std::cin >> index;

            if (index < 0 || index >= phoneBook.getSize())
            {
                std::cout << "Invalid index\n";
            }
            else
            {
                Contact *contact = phoneBook.getContact(index);

                std::cout << "First Name: " << contact->getFirstName() << std::endl;
                std::cout << "Last Name: " << contact->getLastName() << std::endl;
                std::cout << "Nickname: " << contact->getNickname() << std::endl;
                std::cout << "Phone Number: " << contact->getPhoneNumber() << std::endl;
                std::cout << "Darkest Secret: " << contact->getDarkestSecret() << std::endl;
            }
        }
    }

    return 0;
}
