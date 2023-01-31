# Algorithm (c++)

- `cin`과 `getline()`
  - **cin**은 "\n"빼고 입력받음. 반면 **getline()** 은 "...\n"까지 입력받음.
  - 문제 중에 한줄의 입력변수의 수가 정해져있지 않는 경우가 있음
    (ex) tree의 node가 operator면 left, right node의 정보가 나오고, node가 operand라면 나오지 않음
  - 이럴 경우, getline()을 통해 한줄을 입력받고 seperator로 몇개의 문자가 주어졌는지 직접 파약해야함
  - c++에는 java와 다르게 split함수가 없어서 직접 구현해야함..^^;
  - 함수 코드 [(출처)](https://ssungkang.tistory.com/entry/C-string-%EB%AC%B8%EC%9E%90%EC%97%B4-%EB%82%98%EB%88%84%EB%8A%94-split)
    
    ```c++

    #include <vector>
    #include <sstream>

    int main(){
      vector<string> result = split(line, ' ');
    }

    vector<string> split(string input, char delimiter) {
        vector<string> answer;
        stringstream ss(input);
        string temp;
        while (getline(ss, temp, delimiter)) 
            answer.push_back(temp);
        return answer;
    }

    ```
  
- `constexpr` 는 무엇인가!??
  - The keyword constexpr was introduced in C++11 and improved in C++14. It means constant expression. Like const, it can be applied to variables: A compiler error is raised when any code attempts to modify the value. Unlike const, constexpr can also be applied to functions and class constructors. constexpr indicates that the value, or return value, is constant and, where possible, is computed at compile time. [(출처:Microsoft)](https://learn.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=msvc-170)
  - 상수임
  - `const`와 달리 컴파일시에 검사하기 때문에 에러가 있다면, 컴파일시에 에러를 잡아낸다
  - `const`와 달리 함수, class 생성자에서도 사용가능
  - 아래와 같이 사용가능
  
    ```c++
      constexpr int n = 5;
      const std::vector< std::pair< int, int >> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {3, 2}, {4, 3}};
    ``` 


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
