#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    //�� ���� �ش��ϴ� ��¥ ����
    vector<int> days = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int day = b - 1;//1�Ϻ��� ����
    for (int i = 0; i < a - 1; i++) {//�� ��¥���� ��� ��¥ ��
        day += days[i];
    }
    vector<string> vec = { "FRI","SAT","SUN","MON","TUE","WED","THU" };
    answer = vec[day % 7];
    return answer;
}