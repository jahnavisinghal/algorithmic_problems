// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n < 2) {
            return n; 
        }
        int st = 1, en = n, mid;
        while(st <= en) {
            mid = st+(en-st)/2;
            bool bad = isBadVersion(mid);
            if(st == en) {
                if(bad) {
                    return st;
                } else if(en < n) {
                    return en+1;
                } else {
                    return -1;
                }
            }
            if(bad) {
                if(mid == st) {
                    return st;
                }
                en = mid-1;
            } else {
                st = mid+1;
            }
        }
        return -1;
    }
};
