class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> res;

        vector<int> startBloom, endBloom;
        for(int i=0; i<n; i++) {
            startBloom.push_back(flowers[i][0]);
            endBloom.push_back(flowers[i][1]);
        }


        int left, right;
        int startIdx, endIdx;
        sort(startBloom.begin(), startBloom.end());
        sort(endBloom.begin(), endBloom.end());

        for(int i=0; i<people.size(); i++){

            //simpler method (without inner working of BS)
            int time = people[i];
            startIdx = upper_bound(startBloom.begin(), startBloom.end(), time) - startBloom.begin();
            endIdx = lower_bound(endBloom.begin(), endBloom.end(), time) - endBloom.begin();
        
            //with inner working of BS
        //     cout<<startBloom[i]<<" "<<endBloom[i]<<endl;

        // for(int i=0; i<people.size(); i++){
        //     //BS for start bloom vector idx
        //     left = 0;
        //     right = n-1;
        //     startIdx = 0;
        //     while(left <= right) {
        //         int mid = left + (right-left)/2;

        //         if(startBloom[mid] > people[i]){
        //             startIdx = mid;
        //             right = mid-1;
        //         }
        //         else left = mid+1;
        //     }
        //     if(people[i] >= startBloom[n-1]) startIdx = n-1;
        //     cout<<"people[i]: "<<people[i]<<" i:"<<i<<" startIdx: "<<startIdx<<endl;

        //     //BS to fearch for end bloom vec idx
        //     left = 0;
        //     right = n-1;
        //     endIdx=0;
        //     while(left <= right) {
        //         int mid = left + (right-left)/2;

        //         if(endBloom[mid] <= people[i]){
        //             endIdx = mid;
        //             left = mid+1;
        //         }
        //         else right = mid-1;
        //     }
        //     cout<<"i:"<<i<<" endIdx: "<<endIdx<<endl;

            res.push_back(abs(endIdx - startIdx));
        }

        return res;
    }
};