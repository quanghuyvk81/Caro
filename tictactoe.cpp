// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <chrono>
#include <thread>
#pragma comment(lib,"winmm.lib")

using namespace std;

//Ve -------
void PrintLine01(int a) {
	cout << " ";
	for (int i = 0; i < a; i++) cout << "------- ";
	cout << "\n";
}
//Ve |      |
void PrintLine02(int a) {
	cout << "|";
	for (int i = 0; i < a; i++) cout << "       |";
	cout << "\n";
}
//Ve |   arr[b][i]   |
void PrintLine03(char arr[][100], int a, int b) {
	cout << "|";
	for (int i = 0; i < a; i++) {
		cout << "   ";
		cout << arr[b][i];
		cout << "   ";
	}
	cout << "\n";
}
//Ve Board
void PrintBoard(char arr[][100], int a) {
	using namespace std::this_thread;
	using namespace std::chrono;
	PrintLine01(a);
	for (int i = 0; i < a; i++)
	{
		sleep_for(milliseconds(20));
		PrintLine02(a);
		sleep_for(milliseconds(20));
		cout << "|";
		for (int j = 0; j < a; j++) {
			cout << "   " << arr[i][j] << "   |";
			sleep_for(milliseconds(20));
		}
		cout << "\n";
		sleep_for(milliseconds(20));
		PrintLine02(a);
		sleep_for(milliseconds(20));
		PrintLine01(a);
	}
}
//Set bang thanh ' '
void ResetBoard(char arr[][100], int a) {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			arr[i][j] = ' ';
}
//Check Move
bool CheckMoveValid(char arr[][100], int Row, int  Col, int Size) {
	if (Row > Size || Col > Size || arr[Row - 1][Col - 1] != ' ') return false;
	else return true;
}

//Check Winner "Ngang"
bool CheckWinnerNgang(char arr[][100], char Name, int len) {
	int dem;
	for (int i = 0; i < len; i++) {
		dem = 0;
		for (int j = 0; j < len; j++)
			if (arr[i][j] == Name) {
				dem++;
				if (dem == len) {
					return true;
					exit;
				}
			}
	}
	return false;
}
//Check Winner "Doc"
bool CheckWinnerDoc(char arr[][100], char Name, int len) {
	int dem;
	for (int i = 0; i < len; i++) {
		dem = 0;
		for (int j = 0; j < len; j++)
			if (arr[j][i] == Name) {
				dem++;
				if (dem == len) {
					return true;
					exit;
				}
			}
	}
	return false;
}
//Check Winner "Cheo chinh"
bool CheckWinnerCheoChinh(char arr[][100], char Name, int len) {
	for (int i = 0; i < len; i++)
		if (arr[i][i] != Name) {
			return false;
			exit;
		}
	return true;
}
//Check Winner "Cheo phu"
bool CheckWinnerCheoPhu(char arr[][100], char Name, int len) {
	for (int i = 0; i < len; i++)
		if (arr[i][len - 1 - i] != Name) {
			return false;
			exit;
		}
	return true;
}
//Check Winner 
bool CheckWinner(char arr[][100], char Name, int len) {
	if (CheckWinnerNgang(arr, Name, len) == false && CheckWinnerDoc(arr, Name, len) == false && CheckWinnerCheoChinh(arr, Name, len) == false && CheckWinnerCheoPhu(arr, Name, len) == false)
		return false;
	else return true;
}
//Check Draw
bool CheckDraw(char arr[][100], int Size) {
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			if (arr[i][j] == ' ') {
				return false;
				exit;
			}
	return true;
}
struct PlayerInfo {
	char PlayerName[50];
	char PlayerSymbol;
};

