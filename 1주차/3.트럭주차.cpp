#include <bits/stdc++.h>
using namespace std;
int A, B, C, a, b, cnt[104], ret;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>> A >> B >> C;
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        for(int j = a;j < b; j++) cnt[j]++;
    }
    for(int i = 1; i < 100; i++){
        if(cnt[i]){
            if(cnt[i] == 1) ret += A;
            else if(cnt[i] == 2) ret += B * 2;
            else if(cnt[i] == 3) ret += C * 3;
        }
    }
    cout << ret << '\n';
    return 0;
}

/*
1. cnt배열을 이용하여 
2. 
*/