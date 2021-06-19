class MyCircularDeque {
public:
    
    
    struct Node {
        int val;
        Node *next;
        Node *prev;
        
        Node(int k) {
            val = k;
            next = prev = nullptr;
        }
    };
    
    Node *front, *back;
    int maxSize;
    int size;
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        front = back = nullptr;
        maxSize = k;
        size = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        
        if (size == maxSize)
            return false;
        
        if (!front)
            front = back = new Node(value);
        else {
            Node *node = new Node(value);
            
            node->next = front;
            front->prev = node;
            
            front = node;
        }
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size == maxSize)
            return false;
        
        if (!back)
            front = back = new Node(value);
        else {
            Node *node = new Node(value);
            
            node->prev = back;
            back->next = node;
            
            back = node;
        }
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        
        if (size == 0)
            return false;
        
        if (front == back) {
            delete(front);
            front = back = nullptr;
        }
        
        else {
            
            Node *node = front;
            front = front->next;
            front->prev = nullptr;
            
            delete(node);
        }
        size--;
        return true;
        
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        
        if (size == 0)
            return false;
        
        if (front == back) {
            delete(front);
            front = back = nullptr;
        } 
        else {
            
            Node *node = back;
            back = back->prev;
            back->next = nullptr;
            
            delete(node);
        }
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        
        if (!front)
            return -1;
        
        return front->val;
        
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        
        if (!back)
            return -1;
        
        return back->val;
        
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        
        return size==0 ? true : false;
        
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        
        return size==maxSize ? true : false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
