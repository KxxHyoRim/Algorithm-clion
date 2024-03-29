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

- 입력이 몇줄인지 모르는 경우
  ```c++
    string s, t, space;
    while(cin >> s >> t ){
      //
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

- local 변수 배열 초기화 신경쓰기 (Global은 알아서 0)

  ```c++
    int limit[101] = {0,};
    int calc[101] = {0,};
  ```

- 2차원 배열 초기화

  ```c++
    /* before */
    for (auto &i: map)
      memset(i, 0, sizeof(int) * 300);
      
    /* after */
    memset(map, 0, sizeof(map));
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

  - `priority_queue<pair<int,int>>` 

    - pair의 첫번째, 두번째 값을 순차적인 기준으로 내림차순 정렬
    - `map<string, priority_queue<..>>` 조합도 쓸수있음!

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
- **compare** `bool` 함수를 따로 분리해서 쓸 수도 있음

  ``` c++
  bool cmp(string a, string b) {
    if (a.length() == b.length())
        return a < b;
    else return a.length() < b.length();
  }

  vector<string> v;
  ...
  sort(v.begin(), v.end(), cmp);
  ```

- vector & queue 같이 쓰기

  ```c++
  vector<queue<int>> /*variableName*/ (/* size */, queue<int>());
  ```

- **Sort, unique, reverse** 

  - `sort` : **오름차순** 정렬
  - `sort`, `reverse` 순차 실행 : **내림차순** 정렬
  - `vector<pair<int, string>>`, `vector<pair<int,int>>` 형태도 가능
  - 코테볼때 `#include <algorithm>` 잊지말기

  ```c++
  sort(v.begin(), v.end());
  unique(v.begin(), v.end());
  reverse(play_num.begin(), play_num.end());
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


- **`DP`**에서 `min()` check할 때 초기값이 0인것을 주의하자


- **`Dijkstra`**

  - [기본구현](https://github.com/ndb796/python-for-coding-test/blob/master/9/1.cpp)
  - [심화구현(Priority Queue)](https://github.com/ndb796/python-for-coding-test/blob/master/9/2.cpp#L25)

- **`Kruskal`** (최소비용으로 node연결 시키기)

  1. int parent[n] 배열 생성
  2. 자기자신의 parent를 자신으로 설정  //parent[0] = 0, parent[1] = 1 ..
  3. Edge 오름차순 정렬
  4. Cycle이 형성되지 않는다면(edge의 두 node의 parent가 다르다면) edge추가

  - union-find 개념이 필요함

- **`소수점 제거`**

  - 문제에서 실수값을 소수점 첫째 자리에서 반올림하여 정수로 나타내고 싶을 경우 `round()`를 활용한다
  - `cout << round(double값)` 이렇게 할경우 e가 함께 나와 출력형식에 맞지 않게 된다
  - `cout << (long long) round(double값)` -> casting을 활용해 해결할 수 있다

- **`Set`**


  - 값을 가져오고 싶다면 iterator와 *를 활용하자


    - 첫번째 set의 값을 가져오기 위해서는 `int first = *set.begin();`

  - 집합인데 중복을 허용하고 싶다면 `multiset`을 사용하자


    - `insert("a")` `insert("a")` 를 실행하면, `multiset = {"a", "a"}`가 된다

    - `erase("a")` 를 수행하면, 두개의 a가 모두 삭제된다

    - 하나만 삭제하고 싶은 경우 iterator를 활용해야한다

      ```c++
      void Erase_Val(multiset<int> ms) {    // { 1, 1, 2 }
          ms.erase(1);    									// { 2 }
      }
      
      void Erase_Iter(multiset<int> ms) {    // { 1, 1, 2 }
          multiset<int>::iterator it = ms.find(1);
          ms.erase(it);   									// { 1, 2 }
      }
      ```
    - set iterator 안에서 erase할 때는, `it = it.erase("지우는거")` 이렇게 해야 메모리상 문제 없음`exc_bad_access`



- **`Map`**

  - `Map<string, int> m`형식으로 map을 생성하면 
    - `m["str"] += 1;` 이렇게 사용가능하다
  - map은 기본적으로 key를 기준으로 정렬된다
  - 이미 존재하는 <k, v>가 있는데 value 만 수정하고 싶은 경우
     - `emplace(k, v)` 시 v가 변경되지 않고 기존 값으로 유지
     - `map[k] = v`시 v가 정상적으로 변경
   - 새로운 <k,v>를 추가하고자 하는 경우
     - `emplace(k, v)`, `map[k] = v` 둘다 정상 동작

- **`Iterator`**

  - Map, set, 등의 자료형을 쓰다보면 반복문과같이 원소를 하나씩 조회해야할때가 있다

  - 그때 사용하는것이 iterator인데, c++부터는 auto를 지원한다

  - 종료조건으로 `for`문에서 사용하던  `<=` 대신   `!=` 를 사용한다

  - 값을 조회할 때는 `*`를 사용해야한다

    ``` c++
    for(auto it = map.begin; it != map.end(); it++){
      cout << *it << endl;
    }
    ```

  - Map의 iterator를 활용할 경우, `key`, `value`는  `*` 대신 각각 **`first`**, **`second`** 를 활용한다

    ```c++
    for (auto it = m.begin(); it != m.end(); it++) {
        play_num[i].first = it->second;
        play_num[i++].second = it->first;
    }
    ```

- **`map` vs `unordered_map`**
-  map:

    - Based on Red-Black Tree.
    - Stores key-value pairs in **sorted order.**
    - Offers efficient range-based searches and operations.
    - Insertion and deletion take **O(log n) time.**

- unordered_map:
   - **별도로 `#include<unordered_map>` 해주어야함**
   - Based on Hash Table.
   - **Does not maintain a specific order** for keys.
   - Provides fast insertion and deletion, typically **O(1)** on average.
   - May have slightly slower range-based operations.
    

