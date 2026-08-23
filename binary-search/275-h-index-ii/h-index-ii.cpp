class Solution {
public:
    bool checkCit(vector<int>& citations, int mid) {
        int cnt = 0;
        for(int i=0;i<citations.size();i++) {
            if(citations[i]>=mid) cnt++;
        }
        if(cnt>=mid) return true;
        return false;
    }

    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size();
        int res = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(checkCit(citations,mid)) {
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return res;
    }
};