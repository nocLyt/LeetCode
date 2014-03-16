#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <deque>
#include <assert.h>
//
using namespace std;



class Solution {
public:
    void rever(string &s, int l, int r){
        for(int i=l, j= r; i<=j; i++,j--){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    void init(string &s){
        // 删去头部的空格
        while( s.length()>0 && s[0]==' ')
            s.erase(s.begin());
        // 删去尾部的空格
        bool flag = false;
        string::iterator l = s.begin(), r = s.begin();
        for(string::iterator it=s.begin(); it!=s.end(); ++it){
            if ((*it)==' '){
                if (flag){
                    ++r;
                } else {
                    flag = true;
                    l = r = it;
                }
            } else {
                flag = false;
            }
        }
        if (flag){
            s.erase(l,++r);
        }
        if (s.length() == 0)
            return;
        // 单词间可能有多个连续的空格
        string str = "";
        str.push_back(s[0]);
        for(int i=1; i<(int)s.length(); i++){
            if (s[i]==' ' && s[i-1]==s[i])
                continue;
            str.push_back(s[i]);
        }
        s = str;

    }
    void reverseWords(string &s) {
        if (s.length()<1)   return;
        init(s);
        // cout<<"+"<<s<<"+"<<endl;
        int len = s.length();
        rever(s,0,len-1);
        int l=0,r;
        bool flag = false;
        for( r=-1;r<len;r++){
            if ( s[r]==' ' ){
                rever(s, l, r-1);
                l = -1;
            } else {
                if (s[l]==-1)
                    l = r;
            }
        }
        rever(s, l, r-1);
    }
};

int main(){
    string str = "   a   b ";
    Solution sol;
    sol.reverseWords(str);
    cout<<"-"<<str<<"-"<<endl;
}

