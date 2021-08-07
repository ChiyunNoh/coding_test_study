#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for (int i = 0; i < cities.size(); i++) {//��� �ҹ��ڷιٲٱ�
        for (int j = 0; j < cities[i].size(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
    }

    list<string> cache;
    map<string, int> cache_map;//���ø��� �ִ��� ������ �˻��ϱ� ���� map
    if (cacheSize == 0) {
        return 5 * cities.size();
    }

    if (cache.size() < cacheSize) {
        cache.push_front(cities[0]);
        cache_map[cities[0]] = 1;
        answer += 5;
    }
    for (int i = 1; i < cities.size(); i++) {
        if (cache.size() < cacheSize) {
            if (cache_map.find(cities[i]) != cache_map.end()) {//cache hit �߻�.
                for (list<string>::iterator iter = cache.begin(); iter != cache.end(); iter++) {
                    if (*iter == cities[i]) {
                        cache.erase(iter);//����
                        break;
                    }
                }
                answer += 1;
                cache.push_front(cities[i]);
            }
            else {//cache miss �߻�
                cache.push_front(cities[i]);
                cache_map[cities[i]] = 1;
                answer += 5;
            }
        }
        else {
            if (cache_map.find(cities[i]) != cache_map.end()) {//cache hit �߻�.
                for (list<string>::iterator iter = cache.begin(); iter != cache.end(); iter++) {
                    if (*iter == cities[i]) {
                        cache.erase(iter);
                        break;
                    }
                }
                answer += 1;
                cache.push_front(cities[i]);
            }
            else {//cache miss �߻�
                string temp = cache.back();//�� �� ���� ����
                cache.pop_back();
                cache_map.erase(temp);

                cache.push_front(cities[i]);//�� ������ insert
                cache_map[cities[i]] = 1;
                answer += 5;
            }
        }

    }

    return answer;
}