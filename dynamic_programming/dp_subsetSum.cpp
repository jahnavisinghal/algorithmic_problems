# include<iostream>
using namespace std;

/*this program determines if there exists a subset
in the array with sum equal to given sum */
int main() {
    int arr[100] = {1,2,5,8,16};
    int n = 5;
    bool M[100][100];
    int sum = 13;
    for( int i = 0; i < n; i ++ ) {
        for( int j = 0; j <= sum; j ++ ) {
            if( !j ) {
                M[i][j] = false;
                continue;
            }
            if( !i ) {
                M[i][j] = false;
                if( j == arr[i] ) {
                    M[i][j] = true;
                }
                continue;
            }
            if( arr[i] > j ) {
                M[i][j] = M[i-1][j];
            } else if( arr[i] == j ) {
                M[i][j] = true;
            } else {
                M[i][j] = M[i-1][j] || M[i-1][j-arr[i]];
            }
        }
    }
    for( int i = 0; i < n; i ++ ) {
        cout << arr[i] << "\t";
        for( int j = 0; j <= sum; j ++ ) {
            cout << " " << M[i][j];
        }
        cout << "\n";
    }
    cout << "\nFinal answer: " << M[n-1][sum];
    if( M[n-1][sum] ) {
        // to print the sequence:
        int i = n-1, j = sum;
        while( j ) {
            if( arr[i] > j ) {
                i = i-1;
            } else if( M[i][j-arr[i]] || !(j-arr[i]) ) {
                // part of sequence
                cout << " " << arr[i];
                j = j - arr[i];
                i = i-1;
            }
        }
    }
    return 0;
}
