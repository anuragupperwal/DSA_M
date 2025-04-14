class Solution {
public:
    //my flaud approach
    // int maxActiveSectionsAfterTrade(string s) {
    //     int prevZero=-1, prevOne = -1, largestSoFar = 0, zeroStart=-1, zeroEnd = -1;

    //     for(int i=0; i<s.length(); i++) {
    //         if(s[i] == '0') {
    //             if(prevZero == -1){
    //                 prevZero = i;
    //                 largestSoFar = 1;
    //                 zeroStart = i;
    //                 zeroEnd = i;
    //             }
    //             else {
    //                 if(largestSoFar < (i-prevZero+1) ){
    //                     largestSoFar = (i-prevZero+1);
    //                     zeroStart = prevZero;
    //                     zeroEnd = i;
    //                 }
    //             }
    //         }
    //         else { //s[i] == 1
    //             if(prevOne == -1) 
    //                 prevOne = i;
    //             else {
    //                 prevZero = prevOne + 1;
    //                 prevOne = i;
    //             }
    //         }
    //     } // end of for

    //     if(zeroStart == zeroEnd) return 1;
    //     if(zeroStart == -1) return s.length();

    //     while(zeroStart <= zeroEnd) {
    //         s[zeroStart] = '1'; 
    //         zeroStart++;
    //     }

    //     cout<<s;

    //     int res = 0, temp = 1;
    //     bool flag=false;
    //     for(int i=0; i<s.length()-1; i++) {
    //         if(s[i] == '1' && s[i] == s[i+1]){
    //             flag = true;
    //             temp++;
    //         }
    //         else {
    //             res = max(res, temp);
    //             temp = 1;
    //         }
    //     }
    //     if(flag == false) //no one's found 
    //         return 0;
    //     res = max(res, temp);
    //     return res;
    // }

    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<char, int> > v;
        int count = 1, init=0;;
        char prev = s[0];

        if(s[0] == '1') init++;
        for(int i=1; i<s.length(); i++) {
            if(s[i] == prev) {
                count++;
            }
            else {
                v.push_back(make_pair(s[i-1], count));
                count=1;
                prev = s[i];
            }
            if(s[i] == '1') {
                init++;
            }
        }
        v.push_back(make_pair(s[s.length()-1], count));

        int res = init;
        for(int i=0; i<v.size(); i++){
            if(v[i].first == '1' && i!=0 && i!=v.size()-1){
                res = max(res, init + v[i-1].second + v[i+1].second);
            }    
        }
        return res;
    }
};