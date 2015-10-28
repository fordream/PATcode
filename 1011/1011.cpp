/*************************************************************************
	> File Name: pat1011.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Oct 2015 02:50:08 PM UTC
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
    double bet[3][3];
    char choose[3] = {'W', 'T', 'L'};
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin >> bet[i][j];
        }
    }
    int inchar[3] = {0};
    double in[3] = {bet[0][0], bet[1][0], bet[2][0]};
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(bet[i][j] > in[i]) {
                in[i] = bet[i][j];   // 各行最大值
                inchar[i] = j;       // 记录各行最大值下标
            }
        }
    }
    for(int i=0;i<3;i++) {
        cout << choose[inchar[i]] << " ";
    }
    printf("%.2lf\n", 2 * (in[0] * in[1] * in[2] * 0.65 - 1));
    return 0;
}
