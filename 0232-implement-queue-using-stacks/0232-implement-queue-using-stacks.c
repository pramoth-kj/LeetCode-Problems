typedef struct {
    int* arr;
    int front;
    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *obj=(MyQueue*)malloc(sizeof(MyQueue));
    obj->arr=(int*)malloc(sizeof(int)*100);
    obj->front=-1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj == NULL) return;
    /*if(obj->front==-1){
        ++obj->front;
    }*/
    obj->arr[++obj->front]=x;
}

int myQueuePop(MyQueue* obj) {
    if(obj == NULL) return NULL;
    int ele = obj->arr[0];
    for(int i = 0; i < obj->front; i++){
        obj->arr[i] = obj->arr[i+1];
    }
    obj->front -= 1;
    return ele;
}

int myQueuePeek(MyQueue* obj) {
    if(obj == NULL) return NULL;
    return obj->arr[0];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj == NULL) return false;
    return obj->front==-1;
    
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
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