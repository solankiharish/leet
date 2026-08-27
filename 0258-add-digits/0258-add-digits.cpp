class Solution {
public:
    int d(int n)
    {
        if(n<10) return n;
        int sum = 0;
        while(n>0)
        {
            sum += n%10;
            n /= 10;
        }
        return d(sum);
    }
    int addDigits(int num) {
        return d(num);

    }
};