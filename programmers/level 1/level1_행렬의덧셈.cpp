#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer; //2차원배열
    vector<int> temp;           //1차원배열
    
    int row = arr1.size();
    int col = arr1[0].size();
    
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(temp);
        temp.clear();
    }
    return answer;
}