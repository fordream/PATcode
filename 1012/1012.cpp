/*************************************************************************
  > File Name: pat1012.cpp
  > Author: 
  > Mail: 
  > Created Time: Tue 27 Oct 2015 04:06:29 PM UTC
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

// 判断学生是否在成绩列表中
int student_inlist(char ids[7], char idd[10000][7]) {
    for (int i = 0; i < 10000; ++i) {
        if (0 == strcmp(ids, idd[i])) {
    	    return i;
        }
    }
    return -1;
}

int main() {
    int n, m, score[10000][4] = {0}, rank[10000][4];  // rank保存每个学生 A C M E 的排名记录
    char student[10000][7] = {'0'};  // 成绩列表
    char m_student[10000][7];        // 学生列表
    char outchar[4] = {'A', 'C', 'M', 'E'};
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) {
        scanf("%s %d %d %d", student[i], &score[i][1], &score[i][2], &score[i][3]);
        float temp = (score[i][1] + score[i][2] + score[i][3]) / 3.0;         // 计算平均分
        score[i][0] = (int)(temp + 0.5)>(int)temp?(int)temp + 1:(int)temp;    // 四舍五入
    }
    for(int i=0;i<m;i++) {
        scanf("%s", m_student[i]);
    }
    for (int i = 0; i < n; ++i) {
        for(int j = 0;j < 4; ++j) {
            rank[i][j] = 1;    // 各科排名初始化为1
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < n; ++j) {
                if (score[j][i] > score[k][i]) {
                    rank[k][i] ++;     // 计算各科排名
                }
        	}
        }
    }
    
    //for (int i = 0; i < n; ++i)
    //{
    //  for (int j = 0; j < 4; ++j)
    //  {
    //    cout << rank[i][j] << " ";  // 输出各科排名
    //  }
    //  cout << endl;
    //}
    for (int i = 0; i < m; ++i) {
        int index = student_inlist(m_student[i], student);
      	if (index != -1) {
        	int temp = rank[index][0], char_index = 0;
        	for (int j = 0; j < 4; ++j) {
          		if (rank[index][j] < temp) {
            		temp = rank[index][j];   // 找出每个学生排名最靠前的科目，顺序：A C M E并记录名次
            		char_index = j;          
          		}
        	}
        	cout << rank[index][char_index] << " " << outchar[char_index] << endl;
      	} else {
        	cout << "N/A" << endl;
      	}
    }
    return 0;
}