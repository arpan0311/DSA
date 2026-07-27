class MedianFinder {
public:
    MedianFinder() {}
    priority_queue<int> left_side;

    priority_queue<int, vector<int>, greater<int>> right_side;
    void addNum(int num) {
        if (left_side.empty()) {
            left_side.push(num);
        } else {
            if (num >= left_side.top()) {
                right_side.push(num);

                // right_side to left side
                while (right_side.size() > left_side.size()) {
                    left_side.push(right_side.top());
                    right_side.pop();
                }
            } else {
                left_side.push(num);

                while (!left_side.empty() &&
                       left_side.size() > right_side.size() + 1) {
                    right_side.push(left_side.top());
                    left_side.pop();
                }
            }
        }
    }

    double findMedian() {
        int n = left_side.size() + right_side.size();
        if (n % 2 == 0) {
            return (left_side.top() + right_side.top()) / 2.0;
        }
        return left_side.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */