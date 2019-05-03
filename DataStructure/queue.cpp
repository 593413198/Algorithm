/* *********************
 * @file:   queue.cpp
 * @brief:  实现STL中的队列用法
 * @date:   2019/5/3
 * @author: luhao
 * *********************/

#include <iostream>
using namespace std;

template<typename type>
class Queue{
	private:
		type *Head;  //队首指针
		type *Tail; //队尾指针，永远指向空位置
	public:
		int Size;  //已入队的元素数量
		int size(){ return Size;}; //返回Size
		Queue(); //初始化队列
		~Queue(); 
		bool empty() { return (Tail==Head)?1:0;}; //返回队列是否为空
		void push(type x); //元素x入队列
		type first(); //返回队首元素
		type pop(); //出队列一次并返回该元素
		void show(); //自首向尾，打印所有队列元素
};

template<typename type>
Queue<type>::Queue()
{
	Tail = Head = new type[100]; 
	Size = 0;
	//初始化一个type类型、长度100的数组
	//此时Tail和Head分别指向首地址
}

template<typename type>
Queue<type>::~Queue()
{
	/*
	delete[] --Tail;
	delete[] Head;
	* 此举会造成free(): invalid pointer!  
	* 因为指针地址发生了变化 */
	//释放指针，防止内存泄露
}

template<typename type>
void Queue<type>::push(type x)
{
	if (Size == 100){
		cout << "Queue Full!"<<endl; //对列满，内存溢出
		return;
	}
	if (Size == 0){
		*Head = x;
		Tail ++;
		Size++;
		return;
	}
	*Tail++ = x;
	Size ++;	
}

template<typename type>
type Queue<type>::first()
{
	if (empty()){
		cout << "Empty Queue!"<<endl; //提示队空
	}
	else
		return *Head;
}

template<typename type>
type Queue<type>::pop()
{
	if (empty()){
		cout << "Empty Queue!"<<endl; //提示队空
	}
	else {
		Size--;
		return *Head++; //Head元素取出，同时指针后移一个元素
	}
}

template<typename type>
void Queue<type>::show()
{
	if (empty()){
		cout << "Empty Queue!" << endl; //提示队空
		return;
	}
	type *p = Head;
	while (p!=Tail){
		cout << *p << ' ';
		p++;
	}
	cout << endl;
}

int main()
{
	Queue<int> S;
	S.push(1);
	S.push(2);
	S.pop();
	S.show();
	return 1;
}

