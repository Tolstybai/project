#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <Windows.h>
using namespace std;

const int N = 3;

int main()
{
	setlocale(LC_ALL, "Russian");
	int x, y, k, dgt;
	char A[N][N], c, z;
	string s, a, b, name1, name2;
	a = "NOLIKI";
	b = "KRESTIKI";
	z = '0';
	c = 'X';
	cout << "IGRA KRESTIKI-NOLIKI:" << endl;
	cout << "Enter the name of first player : ";
	cin >> name1;
	cout << "Enter the name of second player: ";
	cin >> name2;
	cout << "Who do u choose?(choose the digit):" << endl;
	cout << "if u wnt 0 press 1" << endl;
	cout << "if u wnt x press 2" << endl;
	cout << "number: ";
	cin >> dgt;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = '?';
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 9; i++)
	{
		if ((!(i % 2)) && (dgt == 1)) s = a;
		if ((!(i % 2)) && (dgt == 2)) s = b;
		if ((i % 2) && (dgt == 1)) s = b;
		if ((i % 2) && (dgt == 2)) s = a;
	mylabel:
		cout << "Choose a cell (" << s << ")" << endl;
		cout << "x coordinate(line): ";
		cin >> x;
		cout << "y coordinate(column): ";
		cin >> y;
		x--;
		y--;
		if (A[x][y] != '?')
		{
			system("cls");
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cout << A[i][j] << " ";
				}
				cout << endl;
			}
			cout << "This cell is already occupied!" << endl;
			goto mylabel;
		}
		if ((!(i % 2)) && (dgt == 1)) A[x][y] = z;
		if ((!(i % 2)) && (dgt == 2)) A[x][y] = c;
		if ((i % 2) && (dgt == 1)) A[x][y] = c;
		if ((i % 2) && (dgt == 2)) A[x][y] = z;
		system("cls");
		k = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		if (((A[0][0] == '0') && (A[0][1] == '0') && (A[0][2] == '0')) ||
			((A[1][0] == '0') && (A[1][1] == '0') && (A[1][2] == '0')) ||
			((A[2][0] == '0') && (A[2][1] == '0') && (A[2][2] == '0')) ||
			((A[0][0] == '0') && (A[1][0] == '0') && (A[2][0] == '0')) ||
			((A[0][1] == '0') && (A[1][1] == '0') && (A[2][1] == '0')) ||
			((A[0][2] == '0') && (A[1][2] == '0') && (A[2][2] == '0')) ||
			((A[0][0] == '0') && (A[1][1] == '0') && (A[2][2] == '0')) ||
			((A[2][0] == '0') && (A[1][1] == '0') && (A[0][2] == '0')) ||
			((A[0][0] == 'X') && (A[0][1] == 'X') && (A[0][2] == 'X')) ||
			((A[1][0] == 'X') && (A[1][1] == 'X') && (A[1][2] == 'X')) ||
			((A[2][0] == 'X') && (A[2][1] == 'X') && (A[2][2] == 'X')) ||
			((A[0][0] == 'X') && (A[1][0] == 'X') && (A[2][0] == 'X')) ||
			((A[0][1] == 'X') && (A[1][1] == 'X') && (A[2][1] == 'X')) ||
			((A[0][2] == 'X') && (A[1][2] == 'X') && (A[2][2] == 'X')) ||
			((A[0][0] == 'X') && (A[1][1] == 'X') && (A[2][2] == 'X')) ||
			((A[2][0] == 'X') && (A[1][1] == 'X') && (A[0][2] == 'X')))
		{
			k++;
			cout << "Game over! ";
			if ((A[x][y] == z) && (dgt == 1)) cout << name1 << " won!" << endl;
			if ((A[x][y] == c) && (dgt == 2)) cout << name1 << " won!" << endl;
			if ((A[x][y] == c) && (dgt == 1)) cout << name2 << " won!" << endl;
			if ((A[x][y] == z) && (dgt == 2)) cout << name2 << " won!" << endl;
			break;
		}
	}
	if (!(k)) cout << "DRAW!" << endl;
	system("pause");
	return 0;
}