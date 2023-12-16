#include <iostream>

class Deque
{
private:
    int *data;
    int capacity;
    int front, rear;

public:
    Deque(int size) : capacity(size), front(0), rear(capacity - 1)
    {
        data = new int[capacity];
    }

    ~Deque()
    {
        delete[] data;
    }

    bool isEmpty() const
    {
        return front == rear;
    }

    bool isFull() const
    {
        return (front + 1) % capacity == rear;
    }

    void pushFront(int element)
    {
        if (isFull())
        {
            // Handle full queue case (e.g., throw exception or resize)
            return;
        }
        front = (front - 1 + capacity) % capacity;
        data[front] = element;
    }

    void pushBack(int element)
    {
        if (isFull())
        {
            // Handle full queue case
            return;
        }
        data[rear] = element;
        rear = (rear + 1) % capacity;
    }

    int popFront()
    {
        if (isEmpty())
        {
            // Handle empty queue case
            return -1;
        }
        int value = data[front];
        front = (front + 1) % capacity;
        return value;
    }

    int popBack()
    {
        if (isEmpty())
        {
            // Handle empty queue case
            return -1;
        }
        int value = data[rear];
        rear = (rear - 1 + capacity) % capacity;
        return value;
    }
};

int main()
{
    Deque dequeue(5);
    dequeue.pushFront(1);
    dequeue.pushBack(2);
    dequeue.pushFront(3);
    dequeue.pushBack(4);

    while (!dequeue.isEmpty())
    {
        int element = dequeue.popFront();
        if (element != -1)
        {
            std::cout << element << " ";
        }
    }

    std::cout << std::endl;

    dequeue.pushBack(5);
    dequeue.pushFront(6);

    while (!dequeue.isEmpty())
    {
        int element = dequeue.popBack();
        if (element != -1)
        {
            std::cout << element << " ";
        }
    }

    return 0;
}
