class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.size(); i++){
            if(word[i] == ch){
                int j=0;
                while(j < i){
                    char temp = word[j];
                    word[j] = word[i];
                    word[i] = temp;
                    j++;
                    i--;
                }
                return word;
            }
        }
        return word;
    }
};