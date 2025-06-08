#include <iostream>
#include <vector>
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
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        // 1) Compute last occurrence of each value.
        vector<int> last(n+1, -1);
        for(int i = 0; i < n; i++){
            last[a[i]] = i;
        }

        // 2) Greedily cut whenever we've reached the max last index
        //    of all values seen so far.
        int segments = 0;
        int max_last = 0;
        for(int i = 0; i < n; i++){
            max_last = max(max_last, last[a[i]]);
            if(i == max_last){
                segments++;
            }
        }

        cout << segments << "\n";
    }

    return 0;
}
// clang++ -o c c.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)

// 8
// 6
// 1 2 2 3 1 5
// 8
// 1 2 1 3 2 1 3 2
// 5
// 5 4 3 2 1
// 10
// 5 8 7 5 8 5 7 8 10 9
// 3
// 1 2 2
// 9
// 3 3 1 4 3 2 4 1 2
// 6
// 4 5 4 5 6 4
// 8
// 1 2 1 2 1 2 1 2

// 2
// 3
// 1
// 3
// 1
// 3
// 3
// 4
