/*!***********************
 * @file:   01Bag.cpp
 * @brief:  01背包问题_回溯法
 * @date:   2019/5/1
 * @author: luhao
 * ***********************/
#include <iostream>
#include <stdio.h>
using namespace std;

int n; //物品数量
int c; //背包容量
int w[100]; //每个物品的重量
int v[100]; //每个物品的价值
int sum_w=0;  //已选总质量
int sum_v=0;  //已选总价值
int max_v=0;  //累计最大总价值
int search(int );

int search(int num){
	/* 搜索到第num个物品 */
	if (num==n){
		return 0;
	}
	if (sum_w + w[num] <= c){ //不超过容量，则装入
		sum_v += v[num];
		sum_w += w[num];
		if (sum_v>max_v)   //如果发现更大的价值，更新max_v
			max_v = sum_v;
		search(num+1);  
		sum_v -= v[num];   //回溯，将当前装入的扔掉
		sum_w -= w[num];
	}
	search(num+1); //不装当前物品，继续搜索
}

int main(){
	cout << "输入物品数量n:";
	cin >> n;
	cout << "输入背包容量c:";
	cin >> c;
	cout << "输入n个物品的重量:";
	for (int i=0; i<n; i++)
		cin >> w[i];
	cout << "输入n个物品的价值:";
	for (int i=0; i<n; i++)
		cin >> v[i];
	search(0);
	cout << "最大价值是: "<< max_v << endl;
	return 1;
}
