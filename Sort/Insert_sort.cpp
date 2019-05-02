#include <iostream>
using namespace std;

void insert_sort(int *a, int n){
	for (int i=1; i<n; i++){ //外循环n-1次，第i次外循环结束前i+1个元素排好序列
		int index = i;
		for (int j=i-1; j>=0; j--){ //内循环将第i个元素往前插
			if (a[index]<a[j]){
				int tmp = a[index];
				a[index] = a[j];
				a[j] = tmp;
				index = j;
			}
		}
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
	insert_sort(a,n);
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
