#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = ((brown + yellow) - yellow - 4) / 2;//yellow: ����*����, brown+yellow: (����+2)*(����+2) -> 2*����+2*����=(brown + yellow) - yellow - 4
    int cross = yellow;
    int n = (sum + sqrt(sum * sum - 4 * cross)) / 2;//���� ����, yellow ����
    int m = (sum - sqrt(sum * sum - 4 * cross)) / 2;//���� ����, yellow ����
    answer.push_back(n + 2);
    answer.push_back(m + 2);
    return answer;
}