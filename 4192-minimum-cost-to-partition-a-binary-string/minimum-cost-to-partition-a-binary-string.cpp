typedef long long ll;

class Solution {
public:
    ll enc, flat ;
    vector<int> pref ;
    string t ; 

    ll dfs( int l, int r ) {
        int len = r - l + 1 ; 
        int ones = pref[r+1] - pref[l] ;

        ll cost ;
        if( ones == 0) cost = flat ; 
        else cost = 1LL * len * ones * enc ; 

        if( len % 2 == 0 ) {
            int mid = ( l + r ) / 2 ; 
            cost = min( cost, dfs(l, mid ) + dfs( mid + 1, r ) ) ; 
        }

        return cost; 
    };

    long long minCost(string s, int encCost, int flatCost) {
        t = s ; 
        enc = encCost ;
        flat = flatCost ; 

        int n = s.size() ;

        pref.assign(n+1, 0 ) ;
        for( int i = 0 ; i < n ; i++ ) pref[i+1] = pref[i] + ( s[i] == '1' ) ; 
        return dfs(0, n-1 ) ; 
    }
};