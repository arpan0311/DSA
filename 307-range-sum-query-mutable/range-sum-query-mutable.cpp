class NumArray {
public:
    vector<int> seg;
    int n;

    void build_seg(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build_seg(2 * i + 1, l, mid, nums);
        build_seg(2 * i + 2, mid + 1, r, nums);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void update_seg(int i, int l, int r, int index, int val) {
        if (l == r) {
            seg[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
            update_seg(2 * i + 1, l, mid, index, val);
        else
            update_seg(2 * i + 2, mid + 1, r, index, val);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    int sum_seg(int i, int l, int r, int left, int right) {
        // No overlap
        if (r < left || l > right)
            return 0;

        // Complete overlap
        if (left <= l && r <= right)
            return seg[i];

        // Partial overlap
        int mid = l + (r - l) / 2;

        return sum_seg(2 * i + 1, l, mid, left, right) +
               sum_seg(2 * i + 2, mid + 1, r, left, right);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);

        build_seg(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        update_seg(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return sum_seg(0, 0, n - 1, left, right);
    }
};