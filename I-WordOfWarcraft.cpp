/****************************
 2017.8.3-2017.8.4
 WYC and WAQ
 :)
 ****************************/

//#include"stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void print(int mode, int city_no, int elements, \
           int kinght_type_1, int commond_type_1, int kinght_no_1, int elements_1, int force_1, \
           int kinght_type_2, int commond_type_2, int kinght_no_2, int elements_2, int force_2 );

int tool_qf(int n) {
    if (n == 1) return 2;
    else return 1;
}

class knight {
public:
    int NO, HEA, type, ATK, step, kill_n, dead;
    knight(int n, int t);
    int attack(int n, int RorB);
};

class city {
public:
    int NO, HEA, people, flag, red, blue ;
    city(int n, int h) {
        NO = 0, HEA = 0, people = 0, flag = 0, red = 0, blue = 0;
        NO = n;
        HEA = h;
    }
};

knight *knights[3][30] = {0};
city   *citys[30] = {0};
int city_n = 0, TIME = 0, time = 0;
int HEA_init[7] = {0}, ATK_init[7] = {0};

knight::knight(int n, int t) {
    NO = 0, HEA = 0, type = 0, ATK = 0, step = 0, kill_n = 0, dead = 1;
    NO = n;
    type = t;
    HEA = HEA_init[t - 1];
    ATK = ATK_init[t - 1];
}

