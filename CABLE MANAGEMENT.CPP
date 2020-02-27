#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void intro();
int count=0;
void owner();
void product();
void order_menu();
void all_rec();
void place_order();
void check_order();
void modify_order();
void intro();
void delete_order();
class wcompany
{
	public:
	int ccode,wcore,wsize,wlen,ono;
	char wtype[20],wcolour[20],cname[20];
	void get_order()
	{
		clrscr();
		cout<<"\n Enter customer's code";
		cin>>ccode;
		cout<<"\n Enter customer's name";
		gets(cname);
		cout<<"\n Enter customer's order";
		cout<<"\n Enter the type of wire";
		gets(wtype);
		cout<<"\n Enter the number of core of wire";
		cin>>wcore;
		cout<<"\n Enter the size of wire";
		cin>>wsize;
		cout<<"\n Enter the colour of the wire";
		gets(wcolour);
		cout<<"\n Enter the length of wire you want";
		cin>>wlen;
	}
       void put_order()
	{
		cout<<ccode<<setw(16)<<cname<<setw(11)<<wtype<<setw(7)<<wcore<<setw(12)<<wsize<<
		setw(11)<<wcolour<<setw(6)<<wlen<<setw(10)<<ono<<endl;
	}
	void modify()
	{
		clrscr();
		int ccode1,wcore1,wsize1,wlen1,ono1;
		char wtype1[20],wcolour1[20];

		/*cout<<"\n Enter customer's new code";
		cin>>ccode;
		cout<<"\n Enter customer's name";
		gets(cname); */
		cout<<"\n Enter customer's new order";
		cout<<"\n Enter the type of wire:(Enter'.'to retain old one)";
		gets(wtype1);
		cout<<"\n Enter the number of core of wire:(Enter'.'to retain old one)";
		cin>>wcore1;
		cout<<"\n Enter the size of wire:(Enter'.'to retain old one)";
		cin>>wsize1;
		cout<<"\n Enter the colour of the wire:(Enter'.'to retain old one)";
		gets(wcolour1);
		cout<<"\n Enter the length of wire you want:(Enter'.'to retain old one)";
		cin>>wlen1;
		//if(strcmp(wtype1,'.')!=0)
		strcpy(wtype,wtype1);
		//if(strcmp(wcolour1,'.')!=0)
		strcpy(wcolour,wcolour1);
		wcore=wcore1;
		wsize=wsize1;
		wlen=wlen1;
	}

