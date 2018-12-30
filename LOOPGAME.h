#ifndef LOOPGAME_H_INCLUDED
#define LOOPGAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define Max 100
#define max_line 1000
typedef struct player
{
    int score;
    char name[100];
    int rank;
}player;
typedef struct time_game
{
    int mins;
    int hours;
    int secs;
}time_game ;
void swap(int*a,int*b);
struct time_game split_time(long long total_seconds);
void fill_array(int array[Max][Max], int size, int ch);
void copy_2array(int a1[Max][Max],int a2[Max][Max] , int size);
int found_line(int horizontal[][Max], int vertical[][Max], int size, int p1, int p2, int p3, int p4);
int found_boxes(int h[][Max], int v[][Max], int size, int p1, int p2, int p3, int p4);
int may_be_boxes(int h[][Max], int v[][Max], int size, int p1, int p2, int p3, int p4);
void position_boxes(int boxes[][Max],int h[][Max], int v[][Max], int size, int p1, int p2, int p3, int p4, int ch, int color_num, int color_boxes[][Max]);
void undo_line(int horizontal[][Max], int vertical[][Max], int p1[], int p2[], int p3[], int p4[], int num);
void redo_line(int horizontal[][Max], int vertical[][Max], int p1[], int p2[], int p3[], int p4[], int num);
void get_int(int* input_int);
void get_point(int*p1,int*p2,int grid[][Max],int h_lines[][Max], int v_lines[][Max], int size, char name1[],char name2[],int mov1,int sco1,int mov2,int sco2,int turn,int color[][Max],int boxes[][Max],int* inp,int bo,long long* time, int lines);
void undo(int* g,int boxes[][Max],int h_lines[][Max],int v_lines[][Max],int size,int save_p1[Max],int save_p2[Max],int save_p3[Max],int save_p4[Max],int* mov1,int* sco1,int* mov2,int* sco2,int* turn,int save_color[][Max],int* bo,int* lines);
void redo(int* g,int boxes[][Max],int h_lines[][Max],int v_lines[][Max],int size,int save_p1[Max],int save_p2[Max],int save_p3[Max],int save_p4[Max],int* mov1,int* sco1,int* mov2,int* sco2,int* turn,int save_color[][Max],int* bo,int* lines);
void get_point1(int*p1,int*p2,int grid[][Max],int h_lines[][Max], int v_lines[][Max], int size, char name1[],char name2[],int mov1,int sco1,int mov2,int sco2,int turn,int color[][Max],int boxes[][Max],int bo,long long* time ,int last_p1 , int last_p2, int lines);
void print_game(int p1,int p2,int p3,int p4,int grid[][Max],int h_lines[][Max], int v_lines[][Max], int size,char name1[],char name2[],int* mov1,int* sco1,int* mov2,int* sco2,int* turn,int boxes[][Max],int* bo,int save_color[][Max],int input,long long* time,int* lines);
void read_array_from_file(int size,int array[Max][Max],char name_file[] , FILE *file);
void read_array1D(int r,int array[r],char name_file[] ,FILE *file);
void load_game(FILE *file,int size ,int h_lines[Max][Max],int v_lines[Max][Max],int boxes[Max][Max],int save_color[Max][Max],char name1[],char name2[],int* sco1 ,int* sco2,int* mov1 , int* mov2 , int* g,int* bo,int* t, int save_p1[],int save_p2[],int save_p3[],int save_p4[],char name_file[],int* lines);
void save_game(int size ,int h_lines[Max][Max],int v_lines[Max][Max],int boxes[Max][Max],int save_color[Max][Max],char name1[],char name2[],int sco1 ,int sco2,int mov1 , int mov2 , int g,int bo,int t, int save_p1[],int save_p2[],int save_p3[],int save_p4[],char name_file[],int lines);
void print_line(int size , char name1[],char name2[],int*sco1 , int*sco2, int save_load , char name_file_load[]);
void com_player(int* p1 ,int* p2 ,int* p3 ,int* p4 ,int h[][Max] , int v[][Max] , int size , int t);
void print_line_com(int size , char name1[],char name2[],int*sco1 , int*sco2, int save_load , char name_file_load[]);
void scores_file(FILE* file, player p_win ,char name_file[]);
void Rank(char name_file[]);
void print_game_htp(int p1,int p2,int p3,int p4,int grid[][Max],int h_lines[][Max], int v_lines[][Max], int size,char name1[],char name2[],int* mov1,int* sco1,int* mov2,int* sco2,int* turn,int boxes[][Max],int* bo,int save_color[][Max],int* lines,int f);
void how_to_play(int size);
int scanf_f(char name_file[],char names_files[][100]);
#endif // LOOPGAME_H_INCLUDED
