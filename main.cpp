#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    int choiser;

    std::cout << "Enter 1 to ask user, enter 2 to show results, enter 3 to change questions: ";
    std::cin >> choiser;

    switch(choiser)
    {
        case 1:
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
            break;
        }

        case 2:
        {
            std::string answer;
            std::vector <std::vector <std::string> > answerTable (3);

            std::ifstream fin("biglist.txt");

            int ii = 0;

            int sortPos;

            std::cout << "Enter sorting base position number: ";

            std::cin >> sortPos;

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

                    if(answerTable[sortPos - 1][j] < answerTable[sortPos - 1][j - 1])
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
            break;
        }

        case 3:
        {
            int choiser1;
            std::cout << "Enter 1 to see all questions, enter 2 to delete certain questions, enter 3 to add a list of questions: ";
            std::cin >> choiser1;

            switch(choiser1)
            {
            case 1:
            {
                std::ifstream fin("questionlist.txt");
                std::string question;

                while(getline(fin, question))
                    std::cout << question << std::endl;

                fin.close();
                break;
            }

            case 2:
            {
                std::ifstream fin("questionlist.txt", std::ios::out);
                std::ofstream temp("temp.txt", std::ios::out);
                std::string question;

                int num_line, cur_line = 1;
                std::cout << "Enter a number of string: ";
                std::cin >> num_line;

                while (getline(fin, question))
                {
                    if (cur_line++ != num_line)
                        temp << question << std::endl;
                }

                fin.clear();

                fin.close();
                temp.close();
                std::ofstream fin1("questionlist.txt", std::ios::out);
                std::ifstream temp1("temp.txt", std::ios::out);

                while (getline(temp1, question))
                {
                    if (cur_line++ != num_line)
                        fin1 << question << std::endl;
                }

                fin1.close();
                temp1.close();
            }
            case 3:
            {
                int num_questions;
                std::cout << "Enter a number of questions: ";
                std::cin >> num_questions;

                std::ofstream fin("questionlist.txt", std::ios::app);
                std::string question;

                while(num_questions-- > 0)
                    {
                    std::cin >> question;
                    fin << question << std::endl;
                    }

                fin.close();

            }
        }

        }



    }

    return 0;
}
