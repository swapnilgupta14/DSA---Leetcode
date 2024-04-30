class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long ,long long>mp;

        mp[0]=1;
        int xor1=0;
        long long result=0;

        for(char &ch:word)
        {
            int shift=ch-'a';
            xor1^=(1<<shift);
            result+=mp[xor1];

            for(char c='a';c<='j';c++)
            {
                int shift1=c-'a';
                long long xor2=xor1^(1<<shift1);
                result+=mp[xor2];
            }
            mp[xor1]++;
        }
        return result;
    }
};