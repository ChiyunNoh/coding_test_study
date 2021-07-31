#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<int> second;
    vector<int> value;
    for (int i = 0; i < prices.size(); i++) {

        while (second.size() != 0 && value.back() > prices[i]) {
            value.pop_back();
            int sec = second.back();
            answer[sec] = i - sec;//i��° �ε����϶� ������ ���������Ƿ� i-sec �� ������ �ȶ�������.
            second.pop_back();
        }
        second.push_back(i);
        value.push_back(prices[i]);
    }

    while (second.size() != 0) {//second ���ÿ� ���� �� ó��.
        int sec = second.back();
        answer[sec] = prices.size() - 1 - sec;
        second.pop_back();
    }
    return answer;
}