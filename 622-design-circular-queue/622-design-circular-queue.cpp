class MyCircularQueue {
private:
    int *queue;
    int n;
    int front = -1;
    int rear =-1;

public:
    
    MyCircularQueue(int k) {
        queue = new int[k]; 
        n = k;
    }
    
    ~MyCircularQueue(){
        delete [] queue;
        queue = NULL;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()) front=rear=0;
        else rear = (rear+1)%n;
        queue[rear%n] = value;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front==rear) front=rear=-1;
        else front = (front+1)%n;
        return true;
    }
    
    int Front() {
        if(front==-1) return -1;
        return queue[front%n];
    }
    
    int Rear() {
        if(rear==-1) return -1;
        return queue[rear%n];
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(front==(rear+1)%n) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */