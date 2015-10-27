/*************************************************************************
	> File Name: pat1007.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Oct 2015 03:14:41 AM UTC
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n,start = 0, end = 0, start_temp = 0, sum = 0, max = 0, input[10000];
    bool all_negtive = true;
    cin >> n;
    if(n < 0) {
    	return 0;
    }
    for(int i=0;i<n;i++) {
        cin >> input[i];
        if(input[i] > 0) {
            all_negtive = false;
        }
    } 
    for(int i=0;i<n;i++) {
        sum += input[i];
        if(sum > max) {
            max = sum;
            end = i;
            start = start_temp;
        }
        if(sum < 0) {
            sum = 0;
            start_temp = i +  1;
        }
    }
    if(all_negtive) {
        cout <<  0 << " " << input[0] << " " << input[n-1] << endl;
    } else {
        cout << max << " " << input[start] << " " << input[end] << endl;
    }
    return 0;
}
