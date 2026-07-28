class Solution {
public:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    unordered_map<int, int> delayed;

    int leftSize = 0;
    int rightSize = 0;

    void pruneLeft() {
        while (!left.empty() && delayed[left.top()]) {
            delayed[left.top()]--;
            left.pop();
        }
    }

    void pruneRight() {
        while (!right.empty() && delayed[right.top()]) {
            delayed[right.top()]--;
            right.pop();
        }
    }

    void balance() {

        if (leftSize > rightSize + 1) {
            right.push(left.top());
            left.pop();
            leftSize--;
            rightSize++;
            pruneLeft();
        }

        else if (leftSize < rightSize) {
            left.push(right.top());
            right.pop();
            leftSize++;
            rightSize--;
            pruneRight();
        }
    }

    void add(int x) {

        if (left.empty() || x <= left.top()) {
            left.push(x);
            leftSize++;
        } else {
            right.push(x);
            rightSize++;
        }

        balance();
    }

    void remove(int x) {

        delayed[x]++;

        if (x <= left.top()) {
            leftSize--;

            if (x == left.top())
                pruneLeft();
        } else {
            rightSize--;

            if (!right.empty() && x == right.top())
                pruneRight();
        }

        balance();
    }

    double median(int k) {

        pruneLeft();
        pruneRight();

        if (k & 1)
            return left.top();

        return ((double)left.top() + right.top()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            add(nums[i]);

            if (i >= k)
                remove(nums[i - k]);

            if (i >= k - 1)
                ans.push_back(median(k));
        }

        return ans;
    }
};