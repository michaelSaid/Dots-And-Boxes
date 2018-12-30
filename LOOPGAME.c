#include "LOOPGAME.h"
#include "main_menu.h"
void swap(int*a,int*b)
{
    int t = *a;
    *a = *b ;
    *b = t ;
    return;
}
struct time_game split_time(long long total_seconds)
{
    time_game t ;
    t.hours = (total_seconds/3600)%24;
    t.mins =  (total_seconds%3600)/60;
    t.secs =  (total_seconds%3600) - t.mins*60;
    return t ;
}
void copy_2array(int a1[Max][Max],int a2[Max][Max], int size)
{
    int i, j ;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            a1[i][j]=a2[i][j];
        }
    }
}
void fill_array(int array[Max][Max], int size, int ch)    // function to fill arrays with char
{
    int i, j ;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            array[i][j]=ch;
        }
    }
}
int found_line(int horizontal[][Max], int vertical[][Max], int size, int p1, int p2, int p3, int p4)
{
    int founded=0;
    if(horizontal[p1][p2]==196&&p1==p3)
    {
        founded = 1;
    }
    else if(vertical[p1][p2]==179&&p2==p4)
    {
        founded = 2;
    }
    else
    {
        founded = 0 ;
    }
    return founded ;
}
int found_boxes(int h[][Max], int v[][Max], int size, int p1, int p2, int p3, int p4)
{
    int found = 0;
    if(p1>0&&p1<size&&p1==p3)
    {
        if((h[p1][p2]==h[p1-1][p2]&&v[p1-1][p2+1]==179&&v[p1-1][p2]==179)||(h[p1][p2]==h[p1+1][p2]&&v[p1][p2]==179&&v[p1][p2+1]==179))
        {
            found = 1 ;
            if(h[p1][p2]==h[p1-1][p2]&&h[p1][p2]==h[p1+1][p2]&&v[p1][p2]==179&&v[p1][p2+1]==179&&v[p1][p2]==179&&v[p1-1][p2+1]==179&&v[p1][p2]==179&&v[p1-1][p2]==179)
            {

                found = 2 ;
            }

        }
    }
    else if(p2>0&&p2<size&&p2==p4)
    {
        if((v[p1][p2]==v[p1][p2-1]&&h[p1][p2-1]==196&&h[p1+1][p2-1]==196)||(v[p1][p2]==v[p1][p2+1]&&h[p1][p2]==196&&h[p1+1][p2]==196))
        {
            found = 1 ;
            if(v[p1][p2]==v[p1][p2-1]&&v[p1][p2]==v[p1][p2+1]&&h[p1][p2]==196&&h[p1][p2-1]==196&&h[p1][p2]==196&&h[p1+1][p2-1]==196&&h[p1][p2]==196&&h[p1+1][p2]==196)
            {
                found = 2;
            }
        }
    }
    else if (p1==p3&&h[p1][p2]==h[p1+1][p2]&&v[p1][p2]==179&&v[p1][p2+1]==179&&p1==0)
    {
        found = 1;
    }
    else if (p1==p3&&h[p1][p2]==h[p1-1][p2]&&v[p1-1][p2]==179&&v[p1-1][p2+1]==179&&p1==size-1)
    {
        found = 1;
    }
    else if (p2==p4&&p2==0&&v[p1][p2]==v[p1][p2+1]&&h[p1][p2]==196&&h[p1+1][p2]==196)
    {
        found = 1;
    }
    else if(p2==p4&&p2==size-1&&v[p1][p2]==v[p1][p2-1]&&h[p1][p2-1]==196&&h[p1+1][p2-1]==196)
    {
        found = 1 ;
    }
    else
    {
        found = 0 ;
    }
    return found ;

}

