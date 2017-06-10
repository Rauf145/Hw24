#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

char **Add(char **string, int &length);
char **Remove(char **string, int &length, int num);
int cmp(char *str1, char *str2);
void Sort(char **string, int &length);

void Function(char **string, int &length)
{
	int count1 = 0, count2 = 0, key;
	short s_x = 1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true)
	{
		short x = 1;
		system("cls");
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 31; j++)
			{
				if (i % 2 == 0 && j > 0 && j < 30)
					cout << char(205);
				else if (j == 0 && i > 0 && i < 20|| j == 30 && i > 0 && i < 20)
					cout << char(186);
				else if (i == 0 && j == 0)
					cout << char(201);
				else if (i == 0 && j == 30)
					cout << char(187);
				else if (i == 20 && j == 0)
					cout << char(200);
				else if (i == 20 && j == 30)
					cout << char(188);
				else
					cout << " ";
			}
			cout << endl;
		}
		for (int i = 0 + count1; i < length; i++)
		{
			SetConsoleCursorPosition(h, { 1, x });
			if (i < 10 + count1)
			{
				cout << string[i] << endl;
				x += 2;
			}
		}
		SetConsoleCursorPosition(h, { 1, s_x });
		key = getch();
		if (key == 'a' || key == 'A')
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			string = Add(string, length);
		}
		if (key == 'r' && length > 0 || key == 'R' && length > 0)
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			string = Remove(string, length, count2);
		}
		if (key == 's' &&  length > count2 + 1 && s_x < 19)
		{
			s_x += 2;
			count2++;
		}
		else if (count2 >= 9 && key == 's' && count2 + 1 < length)
		{
			count1++;
			count2++;
		}
		if (key == 'w' && s_x > 1)
		{
			s_x -= 2;
			count2--;
		}
		else if (count2 > 0 && key == 'w')
		{
			count2--;
			count1--;
		}
	}
}

char **Add(char **string, int &length)
{
	char **tempStr = new char*[length + 1];
	for (int i = 0; i < length; i++)
		tempStr[i] = string[i];
	tempStr[length] = new char[255];
	cout << "Enter Name and Last name\n";
	cin.getline (tempStr[length], 255);
	length++;
	delete[] string;
	Sort(tempStr, length);
	return tempStr;
}

char **Remove(char **string, int &length, int num)
{
	int count = 0;
	char **tempStr = new char*[length - 1];
	for (int i = 0; i < length; i++)
	{
		if (i != num)
		{
			tempStr[count] = string[i];
			count++;
		}
		else if (i == num)
			delete[]string[num];
	}
	length--;
	delete[]string;
	Sort(tempStr, length);
	return tempStr;
}

void Sort(char **string, int &length)
{
	long i, j;
	int num1 = 0;
	char *x;
	for (i = 0; i < length; i++)
	{
		for (j = length - 1; j > i; j--)
		{
			num1 = cmp(string[j - 1], string[j]);
			if (num1 > 0)
			{
				x = string[j - 1];
				string[j - 1] = string[j];
				string[j] = x;
			}
		}
	}
}

int cmp(char *str1, char *str2)
{
	int count = 0;
	for (int i = 0; i < 255; i++)
	{
		if (int(str1[i]) > int(str2[i]) && (int(str1[i]) > 64 && int(str1[i]) < 91) && (int(str2[i]) > 64 && int(str2[i]) < 91))
		{
			count = 1;
			break;
		}
		else if (int(str1[i]) > int(str2[i]) && (int(str1[i]) > 96 && int(str1[i]) < 123) && (int(str2[i]) > 96 && int(str2[i]) < 123))
		{
			count = 1;
			break;
		}
		else if (int(str1[i]) < int(str2[i]) && (int(str1[i]) > 64 && int(str1[i]) < 91) && (int(str2[i]) > 64 && int(str2[i]) < 91))
		{
			count = 0;
			break;
		}
		else if (int(str1[i]) < int(str2[i]) && (int(str1[i]) > 96 && int(str1[i]) < 123) && (int(str2[i]) > 96 && int(str2[i]) < 123))
		{
			count = 0;
			break;
		}
		else if (int(str1[i]) + 32 < int(str2[i]) && (int(str1[i]) > 64 && int(str1[i]) < 91) && (int(str2[i]) > 96 && int(str2[i]) < 123))
		{
			count = 0;
			break;
		}
		else if (int(str1[i]) + 32 > int(str2[i]) && (int(str1[i]) > 64 && int(str1[i]) < 91) && (int(str2[i]) > 96 && int(str2[i]) < 123))
		{
			count = 1;
			break;
		}
		else if (int(str1[i]) < int(str2[i]) + 32 && (int(str1[i]) > 96 && int(str1[i]) < 123) && (int(str2[i]) > 64 && int(str2[i]) < 91))
		{
			count = 0;
			break;
		}
		else if (int(str1[i]) > int(str2[i]) + 32 && (int(str1[i]) > 96 && int(str1[i]) < 123) && (int(str2[i]) > 64 && int(str2[i]) < 91))
		{
			count = 1;
			break;
		}
	}
	return count;
}
