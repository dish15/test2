#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define ENTER 13
using namespace std;

const int size1 = 10;
string menuarr[size1] = {
	"Створити репозиторій",
	"Додати до репозиторія",
	"Перейти в іншу гілку",
	"Статус",
	"Створення нової гілки",
	"commit",
	"push",
	"pull",
	"Вивести всі гілки",
	"Злиття"
};

void menuout(int index) {
	for (int c = 0; c < size1; c++) {
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
	system("git add git.cpp");
begin:
	char add[50] = "git add ";
	char branch[50] = "git checkout ";
	char newbranch[50] = "git branch  ";
	char init[] = "git init";
	char status[] = "git status";
	char buffin[50];
	char commit[] = "git commit -m ";
	char push[50] = "git push j ";
	char merge[50] = "git merge ";
	char buff[50];
	system("cls");
	menuout(0);
	int c = 0;
	for (c = 0;;) {
		int a = _getch();
		if (a == UP) {
			if (c == 0)c = size1-1;
			else c--;
			//cout << c << "\n";
			system("cls");
			menuout(c);

		}
		if (a == DOWN) {
			if (c == size1-1)c = 0;
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
		cout << "Введіть назву commit:\n";
		cin >> buffin;
		strcpy_s(buff, commit);
		strcat_s(buff, buffin);
		system(buff);
		break;
	case 6:
		cout << "Введіть назву гілки:\n";
		cin >> buffin;
		strcpy_s(buff, push);
		strcat_s(buff, buffin);
		system(buff);
		break;
	case 7:
		break;
	case 8:
		system("git branch -a");
		break;
	case 9:
		cout << "Введіть назву гілки:\n";
		cin >> buffin;
		strcpy_s(buff, merge);
		strcat_s(buff, buffin);
		system(buff);
		break;
	}

	system("pause");
	goto begin;
}
