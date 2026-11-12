class MyCircularDeque {
private:
    vector<int> data;
    int frontIdx;
    int count;
    int capacity;

public:
    MyCircularDeque(int k) : data(k), frontIdx(0), count(0), capacity(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        frontIdx = (frontIdx - 1 + capacity) % capacity;
        data[frontIdx] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        data[(frontIdx + count) % capacity] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        count--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : data[frontIdx];
    }

    int getRear() {
        return isEmpty() ? -1 : data[(frontIdx + count - 1) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
