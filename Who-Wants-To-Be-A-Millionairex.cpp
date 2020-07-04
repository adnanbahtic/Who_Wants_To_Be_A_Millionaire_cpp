#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

const int ROWS = 1000;
const int COLUMNS = 8;

void Loading_Data(string a[][COLUMNS], int ROWS);
void Print_Game_Title(string a);
void Print_Random_Question(string a[][COLUMNS], int Random_Question, int j, /*bool fifty_fifty, bool call_friend, bool ask_audience*/);
bool Check_Answer(string a[][COLUMNS], string answer, int Random_Question);

int main()
{
	ifstream fin;

	string data[ROWS][COLUMNS];
	string title;
	string choice;
	string choice2;
	string answer;
	string money[15] = { "100 KM", "200 KM", "300 KM", "500 KM", "1000 KM", "2000 KM", "4000 KM", "8000 KM", "16000 KM", "32000 KM", "64000 KM", "125000 KM", "250000 KM", "500000 KM", "1000000 KM" };
	string amount_won;
	string amount_won2;
	string choice3;

	bool flag = false;

	//int i = 1;

	srand(static_cast<unsigned int>(time(0)));

	Loading_Data(data, ROWS);

label: Print_Game_Title(title);
	cout << "Enter s / S to begin or e / E to end: ";
	cin >> choice;

	while (choice != "s" && choice != "S" && choice != "e" && choice != "E")
	{
		cout << "Invalid input. Try again: ";
		cin >> choice;
	}

	if (choice == "s" || choice == "S")
	{
		do
		{

			int i = 1;

			
			do
			{
				system("CLS");

			

				int random_question = rand() % 68 + (i - 1) * 68;
				if (random_question > 1011)
				{
					random_question = 1011;
				}
				Print_Game_Title(title);

				cout << endl;

				Print_Random_Question(data, random_question, i,);

				cout << endl;

				cout << "Please enter your answer or select one of available help options: ";

			lblMainUserInput: cin >> answer;

				while (answer != "1" && answer != "2" && answer != "3" && answer != "4" )
				{
					cout << "Invalid input. Try again: ";
					cin >> answer;
				}

				







				flag = Check_Answer(data, answer, random_question);

				if (flag == true && i < 15)
				{
					cout << "Answer is correct" << endl;
					amount_won = money[i - 1];

					cout << "You currently have " << amount_won << "." << endl;
					cout << "Please press c / C to continue or q / Q to quit: ";

					cin >> choice3;

					while (choice3 != "c" && choice3 != "C" && choice3 != "q" && choice3 != "Q")
					{
						cout << "Invalid input. Try again: ";
						cin >> choice3;
					}
				}
				else if (i == 15)
				{
					amount_won = money[i - 1];
				}
				else
				{
					if (flag == false)
					{
						if (i >= 1 && i <= 5)
						{
							amount_won2 = "0 KM";
						}
						else if (i > 5 && i <= 10)
						{
							amount_won2 = "1000 KM";
						}
						else if (i > 10 && i <= 15)
						{
							amount_won2 = "32000 KM";
						}
					}
				}

				i++;
			} while ((flag == true) && i <= 15 && choice3 != "q" && choice3 != "Q");

			system("CLS");
			if (flag == true && (choice3 == "q" || choice3 == "Q"))
			{
				cout << "You won " << amount_won << "." << endl;
			}
			else if (i == 16)
			{
				cout << "Congradulation you are a millionaire. You won " << amount_won << "." << endl;
			}
			else
			{
				cout << "The answer is not correct." << endl;
				cout << "You won " << amount_won2 << "." << endl;
			}

			cout << "Enter y / Y to begin again or n / N to end: ";

			cin >> choice2;

			while (choice2 != "y" && choice2 != "Y" && choice2 != "n" && choice2 != "N")
			{
				cout << "Invalid input. Try again: ";
				cin >> choice2;
			}
		} while (choice2 == "y" || choice2 == "Y");

		if (choice2 == "n" || choice2 == "N")
		{
			system("CLS");
			goto label;
		}
	}


	fin.close();

	return 0;
}

void Loading_Data(string a[][COLUMNS], int ROWS)
{
	ifstream fin;
	char buff[1000];

	fin.open("Millionaire.txt");

	stringstream s;

	int j = 0;

	for (int j = 0; j < ROWS; j++)
	{
		fin.getline(buff, 1000);
		s << buff;

		for (int i = 0; i < COLUMNS; i++)
		{
			s.getline(buff, 1000, ';');
			a[j][i] = (string)buff;
		}
		s << "";
		s.clear();
	}
}

void Print_Game_Title(string a)
{
	cout << "Who Wants to Be a Millionaire?" << endl;
}

void Print_Random_Question(string a[][COLUMNS], int Random_Question, int j, /*bool fifty_fifty, bool call_friend, bool ask_audience*/)
{
	cout << "QUESTION " << j << "." << endl;
	cout << "-" << a[Random_Question][1] << " (" << a[Random_Question][0] << ")" << endl;
	cout << endl;
	cout << "1 " << a[Random_Question][2] << endl;
	cout << "2 " << a[Random_Question][3] << endl;
	cout << "3 " << a[Random_Question][4] << endl;
	cout << "4 " << a[Random_Question][5] << endl;
	//cout << "Ans:  " << a[Random_Question][7] << endl;
	cout << endl;

	
bool Check_Answer(string a[][COLUMNS], string answer, int Random_Question)
{
	size_t startpos = a[Random_Question][7].find_first_not_of(" \t");

	if (string::npos != startpos)
	{
		a[Random_Question][7] = a[Random_Question][7].substr(startpos);
	}

	if (a[Random_Question][7] == answer)
	{
		return true;
	}
	else
	{
		return false;
	}

}