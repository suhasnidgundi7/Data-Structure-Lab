#include <iostream>

class Queue
{
private:
    int *arr;
    int capacity;
    int front, rear;

public:
    Queue(int size) : capacity(size), front(0), rear(0)
    {
        arr = new int[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return front == rear;
    }

    bool isFull() const
    {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            // Handle full queue case (e.g., throw exception)
            return;
        }
        arr[rear] = element;
        rear = (rear + 1) % capacity;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            // Handle empty queue case (e.g., throw exception)
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        return value;
    }
};

int main()
{
    Queue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    while (!queue.isEmpty())
    {
        int element = queue.dequeue();
        std::cout << element << " ";
    }

    return 0;
}
