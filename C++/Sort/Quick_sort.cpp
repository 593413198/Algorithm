#include <iostream>
using namespace std;

int partition(int *a, int p, int q){
	int pivot = q; //选择最后一个元素作为pivot
	int i=0,j=q-1;
	while (i<=j){
		while (a[i]<=a[pivot] && i<q ){ //i左边都<=pivot
			i++;
		}
		while (a[j]>a[pivot] && j>=p ){ //j右边都>pivot
			j--;
		}
		if (i<j){ //i不会等于j
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	//交换i和pivot
	int tmp = a[i];
	a[i] = a[pivot];
	a[pivot] = tmp;
	return i; //partition结束，满足左边<=它，右边>它
}

void quick_sort(int *a, int beg, int end){
	if (beg>=end)
		return;
	int pivot = partition(a,beg,end);
	quick_sort(a,beg,pivot-1);
	quick_sort(a,pivot+1,end);
}

int main(){
	int n;
	int a[100];
	cout << "输入数字数目:";
	cin >> n;
	cout << "输出所有的数:";
	for (int i=0; i<n; i++)
		cin >> a[i];
	quick_sort(a,0,n-1);
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
