#include <iostream>

class PriorityQueue
{
private:
    int *data;
    int capacity;
    int size;

    void heapifyUp(int idx)
    {
        while (idx > 0 && data[idx] > data[(idx - 1) / 2])
        {
            std::swap(data[idx], data[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void heapifyDown(int idx)
    {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        while (left < size)
        {
            int largest = idx;
            if (left < size && data[left] > data[largest])
            {
                largest = left;
            }
            if (right < size && data[right] > data[largest])
            {
                largest = right;
            }
            if (largest == idx)
            {
                break;
            }
            std::swap(data[idx], data[largest]);
            idx = largest;
        }
    }

public:
    PriorityQueue(int size) : capacity(size), size(0)
    {
        data = new int[capacity];
    }

    ~PriorityQueue()
    {
        delete[] data;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    void push(int element)
    {
        if (size == capacity)
        {
            // Handle full queue case
            return;
        }
        data[size] = element;
        heapifyUp(size);
        size++;
    }

    int pop()
    {
        if (isEmpty())
        {
            // Handle empty queue case
            return -1;
        }
        int highest = data[0];
        data[0] = data[size - 1];
        size--;
        heapifyDown(0);
        return highest;
    }
};
