typedef struct {
    int *requests;  // Array to store requests
    int front;      // Front of the queue
    int rear;       // Rear of the queue
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->requests = (int*)malloc(10000 * sizeof(int)); // Assuming maximum number of requests
    obj->front = 0;
    obj->rear = -1;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    // Add the new request to the queue
    obj->requests[++obj->rear] = t;
    
    // Remove requests older than 3000 milliseconds
    while (obj->requests[obj->front] < t - 3000)
        obj->front++;
    
    // Return the number of requests within the last 3000 milliseconds
    return obj->rear - obj->front + 1;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->requests);
    free(obj);
}
/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
