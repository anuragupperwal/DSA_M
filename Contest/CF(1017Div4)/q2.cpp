#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l, r, resA, resB;
        cin >> n >> m >> l >> r;
        int diff = n - m;
        if( diff-abs(l) >=0 ){
            resA = 0;
            resB = r - (diff - abs(l));
        }
        else {
            resA = diff - abs(l);
            resB = r;
        }

        cout << resA << " " << resB<<endl;
    }
    return 0;
}

// clang++ -o q2 q2.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)
