#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

struct highscore
{char name[50];
 double time;  //Structure for storing high scores
 int area;
}h1;

void halloffame()
{
  fstream afile;
  afile.open("highscor.dat", ios::in);
  while(!afile.eof()) //this statement itself reads the file.
  {afile.read((char*)&h1, sizeof(h1));
   clrscr();
   cout<<"\t\tHall of Fame\n\nArea of grid : "<<h1.area<<"\nName of champion : "<<h1.name
       <<"\nTime taken to complete the game : "<<h1.time;
   getch();
  };
 afile.close();
}

void scorchange(float tim, int ar)
{
 int chek=0;
 char nam[50];
 fstream afile, bfile;

 afile.open("highscor.dat", ios::in);
 bfile.open("temp.dat", ios::out);
 while(afile.read((char*)&h1, sizeof(h1)))
 {if(h1.time>tim&&ar==h1.area)
  {cout<<"\n\nCongratulations!!!! You have made a new record\n\nPlease enter"
       <<" your name : ";
   gets(h1.name);
   h1.time=tim; h1.area=ar;
   cout<<"\n\nThank You! Your record has been saved and can be viewed anytime"
       <<" during gameplay by pressing s/S.";
   getch(); chek++;
  }
  bfile.write((char*)&h1, sizeof(h1));
 };
 if(chek==0)
  {cout<<"\n\nCongratulations!!!! You have made a new record\n\nPlease enter"
       <<" your name : ";
   gets(h1.name);
   h1.time=tim; h1.area=ar;
   cout<<"\n\nThank You! Your record has been saved and can be viewed anytime"
       <<" during gameplay by pressing s/S.";
   bfile.write((char*)&h1, sizeof(h1));
  }
 afile.close();
 bfile.close();

 afile.open("highscor.dat", ios::out);
 bfile.open("temp.dat", ios::in);
 while( bfile.read((char*)&h1,sizeof(h1)) )
 {afile.write((char*)&h1, sizeof(h1)); };
 afile.close();
 bfile.close();


}

void main()
{
 clrscr();
 float a; int ar;
 cout<<"Time : "; cin>>a;
 cout<<"Area : "; cin>>ar;
 scorchange(a,ar);
 halloffame();
 getch();
}


