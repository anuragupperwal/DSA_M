#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> doors;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            doors.push_back(a);
        }

        int firstOne=-1, lastOne=-1;
        for (int i = 0; i < n; i++) {
            if(doors[i] == 1) {
                if(firstOne == -1) {
                    firstOne = i+1;
                    lastOne = i+1;
                }
                else
                    lastOne = i+1;
            }
        }

        // cout << firstOne << " " << lastOne << " "<<x<<endl;
        if ((lastOne - firstOne+1) > x)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}

// clang++ -o a a.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)

// 7
// 4 2
// 0 1 1 0
// 6 3
// 1 0 1 1 0 0
// 8 8
// 1 1 1 0 0 1 1 1
// 1 2
// 1
// 5 1
// 1 0 1 0 1
// 7 4
// 0 0 0 1 1 0 1
// 10 3
// 0 1 0 0 1 0 0 1 0 0


// YES
// NO
// YES
// YES
// NO
// YES
// NO
