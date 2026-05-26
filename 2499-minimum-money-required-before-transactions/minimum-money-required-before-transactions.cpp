class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {

        long long loss = 0;
        int maxi = 0;
        // yahan pe sorting krne ke liye koi order hi ni ban ra
        // one thing phale sara loss kraliya uske bad profit milne pe case back
        // ni add kara kyoki sorting us way m ho ni sakti profit wali
        // transaction mil rahi to avoid karo iske profit ko...
        for (int i = 0; i < transactions.size(); i++) {

            if (transactions[i][0] > transactions[i][1]) {

                loss += (transactions[i][0] - transactions[i][1]);

                // keep maximum cashback
                maxi = max(maxi, transactions[i][1]);
            }

            // profitable or equal transaction
            else {

                // keep maximum cost
                maxi = max(maxi, transactions[i][0]);
            }
        }

        return loss + (long long)maxi;
    }
};