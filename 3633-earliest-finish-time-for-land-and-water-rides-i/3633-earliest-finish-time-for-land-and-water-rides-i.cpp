class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landstart = 0, landend = INT_MAX, waterstart, waterend = INT_MAX, n = landStartTime.size(), m = waterStartTime.size(), res = INT_MAX;
        for(int i = 0; i < n; i++) landend = min(landend, landStartTime[i] + landDuration[i]);
        for(int i = 0; i < m; i++) {
            waterend = min(waterend, waterStartTime[i] + waterDuration[i]);
            if(landend > waterStartTime[i]) res = min(res, landend + waterDuration[i]);
            else res = min(res, waterStartTime[i] + waterDuration[i]);
        }
        for(int i = 0; i < n; i++) {
            if(waterend > landStartTime[i]) res = min(res, waterend + landDuration[i]);
            else res = min(res, landStartTime[i] + landDuration[i]);
        }
        return res;
    }
};