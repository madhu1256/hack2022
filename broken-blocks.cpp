#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
	int m = matrix.size();
	int n = matrix[0].size();
        int a[m][n+2];
        for(int i=0;i<m;i++)a[i][0]=a[i][n+1]=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               a[i][j+1] = matrix[i][j];
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j=1;j<=n;j++){
                if(a[i][j]!=-1){
                    if(a[i+1][j-1]==-1 and a[i+1][j]==-1 and a[i+1][j+1]==-1){  //if all the next level tiles are broken 
                        //do nothing
                    }else{
                        a[i][j]+=max(max(a[i+1][j-1],a[i+1][j]),a[i+1][j+1]);
                    }
                }
            }
        }
        int maxx=a[0][1];
        for(int i=2;i<=n;i++){
            if(a[0][i]>maxx)maxx=a[0][i];
        }
        if(maxx==-1)maxx=0;
        return maxx;
}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
} 
