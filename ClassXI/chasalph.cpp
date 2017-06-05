#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

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
 clrscr();
 int arrx=1, arry=1, trgtx, trgty, gridx=15, gridy=10;
 char grid[21][80], arr='', trgt='a', choice;
 for(int x=0; x<=959; x++) cout<<" ";
 cout<<"***********************Welcome to the Alphabet Chase Game***********************";
 cout<<"\n\nAt any time press C for credits, H for help and R for resizing the grid.\n\n\nPress any key to continue";
 getch();
 randomize();
 rndmize(gridx, gridy, trgtx, trgty);
 comps=clock();
 start=clock();
 end=clock();
 _setcursortype(_NOCURSOR);
 do
 {
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
    cout<<grid[i][j];
   }
  }
  cout<<"\n\nThe time taken to eat the previous letter was : "<<tim<<"\n\nTotal time till now : "<<sum;
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
  if(choice=='h'||choice=='H') help();
  if(choice=='c'||choice=='C') credits();
  if(choice=='r'||choice=='R')
  {
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
 cout<<"\n\nTime for which this game was played : "<<endd(comps,compe);
 getch();
 clrscr();
 credits();
 cout<<"\n\nThank you for playing the game.";
 getch();
}


void credits()
{
 clrscr();
 cout<<"Created by the Smart Programmers : \n\tRavi Prakash.\n\tAbhishek Tomar.";
 getch();
}

void help()
{
 clrscr();
 cout<<"This game is very simple to play. You have an arrow which will point in the dir-ection you will move it. The keys are \n\nX/x : Right\n\nZ/z : Left\n\nK/k : Up\n\nM/m : Down\n\nC/c : Credits\n\nR/r : resize grid\n\nF/f : Find arrow and realocate it\n\nYou have to catch the alphabet in the grid. Once you do that, it will change in-to the next letter and this will go on till the last alphabet.";
 getch();
}

void resize(int& gridx, int& gridy)
{
 clrscr();
 do
 {
  cout<<"Please Note, that the bigger the grid, the slower the program will work.\n\nEnter the number of places in the y coordinate : ";
  cin>>gridy;
  cout<<"\nEnter the number of places in the x coordinate : ";
  cin>>gridx;
  if(gridx>77||gridx<2||gridy<2||gridy>19) cout<<"\n\nKindly enter a number between 2 to 77 for x axis and 2 to 19 for y axis.\n\n";
 }while(gridx>77||gridx<2||gridy<2||gridy>19);
}

void find(int& arrx,int& arry)
{
 arrx=0;
 arry=0;
}

