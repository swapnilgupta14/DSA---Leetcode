// // You start with an initial power of power, an initial score of 0, 
// and a bag of tokens given as an integer array tokens, where each tokens[i] 
// donates the value of tokeni.
// Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):
// Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
// Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
// Return the maximum possible score you can achieve after playing any number of tokens.
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int m_score = 0;
        int n = tokens.size();
        vector<bool> flag(n, true);
        sort(tokens.begin(), tokens.end());
        int i =0;
        int j = n-1;
        while(i <= j){
            cout << i << " " << j << "\n";
            if(power >= tokens[i] && flag[i]){
                score+=1;
                m_score = max(score, m_score);
                power -= tokens[i];
                flag[i] = false;
                i++;
            }else if(score > 0){
                power += tokens[j];
                score -= 1;
                flag[j] = false;
                j--;
            }else{break;
}        }
        return m_score;
    }
};