/*
设Xn={x1,x2,x3,…,xn}，Ym={y1,y2,y3,…,ym}的最长公共子序列为Zk={z1,z2,z3,…,zk}，则：
    1）若xm == yn，则zk＝xm＝yn且Zk-1是Xn-1和Ym-1的最长公共子序列；
    2）若xm != yn，且zk != xn，则Zk是Xn-1和Ym的最长公共子序列；
    3）若xm != yn，且zk != ym，则Zk是Xn和Ym-1的最长公共子序列；
建立递推关系式：
    c[i][j] = :
    1）0; i = 0, j = 0;
    2）c[i-1][j-1]+1; xi == yj;
    3）max(c[i-1][j], c[i][j-1]); xi != yj
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int LCS(int i, int j, char* a, char *b, size_t m, size_t n);
int c[100][100];
int _count = 0;
int main(int argc, const char * argv[]) {
    char *a = "abcdpefgaaaaaaaaaaaaaadaaaaaasaaaafaaaaafga";
    char *b = "ambpppcivpgfffffffffggggggggggggggggggggggg";
    size_t m = strlen(a);
    size_t n = strlen(b);

    //int c[m][n];
    for (int i = 0; i <= m; ++i){
        for(int j = 0; j <= n ; ++j){
            if(i == 0 || j == 0){
                c[i][j] = 0;
            } else {
                c[i][j] = -1;
            }
        }
    }
    cout << LCS(m, n, a, b, m, n) << endl;
}
int LCS(int i,int j,char* a, char* b, size_t m, size_t n){
    _count ++;
    if(a[i] == b[j]){
        c[i][j] = c[i-1][j-1] == -1 ? 1+LCS(i-1,j-1,a,b,m,n) : 1+c[i-1][j-1];
    } else {
        int x = c[i-1][j];
        int y = c[i][j-1];
        if (x == -1 && y == -1){
            c[i][j] = LCS(i-1, j, a, b, m, n) > LCS(i, j-1, a, b, m, n) ? LCS(i-1, j, a, b, m, n) : LCS(i, j-1, a, b, m, n);
        } else if ( x == -1) {
            c[i][j] = LCS(i-1, j, a, b, m, n) > y ? LCS(i-1, j, a, b, m, n) :y;

        } else if ( y == -1) {
            c[i][j] = x > LCS(i, j-1, a, b, m, n)? x:LCS(i, j-1, a, b, m, n);
        } else {
            c[i][j] = x > y ? x : y;
        }
    }
    return c[i][j];
}
