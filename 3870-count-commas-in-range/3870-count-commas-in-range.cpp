class Solution {
public:
    int countCommas(int n) {
        if(n<999) return 0;
        if(n>999 and n<=100000) return n-999;
        return 0;
    }
};