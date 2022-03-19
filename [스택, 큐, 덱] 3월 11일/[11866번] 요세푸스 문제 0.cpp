#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> simulation(int k, queue<int>& q) {
    vector<int> result; //요세푸스 순열
    int cnt = 0; //카운트 변수

    while (!q.empty()) { //q가 비어있을 때까지
        int x = q.front(); //x는 q의 맨 위 원소
        q.pop(); //맨 위의 원소 pop
        cnt++; //카운트+1
        if (cnt == k) { //k번째 pop하는 원소라면
            result.push_back(x); //리턴할 벡터에 x를 push
            cnt = 0; //카운트는 0으로
            continue; //여기서 x는 다시 push하지 않음
        }
        q.push(x); //pop한 원소 다시 push
    }
    return result; //결과값 리턴
}

/**
 * 1. 큐에 1 ~ N까지 값 초기화
 * 2. 이후 k 번째 사람 찾기 위해 pop, push 반복
 * 3. k번째 pop 일 경우 요세푸스 순열에 저장, 이후 원소 제거 (다시 push 하지 않음!)
 */

int main() {
    int n, k;
    queue<int> q;

    //입력
    cin >> n >> k; //n과 k 입력
    for (int i = 1; i <= n; i++) { //큐 초기화
        q.push(i);//큐에 1부터 n까지 push
    }
    //연산
    vector<int> result = simulation(k, q);
    //출력
    cout << '<';
    for (int i = 0; i < result.size() - 1; i++) { //결과값 순서대로 출력
        cout << result[i] << ", "; 
    }
    cout << result[result.size() - 1] << '>';
    return 0;
}