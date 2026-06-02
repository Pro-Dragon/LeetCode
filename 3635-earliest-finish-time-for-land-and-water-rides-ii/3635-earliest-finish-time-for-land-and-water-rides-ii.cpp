class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landstart = 0, landend = INT_MAX, waterstart, waterend = INT_MAX, n = landStartTime.size(), m = waterStartTime.size(), res = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(landend >= landStartTime[i] + landDuration[i]) {
                if(landend == landStartTime[i] + landDuration[i]) {
                    if(landstart < landStartTime[i]) landstart = landStartTime[i]; 
                }
                else landstart = landStartTime[i];
                landend = landStartTime[i] + landDuration[i];
            }
        }
        for(int i = 0; i < m; i++) {
            if(waterend >= waterStartTime[i] + waterDuration[i]) {
                if(waterend == waterStartTime[i] + waterDuration[i]) {
                    if(waterstart < waterStartTime[i]) waterstart = waterStartTime[i]; 
                }
                else waterstart = waterStartTime[i];
                waterend = waterStartTime[i] + waterDuration[i];
            }
            if(waterStartTime[i] < landstart) {
                if(landstart < waterStartTime[i] + waterDuration[i]) res = min(res, waterStartTime[i] + waterDuration[i] + (landend - landstart));
                else res = min(res, landend);
            }
            else if(waterStartTime[i] > landstart) {
                if(waterStartTime[i] < landend) res = min(res, waterDuration[i] + landend);
                else res = min(res, waterStartTime[i] + waterDuration[i]);
            }
            else res = min(res, landend + waterDuration[i]);
        }
        for(int i = 0; i < n; i++) {
            if(landStartTime[i] < waterstart) {
                if(waterstart < landStartTime[i] + landDuration[i]) res = min(res, landStartTime[i] + landDuration[i] + (waterend - waterstart));
                else res = min(res, waterend);
            }
            else if(landStartTime[i] > waterstart) {
                if(landStartTime[i] < waterend) res = min(res, landDuration[i] + waterend);
                else res = min(res, landStartTime[i] + landDuration[i]);
            }
            else res = min(res, waterend + landDuration[i]);
        }
        return res;
    }
};