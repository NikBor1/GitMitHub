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
        std::ofstream fout("biglist.txt", std::ios::app);

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
        std::vector <std::vector <std::string> > answerTable(0);

        std::ifstream fin("questionlist.txt");

        int amQuestions = 0;

        while(getline(fin, answer))
            amQuestions ++;

        std::vector <std::string> v (0);

        for(int i = 0; i < amQuestions; i ++)
            answerTable.push_back(v);

        fin.close();

        std::ifstream fino("biglist.txt");

        int amUsers = 0;

        int sortPos;

        std::cout << "Enter sorting base position number: ";

        std::cin >> sortPos;

        while(getline(fino, answer))
        {
            answerTable[amUsers % amQuestions].push_back(answer);
            amUsers ++;
        }

        amUsers /= amQuestions;

        fino.close();


        for(int i = 0; i < amUsers; i ++)
        {
            for(int j = 1; j < amUsers - i; j ++)
            {

                if(answerTable[sortPos - 1][j] < answerTable[sortPos - 1][j - 1])
                {
                    for(int k = 0; k < amQuestions; k ++)
                        std::swap(answerTable[k][j], answerTable[k][j - 1]);
                }


            }
        }

        for(int i = 0; i < amUsers; i ++)
        {
            for(int j = 0; j < amQuestions; j ++)
                std::cout << answerTable[j][i] << "; ";

            std::cout << std::endl;
        }



    }

    return 0;
}
