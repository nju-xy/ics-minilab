#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int64_t multimod(int64_t a, int64_t b, int64_t m);
int64_t multimod(int64_t a, int64_t b, int64_t m){
    u_int64_t a_mod_m[64];
    int b1[64];
    for(int i = 0; i < 64; ++i){
        b1[i] = (b >> i) & 1;
    }
    a_mod_m[0] = a % m;
    for (int i = 1; i < 64; ++i) {//求（a*2^i）% m的值（必定小于2^63所以即使乘以2也不会溢出）
        a_mod_m[i] = (a_mod_m[i - 1] << 1) % m;
    }
    u_int64_t ans = 0;
    for(int i = 0;i < 64; ++i){
        if(b1[i] == 1){
            ans = (ans + a_mod_m[i]) % m;//ans和a_mod_m[i]必定小于2^63, 所以相加之后不会溢出
        }
    }
    return ans;
}
