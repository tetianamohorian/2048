#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void pStart()
{
    initscr();
    start_color();
    noecho();
    raw();
}

/*****Border*****/
void pDrawBorder()
{
    char border[44] = {"-------------------------------------------"};
    
    int i = 1;
    // Horizontal
    while(i <= 3)
    {
        mvprintw(i*6 - 1, 0, border);
        i++;
    }

    // Vertical
    for(int j = 1; j<=4; j++)
    {
        int k = 1;

        while(k <=23)
        {
            mvprintw(k - 1, 11 * j - 1, "|");
            k++;
        }

       
    }

    // Dot
    for(int j = 1; j <= 4; j++)
    {
        int h = 1;
        while(h <=3)
        {
            mvprintw(h* 6 - 1, 11 * j - 1, "+");

            h++;
        }

    }


    refresh();
    
}

/******Generation tile*****/
void pTilePlacement(int pTile[16])
{
    int size = 16;
    int empty_position = 0;
    int tile_position = 0;
    int num = 0;
    int empty_tile[size];
    int k = 0;
    int i = 0;    

    srand(time(NULL));


    while(i < size)
    {
        if(pTile[i] == 0)
        {
            empty_tile[k] = i;
            k++;
        }

        if(k > 0)
        {
            num = rand () % 10 ? 2 : 4;
            empty_position = rand () % (k);
            tile_position = empty_tile[empty_position];
            pTile[tile_position] = num;
        }

        i++;
    }

    
}

/*****Draw Tile*****/
void pDrawTile(int pNumber, int pTileNumber)
{
    char before[8];
    char after[8];
    int row, column;
    int x, y;

    init_color(1, 523, 867, 515);
    init_color(2, 402, 796, 984);
    init_color(3, 597, 199, 996);
    init_color(4, 996, 601, 601);
    init_color(5, 996, 886, 597);
    init_color(6, 636, 800, 285);
    init_color(7, 50, 660, 683);
    init_color(8, 421, 218, 597);
    init_color(9, 929, 769, 863);
    init_color(10, 578, 93, 93);
    init_color(11, 0, 0, 0);
    init_color(12, 781, 781, 781);

    switch (pNumber)
    {
        case 2:
             strcpy(before, "    ");
             strcpy(after, "     ");
             break;
        case 4:
             strcpy(before, "    ");
             strcpy(after, "     ");
             break;
        case 8:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        case 16:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        case 32:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        case 64:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        case 128:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        case 256:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        case 512:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        case 1024:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        case 2048:
            strcpy(before, "    ");
            strcpy(after, "     ");
            break;
        default:
             break;
    }
    
    
    int k = 0;

    if(pNumber != 0)
    {
        int num = pNumber;

        while(num != 2)
        {
            num = num >> 1;
        }

        k = k + 1;
    }

    row = pTileNumber/4;
    column = pTileNumber % 4;
    y = row * 6;
    x = column * 11;

    use_default_colors();
    assume_default_colors(-1,-1);

    init_pair(1, -1, -1);
    init_pair(2, -1, 1);
    init_pair(3, -1, 2);
    init_pair(4, -1, 3);
    init_pair(5, -1, 4);
    init_pair(6, -1, 5);
    init_pair(7, -1, 6);
    init_pair(8, -1, 7);
    init_pair(9, -1, 8);
    init_pair(10, -1, 9);
    init_pair(11, -1, 10);
    init_pair(12, -1, 11);
    init_pair(13, -1, 12);

    
    if(pNumber == 0)
    {
        attron(COLOR_PAIR(1));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "          ");
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(1));
      
    }

    else if(pNumber == 2)
    {
        attron(COLOR_PAIR(k+2));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k+2));

    }
    else if(pNumber == 4)
    {
        attron(COLOR_PAIR(k+1));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k+1));

    }

    else if(pNumber == 8)
    {
         attron(COLOR_PAIR(k+3));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k+3));
    
    }

    else if(pNumber == 16)
    {
         attron(COLOR_PAIR(k+4));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k+4));

    }
    else if(pNumber == 32)
    {
        attron(COLOR_PAIR(k+5));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k+5));

    }
    
    else if(pNumber == 64)
    {
         attron(COLOR_PAIR(k+6));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k+6));

    }

    else if(pNumber == 128)
    {
        attron(COLOR_PAIR(k-3));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k-3));

    }
    else if(pNumber == 512)
    {
        attron(COLOR_PAIR(k+1));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k+1));
 
    }
    else if(pNumber == 1024)
    {
 attron(COLOR_PAIR(k-1));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k-1));

    }
    else if(pNumber == 2048)
    {
        attron(COLOR_PAIR(k));

        mvprintw(y, x, "          ");
        mvprintw(y+1, x, "          ");
        mvprintw(y+2, x, "%s%d%s", before, pNumber, after);
        mvprintw(y+3, x, "          ");
        mvprintw(y+4, x, "          ");

        attroff(COLOR_PAIR(k));
       
    }



