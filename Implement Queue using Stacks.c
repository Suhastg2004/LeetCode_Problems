
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int stack1[MAX_SIZE];  // Stack for enqueue operation
    int top1;              // Top of stack1
    int stack2[MAX_SIZE];  // Stack for dequeue operation
    int top2;              // Top of stack2
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;  // Push element to stack1
}

int myQueuePop(MyQueue* obj) {
    // If stack2 is empty, transfer elements from stack1 to stack2
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    // Pop element from stack2
    return obj->stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    // If stack2 is empty, transfer elements from stack1 to stack2
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    // Return the top element of stack2 (front of the queue)
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    // If both stacks are empty, the queue is empty
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
