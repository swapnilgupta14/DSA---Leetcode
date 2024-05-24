class Solution {
public:
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
vector<int>lettercount(26,0);
for(char letter:letters){
    lettercount[letter-'a']++;
}
return backtrack(words,lettercount,score,0);
}
//backtracking
private:
int backtrack(vector<string>& words, vector<int>& lettercount, vector<int>& score,int index){
if(index==words.size()) {
    return 0;
}
    int maxscore=backtrack(words,lettercount,score,index+1); // skip
    string currentword=words[index];
    vector<int>currentwordscount(26,0);
    bool canUseCurrentWord=true;
    int currentWordScore = 0;

    for(char c:currentword){
        currentwordscount[c-'a']++;
        if(currentwordscount[c-'a']>lettercount[c-'a']){

canUseCurrentWord=false;

break;
        }
        currentWordScore+=score[c-'a'];
    }
if(canUseCurrentWord){
    for(char c:currentword){
        lettercount[c-'a']--;
    }
    maxscore=max(maxscore,currentWordScore+backtrack(words,lettercount,score,index+1));
    for(char c:currentword){
    lettercount[c-'a']++;
    }

}
    return maxscore;
        
    }
};