refresh();


}

void pPrintInfo(int pResult)
{
//    char s[100];
  //  FILE* f1 = fopen("file.txt", "r");
    switch(pResult)
    {
        /*****Game*****/
        case 0: 
        
      //  char s[100];
  //      FILE* f1 = fopen("file.txt", "r");
   
       // while(fgets(s,100,f1))
        //{
          //  mvprintw(1,50,           "                         %s                       ", s);
        //}
        
            mvprintw(3, 50, "%s",    "           Use your key with arrow to play        ");
            mvprintw(4, 50,  "%s",   "                                                  ");
            mvprintw(5, 50,  "%s",   "                    ___________                   ");
            mvprintw(6, 50,   "%s",  "                   |           |                  ");
            mvprintw(7, 50,   "%s",  "                   |     ^     |                  ");
            mvprintw(8, 50,   "%s",  "                   |___________|                  ");
            mvprintw(9, 50,   "%s",  "        __________________________________        ");
            mvprintw(10, 50,  "%s",  "       |           |           |          |       ");
            mvprintw(11, 50,  "%s",  "       |  <        |     v     |       >  |       ");
            mvprintw(12, 50,  "%s",  "       |___________|___________|__________|       ");
            mvprintw(13, 50,  "%s",  "                                                  ");
            mvprintw(14, 50,  "%s",  "                 Or W, S, A, D instead            ");     
            break;
        /*****Win*****/    
        case 1: 
        
    //    char s[100];
//        FILE* f1 = fopen("file.txt", "r");

       // while(fgets(s,100,f1))
       // {
         //   mvprintw(1,50,           "                         %s                       ", s);
        //}
 
             mvprintw(3, 50, "%s",   "                                                  ");
             mvprintw(4, 50, "%s",   "                                                  ");
             mvprintw(5, 50, "%s",   "                                                  ");
             mvprintw(6, 50, "%s",   "                                                  ");
             mvprintw(7, 50, "%s",   "                                                  ");
             mvprintw(8, 50, "%s",   "                  CONGRATULATION!                 ");
             mvprintw(9, 50, "%s",   "                     YOU WON!                     ");
             mvprintw(10, 50, "%s",  "                                                  ");
             mvprintw(11, 50, "%s",  "                                                  ");
             mvprintw(12, 50, "%s",  "                                                  ");
             mvprintw(13, 50, "%s",  "                                                  ");
             mvprintw(14, 50, "%s",  "                                                  ");
             break;

        case 2:

  //       char s[100];
//         FILE* f1 = fopen("file.txt", "r");

        // while(fgets(s,100,f1))
         //{
           // mvprintw(1,50,           "                         %s                       ", s);
        // }
    
             mvprintw(3, 50, "%s",   "                                                  ");
             mvprintw(4, 50, "%s",   "                                                  ");
             mvprintw(5, 50, "%s",   "                                                  ");
             mvprintw(6, 50, "%s",   "                                                  ");
             mvprintw(7, 50, "%s",   "                                                  ");
             mvprintw(8, 50, "%s",   "                       Oh NO!                     ");
             mvprintw(9, 50, "%s",   "                      YOU LOSE                     ");
             mvprintw(10, 50, "%s",  "                                                  ");
             mvprintw(11, 50, "%s",  "                                                  ");
             mvprintw(12, 50, "%s",  "                                                  ");
             mvprintw(13, 50, "%s",  "                                                  ");
             mvprintw(14, 50, "%s",  "                                                  ");
             break;

        default:
             break;
    }

    mvprintw(20, 54, "%s", "    Press 'r' to retry");
    mvprintw(21, 54, "%s", "          'q' to quit");
    refresh();
}

