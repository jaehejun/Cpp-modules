#ifndef CONTACT_HPP
#define CONTACT_HPP

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
    Contact();
    ~Contact();

     void setFirstName(std::string firstName);
     void setLastName(std::string lastName);
     void setNickname(std::string nickname);
     void setPhoneNumber(std::string phoneNumber);
     void setDarkestSecret(std::string darkestSecret);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNubmer();
    std::string getDarkestSecret();
};

#endif