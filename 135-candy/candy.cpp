class Solution {
public:
    int candy(vector<int>& ratings) {
        // prefix and suffix waala concept hai pahle left ke hisab se fir right ke hisab se simple....
       int n = ratings.size();
    if (n == 0) return 0;
// sabko 1 se initially le liya so let karna ki need na ho
    vector<int> left(n, 1); 
    int sum = 0;            
    int right = 1;        

    
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
        // else condition skip karte hai kyoki sabko 1 hi le liya
    }

   
    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1 && ratings[i] > ratings[i + 1]) {
            right++;
        } else {
            right = 1;
        }
        sum += max(left[i], right);
    }

    return sum;

    }
};