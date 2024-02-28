#include <string>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int s1 = text1.size() + 1;
        int s2 = text2.size() + 1;
        int mat[s1][s2];
        for(int i = 0; i < s2; i++){
            mat[0][i] = 0;
        }
        for(int i = 0; i < s1; i++){
            mat[i][0] = 0;
        }
        for(int i = 1; i < s1; i++){
            for(int j = 1; j < s2; j++){
                if(text1[i - 1] == text2[j - 1]) 
                    mat[i][j] = mat[i - 1][j - 1] + 1;
                else{
                    mat[i][j] = std::max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }
        return mat[s1 - 1][s2 - 1];
    }
};
