#include "main_menu.h"
#include "LOOPGAME.h"

player player1, player2 ;
int main()
{
    int index = 1, screen1 = 0, noExit = 1, input = -1,size=0,screen2 = 0,screen3 = 0,screen4 = 0 , screen_load=0;
    int size_array = 0;
    char names_files[100][100]={0};
    while(noExit)
    {
        printf("\n\n\n\n\n\n");
        system(CLEAR_COMMAND);
        switch(screen1)
        {
        case 0:
            printf("\n\n\n\n\n\n");
            welcomeScreen(&screen1);
            fflush(stdin);
            break;
        case 1:
            printScreen(index, OPTIONS_NUMBER_MENU, OPTIONS_MENU);
            menuInput(&input, &index, &screen1, OPTIONS_NUMBER_MENU);
            break;
        case 2:
            printf("\n\n\nEnter The Size Of Board(2:9):\n");
            get_int(&size);
            system(CLEAR_COMMAND);
            while(1)
            {
                printScreen(index, 3, OPTIONS_START_GAME);
                menuInput(&input, &index, &screen2, 3);
                system(CLEAR_COMMAND);
                if(input==ENTER) break;
            }
            switch(screen2)
            {
            case 1:
                fflush(stdin);
                printf("Player1,Enter your name:\n");
                gets(player1.name);
                printf("Player2,Enter your name:\n");
                gets(player2.name);
                system(CLEAR_COMMAND);
                print_line(size+1,player1.name,player2.name,&player1.score,&player2.score, PLAY,"");
                screen1=1;
                screen2=0;
                printf("If you want to Exit press Esc!\n..Back To Menu press Enter!\n");
                input = _getch();
                if(input==ENTER)
                    break;
                else if(input==ESC)
                {
                    noExit = 0;
                    break;
                }break;
            case 2:
                fflush(stdin);
                printf("Enter your name:\n");
                gets(player1.name);
                system(CLEAR_COMMAND);
                print_line_com(size+1,player1.name,com_name,&player1.score,&player2.score, PLAY,"");
                screen1=1;
                screen2=0;
                printf("If you want to Exit press Esc!\n..Back To Menu press Enter!\n");
                input = _getch();
                if(input==ENTER)
                    break;
                else if(input==ESC)
                {
                    noExit = 0;
                    break;
                }break;
            case 3:
                screen1=1;
                screen2=0;
                index=1;
                break;
            }
            break;
        case 3:
            while(1)
            {
                printScreen(index, 3, OPTIONS_START_GAME);
                menuInput(&input, &index, &screen3, 3);
                system(CLEAR_COMMAND);
                if(input==ENTER) break;
            }
            switch(screen3)
            {
            case 1:
            size_array = scanf_f("file_names_2player.txt",names_files);
            while(1&&size_array)
            {
                printScreen(index, size_array, names_files);
                menuInput(&input, &index, &screen_load, size_array);
                system(CLEAR_COMMAND);
                if(input==ENTER) break;
            }
            if(size_array!=0)
            {
                print_line(size+1,player1.name,player2.name,&player1.score,&player2.score, LOAD,names_files[screen_load-1]);
            }else printf("There is not files\n");
                screen1=1;
                screen2=0;
                screen3=0;
                screen_load=0;
                printf("If you want to Exit press Esc!\n..Back To Menu press Enter!\n");
                input = _getch();
                if(input==ENTER)
                    break;
                else if(input==ESC)
                {
                    noExit = 0;
                    break;
                }break;
            case 2:
            size_array = scanf_f("file_names_player_com.txt",names_files);
            while(1&&size_array)
            {
                printScreen(index, size_array, names_files);
                menuInput(&input, &index, &screen_load, size_array);
                system(CLEAR_COMMAND);
                if(input==ENTER) break;
            }
            if(size_array!=0)
            {
                print_line_com(size+1,player1.name,player2.name,&player1.score,&player2.score, LOAD,names_files[screen_load-1]);
            }else printf("There is not files\n");
            screen1=1;
                screen2=0;
                screen3=0;
                screen_load=0;
                printf("If you want to Exit press Esc!\n..Back To Menu press Enter!\n");
                input = _getch();
                if(input==ENTER)
                    break;
                else if(input==ESC)
                {
                    noExit = 0;
                    break;
                }
                break;
            case 3:
                screen1=1;
                screen2=0;
                screen3=0;
                index=1;
                break;
            }
            break;
        case 4:
        //overview
        overview();
                screen1=1;
                screen2=0;
                screen3=0;
                index=1;
                printf("If you want to Exit press Esc!\n..Back To Menu press Enter!\n");
                input = _getch();
                if(input==ENTER)
                    break;
                else if(input==ESC)
                {
                    noExit = 0;
                    break;
                }
                    break;
        case 5:
        //how to play
        how_to_play(3);
                screen1=1;
                screen2=0;
                screen3=0;
                index=1;
                printf("If you want to Exit press Esc!\n..Back To Menu press Enter!\n");
                fflush(stdin);
                input = _getch();
                if(input==ENTER)
                    break;
                else if(input==ESC)
                {
                    noExit = 0;
                    break;
                }
                break;
        case 6:
            // top 10
            while(1)
            {
                printScreen(index, 3, OPTIONS_START_GAME);
                menuInput(&input, &index, &screen4, 3);
                system(CLEAR_COMMAND);
                if(input==ENTER) break;
            }
            switch(screen4)
            {
            case 1:
                Rank("player_vs_player.txt");
                screen1=1;
                screen2=0;
                screen4=0;
                screen3=0;
                printf("If you want to Exit press Esc!\n..Back To Menu press Enter!\n");
                input = _getch();
                if(input==ENTER)
                    break;
                else if(input==ESC)
                {
                    noExit = 0;
                    break;
                }break;
            case 2:
                Rank("player_vs_com.txt");
                screen1=1;
                screen2=0;
                screen4=0;
                screen3=0;
                printf("If you want to Exit press Esc!\n..Back To Menu press Enter!\n");
                input = _getch();
                if(input==ENTER)
                    break;
                else if(input==ESC)
                {
                    noExit = 0;
                    break;
                }break;

            case 3:
                screen1=1;
                screen2=0;
                screen3=0;
                screen4=0;
                index=1;
                break;
            }
            break;
        case 7:
            if (confirmBox("Exit"))
            {
                noExit = 0;
            }
            else
            {
                screen1 = 1;
                index=1;
            }
            break;
        default:
            noExit = 0;
            break;
        }
    }
    return 0 ;
}
