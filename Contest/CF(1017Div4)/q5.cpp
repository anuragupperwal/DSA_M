#include<iostream>
#include<vector>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            int val;
            cin >> val;
            v[i] = val;
        }

        //prepare bits for each number
        int maxBitsLen = 0;
        vector<vector<int> > bitsCountAllInput;
        for (int i = 0; i < n; i++) {
            int bits = (v[i] == 0) ? 1 : (int)(log2(abs(v[i])) + 1);
            
            maxBitsLen = max(maxBitsLen, bits);
            vector<int> temp(30);
            for (int j = 0, k=0; j<bits; j++, k++){
                if( ((v[i] >> j) & 1) )
                    temp[k]= 1;
            }
            reverse(temp.begin(), temp.end());
            bitsCountAllInput.push_back(temp);
        }

        for (int i = 0; i < bitsCountAllInput.size(); i++){
            // cout << v[i]<<": " << endl;
            bitsCountAllInput[i].erase(bitsCountAllInput[i].begin(), bitsCountAllInput[i].end() - maxBitsLen);
            // for (int j = 0; j < bitsCountAllInput[i].size(); j++)
            // {
            //     cout << bitsCountAllInput[i][j] << " ";
            // }
            // cout << endl;
        }


        //count bits position-wise
        vector<int> bitsCount(maxBitsLen, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < maxBitsLen; j++) {
                if(bitsCountAllInput[i][j] == 1){
                    bitsCount[j] += 1;
                }
            }
        }
        for (int j = 0; j < maxBitsLen; j++) 
            cout << bitsCount[j] << " ";
        cout<<endl;

        int res = 0;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = 0; j < maxBitsLen; j++){
                int count = bitsCount[j];
                if (bitsCountAllInput[i][j] == 1)
                    count = n - bitsCount[j];
                int power = pow(2, j);
                sum += (power * count);
                cout << "Sum: " << sum << " power: "<<power<<" count: "<<count<< endl;;
            }
            res = max(sum, res);
            cout << "res: " << res << endl;
        }
        cout << res << endl;
    }
    return 0;
}

// clang++ -o q5 q5.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)



// 5
// 3
// 18 18 18
// 5
// 1 2 4 8 16
// 5
// 8 13 4 5 15
// 6
// 625 676 729 784 841 900
// 1
// 1

// 0
// 79
// 37
// 1555
// 0
