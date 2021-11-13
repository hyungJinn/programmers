#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int Count;
queue<pair<int, int>> answer;

int solution(vector<int> priorities, int location) {
    int prio_size = priorities.size();
    pair<int, int> swap = make_pair(0,1);
    
    for(int i = 0; i < prio_size; i++)
        answer.push(make_pair(i, priorities[i]));
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    for(int j = 0; j < prio_size;) {
        if(priorities[j] == answer.front().second) {
            ++Count;
            if(answer.front().first == location) break;
            answer.pop();
            ++j;
        } else {
            swap = make_pair(answer.front().first, answer.front().second);
            answer.pop();
            answer.push(swap);
        }
    }

    return Count;
}
