class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       unordered_map<string, int> mp;
       for(auto it: arr){
            mp[it] += 1;
       }
       vector<string> ans;
       for(auto it : arr){
        if(mp[it] == 1) ans.push_back(it);
       }
       if(ans.size() >= k) return ans[k-1];
       return "";
    }
};

// string kthDistinct(vector<string>& arr, int k) {
//         vector<string> dis;
//         int n = arr.size();
//         for(int i=0; i<n; i++){
//             if(arr[i] == "-1") continue;
//             string a = arr[i];
//             bool flag = false;
//             for(int j = i; j<n; j++){
//                 if(arr[j] == "-1") break;
//                 if(arr[j] == a)
//                 {
//                     arr[j] = "-1";
//                     flag = true;
//                 }
//             }
//             if(flag) continue;
//             else dis.push_back(a);
//         }
//         for(string it: arr) cout << it << ",   " ;
//         if(arr[n-1] != "-1") dis.push_back(arr[n-1]);
//         if(dis.size() >= k) return dis[k-1];
//         return "";
//     }