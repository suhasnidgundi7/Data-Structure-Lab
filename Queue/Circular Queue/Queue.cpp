#include <iostream>

class CircularQueue
{
private:
    int *data;
    int capacity;
    int front, rear;

public:
    CircularQueue(int size) : capacity(size), front(0), rear(0)
    {
        data = new int[capacity];
    }

    ~CircularQueue()
    {
        delete[] data;
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
            // Handle full queue case (e.g., throw exception or resize)
            return;
        }
        data[rear] = element;
        rear = (rear + 1) % capacity;
    }

    int dequeue()
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

    int getFront() const
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[front];
    }
};

int main()
{
    CircularQueue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    while (!queue.isEmpty())
    {
        int element = queue.dequeue();
        if (element != -1)
        {
            std::cout << element << " ";
        }
    }

    std::cout << std::endl;

    queue.enqueue(4);
    queue.enqueue(5);

    std::cout << "Front element: " << queue.getFront() << std::endl;
