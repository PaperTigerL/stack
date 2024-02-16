#include "stack_queue.h"
using namespace std;
int main() {
	/*
	MyStack ms;
	int val;
	ms.push(1);
	ms.printStack();//1
	ms.push(2);
	ms.printStack();//2,1
	
	ms.pop(val);
	cout << val << endl;//2
	ms.printStack();//1
	ms.getTop(val);
	cout << val << endl;//1
	ms.printStack();//1
	
	*/
	/*
	MyQueue mq(10);
    int val;
    mq.enQueue (1);
    mq.printQueue();//1
    mq.enQueue (2);
    mq.printQueue();//1,2
    mq.deQueue (val);
    cout<<val<<endl;//1
    mq.printQueue();//2
    mq.getFront(val);
    cout<<val<<endl;//2
 	mq.printQueue();//2
	*/

	//string result;
    int val;
   /* postfixExpression("5*(7-2)", result);
    cout<<result<<endl; // 572-*
    postfixExpression("5*(7-2",result);
    cout<<result<<endl; // Expression is wrong!*/

    expressionVal("5*(7-2)", val);
    cout<<val<<endl; // 25

	
	//yanghui(3);
	

	return 0;
}