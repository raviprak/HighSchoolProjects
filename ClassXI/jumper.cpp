#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

float start, end, comps, compe, tim=0.0, sum=0.0;

inline void rndmize(int gridx, int gridy, int& trgtx, int& trgty)
{
 trgtx=random(gridx)+1;
 trgty=random(gridy)+1;
}

inline float endd(float& start, float& temp)
{
 end=(temp-start)/CLK_TCK;
 return end;
}

void credits();
void help();
void resize(int&, int&);
void find(int&,int&);

void main()
{

 int arrx=1, arry=1, trgtx, trgty, gridx=15, gridy=10;
 char grid[21][80], arr='', trgt='a', choice;
 textcolor(129);
 textbackground(2);
 clrscr();
 gotoxy(1,12);
 cprintf("***********************Welcome to the Alphabet Chase Game***********************");
 cprintf("\n\n\r\rAt any time press C for credits, H for help and R for resizing the grid.\n\n\n\r\r\rPress any key to continue");
 getch();
 randomize();
 rndmize(gridx, gridy, trgtx, trgty);
 comps=clock();
 start=clock();
 end=clock();
 do
 {
  textcolor(5);
  textbackground(3);
  clrscr();
  for(int i=0; i<=(gridy+1); i++)
  {
   for(int j=0; j<=(gridx+1); j++)
   {
    grid[i][j]=' ';
    if(i==(gridy+1)||j==(gridx+1)||i==0||j==0) grid[i][j]='$';
   }
  }
  grid[trgty][trgtx]=trgt;
  grid[arry][arrx]=arr;
  for(i=0; i<=(gridy+1); i++)
  {
   cout<<endl;
   for(int j=0; j<=(gridx+1); j++)
   {
    putch(grid[i][j]);
   }
  }
  textcolor(12);
  cprintf("\n\n\r\rThe time taken to eat the previous letter was : ");
  cout<<tim;
  cprintf("\n\n\r\rTotal time till now : ");
  cout<<sum;
  choice=getch();
  if(choice=='x'||choice=='X')
  {
   if(arrx<=gridx)
   {
    arrx++;
    arr='';
   }
  }
  if(choice=='z'||choice=='Z')
  {
   if(arrx>=1)
   {
    arrx--;
    arr='';
   }
  }
  if(choice=='k'||choice=='K')
  {
   if(arry>=1)
   {
    arry--;
    arr='';
   }
  }
  if(choice=='m'||choice=='M')
  {
   if(arry<=gridy)
   {
    arry++;
    arr='';
   }
  }
  if(choice=='q'||choice=='Q') break;
  if(choice=='h'||choice=='H')
  {
   textcolor(4);
   textbackground(2);
   help();
  }
  if(choice=='c'||choice=='C')
  {
   textcolor(13);
   textbackground(9);
   credits();
  }
  if(choice=='r'||choice=='R')
  {
   textcolor(10);
   textbackground(6);
   resize(gridx, gridy);
   rndmize(gridx, gridy, trgtx, trgty);
   arrx=0;
   arry=0;
  }
  if(choice=='f'||choice=='F') find(arrx, arry);
  if(trgtx==arrx&&trgty==arry)
  {
   end=clock();
   tim=endd(start,end);
   sum+=tim;
   start=clock();
   rndmize(gridx, gridy, trgtx, trgty);
   trgt++;
   if(trgt=='z'+1) trgt='A';
   if(trgt=='Z'+1) break;
  }
 }while(1);
 compe=clock();
 cprintf("\n\n\r\rTime for which this game was played : ");
 cout<<endd(comps,compe);
 getch();
 textcolor(4);
 textbackground(7);
 clrscr();
 credits();
 cprintf("\n\n\r\rThank you for playing the game.");
 getch();
 textcolor(7);
 textbackground(0);
 clrscr();
}


void credits()
{
 clrscr();
 cprintf("Created by the Smart Programmers : \n\r Ravi Prakash.\n\r Abhishek Tomar.");
 getch();
}

void help()
{
 clrscr();
 cprintf("This game is very simple to play. You have an arrow which will point in the dir-ection you will move it. The keys are \n\n\r\rX/x : Right\n\n\r\rZ/z : Left\n\n\r\rK/k : Up\n\n\r\rM/m : Down\n\n\r\rC/c : Credits\n\n\r\rR/r : Resize grid\n\n\r\rF/f : Find arrow and realocate it\n\n\r\rYou have to catch the alphabet in the grid. Once you do that, it will change in-to the next letter and this will go on till the last alphabet.");
 getch();
}

void resize(int& gridx, int& gridy)
{
 clrscr();
 do
 {
  cprintf("Please Note, that the bigger the grid, the slower the program will work.\n\n\r\rEnter the number of places in the y coordinate : ");
  cin>>gridy;
  cprintf("\n\rEnter the number of places in the x coordinate : ");
  cin>>gridx;
  if(gridx>77||gridx<2||gridy<2||gridy>19) cprintf("\n\n\r\rKindly enter a number between 2 to 77 for x axis and 2 to 19 for y axis.\n\n\r\r");
 }while(gridx>77||gridx<2||gridy<2||gridy>19);
}

void find(int& arrx,int& arry)
{
 arrx=0;
 arry=0;
}

