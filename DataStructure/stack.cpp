/* *********************
 * @file:   stack.cpp
 * @brief:  实现STL中的栈用法
 * @date:   2019/5/1
 * @author: luhao
 * *********************/

#include <iostream>
using namespace std;
template<typename type>
class Stack{
	private:
		type *Top;  //栈顶指针,永远指向空位置
		type *Base; //栈底指针
	public:
		int Size;  //已入栈的元素数量
		int size(){ return Size;}; //返回Size
		Stack(); //初始化栈
		~Stack(); 
		bool empty() { return (Base==Top)?1:0;}; //返回栈是否为空
		void push(type x); //元素x入栈
		type top(); //返回栈顶元素
		type pop(); //出栈一次并返回该元素
		void show(); //自底向上，打印所有栈元素
};

template<typename type>
Stack<type>::Stack()
{
	Base = Top = new type[100]; 
	Size = 0;
	//初始化一个type类型、长度100的数组
	//此时Base和Top分别指向首地址
}

template<typename type>
Stack<type>::~Stack()
{
	/*
	delete[] Base;
	delete[] --Top; 
	* 此举会造成free(): invalid pointer! 
	* 因此指针地址发生了变化 */
	//释放指针，防止内存泄露
}

template<typename type>
void Stack<type>::push(type x)
{
	if (this->Size == 100){
		cout << "Stack Full!"<<endl; //栈满，内存溢出
		return;
	}
	*Top++ = x;
	Size ++;	
}

template<typename type>
type Stack<type>::top()
{
	if (empty()){
		cout << "Empty Stack!"<<endl; //提示栈空
	}
	else
		return *(Top-1);
}

template<typename type>
type Stack<type>::pop()
{
	if (empty()){
		cout << "Empty Stack!"<<endl; //提示栈空
	}
	else {
		Size--;
		return *(--Top);
	}
}

template<typename type>
void Stack<type>::show()
{
	if (empty()){
		cout << "Empty Stack!" << endl; //提示栈空
		return;
	}
	type *p = Base;
	while (p!=Top){
		cout << *p << ' ';
		p++;
	}
	cout << endl;
}

int main()
{
	Stack<int> S;
	S.push(1);
	S.push(2);
	S.pop();
	S.show();
	return 1;
}
