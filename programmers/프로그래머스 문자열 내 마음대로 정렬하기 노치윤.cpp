#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    map<string, int> bucket;
    for (int i = 0; i < strings.size(); i++) {
        string temp = "";
        temp += strings[i][n];
        temp += strings[i];
        //map�� key�� "n��° ���� + �ڱ� �ڽ� ���ڿ�" �� �ϸ� ���� 5 �����ϸ鼭 ���� ����
        bucket[temp] = i;
    }
    for (map<string, int>::iterator iter = bucket.begin(); iter != bucket.end(); iter++) {
        answer.push_back(strings[iter->second]);
    }
    return answer;
}