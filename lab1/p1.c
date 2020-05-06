#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
void mul(int *a, int *b, int a_l, int b_l, int *c);
void minus(int *a, int *b);
int notsmaller(int *a, int *b);
int64_t mod(int *c, int *m);
int64_t multimod(int64_t a, int64_t b, int64_t m);
int64_t multimod(int64_t a1, int64_t b1, int64_t m1){
    int a[20] = {0}, b[20] = {0}, m[40] = {0}, c[40] = {0};
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(m, 0, sizeof(m));
    int a_l = 0, b_l = 0, m_l = 0;
    while(a1 > 0){
        a[a_l] = a1 % 10;
        a_l ++;
        a1 /= 10;
    }
    while(b1 > 0){
        b[b_l] = b1 % 10;
        b_l ++;
        b1 /= 10;
    }
    while(m1 > 0){
        m[m_l] = m1 % 10;
        m_l ++;
        m1 /= 10;
    }
    mul(a, b, a_l, b_l, c);
   return mod(c, m);
}
void mul(int *a, int *b, int a_l, int b_l, int *c){
    for(int i = 0; i < a_l + b_l - 1; ++i){
        for(int j = 0; j <= i; ++j){
            if(a_l > j && b_l > i - j){
                c[i] += a[j] * b[i - j];
                if(c[i] > 9){
                    c[i + 1] += c[i] / 10;
                    c[i] %= 10;
                }
            }
        }
    }
}
int notsmaller(int *a, int *b){
    for(int i = 39; i >= 0; --i){
        if(i == 0 && a[0] == b[0])  return 1;
        if(a[i] > b[i])  return 1;
        else if(a[i] < b[i])  return 0;
    }
}
int64_t mod(int *c, int *m){
    int y[40] = {0};
    for (int i = 39; i >= 0; --i) {
        for (int j = 39; j > 0; --j) {
            y[j] = y[j - 1];
        }
        y[0] = c[i];
        while(notsmaller(y, m)){
            minus(y, m);
        }
    }
    int64_t ans = 0;
    int64_t t = 1;
    for (int i = 0; i < 39; ++i) {
        ans += t * y[i];
        t *= 10;
    }
    return ans;
}
void minus(int *a, int *b){
    for (int i = 0; i < 40; ++i) {
        if(a[i] < b[i]){
            a[i + 1] --;
            a[i] += 10;
        }
        a[i] -= b[i];
    }
}
