#include "generate.h"
#include<assert.h>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<conio.h>
using namespace std;
int fill_XY(int x,int y,int shudu[9][9]) {
#ifdef DEBUG
	cout<<"----------------------"<<endl;
	printf("X:%d,Y:%d\n",x,y);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << shudu[i][j] << " ";
		}
		cout << endl;
	}
#endif
	int mark[9] = { 0,0,0,0,0,0,0,0,0 };
	srand((unsigned)time(NULL));
	if (x == 0) {
		for (int i = 0; i < y; i++) 
			mark[shudu[0][i]-1] = 1;
#ifdef DEBUG
		for (int i = 0; i < 9; i++)
			cout << mark[i] << " ";
		cout << endl;
#endif
		int length = 0;
		int left[9] = { 0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 9; i++) {
			if (mark[i] == 0) {
				left[length++] = i + 1;
			}
		}
		int choice = rand() % length;
		shudu[0][y] = left[choice];
#ifdef DEBUG
		cout << shudu[0][y] << endl;
#endif
		if (y<8) {
			return fill_XY(0, y + 1, shudu);
		}
		else {
			return  fill_XY(1,0,shudu);
		}
	}
	else {
		for (int i = 0; i < y; i++) 
			mark[shudu[x][i] - 1] = 1;
		for (int i = 0; i < x; i++)
			mark[shudu[i][y] - 1] = 1;
		switch (x % 3) {
		case 0: {
			switch (y % 3) {
			case 0: {
				break;
			}
			case 1: {
				break;
			}
			case 2: {
				break;
			}
			}
			break;
		}
		case 1: {
			switch (y % 3) {
			case 0: {
				mark[shudu[x - 1][y + 1]-1]=1;
				mark[shudu[x - 1][y + 2]-1]=1;
				break;
			}
			case 1: {
				mark[shudu[x - 1][y - 1] - 1] = 1;
				mark[shudu[x - 1][y + 1] - 1] = 1;
				break;
			}
			case 2: {
				mark[shudu[x - 1][y - 1]-1]=1;
				mark[shudu[x - 1][y - 2]-1]=1;
				break;
			}
			}
			break;
		}
		case 2: {
			switch (y % 3) {
			case 0: {
				mark[shudu[x - 1][y + 1]-1]=1;
				mark[shudu[x - 1][y + 2]-1]=1;
					
				mark[shudu[x - 2][y + 1]-1]=1;
				mark[shudu[x - 2][y + 2]-1]=1;
				
				break;
			}
			case 1: {
				mark[shudu[x - 2][y - 1]-1]=1;
				mark[shudu[x - 1][y - 1]-1]=1;
					
				mark[shudu[x - 2][y + 1]-1]=1;
				mark[shudu[x - 1][y + 1]-1]=1;
				break;
			}
			case 2: {
				mark[shudu[x - 1][y - 1]-1]=1;
				mark[shudu[x - 1][y - 2]-1]=1;
				mark[shudu[x - 2][y - 1]-1]=1;
				mark[shudu[x - 2][y - 2]-1]=1;
				break;
			}
			}
			break;
		}
		}
		int length = 0;
		int left[9] = { 0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 9; i++) {
			if (mark[i] == 0) {
				left[length++] = i + 1;
			}
		}
		if (length == 0)
			return 0;

		for (int i = 0; i < length; i++) {
			shudu[x][y] = left[i];
			if (y!=8) {
				if (fill_XY(x, y + 1, shudu) == 1)
					return 1;
			}
			else if(x!=8){
				if (fill_XY(x+1,0, shudu) == 1)
					return 1;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
}
int fill_xy(int x, int y, int shudu[9][9]) {
//#ifdef DEBUG
//	cout << "----------------------" << endl;
//	printf("X:%d,Y:%d\n", x, y);
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			cout << shudu[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "----------------------" << endl;
//#endif
	if (shudu[x][y] != 0) {
		if (y != 8) {
			if (fill_xy(x, y + 1, shudu) == 1)
				return 1;
		}
		else if (x != 8) {
			if (fill_xy(x + 1, 0, shudu) == 1)
				return 1;
		}
		else {
			return 1;
		}
	}
	int mark[9] = { 0,0,0,0,0,0,0,0,0 };
	srand((unsigned)time(NULL));
	for (int i = 0; i < 9; i++)
		if(shudu[x][i]!=0)
			mark[shudu[x][i] - 1] = 1;
	for (int i = 0; i < 9; i++)
		if(shudu[i][y]!=0)
			mark[shudu[i][y] - 1] = 1;
	switch (x % 3) {
	case 0: {
		switch (y % 3) {
		case 0: {
			if (shudu[x + 1][y + 1]!=0) {
				mark[shudu[x+1][y+1] - 1] = 1;
			}
			if (shudu[x + 1][y + 2]!=0) {
				mark[shudu[x + 1][y+2] - 1] = 1;
			}
			if (shudu[x + 2][y + 1]!=0) {
				mark[shudu[x + 2][y+1] - 1] = 1;
			}
			if (shudu[x + 2][y + 2]!=0) {
				mark[shudu[x + 2][y+2] - 1] = 1;
			}
			break;
		}
		case 1: {
			if (shudu[x + 1][y + 1] != 0) {
				mark[shudu[x + 1][y+1] - 1] = 1;
			}
			if (shudu[x + 1][y -1] != 0) {
				mark[shudu[x + 1][y -1] - 1] = 1;
			}
			if (shudu[x + 2][y - 1] != 0) {
				mark[shudu[x + 2][y - 1] - 1] = 1;
			}
			if (shudu[x + 2][y + 1] != 0) {
				mark[shudu[x + 2][y + 1] - 1] = 1;
			}
			break;
		}
		case 2: {
			if (shudu[x + 1][y - 1] != 0) {
				mark[shudu[x + 1][y-1] - 1] = 1;
			}
			if (shudu[x + 1][y - 2] != 0) {
				mark[shudu[x + 1][y - 2] - 1] = 1;
			}
			if (shudu[x + 2][y - 1] != 0) {
				mark[shudu[x + 2][y - 1] - 1] = 1;
			}
			if (shudu[x + 2][y - 2] != 0) {
				mark[shudu[x + 2][y - 2] - 1] = 1;
			}
			break;
		}
		}
		break;
	}
	case 1: {
		switch (y % 3) {
		case 0: {
			if (shudu[x + 1][y + 1] != 0) {
				mark[shudu[x + 1][y+1] - 1] = 1;
			}
			if (shudu[x + 1][y + 2] != 0) {
				mark[shudu[x + 1][y + 2] - 1] = 1;
			}
			if (shudu[x - 1][y + 1] != 0) {
				mark[shudu[x - 1][y + 1] - 1] = 1;
			}
			if (shudu[x - 1][y + 2] != 0) {
				mark[shudu[x - 1][y + 2] - 1] = 1;
			}
			break;
		}
		case 1: {
			if (shudu[x - 1][y - 1] != 0) {
				mark[shudu[x + 1][y - 1] - 1] = 1;
			}
			if (shudu[x - 1][y + 1] != 0) {
				mark[shudu[x + 1][y + 1] - 1] = 1;
			}
			if (shudu[x + 1][y + 1] != 0) {
				mark[shudu[x + 1][y + 1] - 1] = 1;
			}
			if (shudu[x + 1][y - 1] != 0) {
				mark[shudu[x + 1][y - 1] - 1] = 1;
			}
			break;
		}
		case 2: {
			if (shudu[x + 1][y - 1] != 0) {
				mark[shudu[x + 1][y-1] - 1] = 1;
			}
			if (shudu[x + 1][y - 2] != 0) {
				mark[shudu[x + 1][y - 2] - 1] = 1;
			}
			if (shudu[x - 1][y - 1] != 0) {
				mark[shudu[x - 1][y - 1] - 1] = 1;
			}
			if (shudu[x - 1][y - 2] != 0) {
				mark[shudu[x - 1][y - 2] - 1] = 1;
			}
			break;
		}
		}
		break;
	}
	case 2: {
		switch (y % 3) {
		case 0: {
			if (shudu[x - 1][y + 1] != 0) {
				mark[shudu[x - 1][y] - 1] = 1;
			}
			if (shudu[x - 1][y + 2] != 0) {
				mark[shudu[x - 1][y + 2] - 1] = 1;
			}
			if (shudu[x - 2][y + 1] != 0) {
				mark[shudu[x - 2][y + 1] - 1] = 1;
			}
			if (shudu[x - 2][y + 2] != 0) {
				mark[shudu[x - 2][y + 2] - 1] = 1;
			}

			break;
		}
		case 1: {
			if (shudu[x - 1][y + 1] != 0) {
				mark[shudu[x - 1][y + 1] - 1] = 1;
			}
			if (shudu[x - 1][y - 1] != 0) {
				mark[shudu[x - 1][y - 1] - 1] = 1;
			}
			if (shudu[x - 2][y + 1] != 0) {
				mark[shudu[x - 2][y + 1] - 1] = 1;
			}
			if (shudu[x - 2][y - 1] != 0) {
				mark[shudu[x - 2][y - 1] - 1] = 1;
			}
			break;
		}
		case 2: {
			if (shudu[x - 1][y - 1] != 0) {
				mark[shudu[x - 1][y - 1] - 1] = 1;
			}
			if (shudu[x - 1][y - 2] != 0) {
				mark[shudu[x - 1][y - 2] - 1] = 1;
			}
			if (shudu[x - 2][y - 1] != 0) {
				mark[shudu[x - 2][y - 1] - 1] = 1;
			}
			if (shudu[x - 2][y - 2] != 0) {
				mark[shudu[x - 2][y - 2] - 1] = 1;
			}
			break;
		}
		}
		break;
	}
	}
	int length = 0;
	int left[9] = { 0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 9; i++) {
		if (mark[i] == 0) {
			left[length++] = i + 1;
		}
	}
	if (length == 0)
		return 0;
	int rate = rand() % 2;
	if (rate) {
		int temp = left[length - 1];
		left[length - 1] = temp;
		left[0] = temp;
	}
	for (int i = 0; i < length; i++) {
		shudu[x][y] = left[i];
		if (y != 8) {
			if (fill_xy(x, y + 1, shudu) == 1)
				return 1;
		}
		else if (x != 8) {
			if (fill_xy(x + 1, 0, shudu) == 1)
				return 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}
void generate_terminal(int n) {
#ifdef DEBUG
	cout<<"生成终端文件"<<endl;
#endif
	assert(n>0&&n<=100000);
	int shudu[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			shudu[i][j] = 0;
		}
	}
	fstream file;
	file.open("shudu.txt",ios::app);
	for (int k = 0; k < n; k++) {
		if(fill_XY(0, 0, shudu))
			cout<<"无解"<<endl;
#ifdef DEBUG
		cout << "最终生成的数独终盘:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << shudu[i][j] << " ";
			}
			cout << endl;
		}
#endif
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				file << shudu[i][j] << " ";
			}
			file << endl;
		}
		file << endl;
	}
	file.close();

}
void solve_shudu_fromfile(char file_name[]) {
	fstream file;
	int shudu[9][9];
	file.open(file_name);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			file>>shudu[i][j];
		}
	}
	cout << "待解数独:" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << shudu[i][j] << " ";
		}
		cout << endl;
	}
	fill_xy(0, 0, shudu);
	//cout << file_name << endl;
	cout << "数独终盘:" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << shudu[i][j] << " ";
		}
		cout << endl;
	}
	file.close();
	fstream file_out;
	file_out.open("shuduku.txt",ios::app);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			file_out << shudu[i][j] << " ";
		}
		file_out << endl;
	}
	file_out.close();
}
void print(int shudu[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << shudu[i][j] << " ";
		}
		cout << endl;
	}
}
bool unique(int shudu[9][9]) {
	int temp[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			temp[i][j] = shudu[i][j];
		}
	}
	fill_xy(0, 0, temp);
	int temp1[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			temp1[i][j] = shudu[i][j];
		}
	}
	fill_xy(0, 0, temp1);
	int temp2[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			temp2[i][j] = shudu[i][j];
		}
	}
	fill_xy(0, 0, temp2);
