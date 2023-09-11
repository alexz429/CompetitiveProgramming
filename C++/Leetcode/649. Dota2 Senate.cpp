class Solution {
public:
    string predictPartyVictory(string senate) {
        int R = 0;
        int D = 0;
        queue<int> q;
        for(auto next: senate){
            q.push(next);
            if(next == 'R'){
                R++;
            }
        }
        D = senate.size() - R;
        int pre = 0;
        int side = 1;
        while(D !=0 && R != 0){
            auto next = q.front();
            // cout << next << endl;
            q.pop();
            if(pre !=0){
                if((next == 'R' && side == -1) || (next=='D' && side == 1)){
                    pre--;
                    continue;
                }
            }
            if(next == 'R'){
                side = 1;
                D--;
            }
            else{
                side = -1;
                R--;
            }
            pre++;
            q.push(next);
        }
        if(R > 0){
            return "Radiant";
        }
        return "Dire";
    }
};