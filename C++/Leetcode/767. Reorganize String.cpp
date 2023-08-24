class Solution {
public:
    int arr[26];
    string reorganizeString(string s) {
        string output = "";
        for(char next: s){
            arr[next - 'a']++;
        }
        set<pair<int,int>> pq;
        for(int i=0;i<26;i++){
            if(!arr[i])continue;
            if(arr[i] > (s.size()+1)/2){
                return "";
            }
            pq.insert({arr[i], i});
        }
        pair<int,int> prev = {-1, -1};
        while(!pq.empty()){
            int i = pq.rbegin()->second;
            output += (char)(i + 'a');
            pq.erase(--pq.end());
            arr[i]--;
            if(prev.first != -1){
                pq.insert(prev);
            }
            if(arr[i]){
                prev = {arr[i], i};
            }
            else{
                prev = {-1, -1};
            }
        }
        if(prev.first == -1) return output;
        output += (char)(prev.second + 'a');
        return output;
    }
};