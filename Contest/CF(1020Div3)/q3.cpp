#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n>>k;
        vector<int> a, b;
        for (int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            b.push_back(temp);
        }

        int x = -1, sum;
        bool flag = true;

        for (int i = 0; i < n; i++) {
            if(b[i] != -1) {
                x = a[i] + b[i];
                if(flag == true){
                    sum = x;
                    flag = false;
                }
                if(x != sum){
                    x = -2;
                    break;
                }
            }
        }

        int res=0;
        if (x == -1){
            int minInA = *min_element(a.begin(), a.end());
            int maxInA = *max_element(a.begin(), a.end());

            int maxValPossible = minInA + (k+1);
            res = maxValPossible - maxInA;
        }
        else if(x>-1) {
            bool valid = true;
            for (int i = 0; i < n; i++){
                if(x - a[i] >k || x-a[i]<0){
                    valid = false;
                    break;
                }
            }
            if(valid)
                res = 1;
        }

        cout << res << endl;
    }

    return 0;
}

// clang++ -o q3 q3.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)

// 7
// 3 10
// 1 3 2
// -1 -1 1

// 5 1
// 0 1 0 0 1
// -1 0 1 0 -1

// 5 1
// 0 1 0 0 1
// -1 1 -1 1 -1

// 5 10
// 1 3 2 5 4
// -1 -1 -1 -1 -1

// 5 4
// 1 3 2 1 3
// 1 -1 -1 1 -1

// 5 4
// 1 3 2 1 3
// 2 -1 -1 2 0

// 5 5
// 5 0 5 4 3
// 5 -1 -1 -1 -1



// 1
// 0
// 0
// 7
// 0
// 1
// 0
