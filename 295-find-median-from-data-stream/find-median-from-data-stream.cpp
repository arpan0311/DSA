class MedianFinder {
public:
    priority_queue<int> pq1; // max heap by default
    priority_queue<int, vector<int>, greater<int>>
        pq2; // smallest element at top
    MedianFinder() {}

    void addNum(int num) {
        if (pq1.empty() || num <= pq1.top()){
            pq1.push(num);
        }
        else{
            pq2.push(num);
        }

        // pq1.size()-pq2.size()>1
        if(abs((int)pq1.size()-(int)pq2.size())>1){
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if(pq1.size()<pq2.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    double findMedian() {
        double ans = 0;
        if ((pq1.size() + pq2.size()) % 2 != 0) {
            ans = pq1.top();
        } else {
            if (!pq1.empty() && !pq2.empty()) {
                ans = (pq1.top() + pq2.top()) / 2.0;
            }
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */