#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

// Global Variables
const int total_questions = 20;
int question_counter = 0;
string questions[total_questions]; //from index 0 to 4 in questions array (questions related to Category 1)
                                   //from index 4 to 9 in questions array (questions related to Category 2)
                                   //from index 10 to 14 in questions array (questions related to Category 3)
                                   //from index 14 to 19 in questions array (questions related to Category 4)

string option1[total_questions];
string option2[total_questions];
string option3[total_questions];
string option4[total_questions];
int correct_option[total_questions];

int count = -1;
string player[5];
int score[5] = {0, 0, 0, 0, 0};

// Functions Declaration
void quiz_heading();
char menu_option();
int highest_score();
int lowest_score();
int select_category();
void add_data();
void add_question(string, string, string, string, string, int);
void ask_question(int);
void halt();
void view_players();
void reset_score();
void help();

//Main function
int main()
{

    char option = 'a';
    int number;
    char changeUser;
    string name;
    int highestindex;
    int lowestindex;
    add_data();

start:
    quiz_heading();
    halt();
    system("CLS");

    while ((option != 'q') && (option != 'Q'))
    {

        option = menu_option();
        system("CLS");

        if (option == 'T' || option == 't')
        {
            // Write your code here
            highestindex = highest_score();
            halt();
            system("CLS");
        }

        if (option == 'L' || option == 'l')
        {
            int low = lowest_score();
        }
        if (option == 'S' || option == 's')
        {
            number = select_category();
            halt();
            system("CLS");

            if (number == 1)
            {
                // Write your code here
                for (int i = 0; i < 5; i++)
                {
                    ask_question(i);
                }
                halt();
            }

            if (number == 2)
            {
                // Write your code here
                for (int i = 5; i < 10; i++)
                {
                    ask_question(i);
                }
                halt();
            }

            if (number == 3)
            {
                // Write your code here
                for (int i = 10; i < 15; i++)
                {
                    ask_question(i);
                }
                halt();
            }

            if (number == 4)
            {
                // Write your code here
                for (int i = 15; i < 20; i++)
                {
                    ask_question(i);
                }
                halt();
            }

        repeat:
            cout << endl
                 << "Your Quiz finished. If you want to Continue as " << player[count] << endl
                 << "Press Y otherwise Press N" << endl;
            cin >> changeUser;
            if (changeUser == 'N' || changeUser == 'n')
            {
                goto start;
                system("CLS");
            }
            else if (changeUser == 'Y' || changeUser == 'y')
            {
                system("CLS");
            }
            else
            {
                cout << "You entered invalid option" << endl;
                goto repeat;
                system("CLS");
            }
        }

        if (option == 'v' || option == 'V')
        {
            // Write your code here
            view_players();
            halt();
        }

        if (option == 'R' || option == 'r')
        {
            // Write your code here
            reset_score();
        }

        if (option == 'H' || option == 'h')
        {
            // Write your code here
            help();
        }
        if (option == 'Q' || option == 'q')
        {
            cout << "Quiz Ended" << endl;
        }
    }
    return 0;
}

// Functions Definition

void quiz_heading()
{
    /* this function will show the main heading of welcome to the quiz game and then ask the player name and the store the name in player array
    */

    // Write your code here
    if (count != 5)
    {
        count++;
    }
    if (count < 5)
    {
        cout << "                   Welcome to the Quiz Game                 " << endl;
        cout << "____________________________________________________________" << endl;
        cout << "Username: ";
        cin >> player[count];
        system("CLS");
    }
    else
    {
        cout << "no more space for players." << endl;
        count = 4;
    }
}

char menu_option()
{
    char op;
    cout << "**********************************************************" << endl;
    cout << "                 MENU OF THE GAME                         " << endl;
    cout << "**********************************************************" << endl;
    cout << "> Press S to Start the Game." << endl;
    cout << "> Press V to View the Score of all Players." << endl;
    cout << "> Press T to View the Highest Score of the Player." << endl;
    cout << "> Press L to View the Lowest Score of the Player." << endl;
    cout << "> Press R to Reset the Score of current Player." << endl;
    cout << "> Press H for Help." << endl;
    cout << "> Press Q to Quit the Game." << endl;
    cin >> op;
    return op;
}

