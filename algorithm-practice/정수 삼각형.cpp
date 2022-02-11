#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum[500][500];


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    sum[0][0] = triangle[0][0];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            if (j == 0) sum[i][j] = triangle[i][j] + sum[i - 1][0];
            else if (j == triangle[i].size() - 1)
                sum[i][j] = max(sum[i][j], triangle[i][j] + sum[i - 1][j - 1]);
            else {
                int addForLeft = sum[i - 1][j - 1] + triangle[i][j];
                int addForRight = sum[i - 1][j] + triangle[i][j];
                sum[i][j] = max(addForLeft, addForRight);
            }
        }
    }


    for(int i = 0; i < triangle[n - 1].size(); i++){
        answer = max(sum[n - 1][i], answer);
    }


    return answer;
}
