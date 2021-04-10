#include "pch.h"
#include "CppUnitTest.h"
#include "../ALL_PROJECT/generate.h"
#include "../ALL_PROJECT/common.h"
#include "../ALL_PROJECT/test.h"
#include<iostream>
#include<fstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace shuduUnitTest
{
	TEST_CLASS(shuduUnitTest)
	{
	public:
		TEST_METHOD(fill_xy_test)
		{
			int shudu[9][9] = {
				{1, 0 ,0 ,0 ,0, 0, 0, 8, 5},
				{2, 4, 0, 0, 0, 8, 6, 0, 9},
				{0, 0, 9, 2, 5, 0, 0, 3, 0},
				{0, 1, 0, 0, 6, 0, 7, 0, 8},
				{4, 5, 6, 0, 8, 0, 3, 1, 2},
				{7, 0, 8, 0, 1, 2, 0, 5, 6},
				{5, 0, 1, 8, 4, 0, 0, 0, 0},
				{0, 6, 4, 9, 0, 1, 0, 0, 3},
				{9, 0, 0, 0, 0, 0, 8, 4, 1},
			};
			fill_xy(0,0,shudu);
			print_to_file(shudu);
			bool right = true;
			right=is_right_terminal(shudu);
			Assert::AreEqual(right, true);
		}
		TEST_METHOD(terminal_generate)
		{
			generate_terminal(20);
			bool right = true;
			int shudu[9][9];
			fstream test;
			test.open("C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\ALL_PROJECT\\shudu.txt",ios::in);
			for (int k = 0; k < 20; k++) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						test >> shudu[i][j];
					}
				}
				print_to_file(shudu);
				right = is_right_terminal(shudu);
				Assert::AreEqual(right, true);
			}
			test.close();
		}
		TEST_METHOD(n_generate)
		{
			generate_x_game("C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\ALL_PROJECT\\game.txt", 10);
			bool right = true;
			int shudu[9][9];
			fstream test;
			test.open("C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\ALL_PROJECT\\game.txt");
			for (int k = 0; k < 10; k++) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						test >> shudu[i][j];
					}
				}
				fill_xy(0, 0, shudu);
				print_to_file(shudu);
				right = is_right_terminal(shudu);
				Assert::AreEqual(right, true);
			}
			test.close();
		}
		TEST_METHOD(u_generate)
		{
			generate_terminal(20);
			generate_unique_game(1);
			bool right = true;
			int shudu[9][9];
			fstream test;
			test.open("C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\ALL_PROJECT\\u_game.txt");
			for (int k = 0; k < 1; k++) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						test >> shudu[i][j];
					}
				}
				fill_xy(0, 0, shudu);
				print_to_file(shudu);
				right = is_right_terminal(shudu);
				Assert::AreEqual(right, true);
			}
			test.close();
		}
		TEST_METHOD(m_generate)
		{
			generate_x_mode_game(3, 2);
			bool right = true;
			int shudu[9][9];
			fstream test;
			test.open("C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\ALL_PROJECT\\m_game.txt");
			for (int k = 0; k < 3; k++) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						test >> shudu[i][j];
					}
				}
				fill_xy(0, 0, shudu);
				print_to_file(shudu);
				right = is_right_terminal(shudu);
				Assert::AreEqual(right, true);
			}
			test.close();
		}
		
		TEST_METHOD(r_generate)
		{
			generate_terminal(20);
			generate_x_r_game(3, 25);
			bool right = true;
			int shudu[9][9];
			fstream test;
			test.open("C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\ALL_PROJECT\\r_game.txt");
			for (int k = 0; k < 3; k++) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						test >> shudu[i][j];
					}
				}
				fill_xy(0, 0, shudu);
				print_to_file(shudu);
				right = is_right_terminal(shudu);
				Assert::AreEqual(right, true);
			}
			test.close();
		}
		TEST_METHOD(solve_from_file_generate)
		{
			char file_name[] = "C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\shuduUnitTest\\game.txt";
			solve_shudu_fromfile(file_name);
			bool right = true;
			int shudu[9][9];
			fstream test;
			test.open("C:\\Users\\CLL\\source\\repos\\ALL_PROJECT\\ALL_PROJECT\\shuduku.txt");
			for (int k = 0; k < 1; k++) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						test >> shudu[i][j];
					}
				}
				right = is_right_terminal(shudu);
				Assert::AreEqual(right, true);
			}
			test.close();
		}
	};
}
