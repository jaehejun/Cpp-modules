#include <fstream>
#include <iostream>
#include <sstream>

// void    replace(std::string filename, std::string s1, std::string s2)
//{
//     std::ifstream   ifs(filename);
//     std::ofstream   ofs(filename + ".replace");
//     std::string     line;

//    if (ifs.is_open() && ofs.is_open())
//    {
//        while (getline(ifs, line))
//        {
//            while (line.find(s1) != std::string::npos)
//                line = line.substr(0, line.find(s1)) + s2 + line.substr(line.find(s1) + s1.length(), line.length());
//            ofs << line << std::endl;
//        }
//    }
//    else
//        std::cerr << "Error: Could not open file." << std::endl;
//    ifs.close();
//    ofs.close();
//}

// int main(int argc, char **argv)
//{
//     if (argc == 4)
//         replace(argv[1], argv[2], argv[3]);
//     else
//         std::cerr << "Error: Invalid arguments." << std::endl;
//     return (0);
// }

#include <fstream>
#include <iostream>

void replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream ifs(filename);
    std::ofstream ofs((filename + ".replace"));
    std::string line;

    if (!ifs.is_open() || !ofs.is_open())
    {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    while (std::getline(ifs, line))
    {
        std::string::size_type pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        ofs << line << '\n';
    }

    ifs.close();
    ofs.close();
}

int main(int argc, char **argv)
{
    if (argc == 4)
        replace(argv[1], argv[2], argv[3]);
    else
        std::cerr << "Error: Invalid arguments." << std::endl;
    return 0;
}

//void replace(std::string filename, std::string s1, std::string s2)
//{
//    std::ifstream ifs(filename.c_str());
//    std::ofstream ofs((filename + ".replace").c_str());
//    std::string line;

//    if (!ifs.is_open() || !ofs.is_open())
//    {
//        std::cerr << "Error: Could not open file." << std::endl;
//        return;
//    }

//    while (std::getline(ifs, line))
//    {
//        std::string::size_type pos = 0;
//        while ((pos = line.find(s1, pos)) != std::string::npos)
//        {
//            line.erase(pos, s1.length());
//            line.insert(pos, s2);
//            pos += s2.length();
//        }
//        ofs << line << '\n';
//    }

//    ifs.close();
//    ofs.close();
//}

//int main(int argc, char **argv)
//{
//    if (argc == 4)
//        replace(argv[1], argv[2], argv[3]);
//    else
//        std::cerr << "Error: Invalid arguments." << std::endl;
//    return 0;
//}
