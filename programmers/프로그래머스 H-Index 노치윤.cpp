#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    for (int i = citations.size(); i >= 1; i--) {
        if (citations[citations.size() - i] >= i) return i;//citations[citations.size() - i] >= i �� ��� i ���� ū ���Ұ� idx: citations.size() - i~citations.size()-1���� i�� �����ϰ� ��.

    }
}