char pGetKey()
{
    char key;
    char press_key;
    bool flag_esc;

    press_key = getch();

    if(0x1b == press_key)
    {
        flag_esc = true;

        if(0x5b == getch())
        {   
            press_key = getch();
        }

    }
    else
    {
        flag_esc = false;
    }



    if(flag_esc == true)
    {
        switch(press_key)
        {
             case 'A':
                key = 'U';
                break;
             case 'B':
                key = 'D';
                break;
             case 'C':
                key = 'R';
                break;
             case 'D':
                key = 'L';
                break;
             default:
                key = 'X';
                break;

        }
    }
    else
    {
        switch(press_key)
        {
             case 'w':
                case'W':
                    key = 'U';
                break;
             case 's':
                case'S':
                    key = 'D';
                break;
             case 'd':
                case 'D':
                    key = 'R';
                break;
             case 'a':
                case 'A':
                    key = 'L';
                break;
             case 'r':
                case 'R':
                    key = 'r';
                break;
            case 'q':
                case 'Q':
                    key = 'q';
                break;
            case 'i':
                case 'I':
                    
            case 'h':
                case 'H':
                    key = 'h';
                break;

            default:
                key = 'x';
                break;

        }
    }

    return key;
}



int pMoveTile(int pTile[16], char direction)
{
    int sum = 0;
    switch(direction)
    {
        case 'U':
            for(int i = 0; i <6; i++)
            {
                if(i != 4)
                {
                    for(int j = 0; j <=11; j++)
                    {
                        if(pTile[j] == 0)
                        {
                            pTile[j] = pTile[j+4];
                            pTile[j+4] = 0;
                        }
                    }
                }
                else
                {
                    for(int j = 0; j <=11; j++)
                    {
                        if(pTile[j] == pTile[j+4])
                        {
                            pTile[j] = 2*pTile[j];
                            pTile[j+4] = 0;
                            sum = sum + pTile[j];
                        }

                        
                    }
                }
            }

            case 'D':
                for(int i = 0; i < 6; i++)
                {
                    if(i!=4)
                    {
                        for(int j = 11; j >= 0; j--)
                        {
                            if(pTile[j+4] == 0)
                            {
                                pTile[j+4] = pTile[j];
                                pTile[j] = 0;
                            }
                        }
                    }
                    else
                    {
                        for(int j = 11; j >= 0; j--)
                        {
                            if(pTile[j] == pTile[j+4])
                            {
                                pTile[j+4] = 2 * pTile[j+4];
                                pTile[j] = 0;
                                sum = sum + pTile[j+4];
                            }
                        }

                    }
                }
                break;

                case 'R':

                for(int i = 0; i < 6; i++)
                {
                    if(i != 4)
                    {
                        for(int j = 14; j >=0; j--)
                        {
                            if(j == 3 || j == 7 || j == 11)
                            {
                               continue;
                            }
                            if(pTile[j+1] == 0)
                            {
                              pTile[j+1] = pTile[j];
                              pTile[j] = 0;
                            }
                        }

                    }
                    else
                    {
                        for(int j =14; j>=0; j--)
                        {
                            if(j == 3 || j == 7 || j == 11)
                            {
                                continue;
                            }
                            if(pTile[j] == pTile[j+1])
                            {
                                pTile[j+1] = 2 * pTile[j+1];
                                pTile[j] = 0;
                                sum = sum + pTile[j+1];
                            }
                            
                        }
                    }
                }
                break;

                case 'L':

                for(int i = 0; i <6; i++)
                {
                    if(i != 4)
                    {
                        for(int j = 0; j < 15; j++)
                        {
                            if(j == 3 || j == 7 || j == 11)
                            {
                                continue;

                            }

                            if(pTile[j] == 0)
                            {
                                pTile[j] = pTile[j+1];
                                pTile[j+1] = 0;
                            }

                        }
                    }
                    else
                    {
                        for(int j = 0; j < 15; j++)
                        {
                            if(j == 3 || j == 7 || j == 11)
                            {
                                continue;
                            }

                            if(pTile[j] == pTile[j+1])
                            {
                                pTile[j] = 2 * pTile[j];
                                pTile[j+1] = 0;
                                sum = sum + pTile[j];
                            }
                        }
                    }
                }
                break;
                
    }
   return sum;
}