int knight::attack(int n, int RorB) {
    int HEA_temp = 0; //战斗前生命值
    switch(this->type) {
    case 1:
    case 2:
    case 3://Dragon,Ninja,Iceman
        //主动攻击
        print(3, this->step, NULL,
              this->type, tool_qf(RorB), this->NO, this->HEA, this->ATK,
              knights[RorB][n]->type, RorB, knights[RorB][n]->NO, knights[RorB][n]->HEA, knights[RorB][n]->ATK);
        knights[RorB][n]->HEA -= this->ATK;
        if (knights[RorB][n]->HEA <= 0) {
            knights[RorB][n]->dead = 0;
            this->kill_n++;
            print(5, this->step, NULL, knights[RorB][n]->type, RorB, knights[RorB][n]->NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
            if(this->type == 1) print(6, this->step, NULL, this->type, tool_qf(RorB), this->NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL); //Dragon欢呼
            if (knights[RorB][n]->type == 4) this->HEA += HEA_temp; //Lion奖励生命值
            return tool_qf(RorB);
        } else {
            //反击
            HEA_temp = knights[RorB][n]->HEA;
            if (knights[RorB][n]->type != 2) {//Ninja不反击
                print(4, this->step, NULL,
                      knights[RorB][n]->type, RorB, knights[RorB][n]->NO, NULL, NULL,
                      this->type, tool_qf(RorB), this->NO, NULL, NULL);
                this->HEA -= (knights[RorB][n]->ATK) / 2;
            }
            if (this->HEA <= 0) {
                this->dead = 0;
                print(5, this->step, NULL, this->type, tool_qf(RorB), this->NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
                return RorB;
            } else return 0;//双方均存活
        }
    case 4://Lion
        //主动攻击
        HEA_temp = HEA;
        print(3, this->step, NULL,
              this->type, tool_qf(RorB), this->NO, this->HEA, this->ATK,
              knights[RorB][n]->type, RorB, knights[RorB][n]->NO, knights[RorB][n]->HEA, knights[RorB][n]->ATK);
        knights[RorB][n]->HEA -= this->ATK;
        if (knights[RorB][n]->HEA <= 0) {
            knights[RorB][n]->dead = 0;
            kill_n++;
            print(5, this->step, NULL, knights[RorB][n]->type, RorB, knights[RorB][n]->NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
            if (knights[RorB][n]->type == 4)this->HEA += HEA_temp; //Lion奖励生命值
            return tool_qf(RorB);
        } else {
            //反击
            HEA_temp = knights[RorB][n]->HEA;
            if (knights[RorB][n]->type != 2) {//Ninja不反击
                print(4, this->step, NULL,
                      knights[RorB][n]->type, RorB, knights[RorB][n]->NO, NULL, NULL,
                      this->type, tool_qf(RorB), this->NO, NULL, NULL);
                this->HEA -= (knights[RorB][n]->ATK) / 2;
            }
            if (this->HEA <= 0) {
                this->dead = 0;
                print(5, this->step, NULL, this->type, tool_qf(RorB), this->NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
                knights[RorB][n]->HEA += HEA_temp; //反击被杀，奖励对手生命值
                return RorB;
            } else return 0;//双方均存活
        }
    case 5://Wolf
        print(3, this->step, NULL,
              this->type, tool_qf(RorB), this->NO, this->HEA, this->ATK,
              knights[RorB][n]->type, RorB, knights[RorB][n]->NO, knights[RorB][n]->HEA, knights[RorB][n]->ATK);
        knights[RorB][n]->HEA -= this->ATK;
        if (knights[RorB][n]->HEA <= 0) {
            knights[RorB][n]->dead = 0;
            this->kill_n++;
            print(5, this->step, NULL, knights[RorB][n]->type, RorB, knights[RorB][n]->NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
            //生命攻击翻倍
            if (kill_n % 2 == 0) {
                this->HEA = this->HEA * 2;
                this->ATK = this->ATK * 2;
            }
            if (knights[RorB][n]->type == 4) this->HEA += HEA_temp; //Lion奖励生命值
            return tool_qf(RorB);
        } else {
            //反击
            HEA_temp = knights[RorB][n]->HEA;
            if (knights[RorB][n]->type != 2) {//Ninja不反击
                print(4, this->step, NULL,
                      knights[RorB][n]->type, RorB, knights[RorB][n]->NO, NULL, NULL,
                      this->type, tool_qf(RorB), this->NO, NULL, NULL);
                this->HEA -= (knights[RorB][n]->ATK) / 2;
            }
            if (this->HEA <= 0) {
                this->dead = 0;
                print(5, this->step, NULL, this->type, tool_qf(RorB), this->NO, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
                return RorB;
            } else return 0;//双方均存活
        }
    }
}

void Init() {
    //knights[3][20] = {0};
    //citys[20] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 30; j++) knights[i][j] = NULL;
    }
    for (int i = 0; i < 30; i++) {
        citys[i] = NULL;
    }
    int M = 0;
    cin >> M >> city_n >> TIME;
    citys[0] = new city(0, M);
    citys[city_n + 1] = new city(city_n + 1, M);
    for (int i = 1; i <= city_n; i++) citys[i] = new city(i, 0);
    for (int i = 0; i < 5; i++) cin >> HEA_init[i];
    for (int i = 0; i < 5; i++) cin >> ATK_init[i];
}

int red_list[5] = { 3, 4, 5, 2, 1 }, blue_list[5] = { 4, 1, 2, 3, 5 };
void procress();

int main() {
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
    char kinght[6][10] = { {" "}, {"dragon"}, {"ninja"}, {"iceman"}, {"lion"}, {"wolf"} };
    char commond[3][6] = { {" "}, {"red"}, {"blue"} };

    int h, Min;
    h = time / 6;
    Min = (time % 6) * 10;

    switch (mode) {
    case 1 :        //000:00 blue lion 1 born
        printf("%03d:%02d %s %s %d bron\n", \
               h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1);
        break;
    case 2 :        //000:10 red iceman 1 marched to city 1 with 20 elements and force 30
        printf("%03d:%02d %s %s %d marched to city %d with %d elements and force %d\n", \
               h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, city_no, elements_1, force_1);
        break;
    case 3:         //000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
        printf("%03d:%02d %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n", \
               h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, commond[commond_type_2], kinght[kinght_type_2], kinght_no_2, city_no, elements_1, force_1);
        break;
    case 4:         //001:40 blue dragon 2 fought back against red lion 2 in city 1
        printf("%03d:%02d %s %s %d fought back against %s %s %d in city %d\n", \
               h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, commond[commond_type_2], kinght[kinght_type_2], kinght_no_2, city_no);
        break;
    case 5:         //001:40 red lion 2 was killed in city 1
        printf("%03d:%02d %s %s %d was killed in city %d\n", \
               h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, city_no);
        break;
    case 6:         //003:40 blue dragon 2 yelled in city 4
        printf("%03d:%02d %s %s %d yelled in city %d\n", \
               h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, city_no);
        break;
    case 7:         //001:40 blue dragon 2 earned 10 elements for his headquarter
        printf("%03d:%02d %s %s %d earned %d elements for his headquarter\n", \
               h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, elements);
        break;
    case 8:         //004:40 blue flag raised in city 4
        printf("%03d:%02d %s flag raised in city %d\n", \
               h, Min, commond[commond_type_1], city_no);
        break;
    case 9:         //001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
        printf("%03d:%02d %s %s %d reached %s headquarter with %d elements and force %d\n", \
               h, Min, commond[commond_type_1], kinght[kinght_type_1], kinght_no_1, commond[commond_type_2], elements_1, force_1);
        break;
    case 10:        //003:10 blue headquarter was taken
        printf("%03d:%02d %s headquarter was taken\n", \
               h, Min, commond[commond_type_1]);
        break;
    case 11:        //000:50 100 elements in red headquarter
        //000:50 120 elements in blue headquarter
        printf("%03d:%02d %d elements in red headquarter\n", \
               h, Min, citys[0]->HEA);
        printf("%03d:%d %d elements in blue headquarter\n", \
               h, Min, citys[city_n + 1]->HEA);
        break;
    }
}

void procress() {
    time = 0;
    int sum_kinght_r = 0, sum_kinght_b = 0, R_backup = 0, B_backup = 0;
    Init();
    int who_win[3][23] = { 0 }, round_win[3][23] = { 0 };  //胜利计数 需要初始化
    //t = 0 ;
    while (1/*citys[0]->people < 2 && citys[city_n + 1]->people < 2*/) {
        //t = 0
        bool r_flag = 0, b_flag = 0;
        int r_mem = 0, b_mem = 0;
        if (citys[0]->HEA >= HEA_init[red_list[time % 5] - 1]) {
            sum_kinght_r++;
            knights[1][sum_kinght_r] = new knight(sum_kinght_r, red_list[time % 5]);     //red bron
            citys[0]->HEA -= HEA_init[red_list[time % 5] - 1];
            citys[0]->people++;
            print(1, NULL, NULL, \
                  red_list[time % 5], 1, sum_kinght_r, NULL, \
                  NULL, NULL, NULL, NULL, NULL, NULL );

        }
        if (citys[city_n + 1]->HEA >= HEA_init[blue_list[time % 5] - 1]) {
            sum_kinght_b++;
            knights[2][sum_kinght_b] = new knight(sum_kinght_b, blue_list[time % 5]);     //blue bron
            knights[2][sum_kinght_b]->step = city_n + 1;
            citys[city_n + 1]->HEA -= HEA_init[blue_list[time % 5] - 1];
            citys[city_n + 1]->people++;
            print(1, NULL, NULL, \
                  blue_list[time % 5], 2, sum_kinght_b, NULL, \
                  NULL, NULL, NULL, NULL, NULL, NULL );
        }
        //红蓝需要分开。ERROR
        time++;
        //t = 1
        for (int i = 1; i <= sum_kinght_r; i++) {
            if (knights[1][i]->dead  && (knights[1][i]->step <= city_n)) {                             //Red Move
                citys[knights[1][i]->step]->people--;
                citys[knights[1][i]->step]->red = 0;
                knights[1][i]->step++;
                citys[knights[1][i]->step]->people++;
                citys[knights[1][i]->step]->red = knights[1][i]->NO;
                if (knights[1][i]->step == city_n + 1) {
                    r_flag = 1;
                    r_mem = knights[1][i]->NO;
                }
                if (knights[1][i]->type == 3 && ((knights[1][i]->step & 1) == 0)) {                  //iceman加血
                    if (knights[1][i]->HEA > 9) {
                        knights[1][i]->HEA -= 9;
                    } else {
                        knights[1][i]->HEA = 1;
                    }
                    knights[1][i]->ATK += 20;
                }
            }
        }
        //蓝循环
        for (int i = 1; i <= sum_kinght_b; i++) {
            if (knights[2][i]->dead && knights[2][i]->step > 0) {                                   //Blue Move
                citys[knights[2][i]->step]->people--;
                citys[knights[2][i]->step]->blue = 0;
                knights[2][i]->step--;
                citys[knights[2][i]->step]->people++;
                citys[knights[2][i]->step]->blue = knights[2][i]->NO;
                if (knights[2][i]->step == 0) {
                    b_flag = 1;
                    b_mem = knights[2][i]->NO;
                }

                if (knights[2][i]->type == 3 && ((knights[2][i]->step & 1) == 0)) {                  //iceman加血
                    if (knights[2][i]->HEA > 9) {
                        knights[2][i]->HEA -= 9;
                    } else {
                        knights[2][i]->HEA = 1;
                    }
                    knights[2][i]->ATK += 20;
                }
            }
        }

        if (b_flag) {
            print(9, NULL, NULL, \
                  knights[2][b_mem]->type, 2, knights[2][b_mem]->NO, knights[2][b_mem]->HEA, knights[2][b_mem]->ATK, \
                  NULL, 1, NULL, NULL, NULL);
            b_flag = 0;
        }
        if (citys[0]->people == 2) {                //被占领
            print(10, NULL, NULL, NULL, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
            return;
        }

        for (int i = 1; i <= city_n; i++) {
            if (citys[i]->red && knights[1][citys[i]->red]->dead) {
                print(2, knights[1][citys[i]->red]->step, NULL, \
                      knights[1][citys[i]->red]->type, 1, knights[1][citys[i]->red]->NO, knights[1][citys[i]->red]->HEA, knights[1][citys[i]->red]->ATK, \
                      NULL, NULL, NULL, NULL, NULL);
            }
            if(citys[i]->blue && knights[2][citys[i]->blue]->dead) {
                print(2, knights[2][citys[i]->blue]->step, NULL, \
                      knights[2][citys[i]->blue]->type, 2, knights[2][citys[i]->blue]->NO, knights[2][citys[i]->blue]->HEA, knights[2][citys[i]->blue]->ATK, \
                      NULL, NULL, NULL, NULL, NULL);
            }
        }

        if (r_flag) {
            print(9, NULL, NULL, \
                  knights[1][r_mem]->type, 1, knights[1][r_mem]->NO, knights[1][r_mem]->HEA, knights[1][r_mem]->ATK, \
                  NULL, 2, NULL, NULL, NULL);
            r_flag = 0;
        }
        if (citys[city_n + 1]->people == 2) {                       //被占领
            print(10, NULL, NULL, NULL, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
            return;
        }

        time++;
        //t = 2
        for (int i = 1; i <= city_n; i++) {
            citys[i]->HEA += 10;
        }
        time++;
        //t = 3
        for (int i = 1; i <= city_n; i++) {
            if (citys[i]->people == 1) {
                if (citys[i]->red) {
                    citys[city_n + 1]->HEA += citys[i]->HEA;
                    print(7, i, citys[i]->HEA, \
                          knights[1][citys[i]->red]->type, 1, knights[1][citys[i]->red]->NO, NULL, NULL, \
                          NULL, NULL, NULL, NULL, NULL);
                    citys[i]->HEA = 0;
                }
                if (citys[i]->blue) {
                    citys[0]->HEA += citys[i]->HEA;
                    print(7, i, citys[i]->HEA, \
                          knights[2][citys[i]->blue]->type, 2, knights[2][citys[i]->blue]->NO, NULL, NULL, \
                          NULL, NULL, NULL, NULL, NULL);
                    citys[i]->HEA = 0;

                }
            }
        }
        time++;
        //t = 4,攻击,收集,奖励,插旗模块
        R_backup = citys[0]->HEA, B_backup = citys[city_n + 1]->HEA;
        for (int i = 1; i <= city_n; i++) {
            int win_status = 0;
            if (citys[i]->people == 2 && \
                    knights[1][citys[i]->red]->dead && \
                    knights[2][citys[i]->blue]->dead) {
                if (citys[i]->flag == 1 || ((i & 1) == 1)) {//攻击
                    win_status = knights[1][citys[i]->red]->attack(citys[i]->blue, 2);

                } else if (citys[i]->flag == 2 || ((i & 1) == 0)) {
                    win_status = knights[2][citys[i]->blue]->attack(citys[i]->red, 1);
                }
                //更新插旗与奖励标记,收集生命元,插旗判定
                if (win_status == 1) {
                    who_win[1][i]++;
                    who_win[2][i] = 0;
                    round_win[1][citys[i]->red] = 1;
                    print(7, NULL, citys[i]->HEA,
                          knights[1][citys[i]->red]->type, 1, knights[1][citys[i]->red]->NO, NULL, NULL,
                          NULL, NULL, NULL, NULL, NULL);
                    citys[0]->HEA += citys[i]->HEA;
                    citys[i]->HEA = 0;

                    //
                    citys[i]->blue = 0;
                    citys[i]->people--;


                    if (who_win[1][i] == 2) print(8, i, NULL, NULL, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
                } else if (win_status == 2) {
                    who_win[2][i]++;
                    who_win[1][i] = 0;
                    round_win[2][citys[i]->blue] = 1;
                    print(7, NULL, citys[i]->HEA,
                          knights[2][citys[i]->blue]->type, 2, knights[2][citys[i]->blue]->NO, NULL, NULL,
                          NULL, NULL, NULL, NULL, NULL);
                    citys[city_n + 1]->HEA += citys[i]->HEA;
                    citys[i]->HEA = 0;

                    //
                    citys[i]->red = 0;
                    citys[i]->people--;


                    if (who_win[2][i] == 2) print(8, i, NULL, NULL, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
                }
            }
        }
        //奖励判定
        for (int i = 1; i <= city_n; i++) {
            if (round_win[1][i]) {
                if (R_backup < 8) break;
                knights[1][i]->HEA += 8;
                citys[0]->HEA -= 8;
                R_backup -= 8;
            }
        }
        for (int i = city_n; i >= 1; i--) {
            if (round_win[2][i]) {
                if (B_backup < 8) break;
                knights[2][i]->HEA += 8;
                citys[city_n + 1]->HEA -= 8;
                B_backup -= 8;
            }
        }
        for (int i = 0; i < 3; i++) { //奖励标记初始化
            for (int j = 0; j < 23; j++) round_win[i][j] = 0;
        }
        time++;

        //t = 5
        print(11, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
        time++;
    }
}
