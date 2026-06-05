class Solution {
public:
    pair<long long, long long> helper(int posi, int lastDig, int sndLastDig, int tight, vector<int>&num1Arr, vector<vector<vector<vector<pair<long long,long long>>>>>&digitDP){
        if(posi==num1Arr.size()) return {0,1};
        if(digitDP[posi][lastDig+1][sndLastDig+1][tight].second!=-1){
            return digitDP[posi][lastDig+1][sndLastDig+1][tight];
        }
        int limit=(tight==1)?num1Arr[posi]:9;
        long long grandTotalWaviness=0;
        long long grandTotalWays=0;
        for(int i=0;i<=limit;i++){
            int newTight=(tight==1 and i==num1Arr[posi])?1:0;
            int curDig=(lastDig==-1 and sndLastDig==-1 and i==0)?-1:i;
            pair<long long,long long>subVal=helper(posi+1,curDig,lastDig,newTight,num1Arr,digitDP);
            long long subWaviness=subVal.first;
            long long subWays=subVal.second;
            int add=0;
            if(curDig!=-1 and lastDig!=-1 and sndLastDig!=-1){
                if( lastDig>max(curDig,sndLastDig) || lastDig<min(curDig,sndLastDig) ) add++;
            }
            grandTotalWaviness+=(subWaviness+(add*subWays));
            grandTotalWays+=subWays;
        }
        return digitDP[posi][lastDig+1][sndLastDig+1][tight]={grandTotalWaviness,grandTotalWays};
    }
    long long totalWaviness(long long num1, long long num2) {
        num1--;

        string str1=to_string(num1),str2=to_string(num2);
        int n1=str1.size(),n2=str2.size();
        vector<int>num1Arr(n1),num2Arr(n2);
        for(int i=0;i<n1;i++) num1Arr[i]=(str1[i]-'0');
        for(int i=0;i<n2;i++) num2Arr[i]=(str2[i]-'0');

        vector<vector<vector<vector<pair<long long,long long>>>>>digitDP(16,vector<vector<vector<pair<long long,long long>>>>(11,vector<vector<pair<long long,long long>>>(11,vector<pair<long long,long long>>(2,{-1,-1}))));
        long long num1Ans=helper(0,-1,-1,1,num1Arr,digitDP).first;

        digitDP.assign(16,vector<vector<vector<pair<long long,long long>>>>(11,vector<vector<pair<long long,long long>>>(11,vector<pair<long long,long long>>(2,{-1,-1}))));
        long long num2Ans=helper(0,-1,-1,1,num2Arr,digitDP).first;

        return (num2Ans-num1Ans);
    }
};