#ifdef DEBUG
	cout <<"-------------" << endl;
	print(shudu);
	cout << "-------------" << endl;
	print(temp);
	cout << "-------------" << endl;
	print(temp1);
	cout << "-------------" << endl;
	print(temp2);
#endif // DEBUG
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (temp[i][j] != temp1[i][j])
				return false;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (temp[i][j] != temp2[i][j])
				return false;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (temp1[i][j] != temp2[i][j])
				return false;
		}
	}
}
void set_zero(int shudu[9][9],int r,int m) {
	srand((unsigned)time(NULL));
	int x;
	int y;
	switch (m) {
	case 1:
		for (int i = 0; i < r; i++) {
			x = rand() % 9;
			y = rand() % 9;
			shudu[x][y] = 0;
		}
		break;
	case 2:
		for (int i = 0; i < r; i+=3) {
			x = rand() % 3;
			y = rand() % 9;
			shudu[x][y] = 0;
			x = rand() % 3+3;
			y = rand() % 9;
			shudu[x][y] = 0;
			x = rand() % 3+6;
			y = rand() % 9;
			shudu[x][y] = 0;
		}
		break;
	case 3:
		for (int i = 0; i < r; i+=9) {
			x = rand() % 3;
			y = rand() % 3;
			shudu[x][y] = 0;

			x = rand() % 3;
			y = rand() % 3+3;
			shudu[x][y] = 0;

			x = rand() % 3;
			y = rand() % 3+6;
			shudu[x][y] = 0;

			x = rand() % 3 + 3;
			y = rand() % 3;
			shudu[x][y] = 0;

			x = rand() % 3 + 3;
			y = rand() % 3+3;
			shudu[x][y] = 0;

			x = rand() % 3 + 3;
			y = rand() % 3+6;
			shudu[x][y] = 0;

			x = rand() % 3 + 6;
			y = rand() % 3;
			shudu[x][y] = 0;

			x = rand() % 3 + 6;
			y = rand() % 3+3;
			shudu[x][y] = 0;

			x = rand() % 3 + 6;
			y = rand() % 3+6;
			shudu[x][y] = 0;
		}
		break;
	}
}
void generate_x_game(const char file_name[],int n, int m, int r, int u) {
	assert(n > 0&&n<=10000);
	struct game origin[10];
	fstream file;
	file.open("shudu.txt");
	srand((unsigned)time(NULL));
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				file >> origin[k].shudu[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int option = rand() % 10;
		int shudu[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				shudu[i][j] = origin[option].shudu[i][j];
			}
		}
		set_zero(shudu,r,m);
		if (u != 0)
			while (true) {
				if (unique(shudu))
					break;
				for (int i = 0; i < r; i++) {
					int x = rand() % 9;
					int y = rand() % 9;
					set_zero(shudu, r,m);
				}
			}
		fstream file_game;
		file_game.open(file_name,ios::app);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				file_game << shudu[i][j] << " ";
			}
			file_game << endl;
		}
		file_game << endl;
		file_game.close();

	}
	file.close();
}
void generate_unique_game(int n) {
	assert(n > 0 && n <= 10000);
	generate_x_game("u_game.txt",n, 1, 25, 1);
}
void generate_x_mode_game(int n, int m) {
	assert(n > 0 && n <= 10000);
	assert(m=1||m==2||m==3);
	generate_x_game("m_game.txt",m);
}
void generate_x_r_game(int n, int r) {
	assert(n > 0 && n <= 10000);
	assert(r>=20&&r<=55);
	generate_x_game("r_game.txt",n,1,r);
}
void picture(int x, int y, int shudu[9][9]) {
	cout << "tips:'*'是当前位置" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == x && j == y)
				cout << "*" << " ";
			else if (shudu[i][j] == 0)
				cout << "$" << " ";
			else
				cout << shudu[i][j] << " ";
		}
		cout << endl;
	}
}
void play_game(int mode) {
	fstream file;
	if(mode==1)
		file.open("game.txt");
	else if(mode==2){
		file.open("r_game.txt");
	}
	else if (mode == 3) {
		file.open("u_game.txt");
	}
	else {
		file.open("m_game.txt");
	}
	int shudu[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			file >> shudu[i][j];
		}
	}
	file.close();
	int x = 4, y = 4;
	picture(4, 4, shudu);
	cout << "请通过WASD来控制移动和填数,Q退出" << endl;
	char choice = _getch();
	while (true) {
		char choice = _getch();
		if (choice == '\n')
			continue;
		if (choice == 'Q') {
			break;
		}
		if (choice == 'W') {
			x = x-1;
		}
		if (choice == 'A') {
			y = y - 1;
		}
		if (choice == 'S') {
			x = x + 1;
		}
		if (choice == 'D') {
			y = y + 1;
		}
		if (choice > '0' && choice <= '9')
			shudu[x][y] = atoi(&choice);
		system("cls");
		picture(x, y, shudu);
	}
}