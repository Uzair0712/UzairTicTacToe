#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//First introduction to the Game and asking name
void intro(char name[])
{
    printf("\n\t\tHello\n\t\tWelcome to the Tic Tac Toe Game\n\n");
    printf("\t\tPlease Enter your name :\n\t\t>>> ");
    fgets(name,20,stdin);
    name[strlen(name)-1]='\0';
}

//Taking User's Choice 
void Taking_Choice(int *choice)
{
    int i=0;
    printf("\n\t\tChoose whith whome you want to play :");
    printf("\n\t\t1) With Computer");
    printf("\n\t\t2) With Evil Computer [Warning!! This will not allow you to win]");
    printf("\n\t\t3) With your Friend");
    printf("\n\n\t\tYou can press 0 (zero) at any time to exit the game :");

    
    do
    {
        if(i>0)
            printf("\n\t\tWrong Choic, Re-Enter your choice :");
        printf("\n\t\t>>> ");
        scanf("%d",choice);
        fflush(stdin);
        i++;
    }while(*choice != 1 && *choice != 2 && *choice != 3 && *choice != 0);
}

void display(char name[] ,int a[],char turn[])
{
    int i;
    system("cls");
    printf("\n\t\tGame Of >>> %s\t\tTurn >>> %s",name,turn);
    
    printf("\n\n\t##################################");
    printf("\n\n\t\t-------------------\n\t\t|");
    for(i=0;i<9;i++)
    {
        if(i%3==0 && i!=0)
            printf("\n\t\t|     |     |     |\n\t\t|");
        if(a[i]==0)
            printf("  %d  |",i+1);
        else
            printf("  %c  |",a[i]);
            
    }
    printf("\n\t\t-------------------");
    printf("\n\n\t##################################");
}

int CheckWin(int a[])
{
    int i;
    for(i=0;i<3;i++)
    {
        if(a[i]==a[i+3] && a[i]==a[i+6])
        {
            if(a[i]=='O')
                return 1;
            else if(a[i]=='X')
                return 2;
        }
    }

    for(i=0;i<8;i+=3)
    {
        if(a[i]==a[i+1] && a[i]==a[i+2])
        {
            if(a[i]=='O')
                return 1;
            else if(a[i]=='X')
                return 2;
        }
    }

    for(i=0;i<3;i+=2)
    {
        if(i == 0 && a[0]==a[4] && a[0]==a[8])
        {
            if(a[i]=='O')
                return 1;
            else if(a[i]=='X')
                return 2;
        }
        if(i == 2 && a[2]==a[4] && a[2]==a[6])
        {
            if(a[i]=='O')
                return 1;
            else if(a[i]=='X')
                return 2;
        }
    }
}

//To apply the moves taken by the user
void ApplyChanges(int a[], int position, int * markP, int mark[],int player)
{
    if(player == 1)    
        a[position-1] = 'O';
    else if(player == 2)
        a[position-1] = 'X';
    mark[*markP] = position;
    *markP += 1 ;   
}

