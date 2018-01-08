> Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

> For example:  
> Given n = 13,  
> Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
## 思路一：暴力递归   Runtime Error
```c++
class Solution {
public:
    int panduan(int n){
        int out =0;
        while(n){
            if(n%10==1) out++;
            n =n/10;
        }
        return out;
    }
    int countDigitOne(int n) {
        if(n<=0) return 0;
        return countDigitOne(n-1)+panduan(n);
    }
};

```

## 思路二：枚举找规律
不难发现，100以内的数字，10-19之间有11个1之外，其余都只有一个1.比如56就有(5+1)+10=16个

```
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long k = 1; k <= n; k *= 10) {
            long r = n / k, m = n % k;
            res += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
        }
        return res;
    }
};
```

```
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0, a = 1, b = 1;
        while (n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};
```