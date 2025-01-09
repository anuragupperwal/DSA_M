class Solution {
public:
    //binary search approach
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n = time.size();
        long long left = 1, right=INT_MAX;

        for(int i=0; i<n; i++) right = (right < time[i])?right: time[i];
        right *=totalTrips;

        while(left<right) {
            long long t = left + (right-left)/2;

            long long sum=0;
            for(int i=0; i<n; i++) sum+=t/time[i];

            if(sum >= totalTrips) right = t;
            else left = t+1;

        }
        return right;;
    }


    // //bruteforce approach - gives TLE
    // long long minimumTime(vector<int>& time, int totalTrips) {
    //     long long t=0, n = time.size(), sum=0;

    //     while(sum!=totalTrips){
    //         t++;
    //         for(int i=0; i<n; i++) {
    //             sum += t/time[i];
    //         }
    //     }
    //     cout<<t;
    //     return t;
    // }
};