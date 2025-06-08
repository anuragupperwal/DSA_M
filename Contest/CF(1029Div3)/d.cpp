#include<vector>
#include<iostream>

using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int64> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        // Solve for x and y using positions i=1 and i=2:
        // a[1] = x*1 + y*n
        // a[2] = x*2 + y*(n-1)
        // => y = (2*a[1] - a[2]) / (n+1)
        int64 num = 2*a[1] - a[2];
        int64 den = n + 1;

        // Check divisibility and non-negativity
        if(num < 0 || num % den != 0){
            cout << "NO\n";
            continue;
        }
        int64 y = num / den;
        int64 x = a[1] - y * n;
        if(x < 0){
            cout << "NO\n";
            continue;
        }

        // Verify for all i: a[i] == x*i + y*(n-i+1)
        bool ok = true;
        for(int i = 1; i <= n; i++){
            int64 expected = x * i + y * (n - i + 1);
            if(a[i] != expected){
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}

// clang++ -o d d.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)

// 6
// 4
// 3 6 6 3
// 5
// 21 18 15 12 9
// 10
// 2 6 10 2 5 5 1 2 4 10
// 7
// 10 2 16 12 8 20 4
// 2
// 52 101
// 2
// 10 2


// NO
// YES
// NO
// NO
// YES
// NO
