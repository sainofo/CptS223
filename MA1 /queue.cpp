#include "header.hpp"
#include "queue.hpp"

queue::queue(int size){
    arr = new int[size];
    capacity = size;
    front = 0;
     rear = -1;
     count = 0;
}

queue::~queue(){
    delete arr;
}

void queue::dequeue(){
    if(isEmpty()){
        cout << "UnderFlow\nProgram Terminated\n"<<endl;
        return;
    }
    cout << "Removing " << arr[front] << '\n' <<endl;

    front = (front + 1) % capacity;
    count--;
}

void queue::enqueue(int x){
    if(isFull()){
        cout << "OverFlow\nProgram Terminated\n" << endl;
        return;
    }
    cout << "Inserting " << x << '\n' <<endl;

    rear = (rear + 1) % capacity;
    arr[rear] = size();
    count++;
}

int queue::peek(){
    if(isEmpty()){
        cout << "UnderFlow\nProgram Terminated\n" << endl;
        return;
    }
    return arr[rear];
}

int queue::size(){
    return count + 1;
}

bool queue:: isEmpty(){
    return (size() == 0);
}

bool queue:: isFull(){
    return (size() - 1 == capacity);
}