int may_be_boxes(int h[][Max], int v[][Max], int size, int p1, int p2, int p3, int p4)
{
    int found = 0;
    if(p1>0&&p1<size&&p1==p3)
    {
        if(((h[p1-1][p2]==196)&&(v[p1-1][p2+1]==179||v[p1-1][p2]==179))||((h[p1+1][p2]==196)&&(v[p1][p2]==179||v[p1][p2+1]==179))||(h[p1-1][p2]==h[p1+1][p2])||(v[p1-1][p2+1]==179&&v[p1-1][p2]==179)||(v[p1][p2]==179||v[p1][p2+1]==179))
        {
            found = 1 ;

        }
    }
    else if(p2>0&&p2<size&&p2==p4)
    {
        if((v[p1][p2-1]==179&&(h[p1][p2-1]==196||h[p1+1][p2-1]==196))||(v[p1][p2+1]==179&&(h[p1][p2]==196||h[p1+1][p2]==196))||(v[p1][p2-1]==v[p1][p2+1])||(h[p1][p2-1]==196&&h[p1+1][p2-1]==196)||(h[p1][p2]==196&&h[p1+1][p2]==196))
        {
            found = 1 ;
        }
    }
    else if (p1==p3&&(((h[p1+1][p2]==196)&&(v[p1][p2]==179||v[p1][p2+1]==179))||(v[p1][p2]==179&&v[p1][p2+1]==179))&&p1==0)
    {
        found = 1;
    }
    else if (p1==p3&&(((h[p1-1][p2]==196&&(v[p1-1][p2]==179||v[p1-1][p2+1]==179))||(v[p1-1][p2]==179&&v[p1-1][p2+1]==179)))&&p1==size-1)
    {
        found = 1;
    }
    else if (p2==p4&&p2==0&&((v[p1][p2+1]==179&&(h[p1][p2]==196||h[p1+1][p2]==196))||(h[p1][p2]==196&&h[p1+1][p2]==196)))
    {
        found = 1;
    }
    else if(p2==p4&&p2==size-1&&((v[p1][p2-1]==179&&(h[p1][p2-1]==196||h[p1+1][p2-1]==196))||(h[p1][p2-1]==196&&h[p1+1][p2-1]==196)))
    {
        found = 1 ;
    }
    else
    {
        found = 0 ;
    }
    return found ;
}
void position_boxes(int boxes[][Max],int h[][Max], int v[][Max], int size, int p1, int p2, int p3, int p4, int ch, int color_num, int color_boxes[][Max])
{
    if(found_boxes(h,v,size,p1,p2,p3,p4)==2&&p2==p4)
    {
        boxes[p1][p2-1]=ch;                                                    //compare the middle vertical line with the left and right to draw boxes
        boxes[p1][p2]=ch;
        color_boxes[p1][p2-1]=color_num;
        color_boxes[p1][p2]=color_num;
    }
    else if (found_boxes(h,v,size,p1,p2,p3,p4)==1&&p2>0&&p2<size&&p2==p4)
    {
        if((v[p1][p2]==v[p1][p2-1]&&h[p1][p2-1]==196&&h[p1+1][p2-1]==196))
        {
            boxes[p1][p2-1]=ch;
            color_boxes[p1][p2-1]=color_num;
        }
        else
        {
            boxes[p1][p2]=ch;
            color_boxes[p1][p2]=color_num;
        }
    }
    else if(found_boxes(h,v,size,p1,p2,p3,p4)==2&&p1==p3)                     //compare the middle horizontal line with the up and down to draw boxes
    {
        boxes[p1-1][p2]=ch;
        boxes[p1][p2]=ch;
        color_boxes[p1-1][p2]=color_num;
        color_boxes[p1][p2]=color_num;
    }
    else if (found_boxes(h,v,size,p1,p2,p3,p4)==1&&p1>0&&p1<size&&p1==p3)
    {
        if((h[p1][p2]==h[p1-1][p2]&&v[p1-1][p2+1]==179&&v[p1-1][p2]==179))
        {
            boxes[p1-1][p2]=ch;
            color_boxes[p1-1][p2]=color_num;
        }
        else
        {
            boxes[p1][p2]=ch;
            color_boxes[p1][p2]=color_num;
        }
    }
    else if (found_boxes(h,v,size,p1,p2,p3,p4)==1&&p2==p4&&p2==0)              //checks the bordered lines to draw boxes
    {
        boxes[p1][p2]=ch;
        color_boxes[p1][p2]=color_num;
    }
    else if (found_boxes(h,v,size,p1,p2,p3,p4)==1&&p2==p4&&p2==size-1)
    {
        boxes[p1][p2-1]=ch;
        color_boxes[p1][p2-1]=color_num;
    }
    else if(found_boxes(h,v,size,p1,p2,p3,p4)==1&&p1==p3&&p1==0)
    {
        boxes[p1][p2]=ch;
        color_boxes[p1][p2]=color_num;
    }
    else if (found_boxes(h,v,size,p1,p2,p3,p4)==1&&p1==p3&&p1==size-1)
    {
        boxes[p1-1][p2]=ch;
        color_boxes[p1-1][p2]=color_num;
    }
}
void undo_line(int horizontal[][Max], int vertical[][Max], int p1[], int p2[], int p3[], int p4[], int num)
{
    if(p1[num]==p3[num])
    {
        horizontal[p1[num]][p2[num]] = 255 ;
    }
    else if(p2[num]==p4[num])
    {
        vertical[p1[num]][p2[num]] = 255 ;
    }
}
void redo_line(int horizontal[][Max], int vertical[][Max], int p1[], int p2[], int p3[], int p4[], int num)
{
    if(p1[num]==p3[num])
    {
        horizontal[p1[num]][p2[num]] = 196 ;
    }
    else if(p2[num]==p4[num])
    {
        vertical[p1[num]][p2[num]] = 179 ;
    }
}
void get_int(int* input_int)
{
    char string_input[5000];
    gets(string_input);
    *input_int = string_input[0] - '0';
    while(!(*input_int>1&&*input_int<=9)||string_input[1]!='\0')
    {
        printf("Please Enter The Right Input!:\n");
        gets(string_input);
        *input_int = string_input[0] - '0';
    }
}
void get_point(int*p1,int*p2,int grid[][Max],int h_lines[][Max], int v_lines[][Max], int size, char name1[],char name2[],int mov1,int sco1,int mov2,int sco2,int turn,int color[][Max],int boxes[][Max],int* inp,int bo,long long* time, int lines)
{
    int i, j,ind_x=0,ind_y=0,input=*inp,g=0;
    while(1)
    {
        clock_t time_els = clock();
        if(g>0)
        {
            input = _getch();
            if(input==UNDO||input==REDO||input==ESC)
            {
                *inp = input ;
                break;
            }
        }
        if(input==ENTER)
        {
            *p2=ind_x;
            *p1=ind_y;
            break;
        }
        else if(input==SPECIAL_CHAR)
            input = _getch();
        else
        {
            input = _getch();
            input = _getch();
        }
        if(input==UP_ARROW)
        {
            ind_y--;
            if(ind_y<0)
            {
                ind_y=size-1;
            }
        }
        else if(input==DOWN_ARROW)
        {
            ind_y++;
            if(ind_y>size-1)
            {
                ind_y=0;
            }
        }
        else if(input==RIGHT_ARROW)
        {
            ind_x++;
            if(ind_x>size-1)
                ind_x=0;
        }
        else if(input==LIFT_ARROW)
        {
            ind_x--;
            if(ind_x<0)
                ind_x=size-1;
        }
        system("cls");
        color_text(10);
        printf("%s's moves : %d \t\t",name1,mov1);
        printf("%s's score : %d \n\n",name1,sco1);
        color_text(ENTER);
        printf("%s's moves : %d \t\t",name2,mov2);
        printf("%s's score : %d \n\n",name2,sco2);
        color_text(15);
        printf("to undo move press ctrl+z else to redo ctrl+y ..to exit Esc\n\n");
        if(turn==0)
        {
            color_text(10);
            printf("%s's turn\n\n",name1);
        }
        else
        {
            color_text(ENTER);
            printf("%s's turn\n\n",name2);
        }
        color_text(15);
        for(i=0; i<size; i++)
        {
            for(j=0; j<size; j++)
            {
                if(input==UP_ARROW&&j==ind_x&&i==ind_y)
                {
                    if(turn==0)
                        color_text(10);
                    else color_text(ENTER);
                }
                else if(input==DOWN_ARROW&&j==ind_x&&i==ind_y)
                {
                    if(turn==0)
                        color_text(10);
                    else color_text(ENTER);
                }
                else if(input==RIGHT_ARROW&&j==ind_x&&i==ind_y)
                {
                    if(turn==0)
                        color_text(10);
                    else color_text(ENTER);
                }
                else if(input==LIFT_ARROW&&j==ind_x&&i==ind_y)
                {
                    if(turn==0)
                    {
                        color_text(10);
                    }
                    else color_text(ENTER);
                }
                printf("%c",grid[i][j]);
                color_text(15);
                printf("%c%c",h_lines[i][j],h_lines[i][j]);
            }
            printf("\n");
            for(j=0; j<size; j++)
            {
                printf("%c",v_lines[i][j]);
                color_text(color[i][j]);
                printf("%c%c",boxes[i][j],boxes[i][j]) ;
                color_text(15);
            }
            printf("\n");
        }
        g++;
        printf("\n\nboxes%d\n\nLines:%d\n\n",bo,lines);
        time_els = clock() - time_els ;
        (*time)+=time_els;
        time_game t = split_time(*time/CLOCKS_PER_SEC);
        printf("hours: %d\nminutes: %d\nseconds: %d\n",t.hours,t.mins,t.secs);
    }
}
void undo(int* g,int boxes[][Max],int h_lines[][Max],int v_lines[][Max],int size,int save_p1[Max],int save_p2[Max],int save_p3[Max],int save_p4[Max],int* mov1,int* sco1,int* mov2,int* sco2,int* turn,int save_color[][Max],int* bo,int* lines)
{
    (*g)--;
    if(*turn==1)
    {
        if(!found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]))
        {
            (*mov1)--;
            *turn = 0 ;
        }
        else
        {
            (*mov2)--;
            *turn = 1;
            *sco2-=found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]);
        }
        position_boxes(boxes,h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g],255,0,save_color);
    }
    else
    {
        if(found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]))
        {
            (*mov1)--;
            *turn = 0 ;
            *sco1-=found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]);
        }
        else
        {
            (*mov2)--;
            *turn = 1;
        }
        position_boxes(boxes,h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g],255,0,save_color);
    }
    *bo-=found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]);
    (*lines)++;
    undo_line(h_lines,v_lines,save_p1,save_p2,save_p3,save_p4,*g);
}
void redo(int* g,int boxes[][Max],int h_lines[][Max],int v_lines[][Max],int size,int save_p1[Max],int save_p2[Max],int save_p3[Max],int save_p4[Max],int* mov1,int* sco1,int* mov2,int* sco2,int* turn,int save_color[][Max],int* bo,int* lines)
{
    redo_line(h_lines,v_lines,save_p1,save_p2,save_p3,save_p4,*g);
    if(*turn==0)
    {
        position_boxes(boxes,h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g],219,10,save_color);
        if(!found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]))
        {
            (*mov1)++;
            *turn = 1 ;
        }
        else
        {
            (*mov1)++;
            *turn = 0;
            *sco1+=found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]);
        }
    }
    else
    {
        position_boxes(boxes,h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g],219,ENTER,save_color);
        if(found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]))
        {
            (*mov2)++;
            *turn = 1 ;
            *sco2+=found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]);
        }
        else
        {
            (*mov2)++;
            *turn = 0;
        }
    }
    *bo +=found_boxes(h_lines,v_lines,size,save_p1[*g],save_p2[*g],save_p3[*g],save_p4[*g]);
    (*lines)--;
    (*g)++;
}
void get_point1(int*p1,int*p2,int grid[][Max],int h_lines[][Max], int v_lines[][Max], int size, char name1[],char name2[],int mov1,int sco1,int mov2,int sco2,int turn,int color[][Max],int boxes[][Max],int bo,long long* time,int last_p1, int last_p2, int lines)
{
    int i, j,ind_x=last_p2,ind_y=last_p1,input;
    while(1)
    {
        clock_t time_els = clock();
        input = _getch();
        if(input==ENTER) //enter button
        {
            *p2=ind_x;
            *p1=ind_y;
            break;
        }
        else if(input==SPECIAL_CHAR) input = _getch();
        if(input==UP_ARROW)
        {
            ind_y--;
            if(ind_y<0)
            {
                ind_y=size-1;
            }
        }
        else if(input==DOWN_ARROW)
        {
            ind_y++;
            if(ind_y>size-1)
            {
                ind_y=0;
            }
        }
        else if(input==RIGHT_ARROW)
        {
            ind_x++;
            if(ind_x>size-1)
                ind_x=0;
        }
        else if(input==LIFT_ARROW)
        {
            ind_x--;
            if(ind_x<0)
                ind_x=size-1;
        }
        system("cls");
        color_text(10);
        printf("%s's moves : %d \t\t",name1,mov1);
        printf("%s's score : %d \n\n",name1,sco1);
        color_text(ENTER);
        printf("%s's moves : %d \t\t",name2,mov2);
        printf("%s's score : %d \n\n",name2,sco2);
        color_text(15);
        printf("to undo move press ctrl+z else to redo ctrl+y ..to exit Esc\n\n");
        if(turn==0)
        {
            color_text(10);
            printf("%s's turn\n\n",name1);
        }
        else
        {
            color_text(ENTER);
            printf("%s's turn\n\n",name2);
        }
        color_text(15);
        for(i=0; i<size; i++)
        {
            for(j=0; j<size; j++)
            {
                if(input==UP_ARROW&&j==ind_x&&i==ind_y)
                {
                    if(turn==0)
                        color_text(10);
                    else color_text(ENTER);
                }
                else if(input==DOWN_ARROW&&j==ind_x&&i==ind_y)
                {
                    if(turn==0)
                        color_text(10);
                    else color_text(ENTER);
                }
                else if(input==RIGHT_ARROW&&j==ind_x&&i==ind_y)
                {
                    if(turn==0)
                        color_text(10);
                    else color_text(ENTER);
                }
                else if(input==LIFT_ARROW&&j==ind_x&&i==ind_y)
                {
                    if(turn==0)
                    {
                        color_text(10);
                    }
                    else color_text(ENTER);
                }
                printf("%c",grid[i][j]);
                color_text(15);
                printf("%c%c",h_lines[i][j],h_lines[i][j]);
            }
            printf("\n");
            for(j=0; j<size; j++)
            {
                printf("%c",v_lines[i][j]);
                color_text(color[i][j]);
                printf("%c%c",boxes[i][j],boxes[i][j]) ;
                color_text(15);
            }
            printf("\n");
        }
        printf("\n\nboxes%d\n\nLines:%d\n\n",bo,lines);
        time_els = clock() - time_els ;
        (*time)+=time_els;
        time_game t = split_time(*time/CLOCKS_PER_SEC);
        printf("hours: %d\nminutes: %d\nseconds: %d\n",t.hours,t.mins,t.secs);
    }
}
void print_game(int p1,int p2,int p3,int p4,int grid[][Max],int h_lines[][Max], int v_lines[][Max], int size,char name1[],char name2[],int* mov1,int* sco1,int* mov2,int* sco2,int* turn,int boxes[][Max],int* bo,int save_color[][Max],int input,long long* time,int* lines)
{
    clock_t time_els = clock();
    int i, j ;
    system("cls");
    if(!found_boxes(h_lines,v_lines,size,p1,p2,p3,p4)&&(input!=UNDO&&input!=REDO)&&input!=0)
    {
        if(*turn==1)
        {
            (*mov2)++;
            *turn = 0 ;

        }
        else
        {
            *turn = 1;
            (*mov1)++;
        }
        (*lines)--;
    }
    else if(input!=UNDO&&input!=REDO&&input!=0)
    {
        if(*turn==1)
        {
            (*mov2)++;
            *turn = 1 ;
            *sco2+=found_boxes(h_lines,v_lines,size,p1,p2,p3,p4);

        }
        else
        {
            *turn = 0;
            (*mov1)++;
            *sco1+=found_boxes(h_lines,v_lines,size,p1,p2,p3,p4);
        }
        (*lines)--;
    }
    color_text(10);
    printf("%s's moves : %d \t\t",name1,*mov1);
    printf("%s's score : %d \n\n",name1,*sco1);
    color_text(ENTER);
    printf("%s's moves : %d \t\t",name2,*mov2);
    printf("%s's score : %d \n\n",name2,*sco2);
    color_text(15);
    printf("to undo move press ctrl+z else to redo ctrl+y ..to exit Esc\n\n");
    if(*turn==0)
    {
        color_text(10);
        printf("%s's turn\n\n",name1);
    }
    else
    {
        color_text(ENTER);
        printf("%s's turn\n\n",name2);
    }
    color_text(15);
    for(i=0; i<size; i++)
    {

        for(j=0; j<size; j++)
        {
            if(i==0&&j==0)
            {
                if(*turn==0)
                {
                    color_text(10);
                }
                else color_text(ENTER);
            }
            printf("%c",grid[i][j]);
            color_text(15);
            printf("%c%c",h_lines[i][j],h_lines[i][j]);
        }

        printf("\n");
        for(j=0; j<size; j++)
        {
            printf("%c",v_lines[i][j]);
            color_text(save_color[i][j]);
            printf("%c%c",boxes[i][j],boxes[i][j]) ;
            color_text(15);
        }
        printf("\n");
    }
    if(input!=UNDO&&input!=REDO&&input!=0)
    {
        *bo+=found_boxes(h_lines,v_lines,size,p1,p2,p3,p4);
    }
    printf("\n\nboxes%d\n\nLines:%d\n\n",*bo,*lines);
    time_els = clock() - time_els ;
    (*time)+=time_els/10;
    time_game t = split_time(*time/CLOCKS_PER_SEC);
    printf("hours: %d\nminutes: %d\nseconds: %d\n",t.hours,t.mins,t.secs);
}

