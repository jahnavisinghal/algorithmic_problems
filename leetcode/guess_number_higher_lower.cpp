nt guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(n < 1) {
            return n;
        }
        int st = 1, en = n, mid;
        while(st <= en) {
            mid = st+(en-st)/2;
            //cout << "\n mid " << mid;
            int result = guess(mid);
            if(!result) {
                return mid;
            } else if(result == -1) {
                en = mid-1;
            } else {
                st = mid+1;
            }
        }
        return -1;
    }
};
