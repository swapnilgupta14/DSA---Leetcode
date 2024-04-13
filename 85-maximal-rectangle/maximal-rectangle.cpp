class Solution {
public:
    vector<int> NextSmaller(vector<int> &arr){
        stack<int> st;
        vector<int> arr1(arr.size());
        st.push(-1);
        int curr;
        for(int i=arr.size()-1;i>=0;i--){
            curr=arr[i]; 
            while(st.top()!=-1&&curr<=arr[st.top()]){
                st.pop();
            }
            if(st.top()==-1)
               arr1[i]=arr.size();
            else{
                arr1[i]=st.top();
            }
            st.push(i);
        }
        return arr1;
    }

        vector<int> PrevSmaller(vector<int> &arr){
        stack<int> st;
        vector<int> arr1(arr.size());
        st.push(-1);
        int curr;
        for(int i=0;i<arr.size();i++){
            curr=arr[i]; 
            while(st.top()!=-1&&curr<=arr[st.top()]){
                st.pop();
            }
            if(st.top()==-1)
               arr1[i]=-1;
            else{
                arr1[i]=st.top();
            }
            st.push(i);
        }
        return arr1;
    }

    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int MaxArea=0;
        int w=0;
        vector<int> r=NextSmaller(heights);
        vector<int> l=PrevSmaller(heights);
        for(int i=0;i<heights.size();i++){
            w=r[i]-l[i]-1;
            MaxArea=max(MaxArea,w*heights[i]);
        }
        return MaxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int area=0;
        int MaxArea=0;

        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> matrix1(rows,vector<int>(cols));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='0')
                   matrix1[i][j]=0;
                else
                  matrix1[i][j]=1;
            }
        }

        MaxArea=max(MaxArea,largestRectangleArea(matrix1[0]));
        for(int i=1;i<matrix1.size();i++){
            for(int j=0;j<matrix1[i].size();j++){
                if(matrix1[i][j]==0)
                   matrix1[i][j]=0;
                else{
                    matrix1[i][j]+=matrix1[i-1][j];
                }
            }
            MaxArea=max(MaxArea,largestRectangleArea(matrix1[i]));
        }
        return MaxArea;
    }
};