#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int initCount = 0, res = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                initCount++;
            }
        }

        for (int i = 0; i < n; i++) {
            if(s[i] == '1'){
                res += initCount - 1;
            }
            else
                res += initCount + 1;
        }
        cout << res << endl;
    }

    return 0;
}

// clang++ -o q1 q1.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)