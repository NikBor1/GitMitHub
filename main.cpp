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

    std::cin >> sFilm;


    std::cout << std::endl << "Enter book, you recommend to read, please: ";
    std::string sParty;

    std::cin >> sParty;

    std::ofstream fout("biglist.txt");

    fout << sName << " " << sSurname << " - " << sFilm << " - " << sParty << ";" << std::endl;
    fout.close();


    return 0;
}
