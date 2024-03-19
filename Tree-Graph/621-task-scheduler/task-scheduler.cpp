class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_counts(26, 0);
        for (char task : tasks) {
            task_counts[task - 'A']++; 
        }
        int s = tasks.size();
        int max_count = *max_element(task_counts.begin(), task_counts.end());
        int num_max_tasks = count(task_counts.begin(), task_counts.end(), max_count);
        int num_intervals = (max_count - 1) * (n + 1) + num_max_tasks;
        int m = max(num_intervals, s);
        return m;
    }
};