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
 fstream afile;
 int count=0;

 afile.open("highscor.dat", ios::in);
 afile.seekg(0, ios::end);
 count=afile.tellg()/sizeof(h1);
 cout<<count;

 afile.seekg(0, ios::beg);
 int x=0;
 highscore *h2;
 h2 = new highscore[count];
 while(afile.read((char*)&h1, sizeof(h1)))
 {
  (*(h2+x)).time=h1.time; (*(h2+x)).area=h1.area;
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
    gets((*(h2+i)).name);
    (*(h2+i)).time=tim;      //Now scores are changed in the structure array
    cout<<"\n\nThank You! Your record has been saved and can be viewed anytime"
	<<" during gameplay by pressing s/S.";
    getch();
   }
 }

 afile.open("highscor.dat", ios::out);
 for(i=0; i<count; count++)          //write down the structure array into
 afile.write((char*)(h2+i), sizeof(h1)); //the file

 if(chek==0) //if the area is not already present then add it into the record
 {
  cout<<"\n\nCongratulations!!!! You have made a new record\n\nPlease enter"
      <<" your name : ";
  gets(h1.name);
  h1.time=tim; h1.area=ar;
  cout<<h1.name<<h1.area<<h1.time;
  afile.write((char*)&h1, sizeof(h1));
  cout<<"\n\nThank You! Your record has been saved and can be viewed anytime"
      <<" during gameplay by pressing s/S.";
  getch();
 }
 afile.close();
 // now the scores are written into the file
 for(int j=0; j<count; j++)
 {cout<<"Name : "<<(*(h2+j)).name<<"\nArea : "<<(*(h2+j)).area<<"\nTime : "
      <<(*(h2+j)).time;
 }
 cout<<h1.area<<h1.name<<h1.time;
 getch();
 delete h2;
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


