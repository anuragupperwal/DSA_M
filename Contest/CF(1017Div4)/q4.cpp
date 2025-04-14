#include<iostream>
#include<vector>

using namespace std;

bool solve(){
        string p, s;
        cin >> p;
        cin >> s;
        vector<pair<char, int> > given, maxOut;

        int count = 1;
        char c = p[0];
        for (int i = 1; i < p.length(); i++){
            if(p[i] != c) {
                given.push_back(make_pair(c, count));
                c = p[i];
                count = 1;
            }
            else{
                count++;
            }
        }
        given.push_back(make_pair(c, count));

        c = s[0];
        count = 1;
        for (int i = 1; i < s.length(); i++){
            if(s[i] != c) {
                maxOut.push_back(make_pair(c, count));
                c = s[i];
                count = 1;
            }
            else{
                count++;
            }
        }
        maxOut.push_back(make_pair(c, count));

        if(given.size() != maxOut.size()){
            return false;
        }

        for (int i = 0; i < given.size(); i++) {
            if(given[i].first != maxOut[i].first)
                return false;
            else if (given[i].second * 2 < maxOut[i].second || given[i].second > maxOut[i].second)
                return false;
        }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        bool res = solve();
        if(res)
            cout<<"YES"<<endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// clang++ -o q4 q4.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)


// 5
// R
// RR
// LRLR
// LRLR
// LR
// LLLR
// LLLLLRL
// LLLLRRLL
// LLRLRLRRL
// LLLRLRRLLRRRL


// YES
// YES
// NO
// NO
// YES
