#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
int width=40 , height=25;
int x,y, fruitx, fruity, score;
int tailx[99], taily[99];
int ntail;
enum directions {STOP=0, LEFT,RIGTH,UP,DOWN };
directions dir;
// 1
int setup()
{
	gameover= false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitx= rand() % width;
	fruity= rand() % height;
	score=0;
}
// 2
int draw()
{
    	
	system("cls");
	system("COLOR 1B");
	cout<<"\n\n\n\n \t\t\t\t";
	for(int i=0;i<width+1;i++)
	cout<<"\xB2\xB2";
	
	cout<<endl;
	
	for(int i=0;i<=height;i++)
	{
		for(int j=0;j<=width;j++)
		{
			if(j==0)
	 			cout<<" \t\t\t\t\xB2";
			if(i==y && j==x)
			  	cout<<"0 ";
			else if(i==fruity && j==fruitx)
				cout<<"* ";
			else
			{
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
					
					if(tailx[k]==j && taily[k]==i)
					{
						cout<<"o ";
						print=true;
					}
				}
				if(!print)
				cout<<"  ";	
			}
	       
		   if(j==width-1)
		   cout<<"\xB2";		
	
		}
		cout<<endl;
	}
	cout<<" \t\t\t\t";
	for(int i=0;i<width+1;i++)
	cout<<"\xB2\xB2";
	cout<<endl;
   
}

// 3
int input()
{

	
   if (kbhit())	
{
	switch (getch())
	{
	case 'a':
	   dir=LEFT;
	   break;
	case 'd':
	   dir=RIGTH;
	   break; 
	case 'w':
	   dir=UP;
	   break; 
	case 's':
	   dir=DOWN;
	   break; 
	case 'x':
	 gameover=true;
	 break;       	
	}
}



}

// 4
int logic()
{
	int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<ntail;i++)
    {
    	prev2x=tailx[i];
    	prev2y=taily[i];
    	tailx[i]=prevx;
    	taily[i]=prevy;
    	prevx=prev2x;
    	prevy=prev2y;
	}
switch(dir)
{
	case LEFT:
	 	x--;
	 	break;
	case RIGTH:
	 	x++;
	 	break;
	case UP:
	 	y--;
	 	break;	 
	case DOWN:
	 	y++;
	 	break;
	default:
	break;
}
	if(x> width|| x < 0|| y > height|| y < 0)
	gameover=true;
/*	

	if(x>=width) 
	x=0;	
	else if(x<0)	
	x=width-2;
	
	if(y>=height) 
	y=0;	
	else if(y<0)	
	y=height-1;
*/	
	for(int i=0;i<ntail;i++)
	{
		if(tailx[i]==x && taily[i]==y)
		gameover=true;
	}
	
	if(x==fruitx && y==fruity)
	{
		score+=10;
	fruitx= rand() % width;
	fruity= rand() % height;
	ntail++;
		
	 }	 	  	
}

	



