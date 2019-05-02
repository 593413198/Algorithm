#include <iostream>
using namespace std;

void select_sort(int *a, int n){
	for (int i=0; i<n-1; i++){ //外循环n-1次
		int min = a[i], index = i;
		for (int j=i; j<n; j++){ //内循环找出后n-i个中最小元素，放到第i位置
			if (a[j] < min){
				min = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = min;
	}
}

int main(){
	int n;
	int a[100];
	cout << "输入数字数目:";
	cin >> n;
	cout << "输出所有的数:";
	for (int i=0; i<n; i++)
		cin >> a[i];
	select_sort(a,n);
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
