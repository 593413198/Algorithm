/* *********************
 * @file:   link.cpp
 * @brief:  实现STL中的单链表用法
 * @date:   2019/5/3
 * @author: luhao
 * *********************/

#include <iostream>
using namespace std;

template<class T>
struct Node{
	T name;
	Node<T> *nex;
};


template<class T>
class Link{
	private:
		Node<T> *Head;
		Node<T> *Tail;
		int Size;
	public:
		Link(); //初始化链表
		~Link(); //折构函数
		int size() { return Size; }; //链表长度
		bool empty() { return Size==0; } ; 
		void append(T x); //链表尾部添加一个元素
		void remove(); //删除链表尾部的元素
		void show(); //自首向尾，打印链表
		void reverse(); //TODO 反转链表,面试常考算法
};

template<class T>
Link<T>::Link()
{
	Head = Tail = new Node<T>; 
	//Head->nex = NULL;
	//Tail->nex = NULL;
	Size = 0;
}

template<class T>
Link<T>::~Link()
{
	/*
	* 指针地址发生了变化 */
}

template<class T>
void Link<T>::append(T x)
{
	Node<T> *p = new Node<T>;
	p->name = x;
	if (empty()){ //链表为空
		this->Head = this->Tail = p;
	}
	else {
		this->Tail->nex = p;
		this->Tail = p;
	}
	Size++;
}

template<class T>
void Link<T>::remove()
{
	if (empty()){
		cout << "Empty Link!" << endl;
		return;
	}
	Node<T> *p = this->Head;
	while (p->nex != this->Tail){
		p = p->nex;
	}
	this->Tail = p;
	p->nex = NULL;
	Size --;
}

template<class T>
void Link<T>::show()
{
	if (empty()){
		cout << "Empty Link!" << endl;
		return;
	}
	Node<T> *p = this->Head;
	while (p!=this->Tail){
		cout << p->name << ' ';
		p = p->nex;
	}
	cout << this->Tail->name << endl;
}

template<class T>
void Link<T>::reverse()
{
	/* 反转单链表：
	 * 不断把当前节点cur的nex翻转到它的前面 */
	if (empty())
		return;
	Node<T> *cur = this->Head;
	while (cur->nex!=NULL){
		Node<T> *head = this->Head;
		this->Head = cur->nex;
		cur->nex = this->Head->nex;
		this->Head->nex = head;
	}
	this->Tail = cur;
}

int main()
{
	Link<int> S;
	S.append(1);
	S.append(2);
	S.append(3);
	S.append(4);
	S.remove();
	S.show();
	S.reverse();
	S.show();
	
	return 1;
}
