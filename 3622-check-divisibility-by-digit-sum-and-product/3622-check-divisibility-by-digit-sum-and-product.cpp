class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int s = 0;
        int p = 1;
        while(n>0)
        {
            int a = n%10;
            s += a;
            p *= a;
            n /= 10;
        }
        int b = s+p;
        if(b==0) return 0;
        return (x%b==0);
    }
};