void read_array_from_file(int size,int array[Max][Max],char name_file[], FILE *file)
{
    int i, j ;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            fscanf(file,"%d ",&array[i][j]);
        }
        fscanf(file,"\n");
    }
}
void read_array1D(int r,int array[],char name_file[],FILE *file)
{
    int i ;
    for(i=0; i<r; i++)
    {
        fscanf(file,"%d ",&array[i]);
    }
    fscanf(file,"\n");
}
void save_game(int size,int h_lines[Max][Max],int v_lines[Max][Max],int boxes[Max][Max],int save_color[Max][Max],char name1[],char name2[],int sco1,int sco2,int mov1, int mov2, int g,int bo,int t, int save_p1[],int save_p2[],int save_p3[],int save_p4[],char name_file[],int lines)
{
    int i, j ;
    FILE *file;
    file=fopen(name_file,"w");
    fprintf(file,"%d\n",size);
    fprintf(file,"%d\n",g);
    fprintf(file,"%d\n",lines);
    fprintf(file,"%d %d\n",sco1,mov1);
    fprintf(file,"%d %d\n",sco2,mov2);
    fprintf(file,"%d\n",t);
    fprintf(file,"%d\n",bo);
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            fprintf(file,"%d ",h_lines[i][j]);
        }
        fprintf(file,"\n");
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            fprintf(file,"%d ",v_lines[i][j]);
        }
        fprintf(file,"\n");
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            fprintf(file,"%d ",boxes[i][j]);
        }
        fprintf(file,"\n");
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            fprintf(file,"%d ",save_color[i][j]);
        }
        fprintf(file,"\n");
    }
    for(i=0; i<g; i++)
    {
        fprintf(file,"%d ",save_p1[i]);
    }
    fprintf(file,"\n");
    for(i=0; i<g; i++)
    {
        fprintf(file,"%d ",save_p2[i]);
    }
    fprintf(file,"\n");
    for(i=0; i<g; i++)
    {
        fprintf(file,"%d ",save_p3[i]);
    }
    fprintf(file,"\n");
    for(i=0; i<g; i++)
    {
        fprintf(file,"%d ",save_p4[i]);
    }
    fprintf(file,"\n");
    fprintf(file,"%s,0\n",name1);
    fprintf(file,"%s,0\n",name2);
    fclose(file);
}
void load_game(FILE *file,int size,int h_lines[Max][Max],int v_lines[Max][Max],int boxes[Max][Max],int save_color[Max][Max],char name1[],char name2[],int* sco1,int* sco2,int* mov1, int* mov2, int* g,int* bo,int* t, int save_p1[],int save_p2[],int save_p3[],int save_p4[],char name_file[],int* lines)
{
    fscanf(file,"%d\n",g);
    fscanf(file,"%d\n",lines);
    fscanf(file,"%d %d\n",sco1,mov1);
    fscanf(file,"%d %d\n",sco2,mov2);
    fscanf(file,"%d\n",t);
    fscanf(file,"%d\n",bo);
    read_array_from_file(size, h_lines, name_file, file);
    read_array_from_file(size, v_lines, name_file, file);
    read_array_from_file(size, boxes, name_file,file);
    read_array_from_file(size, save_color, name_file,file);
    read_array1D(*g,save_p1,name_file,file);
    read_array1D(*g,save_p2,name_file,file);
    read_array1D(*g,save_p3,name_file,file);
    read_array1D(*g,save_p4,name_file,file);
    fscanf(file,"%[^,],0\n",name1);
    fscanf(file,"%[^,],0\n",name2);
}
void print_line(int size, char name1[],char name2[],int*sco1, int*sco2, int save_load, char name_file_load[])
{
    int h_lines[Max][Max];
    int v_lines[Max][Max];
    int grid[Max][Max];
    int boxes[Max][Max];
    int save_color[Max][Max];
    int g=0,bo = 0;
    int p3=0, p4=0,p1=0,p2=0;
    int mov1 =0, mov2 = 0 ;
    int turn=0 ;
    int save_p1[max_line]= {0}, save_p2[max_line]= {0}, save_p3[max_line]= {0}, save_p4[max_line]= {0};
    int input=0 ;
    long long time =0 ;
    int num_lines =(size*(size-1)*2);
    *sco1=0;
    *sco2=0;
    clock_t time_els=clock();
    if(save_load==LOAD)
    {
        FILE *file;
        file=fopen(name_file_load,"r");
        while(file==NULL)
        {
            printf("File Not Found\n");
            return;
        }
        fscanf(file,"%d\n",&size);
        fill_array(h_lines,size,255);
        fill_array(v_lines,size,255);
        fill_array(boxes, size, 0);
        fill_array(save_color, size, 0);
        fill_array(grid, size, 167);
        load_game(file,size,h_lines,v_lines,boxes,save_color,name1,name2,sco1,sco2, &mov1,&mov2,&g,&bo,&turn, save_p1,save_p2,save_p3, save_p4,name_file_load,&num_lines);
        fclose(file);
    }
    else
    {
        fill_array(h_lines,size,255);
        fill_array(v_lines,size,255);
        fill_array(boxes, size, 0);
        fill_array(save_color, size, 0);
        fill_array(grid, size, 167);
    }
    time_els = clock() - time_els ;
    print_game(p1,p2,p3,p4,grid,h_lines,v_lines,size,name1,name2,&mov1,sco1,&mov2,sco2,&turn,boxes,&bo,save_color,input,&time,&num_lines);
    for(g; g<(size*(size-1)*2);)
    {
        time_els = clock()- time_els;
        if(input!=SPECIAL_CHAR)
            input = _getch();
        while(input!=ENTER&&input!=SPECIAL_CHAR&&input!=UNDO&&input!=REDO&&save_load!=LOAD&&input!=ESC)
        {
            input = _getch();
        }
        if(input==ESC)
        {
            save_load=SAVE ;
            break;
        }
        else if(input==UNDO&&(mov1>0||mov2>0))
        {
            undo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
        }
        else if (input==REDO&&(save_p1[g]!=0||save_p2[g]!=0||save_p3[g]!=0||save_p4[g]!=0)&&(mov1>=0||mov2>=0))  //redo
        {
            redo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
        }
        else if(input==UNDO&&g==0)
        {
            printf("you can redo or play\n");
            input = _getch();
            if(input==REDO)
                redo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
            else continue;
        }
        else if(input==REDO&&!(save_p1[g]!=0||save_p2[g]!=0||save_p3[g]!=0||save_p4[g]!=0))
        {
            printf("you can undo or play\n");
            input = _getch();
            if(input==UNDO)
                undo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
            else continue;
        }
        else
        {
            time_els = clock() - time_els ;
            time+=time_els/4;
            get_point(&p1,&p2,grid,h_lines,v_lines,size,name1,name2,mov1,*sco1,mov2,*sco2,turn,save_color,boxes,&input,bo,&time,num_lines);
            if(input==ESC)
            {
                save_load=SAVE ;
                break;
            }
            else if(input==UNDO&&(mov1>0||mov2>0))
            {
                undo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
            }
            else if (input==REDO&&(save_p1[g]!=0||save_p2[g]!=0||save_p3[g]!=0||save_p4[g]!=0)&&(mov1>=0||mov2>=0))  //redo
            {
                redo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
            }
            else if(input==UNDO&&g==0)
            {
                printf("you can redo or play\n");
                input = _getch();
                if(input==REDO)
                    redo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
                else continue;
            }
            else if(input==REDO&&!(save_p1[g]!=0||save_p2[g]!=0||save_p3[g]!=0||save_p4[g]!=0))
            {
                printf("you can undo or play\n");
                input = _getch();
                if(input==UNDO)
                    undo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
                else continue;
            }
            else
            {
                time_els = clock() - time_els ;
                get_point1(&p3,&p4,grid,h_lines,v_lines,size,name1,name2,mov1,*sco1,mov2,*sco2,turn,save_color,boxes,bo,&time,p1,p2,num_lines);
                if(p3<p1)
                {
                    swap(&p1,&p3);
                }
                if(p4<p2)
                {
                    swap(&p2,&p4);
                }
                while((((p4-p2==p3-p1)))||((p2==p3)&&(p4==p1))||found_line(h_lines,v_lines,size,p1,p2,p3,p4)||(p3-p1>1)||(p4-p2>1))
                {
                    printf("choose again!\n");
                    input=1;
                    time_els = clock() - time_els ;
                    get_point(&p1,&p2,grid,h_lines,v_lines,size,name1,name2,mov1,*sco1,mov2,*sco2,turn,save_color,boxes,&input,bo,&time,num_lines);
                    time_els = clock() - time_els ;
                    get_point1(&p3,&p4,grid,h_lines,v_lines,size,name1,name2,mov1,*sco1,mov2,*sco2,turn,save_color,boxes,bo,&time,p1,p2,num_lines);
                }
                if(p3<p1)
                {
                    swap(&p1,&p3);
                }
                if(p4<p2)
                {
                    swap(&p2,&p4);
                }
                save_p1[g]= p1 ;
                save_p2[g]= p2 ;
                save_p3[g]= p3 ;
                save_p4[g]= p4 ;
                g++;
                save_p1[g]= 0 ;
                save_p2[g]= 0 ;
                save_p3[g]= 0 ;
                save_p4[g]= 0 ;
                input=1;
                if(p1==p3)
                {
                    h_lines[p1][p2]=196;

                }
                else
                {
                    v_lines[p1][p2]=179;
                }
                if(turn==0)
                    position_boxes(boxes,h_lines,v_lines,size,p1,p2,p3,p4,219,10,save_color);
                else position_boxes(boxes,h_lines,v_lines,size,p1,p2,p3,p4,219,ENTER,save_color);
            }
        }
        time_els = clock() - time_els ;
        time+=time_els/30;
        print_game(p1,p2,p3,p4,grid,h_lines,v_lines,size,name1,name2,&mov1,sco1,&mov2,sco2,&turn,boxes,&bo,save_color,input,&time,&num_lines);
    }
    if(save_load==SAVE)
    {
        if (confirmBox("Save Game"))
        {
            char name_file[100];
            strcpy(name_file,name1);
            strcat(name_file,name2);
            strcat(name_file,".txt");
            printf("Your file's name is %s\n",name_file);
            FILE* file = fopen("file_names_2player.txt","a");
            fprintf(file,"%s,0\n",name_file);
            fclose(file);
            save_game(size,h_lines,v_lines,boxes,save_color,name1,name2, *sco1, *sco2,mov1, mov2,g,bo,turn, save_p1,save_p2,save_p3, save_p4,name_file,num_lines);

        }
    }
    else
    {
        if(*sco1 > *sco2)
        {
            color_text(10);
            printf("%s wins %c\n\n",name1,1);
            color_text(15);
            FILE *f ;
            player p_win;
            p_win.score = *sco1;
            strcpy(p_win.name,name1);
            scores_file(f,p_win,"player_vs_player.txt");
            Rank("player_vs_player.txt");
        }
        else if (*sco1 < *sco2)
        {
            color_text(13);
            printf("%s wins %c\n\n",name2,1);
            color_text(15);
            FILE *f ;
            player p_win;
            p_win.score = *sco2;
            strcpy(p_win.name,name2);
            scores_file(f,p_win,"player_vs_player.txt");
            Rank("player_vs_player.txt");
        }
        else printf("draw %c\n\n",1);
    }
}
void com_player(int* p1,int* p2,int* p3,int* p4,int h[][Max], int v[][Max], int size, int t)
{
    int i, j, found=0;
    int h_lines[Max][Max];
    int v_lines[Max][Max];
    copy_2array(h_lines,h,size);
    copy_2array(v_lines,v,size);
    for(i=0; i<size&&!found; i++)
    {
        for(j=0; j<size-1&&!found; j++)
        {
            if(!found_line(h, v, size,i, j,i,j+1))
            {
                h_lines[i][j]=196;
                if(found_boxes(h_lines, v_lines, size,i, j,i,j+1))
                {
                    *p1=i;
                    *p2=j;
                    *p3=i;
                    *p4=j+1;
                    found=1;
                }
                else h_lines[i][j]=255;
            }
        }
        for(j=0; j<size&&!found; j++)
        {
            if(!found_line(h, v, size,i, j,i+1,j))
            {
                v_lines[i][j]=179;
                if(found_boxes(h_lines, v_lines, size,i, j,i+1,j))
                {
                    *p1=i;
                    *p2=j;
                    *p3=i+1;
                    *p4=j;
                    found=1;
                }
                else v_lines[i][j]=255;
            }
        }
    }
    if(!found)
    {
        for(i=0; i<size; i++)
        {
            for(j=0; j<size-1; j++)
            {
                if(h[i][j]==255&&!may_be_boxes(h,v,size,i,j,i,j+1))
                {
                    *p1=i;
                    *p2=j;
                    *p3=i;
                    *p4=j+1;
                    found=1;
                    break;
                }
            }
            if(found) break;
            for(j=0; j<size-1; j++)
            {
                if(v[j][i]==255&&!may_be_boxes(h,v,size,j,i,j+1,i))
                {
                    *p1=j;
                    *p2=i;
                    *p3=j+1;
                    *p4=i;
                    found=1;
                    break;
                }
            }
            if(found) break;
        }
    }
    if(!found)
    {
        for(i=0; i<size; i++)
        {
            for(j=0; j<size-1; j++)
            {
                if(h[i][j]==255)
                {
                    *p1=i;
                    *p2=j;
                    *p3=i;
                    *p4=j+1;
                    found=1;
                    break;
                }
            }
            if(found) break;
        }
    }
    if(!found)
    {
        for(i=0; i<size-1; i++)
        {
            for(j=0; j<size; j++)
            {
                if(v[i][j]==255)
                {
                    *p1=i;
                    *p2=j;
                    *p3=i+1;
                    *p4=j;
                    found=1;
                    break;
                }
            }
            if(found) break;
        }
    }

}
void print_line_com(int size, char name1[],char name2[],int*sco1, int*sco2, int save_load, char name_file_load[])
{
    int h_lines[Max][Max];
    int v_lines[Max][Max];
    int grid[Max][Max];
    int boxes[Max][Max];
    int save_color[Max][Max];
    int g=0, bo = 0;
    int p3, p4,p1,p2;
    int mov1 =0, mov2 = 0 ;
    int turn=0 ;
    int turn_line_com = 0;
    int save_p1[max_line]= {0}, save_p2[max_line]= {0}, save_p3[max_line]= {0}, save_p4[max_line]= {0};
    int input=0 ;
    long long time =0 ;
    int num_lines =(size*(size-1)*2);
    *sco1=0;
    *sco2=0;
    clock_t time_els =clock() ;
    if(save_load==LOAD)
    {
        FILE *file;
        file=fopen(name_file_load,"r");
        while(file==NULL)
        {
            printf("File Not Found\n");
            return;
        }
        fscanf(file,"%d\n",&size);
        fill_array(h_lines,size,255);
        fill_array(v_lines,size,255);
        fill_array(boxes, size, 0);
        fill_array(save_color, size, 0);
        fill_array(grid, size, 167);
        load_game(file,size,h_lines,v_lines,boxes,save_color,name1,name2,sco1,sco2,&mov1,&mov2,&g,&bo,&turn, save_p1,save_p2,save_p3, save_p4,name_file_load,&num_lines);
        fclose(file);
    }
    else
    {
        fill_array(h_lines,size,255);
        fill_array(v_lines,size,255);
        fill_array(boxes, size, 0);
        fill_array(save_color, size, 0);
        fill_array(grid, size, 167);
    }
    print_game(p1,p2,p3,p4,grid,h_lines,v_lines,size,name1,name2,&mov1,sco1,&mov2,sco2,&turn,boxes,&bo,save_color,input,&time,&num_lines);
    for(g; g<(size*(size-1)*2);)
    {
        time_els = clock() - time_els;
        if(turn==0&&input!=SPECIAL_CHAR)
            input = _getch();
        while(input!=13&&input!=224&&input!=26&&input!=25&&turn==0&&input!=ESC)
        {
            input = _getch();
        }
        if(input==ESC)
        {
            save_load=SAVE ;
            break;
        }
        else if(input==26&&(mov1>0||mov2>0))
        {
            undo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
        }
        else if (input==25&&(save_p1[g]!=0||save_p2[g]!=0||save_p3[g]!=0||save_p4[g]!=0)&&(mov1>=0||mov2>=0))  //redo
        {
            redo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
        }
        else if(input==26&&g==0)
        {
            printf("you can redo or play\n");
            input = _getch();
            if(input==25)
                redo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
            else continue;
        }
        else if(input==25&&!(save_p1[g]!=0||save_p2[g]!=0||save_p3[g]!=0||save_p4[g]!=0))
        {
            printf("you can undo or play\n");
            input = _getch();
            if(input==26)
                undo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
            else continue;
        }
        else
        {
            if(turn==0)
            {
                time_els = clock() - time_els ;
                time+=time_els/5;
                get_point(&p1,&p2,grid,h_lines,v_lines,size,name1,name2,mov1,*sco1,mov2,*sco2,turn,save_color,boxes,&input,bo,&time,num_lines);
                if(input==ESC)
                {
                    save_load=SAVE ;
                    break;
                }
                else if(input==UNDO&&(mov1>0||mov2>0))
                {
                    undo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
                }
                else if (input==REDO&&(save_p1[g]!=0||save_p2[g]!=0||save_p3[g]!=0||save_p4[g]!=0)&&(mov1>=0||mov2>=0))  //redo
                {
                    redo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
                }
                else if(input==UNDO&&g==0)
                {
                    printf("you can redo or play\n");
                    input = _getch();
                    if(input==REDO)
                        redo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
                    else continue;
                }
                else if(input==REDO&&!(save_p1[g]!=0||save_p2[g]!=0||save_p3[g]!=0||save_p4[g]!=0))
                {
                    printf("you can undo or play\n");
                    input = _getch();
                    if(input==UNDO)
                        undo(&g,boxes,h_lines,v_lines,size,save_p1,save_p2,save_p3,save_p4,&mov1,sco1,&mov2,sco2,&turn,save_color,&bo,&num_lines);
                    else continue;
                }
                else
                {
                    get_point1(&p3,&p4,grid,h_lines,v_lines,size,name1,name2,mov1,*sco1,mov2,*sco2,turn,save_color,boxes,bo,&time,p1,p2,num_lines);
                    if(p3<p1)
                    {
                        swap(&p1,&p3);
                    }
                    if(p4<p2)
                    {
                        swap(&p2,&p4);
                    }
                    while((((p4-p2==p3-p1)))||((p2==p3)&&(p4==p1))||found_line(h_lines,v_lines,size,p1,p2,p3,p4)||(p3-p1>1)||(p4-p2>1))
                    {
                        printf("choose again!\n");
                        input=1;
                        time_els = clock() - time_els ;
                        get_point(&p1,&p2,grid,h_lines,v_lines,size,name1,name2,mov1,*sco1,mov2,*sco2,turn,save_color,boxes,&input,bo,&time,num_lines);
                        time_els = clock() - time_els ;
                        get_point1(&p3,&p4,grid,h_lines,v_lines,size,name1,name2,mov1,*sco1,mov2,*sco2,turn,save_color,boxes,bo,&time,p1,p2,num_lines);
                    }
                    if(p3<p1)
                    {
                        swap(&p1,&p3);
                    }
                    if(p4<p2)
                    {
                        swap(&p2,&p4);
                    }
                }
            }
            else if(turn==1)
            {
                com_player(&p1,&p2,&p3,&p4,h_lines,v_lines,size,turn_line_com);
                delay(500);
                if(turn_line_com==0)turn_line_com=1;
                else turn_line_com = 0;
            }
            if(input!=UNDO&&input!=REDO&&input!=ESC)
            {
                save_p1[g]= p1 ;
                save_p2[g]= p2 ;
                save_p3[g]= p3 ;
                save_p4[g]= p4 ;
                g++;
                save_p1[g]= 0 ;
                save_p2[g]= 0 ;
                save_p3[g]= 0 ;
                save_p4[g]= 0 ;
                input=1;
                if(p1==p3)
                {
                    h_lines[p1][p2]=196;

                }
                else
                {
                    v_lines[p1][p2]=179;
                }
                if(turn==0)
                    position_boxes(boxes,h_lines,v_lines,size,p1,p2,p3,p4,219,10,save_color);
                else position_boxes(boxes,h_lines,v_lines,size,p1,p2,p3,p4,219,13,save_color);
            }
        }
        time_els = clock() - time_els ;
        time+=time_els/50;
        print_game(p1,p2,p3,p4,grid,h_lines,v_lines,size,name1,name2,&mov1,sco1,&mov2,sco2,&turn,boxes,&bo,save_color,input,&time,&num_lines);
    }
    if(save_load==SAVE)
    {
        if (confirmBox("Save Game"))
        {
            char name_file[100];
            strcpy(name_file,name1);
            strcat(name_file,".txt");
            printf("Your file's name is %s\n",name_file);
            FILE* file = fopen("file_names_player_com.txt","a");
            fprintf(file,"%s,0\n",name_file);
            fclose(file);
            save_game(size,h_lines,v_lines,boxes,save_color,name1,name2, *sco1, *sco2,mov1, mov2,g,bo,turn, save_p1,save_p2,save_p3, save_p4,name_file,num_lines);
        }
    }
    else
    {
        if(*sco1 > *sco2)
        {
            color_text(10);
            printf("%s wins %c\n\n",name1,1);
            color_text(15);
            FILE *f ;
            player p_win;
            p_win.score = *sco1;
            strcpy(p_win.name,name1);
            scores_file(f,p_win,"player_vs_com.txt");
            Rank("player_vs_com.txt");
        }
        else if (*sco1 < *sco2)
        {
            color_text(13);
            printf("%s wins %c\n\n",name2,1);
            color_text(15);
        }
        else printf("draw %c\n\n",1);
    }
}
void scores_file(FILE* file, player p_win,char name_file[])
{
    int size_array = 0, j, found=0;
    player array[1000]= {0};
    file = fopen(name_file,"r");
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%[^,],%d\n",array[size_array].name,&array[size_array].score);
            size_array++;
        }
    }
    fclose(file);
    for(j=0 ; j<size_array ; j++)
    {
        if(!strcmp(p_win.name,array[j].name)&&p_win.score>array[j].score)
        {
            array[j].score = p_win.score;
            found=1;
        }
        else if(!strcmp(p_win.name,array[j].name)&&p_win.score<=array[j].score)
        {
            return;
        }
    }
    if(!found)
    {
        array[j]=p_win;
        size_array++;
    }
    j=0;
    file = fopen(name_file,"w");
    while(j<size_array)
    {
        fprintf(file,"%s,%d\n",array[j].name,array[j].score);
        j++;
    }
    fclose(file);
}
void Rank(char name_file[])
{
    int size_array = 0, j ;
    player array[1000]= {0};
    FILE* file ;
    file = fopen(name_file,"r");
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%[^,],%d\n",array[size_array].name,&array[size_array].score);
            size_array++;
        }
    }
    else
    {
        printf("There is not rank!\n\n");
        return;
    }
    int i ;
    player temp;
    for(i=0; i<size_array; i++)
    {
        for(j=i+1; j<size_array; j++)
        {
            if(array[i].score<array[j].score)
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    printf("Rank%27s %20s\n\n","Name","Score");
    for(i=0; i<size_array; i++)
    {
        printf(" %d  %30s %15d\n",i+1,array[i].name,array[i].score);
    }
    printf("\n\n");

}
void print_game_htp(int p1,int p2,int p3,int p4,int grid[][Max],int h_lines[][Max], int v_lines[][Max], int size,char name1[],char name2[],int* mov1,int* sco1,int* mov2,int* sco2,int* turn,int boxes[][Max],int* bo,int save_color[][Max],int* lines,int f )
{
    int i, j ;
    system("cls");
    if(!found_boxes(h_lines,v_lines,size,p1,p2,p3,p4)&&f)
    {
        if(*turn==1)
        {
            (*mov2)++;
            *turn = 0 ;

        }
        else
        {
            *turn = 1;
            (*mov1)++;
        }
        (*lines)--;
    }
    else if(f)
    {
        if(*turn==1)
        {
            (*mov2)++;
            *turn = 1 ;
            *sco2+=found_boxes(h_lines,v_lines,size,p1,p2,p3,p4);

        }
        else
        {
            *turn = 0;
            (*mov1)++;
            *sco1+=found_boxes(h_lines,v_lines,size,p1,p2,p3,p4);
        }
        (*lines)--;
    }
    color_text(10);
    printf("%s's moves : %d \t\t",name1,*mov1);
    printf("%s's score : %d \n\n",name1,*sco1);
    color_text(ENTER);
    printf("%s's moves : %d \t\t",name2,*mov2);
    printf("%s's score : %d \n\n",name2,*sco2);
    color_text(15);
    if(*turn==0)
    {
        color_text(10);
        printf("%s's turn\n\n",name1);
    }
    else
    {
        color_text(ENTER);
        printf("%s's turn\n\n",name2);
    }
    color_text(15);
    for(i=0; i<size; i++)
    {

        for(j=0; j<size; j++)
        {
            if(i==p1&&j==p2)
            {
                if(*turn==0)
                {
                    color_text(10);
                }
                else color_text(ENTER);
            }
            printf("%c",grid[i][j]);
            color_text(15);
            printf("%c%c",h_lines[i][j],h_lines[i][j]);
        }

        printf("\n");
        for(j=0; j<size; j++)
        {
            printf("%c",v_lines[i][j]);
            color_text(save_color[i][j]);
            printf("%c%c",boxes[i][j],boxes[i][j]) ;
            color_text(15);
        }
        printf("\n");
    }
    *bo+=found_boxes(h_lines,v_lines,size,p1,p2,p3,p4);

    printf("\n\nboxes%d\n\nLines:%d\n\n",*bo,*lines);

}
void how_to_play(int size)
{
    int h_lines[Max][Max];
    int v_lines[Max][Max];
    int grid[Max][Max];
    int boxes[Max][Max];
    int save_color[Max][Max];
    int g=0, bo = 0;
    int p3, p4,p1,p2;
    int mov1 =0, mov2 = 0 ;
    int turn=0 ;
    int turn_line_com1 = 0;
    int turn_line_com2 = 0;
    int num_lines =(size*(size-1)*2);
    int sco1=0;
    int sco2=0;
    fill_array(h_lines,size,255);
    fill_array(v_lines,size,255);
    fill_array(boxes, size, 0);
    fill_array(save_color, size, 0);
    fill_array(grid, size, 167);
    print_game_htp(p1,p2,p3,p4,grid,h_lines,v_lines,size,"player1","plyaer2",&mov1,&sco1,&mov2,&sco2,&turn,boxes,&bo,save_color,&num_lines,0);
    for(g; g<(size*(size-1)*2); g++)
    {
        Sleep(275);
        if(turn==0)
        {
            com_player(&p1,&p2,&p3,&p4,h_lines,v_lines,size,turn_line_com1);
            if(turn_line_com1==0)turn_line_com1=1;
            else turn_line_com1 = 0;
            if(p3<p1)
            {
                swap(&p1,&p3);
            }
            if(p4<p2)
            {
                swap(&p2,&p4);
            }
        }
        else if(turn==1)
        {
            com_player(&p1,&p2,&p3,&p4,h_lines,v_lines,size,turn_line_com2);
            if(turn_line_com2==0)turn_line_com2=1;
            else turn_line_com2 = 0;
        }
        if(p3<p1)
        {
            swap(&p1,&p3);
        }
        if(p4<p2)
        {
            swap(&p2,&p4);
        }
        if(p1==p3)
        {
            h_lines[p1][p2]=196;

        }
        else
        {
            v_lines[p1][p2]=179;
        }
        if(turn==0)
            position_boxes(boxes,h_lines,v_lines,size,p1,p2,p3,p4,219,10,save_color);
        else position_boxes(boxes,h_lines,v_lines,size,p1,p2,p3,p4,219,13,save_color);
        print_game_htp(p1,p2,p3,p4,grid,h_lines,v_lines,size,"player1","plyaer2",&mov1,&sco1,&mov2,&sco2,&turn,boxes,&bo,save_color,&num_lines,1);
        write_word_delay("If you want draw a line stop the pointer at a point and press Enter,\nthen repeat that again at another adjacent point.",10);
    }
}

int scanf_f(char name_file[],char names_files[][100])
{
    int size_array = 0,j,i,x;
    FILE* file = fopen(name_file,"r");
    if(file!=NULL)
    {
        while(!feof(file))
        {

            fscanf(file,"%[^,],0\n",names_files[size_array]);
            size_array++;
        }
        fclose(file);
        for(i=0; i<size_array; i++)
        {
            for(j=1+i; j<size_array;)
            {
                if(!strcmp(names_files[i],names_files[j]))
                {
                    for(x=j; x<size_array; x++)
                    {
                        strcpy(names_files[x],names_files[x+1]);
                    }
                    size_array--;
                }
                else j++;
            }
        }
        FILE* file = fopen(name_file,"w");
        for(i=0; i<size_array; i++)
        {

            fprintf(file,"%s,0\n",names_files[i]);
        }
        fclose(file);
        return size_array;
    }
    else return 0;
}

