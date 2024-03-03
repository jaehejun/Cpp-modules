#include <fstream>
#include <iostream>

void replaceString(std::string filename, std::string s1, std::string s2)
{
    std::ifstream originalFile((filename).c_str());
    if (!originalFile.is_open())
    {
        std::cerr << "Error : Failed to open file" << std::endl;
        return;
    }
    std::ofstream replaceFile((filename + ".replace").c_str());
    if (!replaceFile.is_open())
    {
        std::cerr << "Error : Failed to open replace file" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(originalFile, line))
    {
        if (!s1.empty())
        {
            std::string::size_type pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
        }
        replaceFile << line;
        if (!originalFile.eof())
        {
            replaceFile << '\n';
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
        replaceString(argv[1], argv[2], argv[3]);
    else
        std::cerr << "Error: Invalid arguments." << std::endl;
    return 0;
}
