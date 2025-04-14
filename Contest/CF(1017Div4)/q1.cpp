#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t>0)
    {
        string s, res;
        getline(cin, s);
        res += s[0];
        for (int i = 1; i < s.length(); i++)
        {
            if(s[i] == ' ' && i+1<s.length())
                res += s[i + 1];
        }
        t--;
        cout << res << endl;
    }

    return 0;
}

// clang++ -o q1 q1.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)

// 7
// united states america
// oh my god
// i cant lie
// binary indexed tree
// believe in yourself
// skibidi slay sigma
// god bless america

// usa
// omg
// icl
// bit
// biy
// sss
// gba
