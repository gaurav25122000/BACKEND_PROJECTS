#include <iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

int main()
{
	int player = 1,i,choice,p;
	char n[2][40];
	clrscr();
	cout<<"Enter first Player Name ";
	cin>>n[0];
	cout<<"Enter Second Player Name ";
	cin>>n[1];
	strupr(n[0]);
	strupr(n[1]);
	char mark;
	do
	{
		board();
		player=(player%2)?1:2;

		if(player==1)
			p=0;
		else
			p=1;

		cout << "Player " << n[p] << ", enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout<<"Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();

		player++;
	}while(i==-1);
	board();
	fstream f1("tic_tac.txt",ios::in|ios::out|ios::binary|ios::app);
	f1<<"\n"<<n[0]<<"\t"<<n[1];
	if(i==1)
	{
		player--;
		if(player==1)
		{
			cout<<"\n\a";
			textcolor(10+128);
			cout<<""<<n[0];
			textcolor(15);
			cout<<" You are Winner";
			f1<<"\t"<<n[0];

		}

		else
		{
			cout<<"\n\a";
			textcolor(10+128);
			cout<<n[1];
			textcolor(15);
			cout<<" You are Winner";
			f1<<"\t"<<n[1];
		}

	}
	else
	{
		textcolor(4+128);
		cout<<"\aGame draw";
		f1<<"\tDraw";
	}
	cin.ignore();
	cin.get();
	char n1[30],n2[30],status[3];

	f1.seekg(0);
	cout<<"\nUSER1\tUSER2\tWINNER";
	while(f1)
	{
		  f1>>n1>>n2>>status;
		  cout<<"\n"<<n1<<"\t"<<n2<<"\t"<<status;
		if(f1.eof())
			break;
	}
	getch();
	return 0;
}

/*********************************************

	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		    && square[4] != '4' && square[5] != '5' && square[6] != '6'
		  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
	clrscr();
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}