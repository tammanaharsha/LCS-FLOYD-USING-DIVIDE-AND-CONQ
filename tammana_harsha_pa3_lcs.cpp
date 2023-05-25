//importing and defining the Length condition
#include <bits/stdc++.h>
#define LENGTH_CONDITION (str1.length() > 100 || str2.length() > 100)

using namespace std;

//Function is used to extract the LCS from the DP matrix
string display_lcs(vector<vector<int>>& dp, vector<vector<char>>& bmaxi, string str1, string str2, int n, int m) {
    string lcs = "";
    int i = n, j = m;
    stack<char> lcs_stack;

    while (i > 0 && j > 0) {
        if (bmaxi[i][j] == 'D'){
            lcs_stack.push(str1[i - 1]);
            i=i-1, j=j-1;
        }
        else if (bmaxi[i][j] == 'U') {
            i=i-1;
        }
        else {
            j=j-1;
        }
    }

    while (!lcs_stack.empty()) {
        lcs += lcs_stack.top();
        lcs_stack.pop();
    }

    return lcs;
}
//This function uses the dynamic programing method to find lcs

void dynamic_programming_lcs(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<char>> bmaxi(n + 1, vector<char>(m + 1)); //create b matrix

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                bmaxi[i][j] = 'D'; //set direction to diagonal
            }
            else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    bmaxi[i][j] = 'U'; //set direction to up
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    bmaxi[i][j] = 'L'; //set direction to left
                }
            }
        }
    }

    string lcs = "";
    int i = n, j = m;
    stack<char> s;

    while (i > 0 && j > 0) {
        if (bmaxi[i][j] == 'D') { //if current cell direction is diagonal
            s.push(str1[i - 1]);
            i=i-1, j=j-1;
        }
        else if (bmaxi[i][j] == 'U') { //if current cell direction is up
            i=i-1;
        }
        else { //if current cell direction is left
            j=j-1;
        }
    }

    while (!s.empty()) {
        lcs += s.top();
        s.pop();
    }

    cout << "Length of LCS: " << lcs.length() << endl;
    cout << "LCS: " << lcs << endl;
}

// verifing the arguments length and strings length; and calling function to find LCS
int main(int argc, char **argv)
{
    if(argc!=3){
        cout<<"error"<<endl;
        return -1;
    }
    string str1 = argv[1];
    string str2 = argv[2];
    
    if(LENGTH_CONDITION){
        cout<<"the string length too long"<<endl;
        return -2;
    }

    dynamic_programming_lcs(str1,str2);
    return 0;
}