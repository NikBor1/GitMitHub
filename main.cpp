#include <iostream>
#include <string>
#include <fstream>

int main()
{


    std::ifstream fin("questionlist.txt");
    std::ofstream fout("biglist.txt");

    std::string question;
    std::string answer;

    while(getline(fin, question))
    {
        std::cout << question << " ";
        getline(std::cin, answer);
        fout << answer << std::endl;
    }

    fin.close();
    fout.close();


    return 0;
}
