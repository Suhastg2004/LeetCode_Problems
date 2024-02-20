#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *ans;
} MyHashMap;

MyHashMap* myHashMapCreate() {
    MyHashMap *obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    obj->ans = (int*)malloc(1000001 * sizeof(int));
    for (int i = 0; i < 1000001; i++) {
        obj->ans[i] = -1;
    }
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->ans[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->ans[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->ans[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->ans);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
