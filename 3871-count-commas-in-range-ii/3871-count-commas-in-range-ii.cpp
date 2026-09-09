class Solution {
public:
    long long countCommas(long long n) {
       long count = 0 ;
       long p = 1000;

        while (p <= n){
            count += n - p + 1;
            p *= 1000;
        }
        return count;
    }
};