int highest_score()
{
    /*
    this function will search the whole array of scores and return the index on which the highest score is present.
    */
    // Write your code here
    int x;
    x = 0;
    count = count + 1;
    cout << left << setw(20) << "Player" << setw(20) << "Highest Score" << endl;
    while (x < 5)
    {
        if (score[count] < score[x])
        {
            score[count] = score[x];
            cout << left << setw(20) << player[x] << "\t" << setw(20) << score[x] << endl;
            count = count + 1;
            x = x + 1;
            break;
        }
    }
    return x;
}

int lowest_score()
{

    int smallest = score[0];
    int postion;

    for (int i = 0; i < 5; i++)

    {
        if (score[i] != 0)
        {
            if (score[i] < smallest)
            {
                smallest = score[i];
                postion = i;
            }
        }
    }
    cout << "lowest score is :" << smallest << " of " << player[postion] << endl;
    return smallest;
}

int select_category()
{
    /*
    this function will show the user about the available categories of your Quiz game and then ask the user to select 1 category and then return that category to main fuction. 
    */
    // Write your code here
    int number;
    cout << "Select an Option from the following Categories" << endl;
    cout << "1. Sports"
         << "                    "
         << "2. Programming" << endl;
    cout << "3. Movies"
         << "                    "
         << "4. Science    " << endl;
    cin >> number;
    return number;
}

void add_data()
{
    /*
    this function will call the add_question("Question", "Option 1", "Option 2", "Option 3", "Option 4", correct option number) 20 times
    and add all the questions related to your categories.
    */
    // Write your code here
    add_question("Q. Chukker and Mallet terms are associated with the game of- ", "1. Water Polo.", "2. Tennis. ", "3. Polo. ", "4. Basket Ball. ", 3);
    add_question("Q. Who among the following Tennis Player has won the US Open Men's Title 2020?", "1. Roger Federer.", "2. Novak Djokovic. ", "3. Rafael Nadal.", "4. Dominic Thiem.", 4);
    add_question("Q. who was the captain of pakistan cricket team of icc world cup t20 2009?", "1. Shoaib Malik.", "2. Younas Khan. ", "3. Salman Butt.", "4. Shahid Afridi.", 2);
    add_question("Q. which country created hockey?", "1. Pakistan .", "2. England . ", "3. Iran     .", "4.None of the above.", 2);
    add_question("Q. What is the national sport in Japan?", "1. Hockey", "2. Sumo wrestling", "3.Cricket", "4. Football", 2);
    add_question("Q. Which is not a High Level Language?", "1. C++", "2. Kobol . ", "3. Java  .", "4. Python", 2);
    add_question("Q. Special symbol permitted with in the identifier name.", "1. @.", "2. $. ", "3. -.", "4. _.", 4);
    add_question("Q. To print a float value which format specifier can be used?.", "1. %f.", "2. %lf. ", "3. %Lf.", "4. None of the above.", 1);
    add_question("Q. Choose the Object oriented programming language from below.", "1.C++ ", "3.NET ", "2.Java", "4.All of the Above . ", 4);
    add_question("Q. in C language, when the ration of loop repetion is unknown then the:", "1. while loop is used", "2. for loop is used", "3. do-while loop is used", "4.None", 1);
    add_question("Q. Which Disney movie was the first to be nominated for an Oscar?. ", "1. Beauty and the Beast.", "2. Snow White and the Seven Dwarf's.", "3. Lion King. ", "4. Aladin. ", 1);
    add_question("Q. The following dialogue is from which movie : what we do in life......echoes in eternity. ?", "1. Any Given Sunday.", "2. American Gangster. ", "3. Gladiator.", "4. Predator.", 3);
    add_question("Q. Who played Jack in Titanic? ", "1. Bill Paxton.", "2. Leonardo DiCaprio. ", "3. Frances Fisher.", "4. Victor Garbor.", 2);
    add_question("Q. Where did Harry Potter go to school?", "1. Hogwarts.", "2. Stanford University. ", "3. Eastwood High.", "4. Star Reachers.", 1);
    add_question("Q. What year was the first Toy Story film released in cinemas?", "1. 2000", "2. 1995", "3. 2002", "4. 1992", 2);
    add_question("Q. What is the biggest planet in our solar system?.", "1.Pluto. ", "2.Jupiter . ", "3. Mars", "4. None", 2);
    add_question("Q. How many hearts do octopuses have?.", "1.One. ", "2.Ten . ", "3. Five.  ", "4.Three  . ", 4);
    add_question("Q. Which two planets lacks moon?.", "1.Mars and Mercury. ", "2.Mercury and Venus . ", "3.Mars and Venus.  ", "4.venus and Jupiter  . ", 2);
    add_question("Q. What is the most abundant gas in the Earth’s atmosphere?.", "1.Nitrogen. ", "2.Oxygen . ", "3.Hydrogen  ", "4.Neon . ", 1);
    add_question("Q. At what temperature are Farenheit and Celsius equal to each other?", "1.  -40", "2. 60", "3. 180", "4. None", 1);
}

