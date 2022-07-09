#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define ENTER 13
using namespace std;

string menuarr[6] = {
	"Створити репозиторій",
	"Додати до репозиторія",
	"Перейти в іншу гілку",
	"Статус",
	"Створення нової гілки",
	"commit"
};

void menuout(int index) {
	for (int c = 0; c < 6; c++) {
		if (c == index) {
			cout << "\t" << menuarr[c] << "\n";
		}
		else {
			cout << menuarr[c] << "\n";
		}
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
begin:
	char add[50] = "git add ";
	char branch[50] = "git branch ";
	char newbranch[50] = "git checkout -b ";
	char init[] = "git init";
	char status[] = "git status";
	char buffin[50];
	char commit[] = "git commit";
	char buff[50];
	system("cls");
	menuout(0);
	int c = 0;
	for (c = 0;;) {
		int a = _getch();
		if (a == UP) {
			if (c == 0)c = 5;
			else c--;
			//cout << c << "\n";
			system("cls");
			menuout(c);

		}
		if (a == DOWN) {
			if (c == 5)c = 0;
			else c++;
			//cout << c << "\n";
			system("cls");
			menuout(c);

		}
		if (a == ENTER) {
			break;
		}
	}
	switch (c) {
	case 0:
		system(init);
		break;
	case 1:
		cout << "Що ви хочете додати?\n";
		cin >> buffin;
		strcpy_s(buff, add);
		strcat_s(buff, buffin);
		system(buff);
		break;

	case 2:
		cout << "Введіть назву гілки:\n";
		cin >> buffin;
		strcpy_s(buff, branch);
		strcat_s(buff, buffin);
		system(buff);
		break;
	case 3:
		system(status);
		break;
	case 4:
		cout << "Введіть назву гілки:\n";
		cin >> buffin;
		strcpy_s(buff, branch);
		strcat_s(buff, buffin);
		system(buff);
		break;
	case 5:
		system(commit);
		break;
	}
	system("pause");
	goto begin;
}