int main() {
	char Board[100][100];
	int Size = 0, WinLength = 0;
	int Row, Col;
	int dem;
	char Winner = ' ';
	char Continue = 'N';
	PlayerInfo Player01, Player02;
	int Color;
	int PlayType;
	srand(time(NULL));
	do {
		PlaySound(TEXT("01_-_Final_Fantasy_-_NES_-_The_Prelude.wav"), NULL, SND_ASYNC | SND_LOOP);
		cout << "*****CHAO MUNG DEN VOI GAME CO CARO*****\n";
		cout << "Luat choi:\n";
		cout << "Nguoi choi thang khi tao thanh duong co do dai bang canh cua ban co!\n";
		cout << "Hoa neu ban co da kin va khong con cho de choi tiep!\n";
		cout << "Chon mau cho ban co: \n";
		cout << "1. Mau trang tren nen xanh.\n";
		cout << "2. Mau luc tren nen den.\n";
		cout << "3. Mau trang tren nen tim.\n";
		cout << "4. Mau trang tren nen den.\n";
		cout << "Mau ban chon la: ";
		do {
			cin >> Color;
			if (Color != 1 && Color != 2 && Color != 3 && Color != 4) cout << "Nhap sai! Vui long nhap lai.\n" << "Mau ban chon la: ";
		} while (Color != 1 && Color != 2 && Color != 3 && Color != 4);
		if (Color == 1) system("color 1F");
		else if (Color == 2) system("color 02");
		else if (Color == 3) system("color 5F");
		else if (Color == 4) system("color 07");
		system("pause");
		PlaySound(NULL, 0, 0);
		system("cls");
		PlaySound(TEXT("08_-_Final_Fantasy_-_NES_-_Menu_Screen.wav"), NULL, SND_ASYNC | SND_LOOP);
		cout << "*****GAME SETTINGS*****\n";
		cout << "Nhap vao kich co ban co: "; cin >> Size;
		WinLength = Size;
		cout << "Che do choi:\n";
		cout << "1. PVE.\n";
		cout << "2. PVP.\n";
		cout << "Nhap vao che do choi: ";
		do {
			cin >> PlayType;
			if (PlayType != 1 && PlayType != 2) cout << "Nhap sai! Vui long nhap lai.\n" << "Che do choi ban chon la: ";
		} while (PlayType != 1 && PlayType != 2);
		if (PlayType == 1) {
			cin.ignore(256, '\n');
			cout << "Nhap vao ten cua ban: "; cin.getline(Player01.PlayerName, 50);
			cout << "Nhap vao ki hieu choi cua ban(1 ki tu) va khac ki tu cua may(O): ";
			do {
				cin >> Player01.PlayerSymbol;
				if (Player01.PlayerSymbol == 'O') cout << "Ki hieu cua ban trung voi ki hieu cua may! Vui long nhap lai.\n" << "Ki hieu cua ban la: ";
			} while (Player01.PlayerSymbol == 'O');
			Player02.PlayerSymbol = 'O';
			ResetBoard(Board, Size);
			PrintBoard(Board, Size);
			system("pause");
			PlaySound(NULL, 0, 0);
			system("cls");
			PlaySound(TEXT("09_-_Final_Fantasy_-_NES_-_Chaos_Temple.wav"), NULL, SND_ASYNC | SND_LOOP);
			PrintBoard(Board, Size);
			dem = 0;
			do {
				do {
					if (dem % 2 == 0) {
						do {
							Row = rand() % Size + 1;
							Col = rand() % Size + 1;
						} while (CheckMoveValid(Board, Row, Col, Size) == false);
						cout << "Goi y di: " << Row << " " << Col << ".\n";
						cout << "Nhap vao vi tri cua ban (Hang, Cot): ";
						cin >> Row >> Col;
					}
					else do {
						Row = rand() % Size + 1;
						Col = rand() % Size + 1;
					} while (CheckMoveValid(Board, Row, Col, Size) == false);
					if (CheckMoveValid(Board, Row, Col, Size) == false) cout << "Vi tri khong hop le! Nhap lai vi tri.\n";
				} while (CheckMoveValid(Board, Row, Col, Size) == false);
				Row--; Col--;
				if (dem % 2 == 0) Board[Row][Col] = Player01.PlayerSymbol;
				else Board[Row][Col] = Player02.PlayerSymbol;
				system("cls");
				PrintBoard(Board, Size);
				dem++;
				if (CheckWinner(Board, Player01.PlayerSymbol, WinLength) == true) Winner = Player01.PlayerSymbol;
				else if (CheckWinner(Board, Player02.PlayerSymbol, WinLength) == true) Winner = Player02.PlayerSymbol;
			} while (Winner == ' ' && CheckDraw(Board, Size) == false);
			PlaySound(NULL, 0, 0);
			if (Winner == Player01.PlayerSymbol) {
				cout << Player01.PlayerName << " da chien thang! May thua.\n";
				PlaySound(TEXT("07_-_Final_Fantasy_-_NES_-_Victory!.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
			else if (Winner == Player02.PlayerSymbol) {
				cout << Player01.PlayerName << " da thua! May thang.\n";
				PlaySound(TEXT("18_-_Final_Fantasy_-_NES_-_Dead_Music.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
			else if (CheckDraw(Board, Size) == true) {
				cout << Player01.PlayerName << " va may da hoa!\n";
				PlaySound(TEXT("18_-_Final_Fantasy_-_NES_-_Dead_Music.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
			cout << "Tong so lan ban va may da choi la: " << dem << " lan.\n";
			cout << "So lan ban da choi la: " << dem - (dem / 2) << " lan.\n";
			cout << "So lan may da choi la: " << dem / 2 << " lan.\n";
			system("pause");
			PlaySound(NULL, 0, 0);
		}
		else {
			cin.ignore(256, '\n');
			cout << "Nhap vao ten nguoi choi thu nhat: "; cin.getline(Player01.PlayerName, 50);
			cout << "Nhap vao ki hieu cua " << Player01.PlayerName << " (1 ki tu) : "; cin >> Player01.PlayerSymbol;
			cin.ignore(256, '\n');
			cout << "Nhap vao ten nguoi choi thu hai: "; cin.getline(Player02.PlayerName, 50);
			cout << "Nhap vao ki hieu cua " << Player02.PlayerName << " (1 ki tu) : ";
			do {
				cin >> Player02.PlayerSymbol;
				if (Player02.PlayerSymbol == Player01.PlayerSymbol) {
					cout << "Ki hieu cua " << Player02.PlayerName << " trung voi ki hieu cua " << Player01.PlayerName << ". Vui long nhap lai!\n";
					cout << "Nhap vao ki hieu cua " << Player02.PlayerName << ": ";
				}
			} while (Player02.PlayerSymbol == Player01.PlayerSymbol);
			ResetBoard(Board, Size);
			PrintBoard(Board, Size);
			system("pause");
			PlaySound(NULL, 0, 0);
			system("cls");
			PrintBoard(Board, Size);
			dem = 0;
			PlaySound(TEXT("09_-_Final_Fantasy_-_NES_-_Chaos_Temple.wav"), NULL, SND_ASYNC | SND_LOOP);
			do {
				do {
					if (dem % 2 == 0) cout << "Nhap vao vi tri cua " << Player01.PlayerName << " (Hang, Cot) : ";
					else cout << "Nhap vao vi tri cua " << Player02.PlayerName << " (Hang, Cot) : ";
					cin >> Row >> Col;
					if (CheckMoveValid(Board, Row, Col, Size) == false) cout << "Vi tri khong hop le! Nhap lai vi tri.\n";
				} while (CheckMoveValid(Board, Row, Col, Size) == false);
				Row--; Col--;
				if (dem % 2 == 0) Board[Row][Col] = Player01.PlayerSymbol;
				else Board[Row][Col] = Player02.PlayerSymbol;
				system("cls");
				PrintBoard(Board, Size);
				dem++;
				if (CheckWinner(Board, Player01.PlayerSymbol, WinLength) == true) Winner = Player01.PlayerSymbol;
				else if (CheckWinner(Board, Player02.PlayerSymbol, WinLength) == true) Winner = Player02.PlayerSymbol;
			} while (Winner == ' ' && CheckDraw(Board, Size) == false);
			PlaySound(NULL, 0, 0);
			PlaySound(TEXT("07_-_Final_Fantasy_-_NES_-_Victory!.wav"), NULL, SND_ASYNC | SND_LOOP);
			if (Winner == Player01.PlayerSymbol) cout << "Nguoi choi thu nhat thang!\n";
			else if (Winner == Player02.PlayerSymbol) cout << "Nguoi choi thu hai thang\n";
			else if (CheckDraw(Board, Size) == true) cout << "Hoa!\n";
			cout << "Tong so lan hai nguoi da choi la: " << dem << " lan.\n";
			cout << "So lan " << Player01.PlayerName << " da choi la : " << dem - (dem / 2) << " lan.\n";
			cout << "So lan " << Player02.PlayerName << " da choi la : " << dem / 2 << " lan.\n";
		}
		Continue = 'N'; Winner = ' ';
		do {
			cout << "Tiep tuc choi(Y/N): "; cin >> Continue;
			if (Continue != 'Y' && Continue != 'N') cout << "Nhap sai!\n";
		} while (Continue != 'Y' && Continue != 'N');
		PlaySound(NULL, 0, 0);
		system("cls");
		system("color 07");
	} while (Continue == 'Y');
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
