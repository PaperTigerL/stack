#include "stack_queue.h"

void MyStack::printStack(){
    listNode* p = topNode;

    while(p != NULL){
        if(p->next == NULL)
            cout << p->data << endl;
        else
            cout << p->data << ",";

        p = p->next;
        
    }
}

void MyQueue::printQueue(){
    int cursor = front;

    while(cursor != rear)
    {
        if((cursor + 1) % capacity == rear)
            cout << queue[cursor] << endl;
        else
            cout << queue[cursor] << ",";

        cursor = (cursor + 1) % capacity;
    }
}
MyStack::MyStack() {
    topNode =nullptr;
    stackSize = 0;
}
MyStack::~MyStack() {
    listNode* cur = topNode;
    while (cur) {
        listNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
}
bool MyStack::push(const int& val) {
    listNode* temp = topNode;
    listNode* node = new listNode();
    node->data = val;
    node->next = temp;
    topNode= node;
    stackSize++;
    return true;
}
bool MyStack::pop(int& item) {
    if (stackSize == 0)return false;
    else {
        item = topNode->data;
        topNode= topNode->next;
        stackSize--;
    }
    return true;
}
bool MyStack::getTop(int& item) {
    if (stackSize == 0)return false;
    else {
        item = topNode->data;
    }
    return true;
}
MyQueue::MyQueue(const int& Capacity) {
    queue = new int[1000];
    capacity = Capacity;
    front = 0;
    rear = 0;
}
MyQueue::~MyQueue() {
    if (queue) {
        delete[] queue;
        queue = nullptr;
    }
}
bool  MyQueue::enQueue(const int& item) {
    if ((rear + 1) % capacity == front) return false;
    else {
        queue[rear] = item;
        rear = (rear + 1) % capacity;
    }
    return true;
}
bool MyQueue::deQueue(int& item) {
    if (rear == front) return false;
    else {
        item = queue[front];
        front = (front + 1) % capacity;
    }
    return true;
}
bool MyQueue::getFront(int& item) {
    if (rear == front) return false;
    else {
        item = queue[front];
    }
    return true;
}
bool MyQueue::isFull() {
    if (abs(rear - front) == capacity) {
        return true;
    }
    else return false;
}
int precedence(char op) {
    if (op == '+' || op == '-')return 1;
    if (op == '*' || op == '/')return 2;
    return 0;
}
bool postfixExpression(const string& infix, string& postfix) {
    if (!checkparentheses(infix) || !checksymbal(infix))
    {   
        postfix = "Expression is wrong!";
        return false;
    }
    stack<char> opStack;
    queue<char>outputQueue;
    map<char, int> precedenceMap = { {'+',1},{'-',1},{'*',2},{'/',2} };
    for (char c : infix) {
        if (isalnum(c)) {
            outputQueue.push(c);
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(') {
                opStack.pop();
            }
        }
        else {
            while (!opStack.empty() && precedenceMap[opStack.top()] >= precedenceMap[c]) {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        outputQueue.push(opStack.top());
        opStack.pop();
    }

    postfix = "";
    while (!outputQueue.empty()) {
        postfix += outputQueue.front();
        outputQueue.pop();
    }
    return true;
}
bool checksymbal(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) {
            if (i == s.size() - 1) return false; // 判断运算符是否在末尾，若是则返回false
            if (i == 0) return false; // 判断运算符是否在开头，若是则返回false
            if ((s[i + 1] - '0' < 0 || s[i + 1] - '0' > 9) && s[i + 1] != '(' && s[i + 1] != ')') return false; // 判断运算符后面是否是数字或括号
        }
    }
    return true; // 遍历结束，未发现错误，返回true
}

bool checkparentheses(string s) {
    stack<char> temp;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            temp.push('(');
        }
        else if (s[i] == ')') {
            if (temp.empty()) return false; // 如果遇到右括号但栈为空，返回false
            temp.pop(); // 匹配到一个括号对，弹出栈顶元素
        }
    }
    return temp.empty(); // 遍历结束，
}
bool applyOp(stack<int>& values, stack<char>& ops) {
    if (values.size() < 2 || ops.empty()) {
        return false;
    }

    int val2 = values.top();
    values.pop();

    int val1 = values.top();
    values.pop();

    char op = ops.top();
    ops.pop();

    if (op == '+') values.push(val1 + val2);
    else if (op == '-') values.push(val1 - val2);
    else if (op == '*') values.push(val1 * val2);
    else if (op == '/') values.push(val1 / val2);

    return true;
}

bool expressionVal(const string& infix, int& val) {
    stack<int> values;
    stack<char> ops;

    for (size_t i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ') {
            continue;
        }
        else if (isdigit(infix[i])) {
            int num = 0;
            while (i < infix.length() && isdigit(infix[i])) {
                num = num * 10 + (infix[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        }
        else if (infix[i] == '(') {
            ops.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                if (!applyOp(values, ops)) {
                    return false;
                }
            }
            ops.pop();
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(infix[i])) {
                if (!applyOp(values, ops)) {
                    return false;
                }
            }
            ops.push(infix[i]);
        }
    }

    while (!ops.empty()) {
        if (!applyOp(values, ops)) {
            return false;
        }
    }

    if (values.size() == 1) {
        val = values.top();
        return true;
    }
    else {
        return false;
    }
}

void yanghui(const int& val) {
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    int times = val;
    while (times) {
        vector<int>next;
        next.push_back(1);
        for (int i = 0; i < temp.size(); i++) {
            if (i < temp.size() - 1) {
                next.push_back(temp[i] + temp[i + 1]);
            }
            cout << temp[i] << " ";
        }
        cout << endl;
        next.push_back(1);
        temp = next;
        times--;
    }
}