#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>

float start, end, comps, compe, tim=0.0, sum=0.0, stat1, stat2, temp;
//initial variables for time

struct highscore
{char name[50];
 float time;  //Structure for storing high scores
 int area;
}h1;

void halloffame()
{
  fstream afile;
  afile.open("highscor.dat", ios::in);
  while(!afile.eof())
  {afile.read((char*)&h1, sizeof(h1));
   clrscr();
   cout<<"\t\tHall of Fame\n\nArea of grid : "<<h1.area<<"\nName of champion : "<<h1.name
       <<"\nTime taken to complete the game : "<<h1.time;
   getch();
  };
 afile.close();
}

inline void rndmize(int gridx, int gridy, int& trgtx, int& trgty)
{
 trgtx=random(gridx)+1;
 trgty=random(gridy)+1;
}
//function to randomly place the target alphabet in the grid

inline float endd(float& start, float& temp)
{
 end=(temp-start)/CLK_TCK;
 return end;
}
//calculates the time difference.

void credits();
void help();
void resize(int&, int&, int&, char); //change the size of the grid
void find(int&,int&); //place the arrow at the start
void scorchange(float time, int area); //func for changing scores

void main()
{
 int arrx=1, arry=1, trgtx, trgty, gridx=15, gridy=10, police=0;
//variables for arrow and target position and size of grid
 char grid[21][80], arr='', trgt='a', choice;
//array of grid, arrow, target, and the key pressed
// textcolor(BLUE); // set textcolor to blink and blue
// textbackground(BLINK+GREEN); //set background colour to green
 clrscr();
 gotoxy(1,12); //Put cursor in 1st coloumn and 12th row
 cprintf("***********************Welcome to the Alphabet Chase Game***********************");
 cprintf("\n\n\r\rAt any time press C for credits, S for high scores, H for help and R for \n\rresizing the grid.\n\n\n\r\r\rPress any key to continue");
 //Note : \n places the cursor in the next line and /r puts it at the first
 //coloumn
 getch();
 randomize(); //initialise the C++ random number generator
 rndmize(gridx, gridy, trgtx, trgty); //call to my own function
 comps=clock(); //save the current time
 start=clock();
 end=clock();
 _setcursortype(_NOCURSOR); //don't show the cursor.
 do
 {
//  textcolor(MAGENTA); //reset colours
//  textbackground(CYAN);
  clrscr();
  for(int i=0; i<=(gridy+1); i++)    //set all the places in grid as space
  {                                  //and the edges as $ (in memmory)
   for(int j=0; j<=(gridx+1); j++)
   {
    grid[i][j]=' ';
    if(i==(gridy+1)||j==(gridx+1)||i==0||j==0) grid[i][j]='$';
   }
  }
  grid[trgty][trgtx]=trgt; //place the target
  grid[arry][arrx]=arr; //place the arrow
  for(i=0; i<=(gridy+1); i++) //now show the grid on screen
  {
   cout<<endl;
   for(int j=0; j<=(gridx+1); j++)
   {
    putch(grid[i][j]);
   }
  }
  stat1=clock(); //note the time when the target was placed
  temp=(stat1-stat2)/CLK_TCK;
  if(temp>=5.0) //if target has been in same position for more than 5 secs
  {             //then reposition the target
   rndmize(gridx, gridy, trgtx, trgty);
   stat2=clock();
  }
//  textcolor(LIGHTRED);
  cprintf("\n\n\r\rThe time taken to eat the previous letter was : ");
  cout<<tim;
  cprintf("\n\n\r\rTotal time till now : ");
  cout<<sum;
  choice=getch(); //get the input

  if(choice=='x'||choice=='X')   //move the arrow by adding or subtracting
  {                              //into or from the grid coordinates
   if(arrx<=gridx)               //change the shape of the arrow too
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

  if(choice=='q'||choice=='Q') break; //quit from game

  if(choice=='h'||choice=='H') //show help screen
  {
//   textcolor(RED);
//   textbackground(GREEN);
   help();
  }

  if(choice=='c'||choice=='C') //show credits
  {
//   textcolor(LIGHTMAGENTA);
//   textbackground(LIGHTBLUE);
   credits();
  }

  if(choice=='r'||choice=='R') //resize the grid
  {
//   textcolor(10);
//   textbackground(6);
   resize(gridx, gridy, police, trgt);
   rndmize(gridx, gridy, trgtx, trgty);
   arrx=0;
   arry=0;
  }

  if(choice=='@') trgt='Z'; //cheatcode

  if(choice=='f'||choice=='F') find(arrx, arry); //place the arrow at start

  if(trgtx==arrx&&trgty==arry) //match the position of the arrow and target.
  {                            //if they are the same then show the next
   end=clock();                //letter until Z. Also note the time.
   tim=endd(start,end);
   sum+=tim;
   start=clock();
   stat2=start;
   rndmize(gridx, gridy, trgtx, trgty);
   trgt++;
   if(trgt=='z'+1) trgt='A';
   if(trgt=='Z'+1) break;
  }

  if(choice=='s'||choice=='S') //show high scores
  {
   halloffame();
  }

 }while(1);
 compe=clock(); //stop the clock
 cprintf("\n\n\r\rTime for which this game was played : ");
 cout<<endd(comps,compe);
 if(trgt=='Z'+1&&police==0)
 {
  scorchange(endd(comps,compe),gridx*gridy);
 };

 getch();
// textcolor(RED);
// textbackground(LIGHTGRAY);
 clrscr();
 credits();
 cprintf("\n\n\r\rThank you for playing the game.");
 getch();
// textcolor(LIGHTGRAY);
// textbackground(BLACK);
 clrscr();
}


void credits()
{
 clrscr();
 cprintf("Created by : \n\r Vinayak Thakur.");
 getch();
}

void help()
{
 clrscr();
 cprintf("This game is very simple to play. You have an arrow which will point in the dir-ection you will move it. The keys are \n\n\r\rX/x : Right\n\n\r\rZ/z : Left\n\n\r\rK/k : Up\n\n\r\rM/m : Down\n\n\r\rC/c : Credits\n\n\r\rR/r : Resize grid\n\n\r\rF/f : Find arrow and realocate it\n\n\r\rS/s : Show high scores\n\n\r\rYou have to catch the alphabet in the grid. Once you do that, it will change in-to the next letter and this will go on till the last alphabet.");
 getch();
}

void resize(int& gridx, int& gridy, int& police, char a)
{                     //func for changing size of grid. If the player changes
 clrscr();            //the size of the grid after eating a then scores will
 do                   //not be considered
 {
  cprintf("Please Note, that the bigger the grid, the slower the game will work.\n\n\r\rEnter the number of places in the y coordinate : ");
  cin>>gridy;
  cprintf("\n\rEnter the number of places in the x coordinate : ");
  cin>>gridx;
  if(gridx>77||gridx<2||gridy<2||gridy>19) cprintf("\n\n\r\rKindly enter a number between 2 to 77 for x axis and 2 to 19 for y axis.\n\n\r\r");
 }while(gridx>77||gridx<2||gridy<2||gridy>19);
 if(a!='a') police++;
}

void find(int& arrx,int& arry)
{
 arrx=0;
 arry=0;
}

void scorchange(float tim, int ar)
{
 int chek=0;
 char nam[50];
 fstream afile;
 int count=-1;

 afile.open("highscor.dat", ios::in);
 while(!afile.eof())
 {
  afile.read((char*)&h1, sizeof(h1));
  count++;
 };
 afile.close();   //algo to count the no. of entries

 afile.open("highscor.dat", ios::in);
 int x=0;
 highscore *h2;
 h2 = new highscore[count];
 while(!afile.eof())
 {
  afile.read((char*)&h1, sizeof(h1));
  (*(h2+x)).time=h1.time; (*(h2+x)).time=h1.time;
  strcpy((*(h2+x)).name, h1.name);
  if(h1.area==ar) chek++;
  x++;
 };                // algo to shift all the high scores in array of structure
 afile.close();    // named t2.

 for(int i=0; i<count; i++) //run through all the scores
 { if( (*(h2+i)).time>tim && ar==(*(h2+i)).area ) //check if time is less
   {                                          //if yes then change the scores
    cout<<"\n\nCongratulations!!!! You have made a new record\n\nPlease enter"
	<<" your name : ";
    gets(nam);
    strcpy( (*(h2+i)).name, nam);
    (*(h2+i)).time=tim;      //Now scores are changed in the structure array
    cout<<"\n\nThank You! Your record has been saved and can be viewed anytime"
	<<" during gameplay by pressing s/S.";
    getch();
   }
 }

 afile.open("highscor.dat", ios::out);
 for(i=0; i<count; count++)          //write down the structure array into
 { afile.write((char*)(h2+i), sizeof(h2+i)); } //the file

 if(chek==0) //if the area is not already present then add it into the record
 {
  cout<<"\n\nCongratulations!!!! You have made a new record\n\nPlease enter"
      <<" your name : ";
  gets(nam);
  strcpy(h1.name, nam);
  h1.time=tim; h1.area=ar;
  afile.write((char*)&h1, sizeof(h1));
  cout<<"\n\nThank You! Your record has been saved and can be viewed anytime"
      <<" during gameplay by pressing s/S.";
  getch();
 }

 // now the scores are written into the file
 delete h2;
}

