class Solution {
public:
    int findMax(vector<vector<int>> &mat,int n,int m, int mid){
        int maxi=INT_MIN;
        int row=0;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxi){
                maxi=mat[i][mid];
                row=i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=findMax(mat,n,m,mid);
            int left,right;
            if(mid-1>=0){
                left=mat[row][mid-1];
            }else{
                left=-1;
            }
            if(mid+1<m){
                right=mat[row][mid+1];
            }else{
                right=-1;
            }
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }else if(mat[row][mid]<left){
                high=mid-1;
            }else{
                
                low=mid+1;
            }
        }
        
        return {-1,-1};
    }
};