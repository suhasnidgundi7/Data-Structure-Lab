#include <iostream>
using namespace std;

#define ARR_SIZE 100

class Stack
{
private:
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[ARR_SIZE];
        top = -1;
    }

    bool is_full()
    {
        return top == arr[ARR_SIZE] - 1;
    }

    bool is_empty()
    {
        return top == -1;
    }

    int peek()
    {
        if (is_empty() == false)
        {
            return arr[top];
        }
    }

    void pop()
    {
        if (is_empty())
        {
            cout << "No Element To Pop" << endl;
            return;
        }
    }

    void push(int element)
    {
        if (is_full())
        {
            cout << "Stack is Full" << endl;
            return;
        }

        top++;
        arr[top] = element;
    }
};

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();

    cout << stack.peek() << endl;

    return 0;
}
