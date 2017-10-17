//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
typedef pair<int, int> pii;
bool vis[105][105], lit[105][105], reached[105][105];
pii sw[105][105][200];
int c[105][105];

void rec(int row, int col)
{
    if(vis[row][col] || !lit[row][col] || !reached[row][col])
        return;
    vis[row][col]=true;
    reached[row][col+1]=true, reached[row][col-1]=true, reached[row+1][col]=true, reached[row-1][col]=true;
    
    rec(row, col+1);
    rec(row, col-1);
    rec(row+1, col);
    rec(row-1, col);
    
    for(int i=0;i<c[row][col];i++){
        lit[sw[row][col][i].first][sw[row][col][i].second]=true;
        rec(sw[row][col][i].first, sw[row][col][i].second);
    }
}

int main()
{
    int n, m, sum=0;
    int i, j;
    lit[1][1]=true;
    reached[0][1]=true, reached[1][0]=true, reached[2][1]=true, reached[1][2]=true, reached[1][1]=true;
    
    cin >> n >> m;
    for(i=0;i<m;i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        sw[x][y][c[x][y]].first=a;
        sw[x][y][c[x][y]++].second=b;
    }
    
    rec(1, 1);
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            if(lit[i][j])
                sum++;
    
    cout << sum << endl;
    
    return 0;
}
