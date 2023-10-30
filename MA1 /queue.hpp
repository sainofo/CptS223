#include "header.hpp"
#include "queue.hpp"

class queue{
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

    public: 
    queue(int size);
    ~queue();

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};
