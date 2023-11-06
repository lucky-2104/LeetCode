class SeatManager {

private:
    int next;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    SeatManager(int n) {
        next = 1;
    }

    int reserve() {
        if (!heap.empty() && heap.top() < next) {
            int reservedSeat = heap.top();
            heap.pop();
            return reservedSeat;
        }

        next++;
        return next - 1;
    }

    void unreserve(int seatNumber) {
        heap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */