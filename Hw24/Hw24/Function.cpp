#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

char **Add(char **string, int &length);
char **Remove(char **string, int &length, int num);
int cmp(char *str1, char *str2);
void Sort(char **string, int &length);
char **Search(char **string, int length, int &counter2);
char **Change(char **string, int length, int index);
char **increaseStr(char **string, int &length);

void Function(char **string, int &length)
{
	int count1 = 0, count2 = 0, key, save_key = 0, counter = 0;
	char **search;
	short s_x = 1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true)
	{
		short x = 1;
		system("cls");
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 101; j++)
			{
				if (i % 2 == 0 && j > 0 && j < 30 || i == 0 && j > 55 && j < 100 || i == 4 && j > 55 && j < 100)
					cout << char(205);
				else if (j == 0 && i > 0 && i < 20|| j == 30 && i > 0 && i < 20 || j == 55 && i > 0  && i < 4 || j == 100 && i > 0 && i < 4)
					cout << char(186);
				else if (i == 0 && j == 0 || i == 0 && j == 55)
					cout << char(201);
				else if (i == 0 && j == 30 || i == 0 && j == 100)
					cout << char(187);
				else if (i == 20 && j == 0 || i == 4 && j == 55)
					cout << char(200);
				else if (i == 20 && j == 30 || i == 4 && j == 100)
					cout << char(188);
				else
					cout << " ";
			}
			cout << endl;
		}
		SetConsoleCursorPosition(h, { 56, 1 });
		cout << " a - add, r - remove, f - find, c - change\n";
		SetConsoleCursorPosition(h, { 56, 2 });
		cout << " \t\tEsc - exit";
		for (int i = 0 + count1; i < length; i++)
		{
			SetConsoleCursorPosition(h, { 1, x });
			if (i < 10 + count1 && save_key != 102)
			{
				cout << string[i] << endl;
				x += 2;
			}
			if (i < 10 + count1 && (save_key == 'f' || save_key == 'F') && i < counter)
			{
				cout << search[i] << endl;
				x += 2;
			}
		}
		SetConsoleCursorPosition(h, { 1, s_x });
		if (kbhit)
			key = getch();
		Sleep(77);
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
		if (key == 'f' && length > 0)
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			search = Search(string, length, counter);
			save_key = key;
		}
		if (key == 's' &&  length > count2 + 1 && s_x < 19)
		{
			s_x += 2;
			count2++;
		}
		if (key == 'c' && save_key != 'f')
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			string = Change(string, length, count2);
		}
		if (key == 27)
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			if (save_key == 'f')
			{
				delete[]search;
				save_key = 0;
			}
			else
				return;
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
	int i, j, num1 = 0;
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

char **Search(char **string, int length, int &counter2)
{
	int counter1 = 0, index = 0;
	counter2 = 0;
	char *search = new char[255];
	char **searchStr = new char*[counter2];
	cout << "Search: ";
	cin.getline(search, 255);
	while (search[index] != '\0')
		index++;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 255; j++)
		{
			if (string[i][j] == search[counter1])
				counter1++;
			else if (counter1 < index)
			{
				counter1 = 0;
				break;
			}
			if (counter1 == index)
			{
				searchStr = increaseStr(searchStr, counter2);
				searchStr[counter2 - 1] = string[i];
				break;
			}
		}
		counter1 = 0;
	}
	return searchStr;
}

char **Change(char **string, int length, int index)
{
	delete[]string[index];
	string[index] = new char[255];
	cout << "Enter name and last name\n";
	cin.getline(string[index], 255);
	Sort(string, length);
	return string;
}

char **increaseStr(char **string, int &length)
{
	char **tempStr = new char*[length + 1];
	for (int i = 0; i < length; i++)
		tempStr[i] = string[i];
	length++;
	delete[] string;
	return tempStr;
}
