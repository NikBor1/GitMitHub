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
         std::ifstream fin("questionlist.txt");
        std::ofstream fout("biglist.txt");

        std::string question;
        std::string answer;

        getline(std::cin, answer);

        while(getline(fin, question))
        {
            std::cout << question << " ";
            getline(std::cin, answer);
            fout << answer << std::endl;
        }

        fin.close();
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
