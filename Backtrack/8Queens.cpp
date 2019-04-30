#include <iostream>
using namespace std;

int x[8][8]; //0:空  1:有皇后
int check(int i, int j); //检查在(i,j)处放上一个新皇后，是否满足条件
int putQueen(int i); //表示放置第i行的皇后
int ans = 0; //最后答案

int check(int i, int j){
	/* 放上该皇后之前一定是满足条件的
	 * return 1: 局面满足条件
	 * return 0: else */
	for (int m = 0; m<8; m++) {//检查(i,j)所在行列
		if (m!= j && x[i][m] ==1) return 0;
		if (m!= i && x[m][j] ==1) return 0;
	}
	for (int m = i-1,n = j-1; m>=0 && n>=0; m--,n--) { //检查到左上角方向
		if (x[m][n]==1)
			return 0;
	}
	for (int m = i-1,n = j+1; m>=0 && n<=7; m--,n++) { //检查到右上角方向
		if (x[m][n]==1)
			return 0;
	}
	return 1;
}

int putQueen(int i) {
	if (i==8) {
		ans ++;
		return 1; //第8行放完，游戏结束
	}
	for (int j=0; j<8; j++){
		x[i][j] = 1; //(i,j)处放皇后
		if ( check(i,j) ){ //若符合条件，继续搜索
			putQueen(i+1);
		}
		//不符合条件，回退一步，重新搜索
		x[i][j] = 0;
	}
}

int main()
{
	putQueen(0);
	cout << "8皇后问题的解个数为:" << ans << endl;
	return 1;
}
