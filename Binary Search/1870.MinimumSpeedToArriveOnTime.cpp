class Solution {
public:
    bool ifValid(vector<int>& dist, double hour, int speed, int n) {
        double calcTime=0;
        for(int i=0; i<n-1; i++) {
            calcTime += ceil((double)dist[i]/speed);
        } 
        calcTime += (double)dist[n-1]/speed;

        return (calcTime <= hour);
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int res=-1;

        int left = 1;
        int right = 1e7; //need to think and optimise upperbound

        while(left <= right) {
            int speed = left + (right-left)/2;

            if(ifValid(dist, hour, speed, n)) {
                res = speed;
                right = speed-1;
            }
            else left = speed+1;
        }
        return res;
    }
};