//How Genuin Computer will mark the X
void computer(int a[], int position, int * markP, int mark[])
{
    int i,x,round=0,make,defense;
    make = mark[*markP-2];
    defense = position;
    srand(time(0));

    if(*markP==1)
    {
        do
        {
            x = rand()%9+1;
        }while(x==mark[0]);

        a[x-1] = 'X';
        mark[1] = x;
        *markP +=1 ; 
    }

    else
    {
    while(round<3)
    {    
        if(round == 0)
                position = make;
        else if(round == 1)
                position = defense;
        else if (round == 2)
        {
                do
                {
                        x = rand()%9+1;
                        for(i=0;i<*markP;i++)
                        {
                                if(mark[i] == x)
                                break;
                        }
                } while (i!=*markP);
                a[x-1] = 'X';
                mark[*markP] = x;
                *markP +=1;
                break;       
        }
    switch (position)
    {
    case 1:
        if(a[0]==a[1] && a[2]==0)
        {
          
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                round = 3;
        }

        else if(a[0]==a[2] && a[1]==0)
        {
            
                a[1] = 'X';
                mark[*markP] = 2;
                *markP += 1 ;    
                round = 3;        
       }

        else if(a[0]==a[3] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                round = 3;
        }

        else if(a[0]==a[6] && a[3]==0)
        {
                a[3] = 'X';
                mark[*markP] = 4;
                *markP += 1 ; 
                round = 3;
        }

        else if(a[0]==a[4] && a[8]==0)
        {
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                round = 3;
        }

        else if(a[0]==a[8] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                round = 3;
        }

        break;
    
    case 2:
        if(a[1]==a[2] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                round = 3;
        }

        else if(a[1]==a[0] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                round = 3;
        }

        else if(a[1]==a[4] && a[7]==0)
        {
                a[7] = 'X';
                mark[*markP] = 8;
                *markP += 1 ;
                round = 3;
        }

        else if(a[1]==a[7] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                round = 3;
        }
        break;

    case 3:
        if(a[2]==a[1] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                round = 3;
        }

        else if(a[2]==a[0] && a[1]==0)
        {
                a[1] = 'X';
                mark[*markP] = 2;
                *markP += 1 ;
                round = 3;
        }

        else if(a[2]==a[5] && a[8]==0)
        {
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                round = 3;
        }
        
        else if(a[2]==a[8] && a[5]==0)
        {
            a[5] = 'X';
            mark[*markP] = 6;
            *markP += 1 ;
            round = 3;
        }

        else if(a[2]==a[4] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                round = 3;
        }

        else if(a[2]==a[6] && a[4]==0)
        {
            a[4] = 'X';
            mark[*markP] = 5;
            *markP += 1 ;
            round = 3;
        }

       
        break;

    case 4:
        if(a[3]==a[0] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                round = 3;
        }

        else if(a[3]==a[6] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                round = 3;
        }

        else if(a[3]==a[4] && a[5]==0)
        {
                a[5] = 'X';
                mark[*markP] = 6;
                *markP += 1 ;
                round = 3;
        }

        else if(a[3]==a[5] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                round = 3;
        }
       
        break;

    case 5:
        if(a[4]==a[1]  && a[7]==0)
        {
                a[7] = 'X';
                mark[*markP] = 8;
                *markP += 1 ;
                round = 3;
        }

        else if(a[4]==a[7] && a[1]==0)
        {
                a[1] = 'X';
                mark[*markP] = 2;
                *markP += 1 ;
                round = 3;
        }

        else if(a[4]==a[3] && a[5]==0)
        {
                a[5] = 'X';
                mark[*markP] = 6;
                *markP += 1 ;
                round = 3;
        }
        
        else if(a[4]==a[5]  && a[3]==0)
        {
                a[3] = 'X';
                mark[*markP] = 4;
                *markP += 1 ;
                round = 3;
        }

        else if(a[4]==a[0] && a[8]==0)
        {
               a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                round = 3;
        }

        else if(a[4]==a[8] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                round = 3;
        }

        else if(a[4]==a[2] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                round = 3;
        }

        else if(a[4]==a[6] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                round = 3;
        } 
         
        break;

    case 6:
        if(a[5]==a[4] && a[3]==0)
        {
                a[3] = 'X';
                mark[*markP] = 4;
                *markP += 1 ;
                round = 3;
        }

        else if(a[5]==a[3]  && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                round = 3;
        }

        else if(a[5]==a[2] && a[8]==0)
        {
            
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                round = 3;
        }

        else if(a[5]==a[8] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                round = 3;
        }
        
        break;

    case 7:
        if(a[6]==a[3] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                round = 3;
        }

        else if(a[6]==a[0] && a[3]==0)
        {
                a[3] = 'X';
                mark[*markP] = 4;
                *markP += 1 ;
                round = 3;
        }

        else if(a[6]==a[7] && a[8]==0)
        {
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                round = 3;
        }

         else if(a[6]==a[8] && a[7]==0)
        {
                a[7] = 'X';
                mark[*markP] = 8;
                *markP += 1 ;
                round = 3;
        }
        
        else if(a[6]==a[4] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                round = 3;
        }

        else if(a[6]==a[2] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                round = 3;
        }
       
        break;

    case 8:
        if(a[7]==a[4] && a[1]==0)
        {
                a[1] = 'X';
                mark[*markP] = 2;
                *markP += 1 ;
                round = 3;
        }

        else if(a[7]==a[1] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                round = 3;
        }

        else if(a[7]==a[6] && a[8]==0)
        {
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                round = 3;
        }

        else if(a[7]==a[8] && a[6]==0)
        {   
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                round = 3;
        }
      
        break;

    case 9:
        if(a[8]==a[7] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                round = 3;
        }

        else if(a[8]==a[6] && a[7]==0)
        {
                a[7] = 'X';
                mark[*markP] = 8;
                *markP += 1 ;
                round = 3;
        }

        else if(a[8]==a[5] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                round = 3;
        }

         else if(a[8]==a[2] && a[5]==0)
        {
                a[5] = 'X';
                mark[*markP] = 6;
                *markP += 1 ;
                round = 3;
        }
        
        else if(a[8]==a[4] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                round = 3;
        }

        else if(a[8]==a[0] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                round = 3;
        }
        break;
    }
    round ++;
    }

    }
}


