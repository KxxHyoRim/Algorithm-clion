# Algorithm (c++)

- 배열 초기화 신경쓰기. 안하면 dummy값 들어가더라~
  ```c++
    int limit[101] = {0,};
    int calc[101] = {0,};
  ```
  
- 빠른입출력
  ```c++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  ```

- `INT_MAX` 상수 사용 못함. -> `#includ <limits.h>` 활용하자

- Binary Tree문제를 풀 때는, array를 활용한다. <br/>
이때, root node의 index를 0이 아닌 **1로 설정**하면 계산하기 편하다. <br/>
Thanks to [@hansh0101](https://github.com/hansh0101)

- String 입력받고 특정 index에 접근하려면, `string[idx]`로 접근하면 됨

- map 탐색할때 상하좌우

  ```c++
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {1, -1, 0, 0};
  ```
  
- map 탐색할떄 범위체크

  ```c++
  nx >= 0 && nx < n && ny >= 0 && ny < n
  ```
  
- queue
  - `empty()` 검사 안하고 `pop()`하면 에러남
  - priority_queue도 마찬가지!



- prioity queue 
  - 기본이 max heap
  - -로 변환한 값을 넣고, 뺄 때 -를 붙이면 min heap으로 작동함
  - `priority_queue<int, vector<int>, greator<int>> pq` 이것도 min heap인데 귀찮으니까..
  
    ``` c++
        priority_queue<int> pq;
        pq.push(x);
        pq.top();
        pq.pop(); // return 값이 void
    ```
  
  - priority queue에 여러 원소를 묶어서 정렬하고자 한다면, `struct`를 활용하자

    ```c++
    struct Treasure {
      int weight;
      int price;

      Treasure(int w, int p) : weight(w), price(p) {}

      bool operator<(const Treasure t) const {
          return this->price < t.price;
      }
    };
    
    int main() {

    priority_queue<Treasure> pq;

    for (int i = 0; i < n; i++) {
        cin >> m >> p;
        pq.emplace(m, p);
    }

    ```

- vector & queue 같이 쓰기

  ```c++
  vector<queue<int>> /*variableName*/ (/* size */, queue<int>());
  ```

- vector 정렬, unique

  ```
  sort(v.begin(), v.end())
  unique(v.begin(), v.end())
  ```


- bfs문제 풀 때, 시작지점이 여러개인 경우, 전역 queue를 사용한다


- 아래 코드의 문제점은, for문을 돌때마다 `pq.size()`가 매번 바뀌기때문에, 정상적인 출력이 안된다.
  pq의 각 vertex를 확인하려면 `while(!pq.empty())` 사용하자.
  ```c++
  cout << pq.size() << "\n";
  for (int i = 0; i < pq.size(); i++) {
      cout << -pq.top() << "\n";
      pq.pop();
  }
  ```


- DP에서 `min()` check할 때 초기값이 0인것을 주의하자


- Dijkstra
  - [기본구현](https://github.com/ndb796/python-for-coding-test/blob/master/9/1.cpp)
  - [심화구현(Priority Queue)](https://github.com/ndb796/python-for-coding-test/blob/master/9/2.cpp#L25)