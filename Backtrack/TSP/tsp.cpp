/*!****************************
 * @file:   tsp.cpp
 * @brief:  tsp旅行商问题_回溯法
 * @date:   2019,5,5
 * @author: luhao
 * ****************************/
#include<iostream>
using namespace std;

int N;  //城市数量
int d[100][100]; //城市间距离
int Min_dist=1000000; //记录最小距离
int dist=0;
int last=0; //记录上一次经过的城市
int vis[100]; //记录是否访问过

int Search(int depth){
	if (depth==N-1){
		dist += d[last][0]; //回到起点城市
		if (dist<Min_dist)
			Min_dist = dist;
		dist -= d[last][0];
		return 1;
	}
	for (int i=1; i<N; i++){
   		if (!vis[i]) {
			int tmp = last; //用于回溯
			dist += d[last][i];
			last = i;
			vis[i] = 1;
			Search(depth+1); //继续前往下一城市
			//回溯开始
			last = tmp;
			dist -= d[tmp][i];
			vis[i] = 0;
	  	}
	}
}

int main(){
	cout << "请输入城市数量：";
	cin >> N;
	cout << "请输入距离："<<endl;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			cin >> d[i][j];
	for (int i=0; i<N; i++)
		vis[i]=0;
	vis[0] = 1;
	Search(0);
	cout << "最小距离是:"<<Min_dist<<endl;
	return 0;
}
