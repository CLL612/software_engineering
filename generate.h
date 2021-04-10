#pragma once
#include "common.h"

struct game {
	int shudu[9][9];
	int level;
	int r;
};
void play_game(int);

void generate_terminal(int n);
void solve_shudu_fromfile(char file[]);
void generate_x_game(const char [],int n,int m=1,int r=45,int u=0);
void generate_unique_game(int n);
void generate_x_mode_game(int n,int m);
void generate_x_r_game(int n, int r);

