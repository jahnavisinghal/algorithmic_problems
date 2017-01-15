# include<iostream>
using namespace std;

int main() {
    int bstElements[100] = {1,2,3,4};
    int n = 4;
    int cost[100] = {4,1,2,3};
    int M[100][100];
    int l = 1, j = 0;
    while( l <= n ) {
        for( int i = 1; i <= n; i ++ ) {
            j = i+l-1;
            if( i == j ) {
                M[i][j] = cost[ i-1 ];
                continue;
            }
            int sum = 0;
            for( int k = i; k <= j; k ++ ) {
                sum += cost[k - 1];
            }
            // min of keeping different elements as root
            int minCost = 1000;
            int subCost = 0;
            for( int k = i; k <=j; k ++ ) {
                // treat k as root
                if( k == i ) {
                    subCost = M[i+1][j];
                } else if( k == j ) {
                    subCost = M[i][j-1];
                } else {
                    subCost = M[i][k-1] + M[k+1][j];
                }
                minCost = min( minCost, subCost );
            }
            M[i][j] = sum + minCost;
         }
         l ++;
    }
    for( int i = 1; i <= n; i ++ ) {
            cout << "\n" << M[i][j];
        for( int j = 1; j <= n; j ++ ) {
            cout << "\t" << M[i][j];
        }
    }
    return 0;
}
