#include <iostream>
using namespace std;

void bubble_sort(int *a, int n){
	for (int i=0; i<n-1; i++){ //外循环n-1次
		for (int j=0; j<n-i-1; j++){ //内循环找出前n-i个中最大元素，不断往末尾移
			if (a[j]>a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
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
	bubble_sort(a,n);
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
