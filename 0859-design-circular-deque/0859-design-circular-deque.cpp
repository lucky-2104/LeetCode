class MyCircularDeque {
public:
    vector<int> ans;  // make ans a class member
    int end = -1;     // pointer to the last element
    MyCircularDeque(int k) {
        ans.resize(k, -1);  // initialize vector with size k
    }

    bool insertFront(int value) {
        int k = ans.size();
        if (end < k - 1) {
            for (int i = end; i >= 0; i--) {
                ans[i + 1] = ans[i];  // shift elements right
            }
            ans[0] = value;
            end++;
            return true;
        }
        return false;
    }

    bool insertLast(int value) {
        int k = ans.size();
        if (end < k - 1) {
            end++;
            ans[end] = value;
            return true;
        }
        return false;
    }

    bool deleteFront() {
        if (end >= 0) {
            for (int i = 0; i < end; i++) {
                ans[i] = ans[i + 1];  // shift elements left
            }
            ans[end] = -1;
            end--;
            return true;
        }
        return false;
    }

    bool deleteLast() {
        if (end >= 0) {
            ans[end] = -1;
            end--;
            return true;
        }
        return false;
    }

    int getFront() {
        if (end >= 0) {
            return ans[0];
        }
        return -1;  // return -1 if deque is empty
    }

    int getRear() {
        if (end >= 0) {
            return ans[end];
        }
        return -1;  // return -1 if deque is empty
    }

    bool isEmpty() {
        return end == -1;
    }

    bool isFull() {
        return end == ans.size() - 1;
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