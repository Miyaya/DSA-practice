class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // find single-source shortest path
        vector<int> distance(N+1, INT_MAX); // 1-index
        
        distance[K]=0;
        for(int j=0; j<N; j++) { // O(V*E)
            for(int i=0; i<times.size(); i++) {
                if(distance[times[i][0]]==INT_MAX) continue;
                if(distance[times[i][1]]>distance[times[i][0]]+times[i][2]) {
                    distance[times[i][1]]=distance[times[i][0]]+times[i][2];
                }
            }
        }
        
        // unreachable
        for(int i=1; i<distance.size(); i++) {
            if(distance[i]==INT_MAX) {
                return -1;
            }
        }
        
        // max of distance list
        return *max_element(distance.begin()+1, distance.end());
    }
};
