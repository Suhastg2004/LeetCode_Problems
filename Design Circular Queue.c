#include <stdlib.h>

typedef struct MyCircularQueue {
    int *data;
    int head;
    int tail;
    int size;
    int capacity;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * k);
    obj->head = obj->tail = 0;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

/** Inserts an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) {
        return false;
    }
    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;
    return true;
}

/** Deletes an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return false;
    }
    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;
    return true;
}

/** Get the front item from the queue. If the queue is empty, return -1. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->data[obj->head];
}

/** Get the last item from the queue. If the queue is empty, return -1. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->data[(obj->tail - 1) % obj->capacity];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

/** Free the space allocated for the circular queue. */
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}
