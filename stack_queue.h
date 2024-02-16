#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<cctype>
using namespace std;
class MyStack;

class listNode {
    friend class MyStack;
private:
    listNode* next;
    int data;
public:
    listNode() : next(nullptr), data(0) {}
    listNode(int nodeData, listNode* succ = nullptr) : data(nodeData), next(succ) {}
};

class MyStack
{
private:
    listNode* topNode;
    int stackSize;


public:
    MyStack();
    ~MyStack();

    bool push(const int&);
    bool pop(int&);
    bool getTop(int&);
    void printStack();
};

class MyQueue
{
private:
    int* queue;
    int capacity;
    int front;
    int rear;

public:
    MyQueue(const int&);
    ~MyQueue();

    bool enQueue(const int&);
    bool deQueue(int&);
    bool getFront(int&);
    void printQueue();

    bool isFull();
};
bool postfixExpression(const string&, string&);
bool expressionVal(const string&, int&);
void yanghui(const int&);
bool checksymbal(string);
bool checkparentheses(string);
int precedence(char);
bool applyOp(stack<int>&, stack<char>&);