//How evil Computer will work
void Evilcomputer(int a[], int position,int *number, int * markP, int mark[])
{
    int i,x,round=0,make,defense;
    make = mark[*markP-2];
    defense = position;
    srand(time(0));

    if(*markP==1)
    {
        do
        {
            x = rand()%9+1;
        }while(x==mark[0]);

        a[x-1] = 'X';
        mark[1] = x;
        *markP +=1 ; 
    }

    else
    {
    while(round<4)
    {    
        if(round == 0)
                position = make;
        else if(round == 1 || round == 3)
                position = defense;
        
        else if (round == 2)
        {
                do
                {
                        x = rand()%9+1;
                        for(i=0;i<*markP;i++)
                        {
                                if(mark[i] == x)
                                break;
                        }
                } while (i!=*markP);
                a[x-1] = 'X';
                mark[*markP] = x;
                *markP +=1;
                break;       
        }
    switch (position)
    {
    case 1:
        if(a[0]==a[1] && a[2]==0)
        {
          
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[0]==a[2] && a[1]==0)
        {
            
                a[1] = 'X';
                mark[*markP] = 2;
                *markP += 1 ;    
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;        
       }

        else if(a[0]==a[3] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[0]==a[6] && a[3]==0)
        {
                a[3] = 'X';
                mark[*markP] = 4;
                *markP += 1 ; 
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[0]==a[4] && a[8]==0)
        {
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[0]==a[8] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        break;
    
    case 2:
        if(a[1]==a[2] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[1]==a[0] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[1]==a[4] && a[7]==0)
        {
                a[7] = 'X';
                mark[*markP] = 8;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[1]==a[7] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
        break;

    case 3:
        if(a[2]==a[1] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[2]==a[0] && a[1]==0)
        {
                a[1] = 'X';
                mark[*markP] = 2;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[2]==a[5] && a[8]==0)
        {
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
        
        else if(a[2]==a[8] && a[5]==0)
        {
            a[5] = 'X';
            mark[*markP] = 6;
            *markP += 1 ;
            if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[2]==a[4] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[2]==a[6] && a[4]==0)
        {
            a[4] = 'X';
            mark[*markP] = 5;
            *markP += 1 ;
            if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
            if(round == 3)
            *number +=1;
        }

       
        break;

    case 4:
        if(a[3]==a[0] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[3]==a[6] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[3]==a[4] && a[5]==0)
        {
                a[5] = 'X';
                mark[*markP] = 6;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[3]==a[5] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
       
        break;

    case 5:
        if(a[4]==a[1]  && a[7]==0)
        {
                a[7] = 'X';
                mark[*markP] = 8;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[4]==a[7] && a[1]==0)
        {
                a[1] = 'X';
                mark[*markP] = 2;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[4]==a[3] && a[5]==0)
        {
                a[5] = 'X';
                mark[*markP] = 6;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
        
        else if(a[4]==a[5]  && a[3]==0)
        {
                a[3] = 'X';
                mark[*markP] = 4;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[4]==a[0] && a[8]==0)
        {
               a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[4]==a[8] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[4]==a[2] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[4]==a[6] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        } 
         
        break;

    case 6:
        if(a[5]==a[4] && a[3]==0)
        {
                a[3] = 'X';
                mark[*markP] = 4;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[5]==a[3]  && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[5]==a[2] && a[8]==0)
        {
            
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[5]==a[8] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
        
        break;

    case 7:
        if(a[6]==a[3] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[6]==a[0] && a[3]==0)
        {
                a[3] = 'X';
                mark[*markP] = 4;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[6]==a[7] && a[8]==0)
        {
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

         else if(a[6]==a[8] && a[7]==0)
        {
                a[7] = 'X';
                mark[*markP] = 8;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
        
        else if(a[6]==a[4] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[6]==a[2] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
       
        break;

    case 8:
        if(a[7]==a[4] && a[1]==0)
        {
                a[1] = 'X';
                mark[*markP] = 2;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[7]==a[1] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[7]==a[6] && a[8]==0)
        {
                a[8] = 'X';
                mark[*markP] = 9;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[7]==a[8] && a[6]==0)
        {   
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
      
        break;

    case 9:
        if(a[8]==a[7] && a[6]==0)
        {
                a[6] = 'X';
                mark[*markP] = 7;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[8]==a[6] && a[7]==0)
        {
                a[7] = 'X';
                mark[*markP] = 8;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[8]==a[5] && a[2]==0)
        {
                a[2] = 'X';
                mark[*markP] = 3;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

         else if(a[8]==a[2] && a[5]==0)
        {
                a[5] = 'X';
                mark[*markP] = 6;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
        
        else if(a[8]==a[4] && a[0]==0)
        {
                a[0] = 'X';
                mark[*markP] = 1;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }

        else if(a[8]==a[0] && a[4]==0)
        {
                a[4] = 'X';
                mark[*markP] = 5;
                *markP += 1 ;
                if(round == 1) 
                round = 2;
                else
                round = 4;
            if(round == 3)
            *number +=1;
        }
        break;
    }
    round++;
    }

    }
}

//To take the position from the Player
int Check_move(int * markP, int mark[],int position)
{
    int i;
    if(position < 1 || position > 9)
        return 0;

    for(i=0;i<*markP;i++)
    {
        if(mark[i]==position)
            return 0;
    }
    return 1;
}


int main()
{
    char name[20],name2[20];
    intro(name);

    while(6)
    {    
    int arr[9]={0};
    int marked[9]={0},mark_count,n,Counter;
    int position,win;
    int choice,player,PlayAgain;
    Taking_Choice(&choice);
    if(choice == 0)
    exit(0);

    if(choice == 3)
    {
        printf("\n\n\t\t>>> Enter player 2's name :\n\t\t>>> ");
        fgets(name2,20,stdin);
        name2[strlen(name2)-1]='\0';
    }

    mark_count = 0;
    n = 0;
    char turn[20];
    do
    {
        player = 1;
        strcpy(turn,name);
        display(name,arr,turn);
        Counter=0;
        do
        {
            if(Counter>0)
                printf("\n\n\t\t>>> Wront Position ");
            printf("\n\n\t\tEnter the Position\n\t\t>>> ");
            scanf("%d",&position);
            if(position == 0)
            exit(0);
            Counter ++;
        } while (!Check_move(&mark_count,marked,position));

        //Applying Changes accorging to the input by the Player
        ApplyChanges(arr,position,&mark_count,marked,player);
        n++;
        //Check if Player won or not
        win = CheckWin(arr);
        if(win == 1)
        {
                display(name,arr,turn);
                printf("\n\n\t\t>>> Congratlations %s won the game ",name);
                getch();
                system("cls");
                printf("\n\t\t>>> Want to play again ????");
                printf("\n\t\t>>> If yes Press only Y or y else press 0 (zero)");
                do
                {
                printf("\n\t\t>>> ");       
                scanf("%c",&PlayAgain);
                }while(PlayAgain != 'Y' && PlayAgain != 'y' && PlayAgain != '0');
                if(PlayAgain == '0')
                exit(0);
                break;
        }

        //Now computer takes it's turn
        if(n<9)
        {
        if(choice == 1)
        {
                computer(arr,position,&mark_count,marked);
                win = CheckWin(arr);
                if(win == 2)
                {
                        display(name,arr,"Computer");
                        printf("\n\n\t\t>>> Sorry! You loose ");
                        getch();
                        system("cls");
                        printf("\n\t\t>>> Want to play again ????");
                        printf("\n\t\t>>> If yes Press only Y or y else press 0 (zero)");
                        do
                        {
                        printf("\n\t\t>>> ");
                        scanf("%c",&PlayAgain);
                        }while(PlayAgain != 'Y' && PlayAgain != 'y' && PlayAgain != '0');
                        if(PlayAgain == '0')
                        exit(0);
                        break;
                }
        }
        else if(choice == 2)
        {
                Evilcomputer(arr,position,&n,&mark_count,marked);
                win = CheckWin(arr);
                if(win == 2)
                {
                        display(name,arr,"ComputerE");
                        printf("\n\n\t\t>>> Sorry! You loose ");
                        getch();
                        system("cls");
                        printf("\n\t\t>>> Want to play again ????");
                        printf("\n\t\t>>> If yes Press only Y or y else press 0 (zero)");
                        do
                        {
                        printf("\n\t\t>>> "); 
                        scanf("%c",&PlayAgain);
                        }while(PlayAgain != 'Y' && PlayAgain != 'y' && PlayAgain != '0');
                        if(PlayAgain == '0')
                        exit(0);
                        break;
                }
        }
        else if(choice == 3)
        {
                strcpy(turn,name2);
                display(name,arr,turn);
                player = 2;
                Counter=0;
                do
                {
                    if(Counter>0)
                        printf("\n\n\t\t>>> Wront Position ");
                    printf("\n\n\t\tEnter the Position\n\t\t>>> ");
                    scanf("%d",&position);
                    if(position == 0)
                    exit(0);
                    Counter ++;
                } while (!Check_move(&mark_count,marked,position));
                  ApplyChanges(arr,position,&mark_count,marked,player);
                   win = CheckWin(arr);
                if(win == 2)
                {
                        display(name,arr,turn);
                        printf("\n\n\t\t>>> Congratulations %s won the game ",name2);
                        getch();
                        system("cls");
                        printf("\n\t\t>>> Want to play again ????");
                        printf("\n\t\t>>> If yes Press only Y or y else press 0 (zero)");
                        do
                        {
                        printf("\n\t\t>>> ");
                        scanf("%c",&PlayAgain);
                        }while(PlayAgain != 'Y' && PlayAgain != 'y' && PlayAgain != '0');
                        if(PlayAgain == '0')
                        exit(0);
                        break;
                }
        } 
        n++;
        }
        }while(n<9); 
        if(n>=9)
        {
                display(name,arr,turn);
                printf("\n\n\t\t>>> The game is TIED !!!!!!!");
                getch();
                system("cls");
                printf("\n\t\t>>> Want to play again ????");
                printf("\n\t\t>>> If yes Press only Y or y else press 0 (zero)");
                do
                {
                printf("\n\t\t>>> ");
                scanf("%c",&PlayAgain);
                }while(PlayAgain != 'Y' && PlayAgain != 'y' && PlayAgain != '0');
                if(PlayAgain == '0')
                exit(0);
        }
    
    }
    
    return 0;
}