       /*wcompany()

	{
		ccode=0;
		ono=0   ;
	}*/
};
void show_column()
{
	cout<<"====================================================\n";
	cout<<"Cust. No."<<setw(7)<<"Name"<<setw(12)<<"wire type"<<setw(8)<<"core"<<setw(14)<<"wiresize"<<
	setw(8)<<"colour"<<setw(8)<<"length"<<setw(14)<<"order no.\n";
	cout<<"====================================================\n";
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
	cout<<" W I R E  D E A L E R  M A N A G E M E N T  S O F T W A R E  ";
	gotoxy(33,16);
	textcolor(WHITE);
	cout<<" D O N E  B Y :  ";
	gotoxy(45,18);
	cout<<" Gaurav Narula";
	gotoxy(25,20);
	cout<<"";
	textcolor(WHITE);
	gotoxy(35,30);
	cout<<" *** PRESS ANY KEY TO CONTINUE ***";
	getch();
}
void search_code()
{
	clrscr();
	int ono1,found=0;
	wcompany c;
	cout<<"\n";
	cout<<"\t\t\t*-----------*"<<"\n";
	cout<<"\t\t\t| SEARCHING |"<<"\n";
	cout<<"\t\t\t*-----------*"<<"\n"<<"\n";
	ifstream fin;
	fin.open("wire.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(1);
	}
	else
	{
		cout<<"\n\tENTER THE CUSTOMER NUMBER TO BE SEARCHED :";
		cin>>ono1;
		while(fin)
		{
			fin.read((char*)&c,sizeof(c));
			if(c.ono==ono1)
			{
				found=1;
				break;
			}
		}
	 }
	 fin.close();
	 if(found==0)
	 {
		cout<<"\n\t Order not found";
		getch();
	 }
	 else
	 {
		cout<<"\n Order found";
		cout<<"\n the order is:\n";
		show_column();
		c.put_order();
		getch();
	 }
owner();
}
void owner()
{
	clrscr();
	char ch2;
	cout<<"\n\n\n\tOWNER MENU";
	cout<<"\n\n\t1.ADD RECORD";
	cout<<"\n\n\t2.MODIFY RECORD";
	cout<<"\n\n\t3.DELETE RECORD";
	cout<<"\n\n\t4.SEARCH CUSTOMER RECORD";
	cout<<"\n\n\t5.ALL RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice : ";
	cin>>ch2;
	switch(ch2)
	{
		case '1': place_order();
			  break;
		case '2': modify_order();
			  break;
		case '3': delete_order();
			  break;
		case '4': search_code();
			  break;
		case '5': all_rec();
			  break;
		case '6': intro();
			  break;

	}
}
void all_rec()
{
	clrscr();
	wcompany c;
	ifstream fin;
	fin.open("wire.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(1);
	}
	else
	{

		show_column();
		while(!fin.eof())
		{
			fin.read((char*)&c,sizeof(c));
			c.put_order();
		}
	fin.close();
	}
	getch();
	owner();
}
void place_order()
{
	wcompany c;
	char ch='y';
	ifstream fin;
	fin.open("wire.dat",ios::binary|ios::in);
	if(!fin)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(1);
	}
	else
	{
		while(!fin.eof())
		{
			fin.read((char*)&c,sizeof(c));
			count++;
		}
	}
	fin.close();
	fstream fout;
	fout.open("wire.dat",ios::binary|ios::app);
	while(ch=='y'||ch=='Y')
	    {
		clrscr();
		fout.seekp(-1*sizeof(c),ios::cur);
		fout.read((char*)&c,sizeof(c));
		count=c.ono;
		c.get_order();
		c.ono=count+1;
		fout.seekp(0,ios::end);
		fout.write((char*)&c,sizeof(c));
		cout<<"\n Order added";
		cout<<"\n order number:"<<c.ono;
		cout<<"\n want to enter more orders????";
		cin>>ch;
		getch();
	    }
	  fout.close();
	  owner();
}
void check_order()
{
	clrscr();
	wcompany c;
	int ono,found=0;
	ifstream fin;
	fin.open("wire.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(1);
	}
	else
	{
		while(fin)
		{
			fin.read((char*)&c,sizeof(c));
			if(c.ono==ono)
			{

				found=1;
				break;
			}
		}
	 }
	 fin.close();
	 if(found==0)
	 cout<<"\n\t Order not placed";
	 else
	 {
		cout<<"\n Order placed";
		cout<<"\n The order is:";
		show_column();
		c.put_order();
		getch();
	  }
	  order_menu();

}
void modify_order()
{
	clrscr();
	wcompany c;
	fstream fio("wire.dat",ios::in|ios::out|ios::binary);
	int ono,location,flag=0;
	long pos;
	char found='f';
	if(!fio)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(1);
	}
	else
	{
		cout<<"\n Enter the Order number of customer you want to modify";
		cin>>ono;
		while(!fio.eof())
		{
			pos=fio.tellg();
			fio.read((char*)&c,sizeof(c));
			if(c.ono==ono)
			{
				c.modify();
				fio.seekg(pos);
				fio.write((char*)&c,sizeof(c));
				found='t';
				break;
			}
		}
		if(found=='f')
		cout<<"\n\t Order not exist";
		fio.seekg(0);
		cout<<"\n now the file contains\n";
		show_column();
		while(!fio.eof())
		{
			fio.read((char*)&c,sizeof(c));
			c.put_order();
			getch();
		}
		fio.close();
		fstream f;
	f.open("wire.dat",ios::binary|ios::in|ios::out);
	if(!f)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(1);
	}
	else
	{
		cout<<"\n Enter the Order number of customer you want to modify";
		cin>>ono;
		while(f)
		{
			f.read((char*)&c,sizeof(c));
			if(c.ono==ono)
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		cout<<"\n\t Order not exist";
		else
		{
			f.seekg(0,ios::beg);
			while(f)
			{
				f.read((char*)&c,sizeof(c));
				if(c.ono==ono)
				{
					cout<<"\n Enter the new details";
					c.modify();
					c.get_order();
					location=f.tellg()-sizeof(c);
					cout<<location;
					f.seekg(location,ios::cur);
					f.write((char*)&c,sizeof(c));
					cout<<"\n order modified";
					getch();
				}
			}
		}
	}
	f.close();
	owner();
}
void delete_order()
{

	clrscr();
	wcompany c;
	int ono,flag=0;
	ifstream fin;
	ofstream fout;
	fin.open("wire.dat",ios::in|ios::binary);
	fout.open("temp.dat",ios::binary|ios::app);
	if(!fin)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(1);
	}
	else
	{
		cout<<"\n Enter the Order number of customer you want to delete";
		cin>>ono;
		while(fin)
		{
			fin.read((char*)&c,sizeof(c));
			if(c.ono==ono)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		      cout<<"\n\t Order not exist";
		else
		{
			fin.seekg(0,ios::beg);
			while(fin)
			{
				fin.read((char*)&c,sizeof(c));
				if(c.ono!=ono)
				fout.write((char*)&c,sizeof(c));
			}
			cout<<"\n Order deleted!!!";
		}
		getch();
	}
	fin.close();
	fout.close();
	remove("wire.dat");
	rename("temp.dat","wire.dat") ;
	owner();
}
void order_menu()
{
	clrscr();
	char ch2;
	cout<<"\n\n\n\t CUSTOMER ORDER MENU";
	cout<<"\n\n\t1.PLACE ORDER";
	cout<<"\n\n\t2.CHECK ORDER";
	cout<<"\n\n\t3.MODIFY ORDER";
	cout<<"\n\n\t4.CANCELLED ORDER";
	cout<<"\n\n\t5.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice : ";
	cin>>ch2;
	switch(ch2)
	{
		case '1': clrscr();
			  place_order();
			  break;
		case '2': check_order();
			  break;
		case '3': modify_order();
			  break;
		case '4': delete_order();
			  break;
		case '5': intro();
			  break;
	}

}
void product()
{ 	char ch;
	clrscr();
	cout<<"\n \n P R I C E     L I S T\n\n";
	cout<<"========================================================================\n";
	cout<<"S.No.	SIZE		AREA	CURRENT		SINGLE CORE	LENGHT \n";
	cout<<"========================================================================\n";
	cout<<"1.	16/22mm		0.50	4		300		90mtrs \n";
	cout<<"2.	24/20mm		0.75	7		450		90mtrs \n";
	cout<<"3.	12/30mm		1.00	11		510		90mtrs \n";
	cout<<"4.	22/30mm		1.50	14		770		90mtrs \n";
	cout<<"5.	36/30mm		2.50	19		1200		90mtrs \n";
	cout<<"6.	56/30mm		4.00	26		1900		90mtrs \n";
	cout<<"\n\n\n\n BACK TO MAIN MENU (PRESS B))";
	cin>>ch;
	if(ch=='b'||ch=='B')
	intro();
getch();
}
void intro()
{
	clrscr();
	char ch,cho;
	textcolor(WHITE);
	cout<<"\n\n\n\tMAIN MENU";
	cout<<"\n\n\t01. OWNER'S MENU";
	cout<<"\n\n\t02. PRODUCTS LIST";
	cout<<"\n\n\t03. ORDERS";
	cout<<"\n\n\t04. REPORTS";
	cout<<"\n\n\t05. EXIT";
	cout<<"\n\n\tPlease Select Your Option (1-5) ";
	cin>>ch;
		switch(ch)
	{
		case '1': clrscr();
			  owner();
			  break;
		case '2': product();
			  break;
		case '3': order_menu();
			  break;
		case '4': all_rec();
			  break;
		case '5': exit(1);
		default :cout<<"\wrong choice entered";
	};
}

void main()
{
	clrscr();
	wcompany c;
	textcolor(WHITE);
	welcome_screen();
	intro();
	getch();

};

}
