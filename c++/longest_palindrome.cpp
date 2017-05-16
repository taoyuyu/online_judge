/*
解题思路
1.以一个字符为中心向两边拓展：复杂度O(n^2)；考虑回文为偶数的情况；
2.拓展KMP：复杂度O(n*logn)；
3.manacher算法。
manacher算法：复杂度O(n) ，
manacher算法流程：
1）在相邻字符串中间插入特殊字符串，例如：abcacf => #a#b#c#a#c#f#
2）定义一个数组p[2*n+1]；其中p[i]记录以S[i]为中心最长回文子串向左/右扩张的长度；
    例如：
    S：# a # b # b # c # a # c # f #
    P：1 2 1 2 3 2 1 2 1 4 1 2 1 2 1
p[i]求解方法：设置辅助变量id，mx，id为已知右边界最大的回文子字符串的中心索引，mx为id+P[id]，也就是这个字符串的右边界。
    结论：
    if( mx - i > p[j] ){
            p[i] = p[j]；
    } else {
            p[i] = mx - i;
    }
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 100001;
int len, p[2*MAX];
char str[2*MAX], newstr[2*MAX];

void change()
{
    int i;
    newstr[0] = '@';
    newstr[1] = '#';
    for (i = 0; i < len; i++){
        newstr[2*i + 2] = str[i];
        newstr[2*i + 3] = '#';
    }
    newstr[2*len + 2] = '\0';
    return ;
}

void Manacher()
{
    int i, j, id, maxid = 0, ans = 1;
    len = 2 * len + 2;
    for (i = 0; i < len; i++){
        if (maxid > i){
            p[i] = min(p[2*id - i], maxid - i);
        }
        else{
            p[i] = 1;
        }
        while (newstr[i+p[i]] == newstr[i-p[i]])
            p[i]++;
        if (p[i] + i > maxid){
            maxid = p[i] + i;
            id = i;
        }
        if (ans < p[i])
            ans = p[i];
    }

    for (i = id, j = 0; i < id + ans; i++){
        if (newstr[i] != '#'){
            str[j] = newstr[i];
            j++;
        }
    }
    str[id+ans] = '\0';
    cout << ans - 1 << " " << str << endl;
    return ;
}

int main()
{
    while (scanf("%s", &str)){
        if (strcmp(str, "END") == 0)   break;
        len = strlen(str);
        change();
        Manacher();
    }
}
