#include "test.h"

void test_shudu() {
	//int shudu[9][9] = {
	//	{1, 0 ,0 ,0 ,0, 0, 0, 8, 5},
	//	{2, 4, 0, 0, 0, 8, 6, 0, 9},
	//	{0, 0, 9, 2, 5, 0, 0, 3, 0},
	//	{0, 1, 0, 0, 6, 0, 7, 0, 8},
	//	{4, 5, 6, 0, 8, 0, 3, 1, 2},
	//	{7, 0, 8, 0, 1, 2, 0, 5, 6},
	//	{5, 0, 1, 8, 4, 0, 0, 0, 0},
	//	{0, 6, 4, 9, 0, 1, 0, 0, 3},
	//	{9, 0, 0, 0, 0, 0, 8, 4, 1},
	//};
	//fill_xy(0, 0, shudu);
	//print_to_file(shudu);
	//bool right = true;
	//right = is_right_terminal(shudu);
	//cout << right << endl;
	//print_to_file(shudu);
	generate_terminal(20);
	generate_x_game("game.txt",10);
	solve_shudu_fromfile((char*)"game.txt");
	
	generate_unique_game(1);
	generate_x_mode_game(3, 2);
	generate_x_r_game(3, 25);
}

bool is_different(int shudu[9][9], int x, int y) {
	if (shudu[x][y] == 0)
		return false;
	for (int i = 0; i < 9; i++)
		if (i != y && shudu[x][i] == shudu[x][y])
			return false;
	for (int i = 0; i < 9; i++)
		if (i != x && shudu[i][y] == shudu[x][y])
			return false;
	switch (x % 3) {
	case 0: {
		switch (y % 3) {
		case 0: {
			if (shudu[x + 1][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 1][y + 2] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 2][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 2][y + 2] == shudu[x][y]) {
				return false;
			}
			break;
		}
		case 1: {
			if (shudu[x + 1][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 1][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 2][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 2][y + 1] == shudu[x][y]) {
				return false;
			}
			break;
		}
		case 2: {
			if (shudu[x + 1][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 1][y - 2] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 2][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 2][y - 2] == shudu[x][y]) {
				return false;
			}
			break;
		}
		}
		break;
	}
	case 1: {
		switch (y % 3) {
		case 0: {
			if (shudu[x + 1][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 1][y + 2] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 1][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 1][y + 2] == shudu[x][y]) {
				return false;
			}
			break;
		}
		case 1: {
			if (shudu[x - 1][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 1][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 1][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 1][y - 1] == shudu[x][y]) {
				return false;
			}
			break;
		}
		case 2: {
			if (shudu[x + 1][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x + 1][y - 2] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 1][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 1][y - 2] == shudu[x][y]) {
				return false;
			}
			break;
		}
		}
		break;
	}
	case 2: {
		switch (y % 3) {
		case 0: {
			if (shudu[x - 1][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 1][y + 2] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 2][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 2][y + 2] == shudu[x][y]) {
				return false;
			}

			break;
		}
		case 1: {
			if (shudu[x - 1][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 1][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 2][y + 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 2][y - 1] == shudu[x][y]) {
				return false;
			}
			break;
		}
		case 2: {
			if (shudu[x - 1][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 1][y - 2] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 2][y - 1] == shudu[x][y]) {
				return false;
			}
			if (shudu[x - 2][y - 2] == shudu[x][y]) {
				return false;
			}
			break;
		}
		}
		break;
	}
	}
	return true;
}
bool is_right_terminal(int terminal[9][9],int r) {
	//bool flag = true;
	if(r!=0){
		int all_r = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (terminal[i][j] < 0 || terminal[i][j]>9)return false;
				if (terminal[i][j] == 0)
					all_r += 1;
			}	
		}
		if (all_r < r)
			return false;
		else
			return true;
	}
	else {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (terminal[i][j] < 0 || terminal[i][j]>9)return false;
				if (!is_different(terminal, i, j)) {
					return false;
				}
			}
		}
		return true;
	}
}
void print_to_file(int shudu[9][9]) {
	ofstream test;
	test.open("C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\ALL_PROJECT\\test.txt", ios::app);
	test<<"---------------------------------------"<<endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			test << shudu[i][j] << " ";
		}
		test << endl;
	}
	test.close();
}