void pPrintStatus(int k)
{
    move(23, 0);
    attron(A_REVERSE | A_BOLD);
    printw("\r%80s", " ");
    printw("\r%70d", k);
    printw("\r%60s", "YOUR SCORE: ");
    printw("\r%s", "-- THE 2048 GAME --");
    move(23, 79);
    attroff(A_REVERSE | A_BOLD);
    refresh();
}

bool pCheckEnd(int pTile[16])
{
    int tile_bak[16];
    int size = 16;
    bool flag_change = false;

    for(int i = 0; i < size; i++)
    {
        tile_bak[i] = pTile[i];
    }
        pMoveTile(pTile, 'U');
        pMoveTile(pTile, 'D');
        pMoveTile(pTile, 'R');
        pMoveTile(pTile, 'L');


    for(int i = 0; i < size; i++)
    {
        if(tile_bak[i] != pTile[i])
        {
            flag_change = true;
        }
    }

    if(flag_change == true)
    {
        for(int i = 0; i < size; i++)
        {
            pTile[i] = tile_bak[i];
            
        }
        return false;
    }

    return true;

}

int main()
{
    char key;
    bool flag_change = false;
    bool result = false;
    int direction = 0; 
    int score = 0;

    int size = 16;
    int tile[size];
    int tile_bak[size];
    char message[33]= "2048\nCreated by Tetiana Mohorian\n";

    char * filename = "file.txt";
    FILE *fp;

    if((fp = fopen(filename,"w")) == NULL)
    {
        perror("Error occured while opening file");
    }

    fputs(message,fp);
    fclose(fp);

    pStart();
    
    pDrawBorder();
    
start:
    score = 0;
    for(int i = 0; i < size; i++)
    {
        tile[i] = 0;    
    }

    pTilePlacement(tile);
    pTilePlacement(tile);

    for(int i = 0; i < size; i++)
    {
        pDrawTile(tile[i], i);
    }
    
    char s[100];
    
    FILE* f1 = fopen("file.txt", "r");
    
    while(fgets(s,100,f1))
    {
       mvprintw(1,50, "             %s", s);
    }


    pPrintInfo(0);
    pPrintStatus(score);

    for(direction = 1; pCheckEnd (tile) == false; direction++)
    {
        //score = 0;

        for(int i = 0; i < size; i++)
        {
            tile_bak[i] = tile[i];
        }

        if(result == true)
        {
            for(int i = 0; i < size; i++)
            {
                if(tile[i] == 2048)
                {
                   pPrintInfo(1);
                   result = true;
                }
            }
        }

        else
        {
            pPrintInfo(0);    
        }

    key = pGetKey();

    switch(key)
    {
        case 'U': 
            case 'D':
                case 'R': 
                    case 'L':
                    score = score + pMoveTile(tile, key);  
        break;

        case 'q': 
        goto end;
        break;

        case 'r': 
        goto start;
        break;

        case 'h': 
        break;

        default: 
        break;
    }
    
    flag_change = false;

    for(int i = 0; i < size; i++)
    {
        if(tile[i] != tile_bak[i])
        {
            flag_change = true;
        }
    }

    if(flag_change == true)
    {
        pTilePlacement(tile);
        
    }

    for(int i = 0; i < size; i++)
    {
        pDrawTile(tile[i], i);

    }

    pPrintStatus(score);
}
    pPrintInfo(2);
    
    while(1)
    {
        switch(pGetKey())
        {
            case 'q':
                goto end;
            case 'r':
                goto start;
            default:
                continue;
        }
    }


end:    
    endwin();

    return 0;
}
