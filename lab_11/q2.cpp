#include <iostream>
#include <stdexcept>
using namespace std;

class QueueOverflowException : public exception{};
class QueueUnderflowException : public exception{};

template <typename T>
class Queue
{
    private:
        T* data;
        int capacity;
        int current;

    public:
        Queue(int capacity) : capacity(capacity), current(0)
        {
            data = new T[capacity];
        }

        void enqueue(T value)
        {
            if (current >= capacity)
            {
                throw QueueOverflowException();
            }
            data[current++] = value;
            cout << "Element added successfully.\n";
        }

        void dequeue()
        {
            if (current <= 0)
            {
                throw QueueUnderflowException();
            }
            for (int i = 0; i < current - 1; i++)
            {
                data[i] = data[i + 1];
            }
            current--;
            cout << "Element removed from queue.\n";
        }

        ~Queue()
        {
            delete[] data;
        }
};

int main()
{
    Queue<int> q(2);

    try
    {
        q.enqueue(10);
        q.dequeue();
        q.enqueue(20);
        q.enqueue(30);
        cout << "Trying to add another element to a full queue...\n";
        q.enqueue(40);
    }
    catch (QueueOverflowException& e)
    {
        cout << "QueueOverflowException caught: " << e.what() << endl;
    }

    try
    {
        q.dequeue();
        q.dequeue();
        cout << "Trying to remove from an empty queue...\n";
        q.dequeue();
    }
    catch (QueueUnderflowException& e)
    {
        cout << "QueueUnderflowException caught: " << e.what() << endl;
    }

    return 0;
}
