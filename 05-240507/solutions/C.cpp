#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(A,B) (A>B?A:B)

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    vector<vector<int>> map;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<i+1;j++){
            int a;
            cin>>a;
            row.push_back(a);
        }
        map.push_back(row);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<map[i].size();j++){
            if(j==0) map[i][j]=map[i-1][j]+map[i][j];
            else if(j==map[i].size()-1) map[i][j]=map[i-1][j-1]+map[i][j];
            else {
                map[i][j]=MAX(map[i-1][j-1],map[i-1][j])+map[i][j];
            }
            //cout<<map[i][j]<<" ";
        }
        //cout<<endl;
    }
    
    sort(map[n-1].begin(),map[n-1].end());
    cout<<map[n-1][n-1];
    return 0;
}
