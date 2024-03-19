class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++; 
        }
        int s = tasks.size();
        int max_count = *max_element(freq.begin(), freq.end());
        int num_max_tasks = count(freq.begin(), freq.end(), max_count);
        int num_intervals = (max_count - 1) * (n + 1) + num_max_tasks;
        int m = max(num_intervals, s);
        return m;
    }
};