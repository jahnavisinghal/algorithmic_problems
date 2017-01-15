# include<iostream>
# include<cstring>
using namespace std;

int main() {
    char* str1 = "abcdef";
    char* str2 = "adbef";
    int M[100][100];
    for( int i = 0; i <= strlen(str1); i ++ ) {
        for( int j = 0; j <= strlen( str2); j ++ ) {
            if( !i || !j ) {
                M[i][j] = 0;
                continue;
            }
            if( str1[i-1] == str2[j-1] ) {
                M[i][j] = M[i-1][j-1];
            } else {
                M[i][j] = min( M[i-1][j], min( M[i][j-1],M[i-1][j-1])) + 1;
            }
        }
    }
    for( int i = 0; i <= strlen(str1); i ++ ) {
        if( i ) {
            cout << "\n" << str1[i-1] << " ";
        }
        for( int j = 0; j <= strlen( str2); j ++ ) {
            cout << " " << M[i][j];
        }
    }
    int i = strlen(str1), j = strlen(str2);
    cout << "\nEdit distance: " << M[i][j];
    while( i && j ) {
        if( str1[i-1] == str2[j-1] ) {
            // no edit
            i--;
            j--;
        } else if( M[i][j]-1 == M[i-1][j] ) {
            cout << "\nEdit: " << str1[i-1] << " - " << str2[j-1];
            i--;
        } else if( M[i][j]-1 == M[i][j-1] ) {
            cout << "\nEdit: " << str1[i-1] << " - " << str2[j-1];
            j--;
        } else {
            cout << "\nEdit: " << str1[i-1] << " - " << str2[j-1];
            i--;
            j--;
        }
    }
    return 0;
}
