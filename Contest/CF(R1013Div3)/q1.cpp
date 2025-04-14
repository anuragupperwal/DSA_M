#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> inp;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            inp.push_back(a);
        }

        unordered_map<int, int> map;
        map[0] = 3;
        map[1] = 1;
        map[2] = 2;
        map[3] = 1;
        map[5] = 1;

        int count = 8;
        for (int i = 0; i < n; i++)
        {
            if(map.find(inp[i]) != map.end()){
                auto itr = map.find(inp[i]);
                if(itr->second >0){
                    itr->second -= 1;
                    count--;
                }
            }
            if(count == 0){
                cout << n - i << "done"<<endl;
                break;
            }
            }
    }
    return 0;
}


// clang++ -o q1 q1.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)