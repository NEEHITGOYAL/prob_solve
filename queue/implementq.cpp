#include<bits/stdc++.h>
using namespace std;

//queue implementation using array
class Queue{
public:
    int front,rear,size;
    unsigned capacity;
    int* arr;
};

Queue* create(unsigned capacity){
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity-1;
    queue->arr = new int[queue->capacity];
    return queue;
}

bool isFull(Queue* queue){
    return (queue->size == queue->capacity);
}

bool isempty(Queue* queue){
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}
 
// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* queue)
{
    if (isempty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Function to get front of queue
int front(Queue* queue)
{
    if (isempty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}
 
// Function to get rear of queue
int rear(Queue* queue)
{
    if (isempty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}

}