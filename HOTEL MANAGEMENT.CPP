#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
int password()
{
 char b[8];
 int ch,i;
 clrscr();
 gotoxy(5,5);
 cout<<"Enter the password : ";
gets(b);
 if(strcmpi(b,"admin")==0)
 {
  getch();
  return(1);
 }
 else
 {
  gotoxy(30,10);
  cout<<"ACCESS DENIED!!!";
  getch();
  return(0);
 }
}

 scr_clear()
{
 int r=1,i;
 for(i=1;i<=30;i++)
 {
  clreol();
  delay(20);
  r++;
 }
 return(0);
}

			  //Information about the room
struct room
{
 int r_no;
 char prname[40];
 char prtype[20];
 char status;
 int charges;
 int bal,days,rent;
 long int bill;
}
varf1;

			//Information about the customer
struct customer
{
 int r_no;
 char cust_name[20];
 char cust_addr[20];
 int paid;
}
varf2;

		       //Object of fstream class
fstream temp,file;

		      //Declaration of class hotel
class hotel
{
 private:
 int count;

 public:
 hotel()
 {
  count = 0;
 }
 void r_add();
 void r_booking();
 void run();
 void r_status();
 void r_vacant();
 void r_check();
 void r_delete();
 void ano();
 void bno();
 void output();
}h;

		      //Function for adding room
