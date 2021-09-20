#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
        std::vector <std::vector <std::string> > answerTable (3);

        std::ifstream fin("biglist.txt");

        int ii = 0;

        while(fin >> answer)
        {
            answerTable[ii % 3].push_back(answer);
            ii ++;
        }

        ii /= 3;

        fin.close();


        for(int i = 0; i < ii; i ++)
        {
            for(int j = 1; j < ii - i; j ++)
            {

                if(answerTable[1][j] < answerTable[1][j - 1])
                {
                    std::swap(answerTable[1][j], answerTable[1][j - 1]);
                    std::swap(answerTable[0][j], answerTable[0][j - 1]);
                    std::swap(answerTable[2][j], answerTable[2][j - 1]);
                }


            }
        }

        int differentBooks = 1;

        for(int i = 1; i < ii; i ++)
        {
            if(answerTable[2][i] != answerTable[2][i - 1])
                differentBooks ++;
        }

        for(int i = 0; i < ii; i ++)
            std::cout << answerTable[1][i] << " " << answerTable[0][i] << " " << answerTable[2][i] << std::endl;

        std::cout << ii << " people, " << differentBooks << " book(s)." << std::endl;

    }

    return 0;
}
