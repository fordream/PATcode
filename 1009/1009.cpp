/*************************************************************************
	> File Name: pat1009.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Oct 2015 11:45:37 AM UTC
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
    int na, nb, in;
    float a[1001] = {0.0}, b[1001] = {0.0}, c[2001] = {0.0};
    cin >> na;
    for(int i=0;i<na;i++) {
        cin >> in;
        cin >> a[in];
    }
    cin >> nb;
    for(int i=0;i<nb;i++) {
        cin >> in;
        cin >> b[in];
    }
    for(int i=0;i<1001;i++) {
        for(int j=0;j<1001;j++) {
            c[i+j]  += a[i] * b[j];   // 下标相同的项相加
        }    
    }
    int count = 0;
    for(int i=0;i<2001;i++) {
        if(c[i]) {
            count ++;
        }
    }
    printf("%d", count);
    for(int i=2000;i>=0;i--) {
        if(c[i]) {
            printf(" %d %.1f", i, c[i]);
        }   
    }
    printf("\n");
    return 0;
}
