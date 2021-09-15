#include <iostream>
#include <string>
#include <fstream>

int main()
{


    int choiser;

    std::cout << "Enter 1 to ask user, enter 2 to show results ";
    std::cin >> choiser;

    if(choiser == 1)
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
    }
    else
    {
        std::string answer;

        std::ifstream fin("biglist.txt");

        while(getline(fin, answer))
            std::cout << answer << std::endl;


        fin.close();
    }

    return 0;
}
