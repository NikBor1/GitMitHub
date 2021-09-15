#include <iostream>
#include <string>
#include <fstream>

int main()
{



    std::cout << "Enter your name and surname, please: ";
    std::string sName;
    std::string sSurname;

    std::cin >> sName >> sSurname;

    std::cout << std::endl << "Enter book, you recommend to read, please: ";
    std::string sFilm;

    getline(std::cin, sFilm);
    getline(std::cin, sFilm);

    std::ofstream fout("biglist.txt");

    fout << sName << " " << sSurname << " - " << sFilm << ";" << std::endl;
    fout.close();

    std::string answer;

    std::ifstream fin("biglist.txt");

    while(getline(fin, answer))
        std::cout << answer << std::endl;


    fin.close();


    return 0;
}
