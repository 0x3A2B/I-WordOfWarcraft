#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void print(int mode, int city_no, int elements, \
	int kinght_type_1, int commond_type_1, int kinght_no_1, int elements_1, int force_1, \
	int kinght_type_2, int commond_type_2, int kinght_no_2, int elements_2, int force_2);
//WYC Part Start

int tool_qf(int n) {
	if (n == 1) return 2;
	else return 1;
}

class knight {
public:
	int NO = 0, HEA = 0, type = 0, ATK = 0, step = 0, kill_n = 0, dead = 1;
	knight(int n, int t);
	int attack(int n, int RorB);
};

class city {
public:
	int NO = 0, HEA = 0, people = 0, flag = 0, red = 0, blue = 0;
	city(int n, int h) {
		NO = n;
		HEA = h;
	}
};

knight *knights[3][20] = { 0 };
city   *citys[22] = { 0 };
int city_n = 0, TIME = 0, time = 0;
int HEA_init[5] = { 0 }, ATK_init[5] = { 0 };

knight::knight(int n, int t) {
	NO = n;
	type = t;
	HEA = HEA_init[t - 1];
	ATK = ATK_init[t - 1];
}

int knight::attack(int n, int RorB) {
	switch (type) {
	case 1:
		print(3, step, NULL,
			type, tool_qf(RorB), NO, HEA, ATK,
			knights[RorB][n]->type, RorB, knights[RorB][n]->NO, knights[RorB][n]->HEA, knights[RorB][n]->ATK);
		//HEA -= (knights[RorB][n]->ATK) / 2;
		knights[RorB][n]->HEA -= ATK;
		if (knights[RorB][n]->HEA <= 0) {
			knights[RorB][n]->dead = 0;
			print(5, step, NULL, knights[RorB][n]->type, RorB, knights[RorB][n]->NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		}
		else {
			print(4, step, NULL,
				knights[RorB][n]->type, RorB, knights[RorB][n]->NO, NULL, NULL,
				type, tool_qf(RorB), NO, NULL, NULL);
			HEA -= (knights[RorB][n]->ATK) / 2;
			if (HEA <= 0) {
				dead = 0;
				print(5, step, NULL, type, tool_qf(RorB), NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
			}
			else {
				//print(6, step, )
			}
		}
	}
}

void init() {
	knights[3][20] = { 0 };
	citys[20] = { 0 };
	int M = 0;
	cin >> M >> city_n >> TIME;
	citys[0] = new city(0, M);
	citys[city_n + 1] = new city(city_n + 1, M);
	for (int i = 1; i <= city_n; i++) citys[i] = new city(i, 0);
	for (int i = 0; i < 5; i++) cin >> HEA_init[i];
	for (int i = 0; i < 5; i++) cin >> ATK_init[i];
}




//WAQ Part Start
int red_list[5] = { 1,2,3,4,5 }, blue_list[5] = { 2,5,4,1,3 };


void procress();
int main() {
	cout << "Hello world!" << endl;
	int zushu, lalala = 1;
	cin >> zushu;
	while (zushu) {
		printf("Case:%d\n", lalala);
		zushu--;
		procress();
		lalala++;
	}
	return 0;
}
void print(int mode, int city_no, int elements, \
	int kinght_type_1, int commond_type_1, int kinght_no_1, int elements_1, int force_1, \
	int kinght_type_2, int commond_type_2, int kinght_no_2, int elements_2, int force_2 ) {
	char kinght[6][10] = { { " " },{ "dragon" },{ "ninja" },{ "iceman" },{ "lion" },{ "wolf" } };
	char commond[3][6] = { { " " },{ "red" },{ "blue" } };

	int h, Min;
	h = time / 6;
	Min = (time % 6) * 10;

	switch (mode) {
	case 1:        //000:00 blue lion 1 born
		printf("%03d:%d %s %s %d bron\n", \
			h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1);
		break;
	case 2:        //000:10 red iceman 1 marched to city 1 with 20 elements and force 30
		printf("%03d:%d %s %s %d marched to city %d with %d elements and force %d\n", \
			h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, city_no, elements_1, force_1);
		break;
	case 3:         //000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
		printf("%03d:%d %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n", \
			h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, commond[commond_type_2], kinght[kinght_type_2], kinght_no_2, city_no, elements_1, force_1);
		break;
	case 4:         //001:40 blue dragon 2 fought back against red lion 2 in city 1
		printf("%03d:%d %s %s %d fought back against %s %s %d in city %d\n", \
			h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, commond[commond_type_2], kinght[kinght_type_2], kinght_no_2, city_no);
		break;
	case 5:         //001:40 red lion 2 was killed in city 1
		printf("%03d:%d %s %s %d was killed in city %d\n", \
			h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, city_no);
		break;
	case 6:         //003:40 blue dragon 2 yelled in city 4
		printf("%03d:%d %s %s %d yelled in city %d\n", \
			h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, city_no);
		break;
	case 7:         //001:40 blue dragon 2 earned 10 elements for his headquarter
		printf("%03d:%d %s %s %d earned %d elements for his headquarter\n", \
			h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, elements);
		break;
	case 8:         //004:40 blue flag raised in city 4
		printf("%03d:%d %s flag raised in city %d\n", \
			h, Min, commond[commond_type_1], city_no);
		break;
	case 9:         //001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
		printf("%03d:%d %s %s %d reached %s headquarter with %d elements and force %d\n", \
			h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, commond[commond_type_2], elements_1, force_1);
		break;
	case 10:        //003:10 blue headquarter was taken
		printf("%03d:%d %s headquarter was taken\n", \
			h, Min, commond[commond_type_1]);
		break;
	case 11:        //000:50 100 elements in red headquarter
					//000:50 120 elements in blue headquarter
		printf("%03d:%d %d elements in red headquarter\n", \
			h, Min, citys[0]->HEA);
		printf("%03d:%d %d elements in blue headquarter\n", \
			h, Min, citys[city_n + 1]->HEA);
		break;
	}
}

void procress()
{
	time = 0;
	int sum_kinght = 0;
	init();
	//t = 0 ;
	while (citys[0]->people < 2 && citys[city_n+1]->people < 2) {
		//t = 0
		if (citys[0]->HEA > HEA_init[red_list[time % 5] - 1]) {
			knights[1][sum_kinght] = new knight(sum_kinght + 1, red_list[time % 5]);     //red bron
			citys[0]->HEA -= HEA_init[red_list[time % 5] - 1];
			print(1, NULL, NULL, \
				  red_list[time % 5], 1, sum_kinght + 1, NULL, \
				  NULL, NULL, NULL, NULL, NULL, NULL );
		}
		if (citys[city_n+1]->HEA > HEA_init[blue_list[time % 5] - 1]) {
			knights[2][sum_kinght] = new knight(sum_kinght + 1, blue_list[time % 5]);     //blue bron
			knights[2][sum_kinght]->step = city_n;
			citys[city_n+1]->HEA -= HEA_init[blue_list[time % 5] - 1];
			print(1, NULL, NULL, \
				  blue_list[time % 5], 2, sum_kinght + 1, NULL, \
				  NULL, NULL, NULL, NULL, NULL, NULL );
		}
		sum_kinght++;
		time++;
		//t = 1
		for (int i = 0; i < sum_kinght; i++) {
			if (knights[1][i]->dead) {                             //Red Move
				citys[knights[1][i]->step]->people--;
				knights[1][i]->step++;
				citys[knights[1][i]->step]->people++;
				if (knights[1][i]->step == city_n +1) {
					print(9, NULL, NULL, \
						knights[1][i]->type, 1, knights[1][i]->NO, knights[1][i]->HEA, knights[1][i]->ATK, \
						NULL, 2, NULL, NULL, NULL);
				}
				if (citys[0]->people == 2) {                       //被占领



					return;
				}
				print(2, knights[1][i]->step, NULL, \
					  knights[1][i]->type, 1, knights[1][i]->NO, knights[1][i]->HEA, knights[1][i]->ATK,\
					  NULL, NULL, NULL, NULL, NULL );
			}
			if (knights[2][i]->dead) {                              //Blue Move
				citys[knights[2][i]->step]->people--;
				knights[2][i]->step--;
				citys[knights[2][i]->step]->people++;
				if (knights[2][i]->step == 0) {
					print(9, NULL, NULL, \
						knights[2][i]->type, 2, knights[2][i]->NO, knights[2][i]->HEA, knights[2][i]->ATK, \
						NULL, 1, NULL, NULL, NULL);
				}
				if (citys[city_n + 1]->people == 2) {                //被占领
					
					
					
					
					return;
				}
				print(2, knights[2][i]->step, NULL,\
					  knights[2][i]->type, 2, knights[2][i]->NO, knights[2][i]->HEA, knights[2][i]->ATK, \
					  NULL, NULL, NULL, NULL, NULL );
			}
		}
		time++; 
		//t = 2
		



		//t = 3
		




		//t = 4
		


		//t = 5
		




	}


}
