/*************************************************************************
	> File Name: pat1008.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Oct 2015 05:35:12 AM UTC
 ************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int n, time = 0, floor = 0;
    cin >> n;
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        if(temp < 0) {
            return 0;
        }
        if(temp > floor) {  // 上楼时间
            time += (temp - floor) * 6;
            floor = temp;
        } else if(temp < floor) {  // 下楼时间
            time += (floor - temp) * 4;
            floor = temp;
        }
    }
    time += 5 * n;  // 所有停留时间
    cout << time << endl;
    return 0;
}
