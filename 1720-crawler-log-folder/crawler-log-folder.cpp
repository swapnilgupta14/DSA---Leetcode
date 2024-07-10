class Solution {
public:
    int minOperations(vector<string>& logs) {
        int subCount = 0;
        for(auto it : logs){
            string str = it;
            if(it[it.size()-2] != '.'){
                subCount +=1;
            }
            if(it == "../"){
                if(subCount > 0) subCount--;
            }else{
                continue;
            }
        }
        return subCount<1 ? 0 : subCount;
    }
};