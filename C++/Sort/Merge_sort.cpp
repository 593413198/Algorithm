#include <iostream>
using namespace std;

void merge(int *a, int *b, int p, int r, int q){ //合并下标为p到r 与 r+1到q 这两部分
	int write = p; //写入b的下标
	int i=p,j=r+1; //分别标记左右序列正要读的位置
	while (i<=r && j <= q){
		if (a[i]<=a[j])
			b[write++] = a[i++];
        else if (a[i]>a[j])
			b[write++] = a[j++];
	}
	//此时左、右序列可能有一个未写完
	while (i<=r)
		b[write++] = a[i++];
	while (j<=q)
		b[write++] = a[j++];
	for (int k=p; k<=q; k++)
		a[k] = b[k];
}

void merge_sort(int *a, int *b, int beg, int end){
	if (end==beg){ //1个元素直接返回
		return;
	}
	if (end-beg == 1){ //2个元素，排个序
		if (a[beg]>a[end]){
			int tmp = a[beg];
			a[beg] = a[end];
			a [end] = tmp;
		}
		return;
	}
	merge_sort(a,b,beg,(beg+end)/2);
	merge_sort(a,b,(beg+end)/2+1,end);
	merge(a,b,beg,(beg+end)/2,end);
}

int main(){
	int n;
	int a[100],b[100];
	cout << "输入数字数目:";
	cin >> n;
	cout << "输出所有的数:";
	for (int i=0; i<n; i++)
		cin >> a[i];
	merge_sort(a,b,0,n-1);
	for (int i=0; i<n; i++)
		cout << b[i] << ' ';
	cout << endl;
}
