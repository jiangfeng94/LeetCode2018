# 214. Shortest Palindrome
> Given "aacecaaa", return "aaacecaaa".  
> Given "abcd", return "dcbabcd".
> 特别需要注意 “aaba” return "aabaa"

## 我写的代码
```
string stortestPalindrome(string s){
        int size = s.length();
        int end =s.length()-1;
        int i=0,j=end;
        string tmp ="";
        while (i<j){
                if(s[i] == s[j]) {
                        i++;
                        j--;
                }
                else{
                        i=0;
                        end--;
                        j =end;
                }

        }
        string out="";
        for(int k=size+1;k>end;k--){
                out =out +s[k];
        }
        for(int k =0;k<size;k++){
                out =out + s[k];
        }
        return out;
}
```

结果：
>  Time Limit Exceeded   
>  Last exexuted input : "aaaaaaaaaaaaaaaaaaaaaaaaaaaa"

## 网上提供的优秀解法

```
    string shortestPalindrome(string s) {
        string str =s;
        reverse(str.begin(),str.end());
        str =s + '#' +str;
        int len1 =s.length(), len2 =str.length();
        vector<int> vec(len2,0);
        for(int i=1;i<len2;i++){
            int k =vec[i-1];
            while(k>0 && str[k] != str[i]) k =vec[k-1];
            vec[i] = (k+=str[i] ==str[k]);
        }
        return str.substr(len1+1,len1-vec[len2-1])+s;
    }
```