//****************         AIR TICKET BOOKING SYSTEM          ******************
//********************************************************************
//                      INCLUDING HEADER FILES
//********************************************************************
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<iomanip.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>

//********************************************************************
//            CLASS DECLARATION FOR BOOKING FLIGHT
//********************************************************************

class ticket; // forward declaration of class
class booking
{

private :
		int booking_no;
		char name[30];
		int adults,kids,old;
public :
		booking()
		{
		booking_no=0;
		}
		int ret_book()
		{
			return(booking_no);
		}
		void get_booking(int book)
		{
			booking_no=book;
		}
		int auto_booking();
		void input();
		friend void cal_fare(booking &,ticket &);
		void output();
};
//********************************************************************
//	FUNCTION TO INPUT BOOKING DETAILS
//********************************************************************
void booking::input()         // All Details Entered by the User
{
	cout<<"\t Name : " ;
	cin>>name;
	cout<<"\t No Of Adults : ";
	cin>>adults;
	cout<<"\t No Of Kids : ";
	cin>>kids ;
	cout<<"\t No Of Senior Citizen : ";
	cin>>old;
}
//********************************************************************
//             FUNCTION TO OUTPUT BOOKING DETAILS
//********************************************************************
void booking::output()             // Displaying the details
{
cout<<setw(5)<<booking_no<<setw(15)<<name<<setw(8)<<adults;
cout<<setw(14)<<kids<<setw(12)<<old<<endl;
}
//********************************************************************
//            FUNCTION USED TO AUTOGENERATE BOOKING NUMBER
//********************************************************************
int booking::auto_booking()       // To assign booking number
{
booking b ;
int book=0;
ifstream if1("booking.txt",ios::in);
if1.seekg(0,ios::beg) ;
while(if1.read((char *)this,sizeof(b) ))
       {
	book=this->ret_book();
       }
if1.close();
return(book);

}
//********************************************************************
//          CLASS TICKECT USED TO INPUT/OUTPUT TICKET DETAILS
//********************************************************************
class ticket
{
private:
	int booking_no;
char boarding[20],destination[20],date2[10];
char time[7],clss[2];
int flight_no;
float fare,fare1;

public  :
		void getvalue(int);
		void putvalue();
		void cal_fare1(int,char[]);
		friend void cal_fare(booking &,ticket &);
		int ret_booking()
		{
			return(booking_no);
		}
};
//********************************************************************
//              FUNCTION TO DISPLAY FLIGHT DETAILS
//********************************************************************
void flight_details()
{
	cout<<"      Flights        Economy     Business      Timings        \n";
	cout<<"      -------         -------     --------       -------    \n";
	cout<<"        					       hrs:min  \n";
	cout<<" 1.  Jet Airways    Rs 22000     Rs 34000       03:00 \n";
	cout<<"                                                13:30 \n";
	cout<<"                                                23:30 \n\n";
	cout<<" 2.  Indigo         Rs 12899    Rs 21000        06:00 \n";
	cout<<"                                                21:45 \n";
	cout<<"                                                14:35 \n\n";
	cout<<" 3.  Spice Jet      Rs 19499     Rs 20999       03:00 \n";
	cout<<"                                                09:30 \n";
	cout<<"                                                22:50 \n\n";
	cout<<" 4.  Air India      Rs 23000     Rs 34000       08:45 \n";
	cout<<"                                                12:45  \n";
	cout<<"                                                15:20 \n\n";
	cout<<" 5.  Deccan         Rs 22000     Rs 34578       00:10  \n";
	cout<<"                                                14:15 \n";
	cout<<"                                                17:10 \n\n";
}
//********************************************************************
//                 FUNCTION TO CALCULATE FARE ACCORDING TO CLASS
//********************************************************************
void ticket::cal_fare1(int flight_no,char clss[])
{

	switch(flight_no)
	   {
		case 1 :
			if ( strcmp(clss,"E")== 0)
			   fare1 = 22000 ;
			else if( strcmp(clss,"B")== 0)
				  fare1 = 34000 ;
				else
					 fare1 = 0 ;
					break ;
		case 2 :
			if (strcmp(clss,"E")== 0 )
			       fare1 = 12899 ;
				else if ( strcmp(clss,"B") == 0)
					fare1 = 21000 ;
					else
					      fare1 = 0 ;
						break ;
		case 3 :
			if ( strcmp(clss, "E" ) == 0 )
			      fare1 = 19499 ;
				else if ( strcmp(clss,"B"))
				     fare1 = 20999 ;
					else
					   fare1 = 0 ;
					break ;

		case 4 :
			if  (strcmp(clss ,"E" ) == 0 )
			     fare1 = 23000 ;
				else if ( strcmp(clss,"B") == 0 )
				    fare1 = 34000 ;
				else
					fare1 = 0 ;
					break ;
	case 5 :
		if  (strcmp(clss, "E" ) == 0 )
			   fare1 = 22000 ;
			else if ( strcmp( clss ,"B") == 0 )
				 fare1 = 34578 ;
				else
				       fare1 = 0 ;
					break ;
	default :
		cout<<"\n\n OOPS !! TRY AGAIN !!!! :) \t\t\t" <<endl ;
	      }
}
//********************************************************************
//                    FUNCTION TO INPUT TICKET DETAILS
//********************************************************************
void ticket::getvalue(int book)
{
	booking_no=book;
	cout<<"\tBoarding Place - " ;
	cin>>boarding;
	dest:
	cout<<"\tDestination Place - " ;
	cin>>destination;
	//----------- checking destination --------------
	if(strcmp(boarding,destination)==0)
	{
	cout<<"\tError!! Enter Another Destination "<<endl;
	goto dest;
	}
	//------------------------------------------------
	cout<<"\tDate of Departure ( dd-mm-yy) -   ";
	cin>>date2;
	//--------------callin flight details --------------
	flight_details();

	flight:
	cout<<"\n\tEnter  Your  Prefered  Flight  No ( 1 - 5 )  -  " ;
	cin>>flight_no;
	if(!(flight_no>=1 &&flight_no<=5))
	goto flight;
	cl:
	cout<<"\n\nEnter the Class ( B for Business / E for Economy ) - ";
	cin>>clss;
	//----------- checking class --------------------------
	if(!(strcmp(clss,"E")==0||strcmp(clss,"B")==0))
	{
		cout<<"\tError!! Enter class again";
		goto cl;
	}
       cal_fare1(flight_no,clss);
cout<<"\n\tEnter Your Timings Prefered in hh:mm format \t" ;
cin>>time;
}
//********************************************************************
//                  FUNCTION TO INPUT TICKET DETAILS
//********************************************************************
void ticket::putvalue()
{
cout<<setw(8)<<boarding<<setw(10)<<destination<<setw(12)<<date2;
cout<<setw(5)<<flight_no;
cout<<setw(11)<<clss<<setw(12)<<time<<setw(12)<<fare<<endl;
}
//********************************************************************
//         FRIEND FUNCTION TO CALCULATE BOOKING FARE
//********************************************************************
void cal_fare(booking &b,ticket&t)   // To Calculate Total Fare
{
	t.booking_no=b.booking_no;
	int total ;
	total = b.adults + (b.kids * 0.75) + (b.old * 0.50) ;
	t.fare = t.fare1 * total ;
}
//********************************************************************
//                  ADDING DETAILS IN FILE -BOOKING
//********************************************************************
void add()                         // Booking of ticket
{
int bookingno;
	booking b ;
	bookingno=b.auto_booking(); // generate booking no
	b.get_booking(bookingno);
ofstream of1("booking.txt",ios::out|ios::app);
ofstream of2("tickets.txt",ios::out|ios::app);
ticket tc;
char ans;
do
       {

		bookingno++;
		b.get_booking(bookingno);
		b.input();
	of1.write((char *)&b,sizeof(b));

	tc.getvalue(bookingno);
	   //-------------------------------------------
	cal_fare(b,tc);    // calling friend function
	of2.write((char *)&tc,sizeof(tc));
	cout<<"\n\n\tWant to add more records? ( y/n)";
	cin>>ans;
}while(ans=='y'||ans=='Y');
of1.close();
of2.close();
}
//********************************************************************
//              DISPLAYING CONTENTS OF BOOKING FILE
//********************************************************************
void display()                            // Displaying the ticket
{
booking b ;
ticket tc;

ifstream if1("booking.txt",ios::in);
ifstream if2("tickets.txt",ios::in);
cout<<"\n*********************************************************"<<endl;
cout<<"\nBooking_no\t Name\t  Adults   \tKids\t  S.Citizen "<<endl;
cout<<"\n*********************************************************"<<endl;
while(if1.read((char* )&b,sizeof(b)))
       {
		b.output();
       }
cout<<"\n\n************************************************************"<<endl;
cout<<"\n Boarding  Destination  Dt_Dept";
cout<<" Flight No.  Class   Timings      Fare"<<endl;
cout<<"\n********************************************************"<<endl<<endl;
while(if2.read((char* )&tc,sizeof(tc)))
    {
	tc.putvalue();
      }
if1.close();
if2.close();
}
//********************************************************************
//         FUNCTION DEL USED TO DELETE RECORDS FROM FILE -CANCEL
//********************************************************************
void del(int bookingno)
{
	booking b;

ifstream if1("booking.txt") ;
ofstream temp("temp.txt");		// create temporary file
while (if1.read(( char *)&b,sizeof(b)))
  {
if(bookingno!=b.ret_book())
    {

	temp.write(( char * )&b,sizeof(b));
    }
  }
if1.close();
temp.close();

remove("booking.txt");
rename("temp.txt","booking.txt") ;
}
void del1(int bookingno)
{
	ticket tc;
ifstream if2("tickets.txt" ) ;
ofstream tmp("temp1.txt");// create temporary file
while(if2.read(( char *)&tc,sizeof(tc)))
  {
if(bookingno!=tc.ret_booking())
    {

	tmp.write(( char * )&tc,sizeof(tc));
    }
  }
if2.close();
tmp.close();

remove("tickets.txt");
rename("temp1.txt","tickets.txt") ;
}
void menu()
{
cout<<"\t\t***********************************************"<<endl<<endl;
cout<<"\t\t       Welcome To Air Ticket Booking System    "<<endl<<endl;
cout<<"\t\t***********************************************"<<endl<<endl;
cout<<"\t\t\t  1. Booking The Ticket         \n\n";
cout<<"\t\t\t  2. Booking Details 	   \n\n";
cout<<"\t\t\t  3. Cancellation Of Ticket     \n\n";
cout<<"\t\t\t  4. exit                       \n\n";
cout<<"\t\t***********************************************"<<endl;
}
void welcome_screen()
{
	clrscr();
	char ch;
	gotoxy(15,10);
	cout<<"******************* W E L C O M E ********************* ";
	gotoxy(25,12);
	cout<<"***  *** " ;
	gotoxy(15,14);
	textcolor(WHITE);
	cout<<"        AIRLINE   M A N A G E M E N T  S O F T W A R E  ";
	gotoxy(33,16);
	textcolor(WHITE);
	cout<<" D O N E  B Y :  ";
	gotoxy(45,18);
	cout<<" GAURAV NARULA ";
	gotoxy(25,20);
	cout<<"";
	textcolor(WHITE);
	gotoxy(35,30);
	cout<<" *** PRESS ANY KEY TO CONTINUE ***";
	getch();
}

//********************************************************************
//                      MAIN PROGRAM
//********************************************************************
void main ()
{
int choose,book;
textcolor(WHITE);
welcome_screen();
char ans ;
clrscr () ;
do
     {
	clrscr();
	menu();
	cout<<"\n\t\t\t     Enter Your Choice - ";
	cin>> choose;

	switch(choose)
	 {
	case 1: add();
		break ;
	case 2: display() ;
		break ;
	case 3:cout<<"\t\t Enter The Booking Number You Want To Cancel = ";
		cin>>book;
		del(book);
		del1(book);
		break ;
	case 4:exit(0);
	default :cout<<"\n\t\t Oops Try Again !! \n";
	  }
	cout<<"\n\t\t Do You Want To Continue ( Y / N ) - ";
	cin>>ans;
}while(ans=='Y'||ans=='y');
getch();
}