void add_question(string q, string o1, string o2, string o3, string o4, int ans)
{
    /*
    this function will store the questions in your related global parallel arrays defined at the begining of the code 
    */
    // Write your code here

    questions[question_counter] = q;
    option1[question_counter] = o1;
    option2[question_counter] = o2;
    option3[question_counter] = o3;
    option4[question_counter] = o4;
    correct_option[question_counter] = ans;
    question_counter++;
}

void ask_question(int index)
{
    /*
    this function will receive the index of the question that you want to ask the user and then show the question and its available
    options. then ask the user about the correct option and then check whether the user entered the correct option or not. then it will
    calculate the marks for the current logged in user.
    */
    // Write your code here
    cout << add_question[index] << endl;
    cout << left << setw(80) << questions[index] << endl;
    cout << left << setw(80) << option1[index] << setw(80) << option2[index] << endl;
    cout << left << setw(80) << option3[index] << setw(80) << option4[index] << endl;
    int input;
    cout << "Enter your option number ";
    cin >> input;
    if (input == correct_option[index])
    {
        cout << "Hurray!!! Your Answer is correct!!!" << endl;
        score[count] = score[count] + 100;
    }
    else
    {
        cout << "Your Answer is incorrect." << endl;
        score[count] = score[count] - 50;
    }
}

void halt()
{
    cout << "Press any key to continue..." << endl;
    getch();
}

void view_players()
{
    /*
    this function will show all the available players and their scores
    */
    // Write your code here
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(20) << "Players" << setw(20) << "Scores" << endl;
        cout << left << setw(20) << player[i] << setw(20) << score[i] << endl;
    }
}

void reset_score()
{
    /*
    this function will reset the score of the current player.
    */
    // Write your code here
    for( int i = 0 ; i < 5; i++ )
    {
       if(count==i)
       {
           cout<<player[i];
           cout<<"              ";
           score[i]={0};
           cout<<score[i]<<endl;
       }
    
    }
    halt();
    
 
     
}

void help()
{
    cout << "Here are some of the Rules and Regulations of the Game." << endl
         << endl;
    cout << "Firstly, there will be no hooting and shouting while playing the game." << endl;
    cout << "There are 4 categories in the Game." << endl;
    cout << "You can choose any one of them." << endl;
    cout << "Each category consists of 5 Questions." << endl;
    cout << "Each Question carries 100 Marks." << endl;
    cout << "Correct answer will give you +100 marks whereas Wrong answer will give you -50 marks" << endl;
    halt();
}