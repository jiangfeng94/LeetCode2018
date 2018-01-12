## 301. Remove Invalid Parentheses
> Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
>
>Note: The input string may contain letters other than the parentheses ( and ).
>
>在一个给定的字符串中，移除掉最少量的无效括号，从而使得这个字符串变为有效，返回所有有效的结果。 
　　注意：字符串中除了‘（’和‘）’之外，还可能有字母。
　　
```
class Solution {
public:
    char pa[2] = {'(' , ')'} ; //检测右括号是否多余
    char pa_re[2] = {')' , '('} ; //检测左括号是否多余

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans ;
        _remove(s , ans , 0 , 0 , pa) ;
        return ans ;
    }

    void _remove(string s , vector<string> &ans , int last_i , int last_j , char pa[]){
        for(int i = last_i , count = 0 ; i < s.size() ; ++i){
            if(s[i] == pa[0]) ++count ;
            if(s[i] == pa[1]) --count ;
            //直到我们找到有且仅有产生一个括号多余的情况
            if(count >= 0) continue ;
            //前面的任意一个括号都可以去掉，如果有多个连续，则默认去掉第一个
            for(int j = last_j ; j <= i ; ++j)
                if(s[j] == pa[1] && (j == last_j || s[j - 1] != pa[1]) ){
                    string newStr = s.substr(0,j) + s.substr(j+1) ;
                    _remove(newStr , ans , i , j , pa) ;
                }
            return ;
        }

        //倒转字符串
        string reversed_str ;
        reversed_str.clear() ;
        for(int i = s.size() - 1 ; i >= 0 ; --i)
            reversed_str.push_back(s[i]) ;

        //确认我们是否已经检测过左括号，如果已经检测过，则可以放入答案中，如果还没有检测则检测左括号
        if(pa[0] == '('){
            //说明还没检测过
            _remove(reversed_str , ans , 0 , 0 , pa_re) ;
        }
        else
            //已经检测过
            ans.push_back(reversed_str) ;
    }
};
```