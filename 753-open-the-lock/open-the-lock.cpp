class Solution {
public:
    string rotation(std::string code, int pos, int val){
        int x = code[pos]-'0';
        
        if(val >= 0)
            x = (x+val)%10;
        else
            x = (x+val+10)%10;
        
        code[pos] = x+'0';
        
        return code;
    }

    int openLock(vector<string>& deadends, string target) {

        std::string start = "0000";
        std::set<string> deadset;
        for(auto end: deadends){
            deadset.insert(end);
        }

        if(deadset.find(start)!= deadset.end()){
           return -1; 
        }

        std::queue<std::pair<string, int>> q;
        q.push({start, 0});
        deadset.insert(start);

        std::vector<pair<int,int>> moves = {{0,1},{1,1},{2,1},{3,1},{0,-1},{1,-1},{2,-1},{3,-1}};

        while(!q.empty()){
            pair<std::string, int> top = q.front();
            q.pop();
            string code = top.first;
            int cost = top.second;

            if(target == code){
                return cost;
            }

            for(auto move: moves){
                int pos = move.first;
                int val = move.second; 
                string next_code = rotation(code, pos, val);

                if(target == next_code){
                    return cost+1;
                }

                if(deadset.find(next_code) != deadset.end()){
                    continue;
                }
                int depth = cost+1;
                q.push({next_code, depth}); 
                deadset.insert(next_code);           
            }
        }

        return -1;
    }
};