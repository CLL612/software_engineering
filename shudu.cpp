#include "common.h"
#include "generate.h"

void show_table() {
	cout << "--------数独---------" << endl;
	cout << "--难度1\n--难度2\n--难度3\n";
	cout<<"--从中选择你要选择的模式(输入q退出):";
}
void user_mode() {
	char option;
	cin >> option;
	switch (option) {
	case '1':
		play_game(1);
		return;
	case '2':
		play_game(2);
		return;
	case '3':
		play_game(3);
		return;
	case '4':
		play_game(4);
		return;
	case 'q':
		return;
	default:
		cout << "没有这样的选择,请重新选择." << endl;
		user_mode();
		return;
	}
}
bool ui_loop(int argc,char **argv) {
#ifdef DEBUG
	for (int i = 0; i < argc; i++)
		cout << argv[i]<<" ";
	cout<< endl;
#endif
	switch (argc) {
	case 1: {
		while (true) {
			show_table();
			user_mode();
			cout <<"是否继续(y/n)?>>>>";
			char is_ok;
			cin >> is_ok;
			if (is_ok != 'y') {
				break;
			}
		}
		return true;
	}
	case 2:
		return false;
	case 3:
		//shudu.exe -c (1-1000000)
		if (strcmp("-c", argv[1]) == 0) {
			generate_terminal(atoi(argv[2]));
			return true;
		}
		//shudu.exe -s file_path
		else if (strcmp("-s", argv[1]) == 0) {
			solve_shudu_fromfile(argv[2]);
			return true;
		}
		//shudu.exe -n (1-10000)
		else if (strcmp("-n", argv[1]) == 0) {
			generate_x_game("game.txt",atoi(argv[2]));
			return true;
		}
		else
			return false;
	case 4:
		//shudu.exe -n (1-10000) -u
		if (strcmp("-u", argv[3])==0&& strcmp("-n", argv[1])==0) {
			generate_unique_game(atoi(argv[2]));
			return true;
		}
		return false;
	case 5:
		//shudu.exe -n (1-10000) -m (1-3)
		if (strcmp("-m", argv[3]) == 0 && strcmp("-n", argv[1]) == 0) {
			generate_x_mode_game(atoi(argv[2]), atoi(argv[4]));
			return true;
		}
		//shudu.exe -n (1-10000) -r (20-55)
		if (strcmp("-r", argv[3]) == 0 && strcmp("-n", argv[1]) == 0) {
			generate_x_r_game(atoi(argv[2]), atoi(argv[4]));
			return true;
		}
		return false;
	default:
		return false;
	}
}