#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
void delay(unsigned int mseconds);
void welcomeScreen(int * scr) ;
void printScreen(int index , int OPTIONS_NUMBER , char OPTIONS[][100]);
void menuInput(int * input, int * index, int * screen ,int OPTIONS_NUMBER);
void color_text(int k);
int confirmBox( char process[]);
void write_word_delay(char word[],int sec);
void overview();
static const int SPECIAL_CHAR = 224;
static const int DOWN_ARROW = 80;
static const int UP_ARROW = 72;
static const int RIGHT_ARROW =77 ;
static const int LIFT_ARROW = 75;
static const int ENTER = 13;
static const int ESC = 27;
static const int UNDO = 26;
static const int REDO = 25;
static const int SAVE = 1;
static const int LOAD = 0;
static const int PLAY = 2;
static const int OPTIONS_NUMBER_MENU = 6;
static const char OPTIONS_MENU[][100] = {
    "1. Start game",
    "2. Load game",
    "3. Overview",
    "4. How to play",
    "5. Top 10 players",
    "6. Exit"
};
static const char com_name[]= {
    "Computer"
};
static const char OPTIONS_START_GAME[][100] = {
    "1. Human VS Human",
    "2. Human VS Computer",
    "3. Back"
};
static const char CLEAR_COMMAND[] = "cls||clear";
#endif // MAIN_MENU_H_INCLUDED