int main()
{
	
	
	system("COLOR 75");

	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t         @@@@@@@@@@                          \n";
	cout<<"\t       @@@@@@@@@@@@@@                       \n";
	cout<<"\t     @@@@@@@@@@@@@@@@@                      \n";
	cout<<"\t   @@@@@@@@@@@@@@@@@@@@                           \n";
	cout<<"\t  @@@@@@@@@@@@@@@@@@@@@@                    \n";
	cout<<"\t @@@@@@             @@@@                                                                                                        \n";
	cout<<"\t@@@@@@                    @@@@@@@@@@@           @@@@@@@@             @@@@@@@@@@@                @@@@@@@    @@@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@ \n";
	cout<<"\t@@@@@@                    @@@@@@@@@@@@           @@@@@@             @@@@@@@@@@@@@               @@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@ \n";
	cout<<"\t @@@@@@                   @@@@@@@@@@@@@   \xB2\xB2\xB2\xB2   @@@@ \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2        \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  @@@@@@@      @@@@@@@@@@@@@@@@@@@@@ \n";
	cout<<"\t  @@@@@@@@@@@@@@@@@@      @@@@@@@ @@@@@@  \xB2\xB2\xB2\xB2        \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2        \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  @@@@@        @@@@@@@            @@       \n";
	cout<<"\t                 @@@@@@   @@@@@@@  @@@@@  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2        \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2     \xB2\xB2\xB2\xB2   @@@@@@          @@@@@@@@@@@@@@@       \n";
	cout<<"\t                  @@@@@@  @@@@@@@   @@@@  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2        \xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2     \xB2\xB2\xB2\xB2   @@@@            @@@@@@@@@@@@@@@       \n";
	cout<<"\t                  @@@@@@  @@@@@@@    @@@  \xB2\xB2\xB2\xB2        \xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2    \xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2     \xB2\xB2\xB2\xB2   @@@@            @@@@@@@             \n";
	cout<<"\t@@@@             @@@@@@   @@@@@@@     @@  \xB2\xB2\xB2\xB2  @@@@  \xB2\xB2\xB2\xB2    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    \xB2\xB2\xB2\xB2    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2     \xB2\xB2\xB2\xB2   @@@@@@          @@@@@@@            @@ \n";
	cout<<"\t @@@@@@@@@@@@@@@@@@@@     @@@@@@@       @       @@@@@@     @@@@@@@              @@@@@@@         @@@@@@@  @@@@@@@        @@@@@@@@@@@@@@@@@@@@@ \n";
	cout<<"\t   @@@@@@@@@@@@@@@@       @@@@@@@        @@@@@@@@@@@@@@   @@@@@@@                @@@@@@@        @@@@@@@    @@@@@@@@     @@@@@@@@@@@@@@@@@@@@@ \n";
	cout<<"\t     @@@@@@@@@@@@        @@@@@@@@@        @@@@@@@@@@@@@  @@@@@@@@@              @@@@@@@@@      @@@@@@@@@   @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@ \n";
	cout<<"\t       @@@@@@@@                                                                 \n";
	cout<<"\n\n\n\n";

	cout<<" \n\n\n\n\t\t\t\t\t\t\t\t\tPress any key TO PLAY...";
	getch();
	{
		cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLoading Game...\n\n\t\t\t\t*****";
		for(int i=0;i<80;i++)
		{
			Sleep(50);
			cout<<"\xB2";
		}
		cout<<"*****";
		Sleep(500);
		system("cls");
		setup();
        while(!gameover)
		{
			draw();
			input();
			logic();
			Sleep(100);
		 } 
		 
		 cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\tGAME OVER !!! ";
		 Sleep(1000);
		 
		 
		 cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\tYour Score is : "<<score;
	     Sleep(5000);
		 //getch();
		system("cls");
		system("COLOR 4E");
		for(int i=0;i<168;i++)
		{
		
			cout<<"\xB2";
		}
		cout<<"\n\n\n\n\n\n\t\t\tDEVELOPED BY";
		Sleep(800);
		cout<<"\n\n\n\t\t";
		for(int i=0;i<30;i++)
		{
			Sleep(20);
			cout<<"*";
		}
		cout<<"\n\t\t";
		for(int i=0;i<30;i++)
		{
			Sleep(20);
			cout<<"*";
		}
		
		cout<<"\n\n\n\t\t\t\t\t\t\tUMAR FAROOQ.";
		Sleep(800);
		cout<<"\n\n\n\t\t\t\t\t\t";
		for(int i=0;i<30;i++)
		{
			Sleep(20);
			cout<<"*";
		}
		cout<<"\n\t\t\t\t\t\t";
		for(int i=0;i<30;i++)
		{
			Sleep(20);
			cout<<"*";
		}
		

		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		for(int i=0;i<168;i++)
		{

			cout<<"\xB2";
		}
		getch();
		system("cls"); 
	}
		system("COLOR 70");

		
system("pause"); 	
}
