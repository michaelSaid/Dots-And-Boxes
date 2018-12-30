#include "main_menu.h"
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void color_text(int k)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
void welcomeScreen(int * scr) {
    printf("\t\t\t\t    ");
    write_word_delay("Dots & boxes",150);
        printf("\t\t\t\t    ");
    write_word_delay("Welcome to our game",25);
        printf("\t\t\t\t    ");
    write_word_delay("Press enter to start",25);
    fflush(stdin);
    while(getchar() != '\n');
    fflush(stdin);
    (*scr)++;
}
void printScreen(int index , int OPTIONS_NUMBER , char OPTIONS[][100]) {
    int i = 1;
    printf("\n\n\n\n\n\n");
    for (i = 1; i <= OPTIONS_NUMBER; i++) {
        if (index == i) {
            printf("   ");
            color_text(11);
        }
        printf(OPTIONS[i - 1]);
        printf("\n");
        color_text(15);
    }
}
void menuInput(int * input, int * index, int * screen,int OPTIONS_NUMBER) {
    while(TRUE) {
            fflush(stdin);
        *input = _getch();
            Beep (1500,25);
            Sleep(50);
        if (*input == SPECIAL_CHAR) {
            *input = _getch();
            if (*input == DOWN_ARROW) {
                (*index)++;
                if (*index > OPTIONS_NUMBER) {
                    *index = 1;
                }
                break;
            } else if (*input == UP_ARROW) {
                (*index)--;
                if (*index < 1) {
                    *index = OPTIONS_NUMBER;
                }
                break;
            }
        } else if (*input == ENTER) {
            *screen +=  *index;
            break;
        }
    }
}
int confirmBox( char process[]) {
    system(CLEAR_COMMAND);
    printf("Are you sure you want to %s ?\n",process);
    printf("yes\n");
    color_text(11);
    printf("   no\n");
    color_text(15);
    int choice = 0;
    int input = _getch();
    Beep (500,3);
    Sleep(30);
   int  answer = -1;
    while (answer == -1) {
        if (input == ENTER) {
            answer = choice;
        } else if (input == SPECIAL_CHAR) {
            input = _getch();
            if (input == UP_ARROW) {
                if (choice != 1) {
                    system(CLEAR_COMMAND);
    printf("Are you sure you want to %s ?\n",process);
                    color_text(11);
                    printf("   yes\n");
                    color_text(15);
                    printf("no\n");
                    choice = 1;
                }
            } else if (input == DOWN_ARROW) {
                if (choice != 0) {
                    system(CLEAR_COMMAND);
    printf("Are you sure you want to %s ?\n",process);
                    printf("yes\n");
                    color_text(11);
                    printf("   no\n");
                    color_text(15);
                    choice = 0;
                }
            } else {

                input = _getch();
                Beep (500,3);
                Sleep(30);
            }
        } else {
            input = _getch();
            Beep (500,3);
            Sleep(30);
        }
    }
    return answer;
}
void write_word_delay(char word[] ,int sec)
{
    int i=0 ;
    while(word[i]!='\0')
    {
        printf("%c",word[i]);
        delay(sec);
        i++;
    }
    printf("\n\n");
}
void overview()
{
     Sleep(50);
    color_text(14);
    write_word_delay("Dots and Boxes is a pencil-and-paper game for two players (sometimes more).",20);
    write_word_delay("It was first published in the 19th century by Edouard Lucas, who called it la pipopipette.",20);
    write_word_delay("The goal of the game is to connect dots and take as much boxes as you can and mark them with your color.",20);
    write_word_delay("Score is calculated based on the number of boxes you have. The game ends when no more lines can be placed.\n The winner is the player with the most points.",20);
    write_word_delay("When a player connects dots, it may produce a chain,\n a chain is a groups of adjacent boxes in which any move gives all the boxes in the chain to the player.",20);
    color_text(15);
}