void hotel::r_add()
{
 scr_clear();
 char ans='n';
 do
 {
  clrscr();
  int rent,bal,ds,inp;
  char inp2[20];
  output();
  cout<<"\n\n Add new room details";
  file.open("room.dat",ios::in | ios::out);
  if(!file)
  {
   cout<<"\n File does not open";
   getch();
   exit(0);
  }
  file.seekg(0,ios::beg);
  while(file.read((char*)&varf1,sizeof(varf1)))
  count = varf1.r_no;
  file.close();
  varf1.r_no = count+1;
  count++;
  cout<<"\n Room number : "<<count;
  cout<<"\n Room type : "<<endl;
  cout<<"\n\t 1. Economic(s) or Economic(d) Rs. 4000";
  cout<<"\n\t 2. Delux(s) or Delux(d) Rs. 6000";
  cout<<"\n\t 3. Luxury(s) or Luxury(d) Rs. 8000";
  cout<<"\n\n For eg, Delux(s). This signifies 'delux' economy type single room \n\n";
  cout<<"\nEnter your choice : ";
  cin>>inp;
  if(inp==1)
  {
   varf1.charges=4000;
   strcpy(varf1.prname,"economic");
  }
  else if(inp==2)
  {
   varf1.charges=6000;
   strcpy(varf1.prname,"delux");
  }
  else
  {
   varf1.charges=8000;
   strcpy(varf1.prname,"luxury");
  }
  varf1.status='v';
  file.open("room.dat",ios::app | ios::out);
  if(!file)
  {
   cout<<"\n File does not open";
   getch();
   exit(0);
  }
  file.seekp(count*sizeof(varf1));
  file.write((char*)&varf1,sizeof(varf1));
  file.close();
  cout<<"\n\n Input more room detail (Y/N) : ";
  cin>>ans;
 }
 while(ans=='Y'||ans=='y');
 clrscr();
}
void hotel::r_booking()
{
 scr_clear();
 char ans='Y';
 do
 {
  clrscr();
  char inp2[20],inp3[40];
  int inp;
  int h=0;
  int t_code=0;
  output();
  cout<<"\nRoom booking details ";
  cout<<"\nRoom no : \t";
  cin>>inp;
  file.open("room.dat",ios::in | ios::out);
  if(!file)
  {
   cout<<"\n file does not open ";
   getch();
   exit(0);
  }
  file.seekg(ios::beg);
  while(file.read((char*)&varf1,sizeof(varf1)))
  if((inp==varf1.r_no)&&(varf1.status=='v'))
  {
   t_code = varf1.r_no;
   h=1;
   break;
  }
  file.close();
  if(h)
  {
   char inp2[20],inp3[40];
   cout<<"\n Customer Name : ";
   gets(inp2);
   strcpy(varf2.cust_name,inp2);
   cout<<"\n Customer Address : ";
   gets(inp3);
   strcpy(varf2.cust_addr,inp3);
   cout<<"\n Amount Paid : ";
   cin>>varf2.paid;
   varf1.rent = varf2.paid;
   cout<<"\nEnter the no of days : ";
   cin>>varf1.days;
   clrscr();
   cout<<"\n\n Now this room is booked for \n";
   cout<<"\n\t"<<varf2.cust_name;
   cout<<"\n\t"<<varf2.cust_addr;
   varf2.r_no=t_code;
   varf1.status='n';
   if(strcmpi(varf1.prname,"economic")==0)
   varf1.bal=varf1.charges-varf1.rent;
   else if(strcmpi(varf1.prname,"delux")==0)
   varf1.bal=varf1.charges-varf1.rent;
   else if(strcmpi(varf1.prname,"luxury")==0)
   varf1.bal=varf1.charges-varf1.rent;
   varf1.bill=(varf1.charges*varf1.days)-varf1.rent;
   file.open("room.dat",ios::out|ios::ate);
   if(!file)
   {
    cout<<"\nFile does not open";
    getch();
    exit(0);
   }
   int recno;
   recno=varf1.r_no;
   int location;
   location=(recno-1)*sizeof(varf1);
   file.seekp(location,ios::beg);
   file.write((char*)&varf1,sizeof(varf1));
   file.close();
   file.open("cust.dat",ios::app|ios::out);
   if (!file)
   {
    cout<<"\nfile does not open";
    getch();
    exit(0);
   }
    file.write((char*)&varf2,sizeof(varf2));
    file.close();
    cout<<"\n\n\nBook more room(y/n) :";
    cin>>ans;
   }
   else
   {
    ano();
    ans='n';
   }
  }
   while(ans=='y'||ans=='Y');
   clrscr();
 }

 void hotel::run()
 {
  char go='y';
  do
  {
   char choice;
   output();
   gotoxy(30,10);
   cout<<"1. Create new room";
   gotoxy(30,11);
   cout<<"2. Room booking";
   gotoxy(30,12);
   cout<<"3. Room vacant";
   gotoxy(30,13);
   cout<<"4. Room status report";
   gotoxy(30,14);
   cout<<"5. Check details";
   gotoxy(30,15);
   cout<<"6. Delete record";
   gotoxy(30,16);
   cout<<"0. Exit";
   gotoxy(30,17);
   cout<<"Your choice : ";
   fflush(stdin);
   choice=getch();
   switch(choice)
   {
    case '1':clrscr();
	     r_add();
	     break;
    case '2':clrscr();
	     r_booking();
	     break;
    case '3':clrscr();
	     r_vacant();
	     break;
    case '4':clrscr();
	     r_status();
	     break;
    case '5':clrscr();
	     r_check();
	     break;
    case '6':clrscr();
	     r_delete();
	     break;
    case '0':go='n';
	     break;
   }
  }
   while (go!='n');
   clrscr();
 }
   void hotel::r_vacant()
   {
    scr_clear();
    char ans='y';
    do
    {
    int temp;
    clrscr();
    output();
    fflush(stdin);
    cout<<"\n\n Room number : ";
    cin>>temp;
    char h='n';
    file.open("room.dat",ios::in);
    if(!file)
    {
     cout<<"\n File does not open";
     getch();
     exit(0);
    }
    file.seekg(0,ios::beg);
    int t_code = 0;
    while(file.read((char*)&varf1,sizeof(varf1)))
    {
     if(varf1.r_no==temp)
     {
      t_code=varf1.r_no;
      h='y';
      break;
     }
    }
    file.close();
    if(h=='y')
    {
     varf1.status='v';
     file.open("room.dat",ios::out|ios::ate);
    if (!file)
    {
     cout<<"\nfile does not open";
     getch();
     exit(0);
    }
    int recno;
    recno=t_code;
    int location;
    location=(recno-1)*sizeof(varf1);
    file.seekp(location);
    file.write((char*)&varf1,sizeof(varf1));
    file.close();
    cout<<"\n Anymore room (y/n) : ";
    cin>>ans;
   }
   else
   {
    bno();
    ans='y';
   }
  }
   while(ans=='y'||ans=='Y');
   clrscr();
 }
 void hotel::r_status()
 {
  scr_clear();
  int j=0;
  clrscr();
  output();
   gotoxy(2,8);
   cout<<"r_no";
   gotoxy(10,8);
   cout<<"Room ";
   gotoxy(20,8);
   cout<<"Status";
   gotoxy(32,8);
   cout<<"Charges";
   gotoxy(45,8);
   cout<<"Paid amt";
   gotoxy(55,8);
   cout<<"Balance";
   gotoxy(65,8);
   cout<<"Days";
   gotoxy(72,8);
   cout<<"Bill";
   gotoxy(2,9);
  cout<<"=====================================================";
  file.open("room.dat",ios::in);
    if (!file)
    {
     cout<<"\nfile does not open";
     getch();
     exit(0);
    }
    file.seekg(0,ios::beg);
    j=1;
    while(file.read((char*)&varf1,sizeof(varf1)))
    {
     gotoxy(3,9+j);
     cout<<varf1.r_no;
     gotoxy(10,9+j);
     cout<<varf1.prname;
     gotoxy(20,9+j);
     if(varf1.status=='v')
     cout<<"Vacant";
     else
     cout<<"non-vacant";
     gotoxy(34,9+j);
     cout<<varf1.charges;
     if(varf1.status!='v')
     {
      gotoxy(47,9+j);
      cout<<varf1.rent;
      gotoxy(57,9+j);
      cout<<varf1.bal;
      gotoxy(66,9+j);
      cout<<varf1.days;
      gotoxy(73,9+j);
      cout<<varf1.bill;
     }
     if(j>14)
     {
      j++;
      gotoxy(50,6+j);
      cout<<"Press any key to continue....";
      getch();
      clrscr();
      output();
      gotoxy(4,8);
      cout<<"Room no";
      gotoxy(20,8);
      cout<<"Room";
      gotoxy(40,8);
      cout<<"Status";
      gotoxy(68,8);
      cout<<"Charges";
      gotoxy(4,9);
      cout<<"===============================================>>";
      j=1;
    }
    else
     j++;
    }
    file.close();
    getch();
    clrscr();
 }
  void hotel::r_check()
  {
   scr_clear();
   char oms='y';
   do
   {
    clrscr();
    output();
    int check;
    gotoxy(1,5);
    cout<<"\n\nTo check detail about the customer";
    cout<<"\nEnter the room no : ";
    cin>>check;
    file.open("cust.dat",ios::in);
    if (!file)
    {
     cout<<"\nfile does not open";
     getch();
     exit(0);
    }
    file.seekg(0,ios::beg);
    while(file.read((char*)&varf2,sizeof(varf2)))
    {
     if(check==varf2.r_no)
     {
      cout<<"\nRoom no : "<<varf2.r_no;
      cout<<"\nCustomer name : "<<varf2.cust_name;
      cout<<"\nCustomer address : "<<varf2.cust_addr;
      cout<<"\nAmount paid : "<<varf2.paid;
     }
    }
    file.close();
    getch();
    cout<<"\n\nCheck any other person(y/n) :";
    cin>>oms;
  }
  while((oms=='y')||(oms=='Y'));
  clrscr();
 }
 void hotel::r_delete()
 {
  int no;
  scr_clear();
  cout<<"\nDo delete a record ";
  cout<<"\nEnter room no. : ";
  cin>>no;
  file.open("cust.dat",ios::in);
  temp.open("cust1.dat",ios::out);
    if (!file)
    {
     cout<<"\nfile does not open";
     getch();
     exit(0);
    }
    if (!temp)
    {
     cout<<"\nfile does not open";
     getch();
     exit(0);
    }
   while(file.read((char*)&varf2,sizeof(varf2)))
   {
    if(no!=varf2.r_no)
    {
     temp.write((char*)&varf2,sizeof(varf2));
    }
   }
   getch();
   clrscr();
   delete("cust.dat");
   rename("cust1.dat","cust.dat");
  }
  void hotel::ano()
  {
   scr_clear();
   cout<<"\n This type is not available";
   getch();
   clrscr();
  }
  void hotel::bno()
  {
   scr_clear();
   cout<<"\n This type was never booked ";
   getch();
  }
  void hotel::output()
  {
   scr_clear();
   gotoxy(25,4);
   cout<<"*******************************************";
   gotoxy(25,5);
   cout<<"           WELCOME TO LEE MERIDIEN";
   gotoxy(25,6);
   cout<<"*******************************************";
  }
  void main()
  {
   int p,i=1;
   clrscr();
   while(i<=3)
   {
    p=password();
    if(p==1)
    {
     clrscr();
     h.run();
     break;
    }
    else
    {
     if(i==1)
     {
      gotoxy(28,12);
      cout<<"This was your first chance";
      gotoxy(33,13);
      cout<<"please try again";
      getch();
     }
     else if(i==2)
     {
      gotoxy(28,12);
      cout<<"This was your second chance";
      gotoxy(33,13);
      cout<<"please try again";
      getch();
     }
     else
     {
      gotoxy(28,12);
      cout<<"This was your last chance";
      gotoxy(22,13);
      cout<<"Sorry you can't open this project";
      getch();
     }
    }
    i++;
   }
   getch();
  }
