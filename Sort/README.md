## 排序算法的深入分析和实现
**1.1 排序的定义**
对一序列对象根据某个关键字进行排序。
**1.2 术语说明**
**稳定**：如果a原本在b前面，而a=b，排序之后a仍然在b的前面；
**不稳定**：如果a原本在b的前面，而a=b，排序之后a可能会出现在b的后面；
**内排序In-place**：所有排序操作都在内存中完成；
**外排序Out-place**：由于数据太大，因此把数据放在磁盘中，而排序通过磁盘和内存的数据传输才能进行；

**1.3 算法总结**![在这里插入图片描述](https://img-blog.csdnimg.cn/20190419171130152.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x1aGFvMTk5ODA5MDk=,size_16,color_FFFFFF,t_70)

**1、冒泡排序（Bubble Sort）**
相邻两个元素比较大小，一次外循环比较(n-1)次；
如跑完第一次循环，最大的元素被移到最后一位；
内循环跑(n-i)次，因为最后i个元素已排好序；
![冒泡排序](https://img-blog.csdnimg.cn/20190420003741295.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x1aGFvMTk5ODA5MDk=,size_16,color_FFFFFF,t_70)

**时间复杂度分析**：
比较次数：不管怎样，冒泡排序都要比较(n+(n-1)+..+2+1)次，即n(n-1)/2 ，O(N^2);
交换次数：有序不需要交换，逆序交换n(n-1)/2次；O(N^2);

**稳定性分析：**
相邻两元素大小一样，自然不会多此一举去交换，因此稳定；

**C++代码实现：**
```c
//冒泡排序
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
```
**2、选择排序（Select Sort）**
每次选择第i小的元素，把它放在index为i的位置上；
一共n次外循环，第一次选出最小元素，放在第一个；第i次选出第i小的元素；
每次内循环要比较(n-i)次，最终选出后(n-i)个元素中最小的，放到i位置上。
![选择排序](https://img-blog.csdnimg.cn/2019042000365789.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x1aGFvMTk5ODA5MDk=,size_16,color_FFFFFF,t_70)

**时间复杂度分析**：
比较次数：选择排序同样比较(n+(n-1)+..+2+1)次，即n(n-1)/2 ，O(N^2);
交换次数：有序不需要交换，逆序交换n(n-1)/2次；O(N^2);

**稳定性分析：**
因为涉及相隔较远的元素交换位置！
例如3 2 3 1，第一次循环结束，3和1交换，破坏了稳定。显然选择排序是不稳定。 

**C++代码实现：**
```c
//选择排序
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
```
**3、插入排序（Insert Sort）**
类比平时打牌时插牌，拿到新元素，把它放到已排好序的元素中的适当位置；
外循环n次，第i次外循环结束，则前i个数已排好序，第一个默认排好序；
内循环为执行(n-i)次，将新元素和前i个排好序的依次比较，是一个不断往前插的过程；
![插入排序](https://img-blog.csdnimg.cn/20190420003829832.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x1aGFvMTk5ODA5MDk=,size_16,color_FFFFFF,t_70)

**时间复杂度分析**：
比较次数：同O(N^2);
交换次数：有序不需要交换，逆序交换n(n-1)/2次；O(N^2);

**稳定性分析：**
插入排序是稳定的；例如 1 2 3 3，前三个已经排好序，最后的3显然不会再往前插；

**C++代码实现：**
```c
//插入排序
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

```

**4、归并排序（Merge Sort）**
采用分治法，将序列分成两个n/2长度的子序列，合并时依次按大小输出到新序列；
占用额外空间，非原址排序；
![归并排序](https://img-blog.csdnimg.cn/20190420003900232.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x1aGFvMTk5ODA5MDk=,size_5,color_FFFFFF,t_70)

**时间复杂度分析**：
每次递归复杂度O(n)，递归层数O(lgn)，所以复杂度为O(nlgn);

**稳定性分析：**
归并排序是稳定的，合并过程左右两个序列的比较大小保证了这种稳定性；

**C++代码实现：**

```c
//归并排序
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
```


**5、快速排序（Quick Sort）**
从数列中挑出一个元素，称为 “基准”(pivot)；
重新排序数列，所有比pivot小的摆放在基准前面，所有比pivot大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；

Partition操作实现：
pivot选择末尾元素，维护i和j，i指向头，j指向pivot前一个。i不断往后搜索直到找到第一个大于pivot的元素；j不断往前搜索直到找到第一个小于pivot的元素。i,j都找到时交换i,j上的元素，如果j<i，退出循环，此时交换pivot和i位置，满足pivot(即i原来位置)左边都比它小，右边都比它大；
![快速排序](https://img-blog.csdnimg.cn/20190420015014337.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x1aGFvMTk5ODA5MDk=,size_16,color_FFFFFF,t_70)
**时间复杂度分析**：
每次递归复杂度O(n)，递归层数O(lgn)，所以复杂度为O(nlgn);

**稳定性分析：**
快速排序是不稳定的；
因为间隔元素的交换，很可能打破原有相同元素的顺序关系；
例如3 3 1 1 2，选择2为pivot，那么第一次循环，3和1就发生了交换，打乱了稳定性；

**C++代码实现：**

```c
//快速排序
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
```


