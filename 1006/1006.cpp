/*************************************************************************
	> File Name: pat1006.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Oct 2015 01:16:22 AM UTC
 ************************************************************************/

#include<iostream>
using namespace std;
struct people {
    string name;
    string start;
    string end;
};

// 比较时间先后
int compire(string p1, string p2) {
    for(int i=0;i<p1.length();i++) {
        if((p1[i] - p2[i]) > 0) {  
            return 1;
        } 
        if((p1[i] - p2[i]) < 0) {
            return -1;
        }
    }
    return 0;
}

int main() {
    int n;
    struct people input[10000];
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> input[i].name;
        cin >> input[i].start;
        cin >> input[i].end;
    }
    struct people min = input[0], max = input[0];
    for(int i=0;i<n;i++) {

		// 找出最早in
        if(compire(input[i].start, min.start) < 0) {
            min = input[i];
        }

		// 找出最晚out
        if(compire(input[i].end, max.end) > 0) {
            max = input[i];       
        }
    }
    cout << min.name << " " << max.name << endl; 
    return 0;
}
