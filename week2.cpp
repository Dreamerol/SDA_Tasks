//week 2
//Is there a cycle in oriented graph where one Node can only access another
struct Node{
    Node* next=nullptr;
};
bool goesToStartingPoint(Node* node){
    Node* startingPoint = node;
    Node* curr = node->next;
        while(curr){
             
        if(curr == startingPoint)  return 1;
        curr = curr->next;
 
        }
    return 0;
}
bool isThereCycleInGraph(vector<Node*>& nodes){
    for(int i =0;i<nodes.size();i++){
        if(goesToStartingPoint(nodes[i])) return 1;
    }
    return 0;
}

//Three sum
    bool isInThere(vector<vector<int>>& triplets, vector<int>& triplet){
        for(int i = 0;i<triplets.size();i++){
            if(triplets[i][0] == triplet[0]&&triplets[i][1]==triplet[1]&&triplets[i][2] == triplet[2]) return 1;
        }
        return 0;
    }
    void swap(int& a, int& b){
        int h = a;
        a = b;
        b = h;
    }
    void SelectionSort(vector<int>& nums){
        int size = nums.size();
        for(int i = 0;i<size-1;i++){
            int minidx = i;
            for(int j = i+1;j<size;j++){
                if(nums[minidx] > nums[j]) minidx = j;
            }
            if(minidx!=i){
                swap(nums[minidx], nums[i]);
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        SelectionSort(nums);
        vector<vector<int>> triplets;
        int size = nums.size();
        for(int i = 0;i<size;i++){
           if(nums[i]>0) break;
           int target = -nums[i];
           int startIdx = i+1;
           int endIdx = size-1;
           
           while(startIdx<endIdx){
            
            int sum  = nums[startIdx]+nums[endIdx];
            if(sum>target) endIdx--;
            else if(sum == target){
                vector<int> triplet = {nums[i], nums[startIdx], nums[endIdx]};
                startIdx++;
                endIdx--;
              if(!isInThere(triplets,triplet)) triplets.push_back(triplet);
            }
            else {startIdx++;}
           }


        
        }
     return triplets;
    }
/zadacha Reconstruction Queue
void swap(vector<int>& a, vector<int>& b){
        vector<int> h = a;
        a = b;
        b = h;
    }
    void SelectionSort(vector<vector<int>>& people){
        int size = people.size();
        for(int i = 0;i<size-1;i++){
            int maxidx = i;
            for(int j = i+1;j<size;j++){
                if(people[maxidx][0] < people[j][0]) maxidx = j;
                else if(people[maxidx][0] == people[j][0]){
                    if(people[maxidx][1] > people[j][1])  maxidx = j;
                }
            }
            if(maxidx != i){
                swap(people[maxidx], people[i]);
            }
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
        if(size == 1) return people;
        vector<vector<int>> newQueue;
        SelectionSort(people);
        
        for(int i = 0;i<people.size();i++){
            int pos=people[i][1];
          newQueue.insert(newQueue.begin()+pos, people[i]);
        }    
        
        return newQueue;
    }

//zadacha longest Number Concatenation

long power(int base, int stepen){
    int count = 1;
    for(int i = 0;i<stepen;i++){
        count *= base;
    }
    return count;
}
void swap(int& a, int& b){
    int h = a;
    a = b;
    b = h;
}
int len(long num){
     if(num == 0) return 1;
    int cnt = 0;
    while(num){
        num /= 10;
        cnt++;
    }
   
    return cnt;
}
bool biggerNum(long a, long b){
    // int ln1 = len(a);
    // int ln2 = len(b);
    
    // long long rightNumber = b*pow(10, ln1) + a;
    // long long leftNumber = a*pow(10, ln2) + b;
    string rightNumber = to_string(a) + to_string(b);
    string leftNumber = to_string(b) + to_string(a);
    
    return (rightNumber < leftNumber);
    
}
string largestNumber(vector<int>& ar){
    int size = ar.size();
    for(int i = 0;i<size - 1;i++){
        int maxidx = i;
        for(int j = i+1;j<size;j++){
            if(biggerNum(ar[maxidx], ar[j])){
                maxidx = j;
            }
        }
        if(maxidx != i){
            swap(ar[i], ar[maxidx]);
        }
    }

    string txt;
    bool flag = false;
    for(int i = 0;i<size;i++){
        if(ar[i] != 0) {flag = true;break;}
    }
    
    if(!flag)  {txt = '0'; cout<<2;return txt;}

    for(int i = 0;i<size;i++){
        int ln = len(ar[i]);
        
        for(int k = 0;k<ln;k++){
        
        int x = (ar[i] /(power(10, ln - k - 1))) % 10;
        txt+=(x + '0');
        }
        
    }
    return txt;
}
//Homework
1//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printSorted(string& str, int N){
   int nums[10]{};
    int smallchars[26]{};
    int bigchars[26]{};
    
    for(int i = 0;i<N;i++){
        if(str[i]<='9' && str[i]>='0') nums[str[i]-'0']++;
        else if((str[i]<='z' && str[i]>='a')) smallchars[str[i]-'a']++;
        else if((str[i]<='Z' && str[i]>='A')) bigchars[str[i]-'A']++;
    }
    for(int i = 0;i<10;i++){
        for(int j = 0;j<nums[i];j++){
            cout<<i;
        }
}
    for(int i = 0;i<26;i++){
         for(int j = 0;j<smallchars[i];j++){
             char el = i +'a';
            cout<<el;
        }
    }
     for(int i = 0;i<26;i++){
         for(int j = 0;j<bigchars[i];j++){
             char el = i +'A';
            cout<<el;
        }
    }
}
int main() {
    int N;
    cin>>N;
    string str;
    cin>>str;
    printSorted(str, N);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

2//
int N;
    cin>>N;
    vector<int> nums;
    for(int i = 0;i<N;i++){
        int num;
        cin>>num;
        nums.push_back(num);
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int idx = size/2;
        if(size%2==0){
            cout<<(nums[idx] + nums[idx-1])/2.0;
        }
        else {cout<<nums[idx];}
        cout<<'\n';
    }

/faster approach
int main() {
    int N;
    cin>>N;
    vector<int> nums(N);
    cin>>nums[0];
    cout<<nums[0]<<'\n';
    int size = 1;
    for(int i = 1;i<N;i++){
       int num;
        cin>>num;
        size++;
        int j = 0;
        while(j < size-1 && num>=nums[j]){
          j++;
        }
        
        for(int h = j;h<size;h++){
         nums[h+1]=nums[h];
        }
        nums[j]=num;
        int d = size/2;
        if(size%2 == 0) cout<<((nums[d]+nums[d-1])/2.0);
        else cout<<nums[d];
        cout<<'\n';
    }
   
}
3//

// void swap(pair<string, int>& a, pair<string, int>& b){
// pair<string, int> h = a;
// a = b;
// b = h;
// }
// void sortStudents(vector<pair<string, int>>& students, int N){
//     for(int i = 0;i<N-1;i++){
//         int minidx= i;
//      for(int j = i+1;j<N;j++){
//       if(students[minidx].second < students[j].second) minidx = j;
//        else if(students[minidx].second == students[j].second){
//         if(students[minidx].first> students[j].first) minidx = j;}
// }
//         if(minidx != i) swap(students[i], students[minidx]);
//     }
// }

int main() {
    int N;
    cin>>N;
    vector<pair<string, int>> students(N);
    for(int i = 0;i<N;i++){
cin>>students[i].first;}
    for(int i = 0;i<N;i++){
        cin>>students[i].second;
    }
    sort(students.begin(), students.end(), [](const pair<string, int>& a, const pair<string, int>& b){
        if(a.second != b.second){
           return a.second > b.second;
        }
        return a.first < b.first;
    });
    //sortStudents(students, N);
    for(int i = 0;i<N;i++){
cout<<students[i].first<<' '<<students[i].second<<'\n';
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

//zadaci seminar
/1
bool onlyNegative(vector<int>& nums){
    for(int i = 0;i<nums.size();i++){
        if(nums[i]>0) return 0;
    }
    return 1;
}
bool onlyPositive(vector<int>& nums){
    for(int i = 0;i<nums.size();i++){
        if(nums[i]<0) return 0;
    }
    return 1;
}
int idxofPivot(vector<int>& nums){
    for(int i = 0;i<nums.size();i++){
        if(nums[i] ==0) return i;
        else if(i < nums.size() -1 &&nums[i]*nums[i+1]<0) return i+1;
    }
    return -1;
    
}

    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> helper(size);
        if(onlyNegative(nums)){
            for(int i = size-1;i>=0;i--){
                helper[size-1-i] = nums[i]*nums[i];
            }
            return helper;
        }
        else if(onlyPositive(nums)){
             for(int i = 0;i<size;i++){
                helper[i] = nums[i]*nums[i];
            }
            return helper;
        }
        int p2 =idxofPivot(nums);
        int p1 = p2-1;
        int k = 0;
        while(p2 <= size - 1 && p1 >= 0){
            int l1 = nums[p1]*nums[p1];
            int l2 = nums[p2]* nums[p2];
            if(l1 > l2){
                helper[k] = l2;
                p2++; 
            }
            else{
                helper[k] = l1;
                p1--; 
            }
          
            
            k++;
          
        }
        if(p1 < 0) {
            while(p2 <= size-1){
            helper[k++] = nums[p2]* nums[p2];
            p2++;}
            }
        else if(p2 > size - 1) {
            while(p1 >= 0){helper[k++] = nums[p1] * nums[p1];
            p1--;}}
        return helper;
    }
};
2/
   int max(vector<int>& ar){
        int maxi = 0;
        for(int i = 0;i<ar.size();i++){
            if(ar[i]> maxi) maxi = ar[i];
        }
        return maxi;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> uniqueEls;
        int max1 = max(nums1);
        int max2 = max(nums2);
        int K = min(max1, max2) + 1;

        vector<int> counter1(max1+1, 0);
        vector<int> counter2(max2+1, 0);
        for(int i = 0;i<nums1.size();i++){
            counter1[nums1[i]]++;
        }
          for(int i = 0;i<nums2.size();i++){
            counter2[nums2[i]]++;
        }
        for(int i = 0;i<K;i++){
            if(counter1[i]>0 && counter2[i]>0){
                int mini = min(counter1[i], counter2[i]);
                for(int j =0;j<mini;j++){
                uniqueEls.push_back(i);}
            }
        }
        return uniqueEls;
3/
   char findTheDifference(string s, string t) {
    int counter[26];
    for(int i = 0;i<s.length();i++){
        counter[s[i]-'a']++;
    } 
    for(int j = 0;j<t.length();j++){
        counter[t[j]-'a']--;
    }
    char el;
    for(int i = 0;i<26;i++){
        
        if(counter[i] < 0) {el = 'a' + i;};
    }
   return el;
    }
4/
    void merge(vector<int>& ar, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right-mid;
        vector<int> L(n1);
        vector<int> R(n2);

        for(int i = 0;i<n1;i++){
            L[i] = ar[left+i];
        }
        for(int j =0;j<n2;j++){
            R[j] = ar[mid+1+j];
        }
        int i = 0;
        int j = 0;
        int k = left;

        while(i<n1&&j<n2){
            if(L[i]<= R[j]){
                ar[k] =L[i];
                i++; 
            }
            else{
                ar[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            ar[k] = L[i];
            k++;
            i++;
        }
        while(j<n2){
            ar[k] = R[j];
            k++;
            j++;
        }
    }
    void mergeSort(vector<int>& ar, int left, int right){
       if(left<right){
         int mid = left + (right-left) / 2;
         mergeSort(ar, left, mid);
         mergeSort(ar, mid+1, right);
         merge(ar, left, mid, right);
       }


    }
    bool containsDuplicate(vector<int>& nums) {
       int start = 0;
       int end = nums.size()-1;
       mergeSort(nums, start, end);
       for(int i = 0;i<end;i++){
        if(nums[i] == nums[i+1]) return 1;
       }
       return 0;

    }

/--------------------------------------------------
konsultaciq
1/
#include<iostream>
#include <vector>
using namespace std;
void readRooms(int* rooms, size_t size){
    for(size_t i = 0;i<size;i++){
        cin>>rooms[i];
    }
}
int clean(int num, int* rooms, int size, bool* isCleaned){
    size_t count = 0;
    int startingPoint = num;
    // while(true){
        
    //     num = rooms[num];
    //     count++;
    //     if(startingPoint == num) break;
    //     isCleaned = true;
    // }
    while(!isCleaned[i]){
        num = rooms[i];
        count++;
    }
}
void cleanBuilding(size_t n){
    int* rooms = new int[n];
    readRooms(rooms, n);
    bool* isCleaned = new bool[n];
    size_t longestSeq = 0;
    size_t neededCleaners = 0;
    for(size_t i = 0;i<n;i++){
        if(!isCleaned[i]){
            int seq = clean(int, rooms, n);
            neededCleaners++;//vseki pyt kato vlezem v chista staq ni trqbva nov chistach
        if(seq > maxi) longestSeq = seq;
            
        }    
    }
    cout<<neededCleaners<<' '<<longestSeq<<'\n';
    delete[] rooms;
    delete[] isCleaned;
}

//zad1
int clean(bool* visited, int num, int* rooms){
    int cnt = 0;
    while(!visited[num]){
        visited[num] = true;
        num = rooms[num];
        
        cnt++;
    }
    return cnt;
}
void countRooms(){
    int N;
    cin>>N;
    int* rooms = new int[N];
    int neededCleaners = 0;
    int longestSeq = 0;
    for(int i = 0;i<N;i++){
        cin>>rooms[i];
    }
    
    bool* visited = new bool[N];
    for(int i = 0;i<N;i++){
        if(!visited[i]){
            neededCleaners++;
            int seq = clean(visited, i, rooms);
            longestSeq = max(longestSeq, seq);
        }
    }
    cout<<longestSeq<<' '<<neededCleaners;
   
}

2/
//zad2
bool existPath(vector<vector<int>>& maze, int x, int y){
    int n = maze.size();
    int m = maze[0].size();
    
    if(x < 0 || x>= n || y < 0 || y>= m) return false;
    
    if(maze[x][y] == 1||maze[x][y] == 2) return false;
    
    maze[x][y] = 2; //mark as visited
    if(x == n-1 && y == m-1) return true;
    if(existPath(maze, x-1, y) || existPath(maze, x+1, y)||existPath(maze,x,y-1)||existPath(maze,x,y+1)) return true;
    
    return false;
}
int main(){
  vector<vector<int>> lab = {
      {0,0,0,0},
      {1, 1,0,0},
      {1, 1, 1,0},
      {0,0,0,0,},
  };
   
    cout<<existPath(lab,0,0);


bool isValid(const pair<int, int>& pos, int rows, int cols){
    return (pos.first >= 0 && pos.first <=rows - 1 && pos.second >= 0 && pos.second <= cols-1); 
}
bool existPath(vector<vector<int>>& matrix, const pair<int, int>& start, const pair<int, int>& end){
    if(!isValid(start, matrix.size(), matrix[0].size())) return false;
    if(matrix[start.first][start.second] == 1||matrix[start.first][start.second] == 2){//2 - posetena
        return false;
    }
    if(start.first == end.first&& start.second == end.second){
        return true;
    }
    matrix[start.first][start.second] =2;
    if((existPath(matrix, {start.first-1, start.second}, end))  ||
    (existPath(matrix, {start.first+1, start.second}, end))  ||
    (existPath(matrix, {start.first, start.second-1}, end))  ||
    (existPath(matrix, {start.first, start.second+1}, end))) return true;

return false;

}

//3
void generateSubsets(vector<int>& nums,vector<int>& current, vector<vector<int>>& subsets, int idx){
    if(idx == nums.size()){
        subsets.push_back(current);
        return;
    }
    
    current.push_back(nums[idx]);
    generateSubsets(nums, current, subsets, idx+1);
    current.pop_back();
    generateSubsets(nums,current, subsets, idx+1);
}
4//
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0] - a[1]  < b[0] - b[1];
}
int twoCity(vector<vector<int>>& costs){
    sort(costs.begin(), costs.end(), cmp);
    //sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
    //    return a[0]-a[1] < b[0]- b[1];
    //})
    for(auto& v : costs){
        cout<<v[0]<<' '<<v[1]<<'\n';
    }
    int size = costs.size()/ 2;
    int result;
    for(int i = 0;i<size;i++){
        result += costs[i][0]+costs[i+size][1];
    }
}

int twoCitySchedCost(vector<vector<int>>& costs) {
      sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] - a[1] < b[0] - b[1];
      });
      int sum = 0;
      int s = costs.size() - 1;
      for(int i = 0;i<costs.size()/2;i++){
        sum += (costs[i][0] + costs[s-i][1]);
      }
      return sum;

    }

5//
void countingSort(vector<int>& arr){
    vector<int> positive(101);
    vector<int> negative(101);
    vector<pair<int, int>> pairs;
    
    for(int i = 0;i<arr.size();i++){
        pairs.push_back({arr[i], i});
    }
    for(int i = 0;i<arr.size();i++){
        if(arr[i]>= 0){
        positive[arr[i]]++;
        }
        else{
            negative[-arr[i]]++;
        }
    }
    for(int i = 0;i<101;i++){
        for(int j = 0;j<positive[i];j++){
            cout<<i<<' ';
        }
         for(int j = 0;j<negative[i];j++){
            cout<<-i<<' ';
        }
    }
    
}
//solution 2
void partition(vector<int>& ar, size_t pivot){
    int left = 0;
    int right = ar.size() - 1;
    
    while(left < right){
     while(abs(ar[left]) <=pivot){
         left++;
         if(left >= right) break;
     }    
     while(abs(ar[right]) > pivot){
         right--;
         if(left >= right) break;
     }
     if(left >= right) break;
     swap(ar[left], ar[right]);
    }
    
}
int main(){
    
    vector<int> ar = {1, 3, -2, 5,2,-7, 8, 10, -9, 9};
    int pivotIdx = 0;
    for(int i = 0;i<100;i++){
        partition(ar, i);
        //cout<<ar[i]<<' ';
    }
        for(int i = 0;i<ar.size();i++){
       // int pivotIdx = partition(ar, ar[i]);
        cout<<ar[i]<<' ';
    }
    //countingSort(ar);
     return 0;
}
//
int partition(vector<int>& arr, size_t pivot){
    size_t left = 0;
    size_t right = arr.size() -1;
    while(left < right){
        while(abs(arr[left])<=pivot){
            left++;
            if(left >= right){
                break;
            }
        }
        while(abs(arr[right]) >=pivot){
            right--;
            if(left >= right){
                break;
            }
        }
        if(left >= right){
                break;
            }
        swap(arr[left], arr[right]);
    }
    
    return left;
}
void solution2(vector<int>& ar){
    size_t pivotIdx = 0;
    for(size_t i = 0;i<=100;i++){
        pivotIdx = partition(arr, i);
    }
}
//
void partition(vector<int>& ar, size_t pivot){
    int left = 0;
    int right = ar.size() - 1;
    
    while(left < right){
     while(abs(ar[left]) <=pivot){
         left++;
         if(left >= right) break;
     }    
     while(abs(ar[right] >= pivot)){
         right--;
         if(left >= right) break;
     }
     if(left >= right) break;
     swap(ar[left], ar[right]);
    }
}
//merge sort with indexes and numbers
void merge(vector<pair<int, int>>& ar, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<pair<int,int>> L(n1);
    vector<pair<int,int>> R(n2);
    for(int i = 0;i<n1;i++) L[i] = ar[start+i];
    for(int j = 0;j<n2;j++) R[j] = ar[mid + 1+j];
    int i = 0;
    int j = 0;
    int k = start;
    while(i < n1 && j < n2){
        if(L[i].first <= R[j].first) {
            ar[k++] = L[i++];
        }
        else{
            ar[k++] = R[j++];
        }
    }
    while(i < n1){
        ar[k++] = L[i++];
    }
    while(j<n2){
        ar[k++] = R[j++];
    }
    
}
void mergeSort(vector<pair<int, int>>& ar, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        mergeSort(ar, start, mid);
        mergeSort(ar, mid+1, end);
        merge(ar, start, mid, end);
    }
}
int main(){
    
    vector<int> ar = {1, 3, -2, 5,2,-7, 8, 10, -9, 9};
    int n = ar.size();
    vector<pair<int, int>> ar2(n);
    
    
    int pivotIdx = 0;
    for(int i = 0;i<n;i++){
        ar2[i] = {ar[i],i};
        
        //cout<<ar[i]<<' ';
    }
    mergeSort(ar2, 0, n);
        for(int i = 0;i<ar2.size();i++){
       // int pivotIdx = partition(ar, ar[i]);
        cout<<ar2[i].first<<' '<<ar2[i].second<<'\n';
    }
  
     return 0;
}

6/
void merge(vector<int>& first, vector<int>& second,vector<pair<int,int>>& arr){
    int firstIdx = 0;
    int SecondIdx = 0;
    int ResultIdx = 0;
    while(firstIdx < first.size(), SecondIdx<second.size()){
        if(first[firstIdx] <= second[SecondIdx]){ //= za stabilnost
            arr[ResultIdx] = first[firstIdx++];
        }
        else{
            arr[ResultIdx] = second[SecondIdx++];
        }
        ResultIdx++;
    }
    while(firstIdx<first.size()){
        arr[ResultIdx++] =first[firstIdx++];
    }
    while(SecondIdx < second.size()){
        arr[ResultIdx++] = second[SecondIdx++];
    }
}
void ex6(vector<int>& arr){
    vector<int> even;
    vector<int> odd;
    vector<pair<int, int>> arr2;
    for(int i = 0;i<arr.size();i++){
        if(i%2 == 0)even.push_back(arr[i]);
        else odd.push_back(arr[i]);
        arr2.push_back({arr[i], i});
    }
    reverse(odd.begin(), odd.end());
    merge(even, odd, arr);
}
//
void reverse(vector<pair<int, int>>& ar, int N){
    for(int i = 0;i<N/2;i++){
        swap(ar[i], ar[N-i-1]);
    }
}
void merge(vector<pair<int, int>>& ar, int start, int end){
    int midSize = ar.size()/2;
    vector<pair<int,int>> L(midSize);
    vector<pair<int,int>> R(midSize);
    int y=0, u=0;
    for(int i = 0;i<ar.size();i++){
        if(i%2 == 0){
            L[y++] = ar[i];
        }    
        else{
            R[u++] = ar[i];
        }
    }
    reverse(R, midSize);
    
    
    int i = 0;
    int j = 0;
    int k = start;
    
    while(i < midSize && j < midSize){
        if(L[i].first <= R[j].first) {
            ar[k++] = L[i++];
        }
        else{
            ar[k++] = R[j++];
        }
    }
    while(i < midSize){
        ar[k++] = L[i++];
    }
    while(j<midSize){
        ar[k++] = R[j++];
    }
    
}

//zadachi Exam
1/Counting Sort
using namespace std;
int maxi(vector<int>& ar){
    int maxi = 0;
    int size =ar.size();
for(int i = 0;i <size ;i++){
    if(ar[i] > maxi) maxi = ar[i];
}
    return maxi;
}
void print(vector<int>& ar){
  int size = maxi(ar);
    
  vector<int> counter(size+1);
  for(size_t i = 0;i<ar.size();i++){
     counter[ar[i]]++;
  }
    for(int i = 0;i<counter.size();i++){
if(counter[i] > 0) cout<<i<<' ';}
}
2/Frequent symbols
int partition(vector<pair<char, int>>& ar, int low, int high){
        int pivot = ar[high].second;
        int i = low;
        for(int j = low;j<high;j++){
            if(ar[j].second >= pivot){
                swap(ar[i], ar[j]);
                i++;
            }
        }
        swap(ar[i], ar[high]);
        return i;
    }
    void quicksort(vector<pair<char, int>>& ar, int low, int high){
        if(low < high){
            int pi = partition(ar,low, high);
            quicksort(ar, low, pi-1);
            quicksort(ar, pi+1, high);
        }
    }
public:
    string frequencySort(string s) {
        vector<pair<char, int>> countsLower(26);
        vector<pair<char, int>> countsUpper(26);
        vector<pair<char, int>> countsDigits(10);
        for(int i = 0;i<26;i++){
            countsLower[i].first =  i + 'a';
            countsUpper[i].first = i+'A';
            if(i < 10) countsDigits[i].first = i+'0';
        }
        for(int i = 0;i<s.length();i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
            countsLower[s[i]-'a'].second++;}
            else if(s[i]>= 'A'&&s[i]<='Z'){
                countsUpper[s[i]-'A'].second++;
            }
            else{
                countsDigits[s[i]-'0'].second++;
            }

        }
         vector<pair<char, int>> finalCounts;
         for(int i = 0;i<26;i++){
            if(countsLower[i].second > 0)finalCounts.push_back(countsLower[i]);
            if(countsUpper[i].second > 0)finalCounts.push_back(countsUpper[i]);
         }
         for(int i = 0;i<10;i++){
            if(countsDigits[i].second > 0)finalCounts.push_back(countsDigits[i]);
         }


         string res;
        quicksort(finalCounts, 0, finalCounts.size()- 1);
        for(int i = 0;i<finalCounts.size();i++){
            cout<<finalCounts[i].first<<' '<<finalCounts[i].second<<'\n';
            for(int j = 0;j<finalCounts[i].second;j++){
                res += finalCounts[i].first;
            }
        }
        return res;

    }

3/Non-overlapping intervals
Idea
1/sort by the end time of the interval
2/if previous end > new Start -> they overlap -> count--;
3/Else if they not overlap we set the current end time to the last end time - cause the last two intervals dont overlap
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
/wrong idea
    //     int cnt = intervals.size();
    //     sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
    //         return a[1] - a[0] > b[1]-b[0];
    //     });
    //     for(int i = 0;i<intervals.size()-1;i++){
    //         for(int j = i+1;j<intervals.size();j++){
    //             if(!((intervals[i][0] >= intervals[j][1] && intervals[i][1] >= intervals[j][1])|| (intervals[i][0] <= intervals[j][0] && intervals[i][1] <= intervals[j][0]))){
    //                 cnt--;break;
    //             }
    //         }
    //     }
    //     return intervals.size()- cnt;
    // }
       int cnt = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int currEnd = intervals[0][1];
        for(int i = 1;i<intervals.size();i++){
            if(currEnd > intervals[i][0]) {
            cnt--;
            }
            else currEnd = intervals[i][1];

        }
        return intervals.size() -cnt;}



3/Counting Sort -Ex2
int IDX(string txt, char el){
    int size=txt.length();
for(int i = 0;i<size;i++)
{
if(txt[i] == el) return i;
}
    return -1;
}
void printIdx(string txt){
    vector<int> f;
vector<int> l(26);
    vector<int> u(26);
    vector<int> d(10);
    int size = txt.length();
    for(int i = 0;i<size;i++){
    if(txt[i] >= 'a' && txt[i]<='z'){
     l[txt[i]-'a']++;
    }
    else if(txt[i]>='A' && txt[i]<= 'Z'){
     u[txt[i]-'A']++;
    }
        else{
    d[txt[i]-'0']++;
        }
    }
    for(int i = 0;i<26;i++){
      if(l[i] == 1){
          f.push_back(IDX(txt, i+'a'));
      }
        if(u[i] == 1){
            f.push_back(IDX(txt, i+'A'));
}
    }
    for(int i = 0;i<10;i++){
    if(d[i] == 1)f.push_back(IDX(txt, i+'0'));
    }
    
    sort(f.begin(), f.end());
    int s = f.size();
    for(int i = 0;i<s;i++){
     cout<<f[i]<<' ';
    }

}
int main() {
    string txt;
    cin>>txt;
    printIdx(txt);

//3
void SelectionSort(vector<vector<int>>& score, int k){
    for(int i = 0;i<score.size()-1;i++){
        int minidx = i;
        for(int j = i+1;j<score.size();j++){
            if(score[minidx][k] < score[j][k]) minidx = j;
        }
        if(minidx != i) swap(score[minidx], score[i]);
    }
}
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
       SelectionSort(score,k);
       return score;
    }
4//Merge intervals
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> finalIntervals;
        
        vector<int> current = {intervals[0][0], intervals[0][1]};
        for(int i = 1;i<intervals.size();i++){
            while(i <= intervals.size()-1 && current[1] >= intervals[i][0]){
                current = {min(current[0], intervals[i][0]), max(intervals[i][1], current[1])};
                i++;
              
               
                
            }
            
             cout<<current[0]<<' '<<current[1]<<'\n';
                finalIntervals.push_back(current);
                if(i>=intervals.size()) break;
                current = intervals[i];
                if(i == intervals.size()-1)finalIntervals.push_back(current);

            
        }
        return finalIntervals;
    }  
 int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

//3 Exam
int max(vector<int>& ar){
int maxi = 0;
    int size = ar.size();
    for(int i = 0;i<size;i++){
     if(maxi < ar[i]) maxi = ar[i];
    }
    return maxi;
}
void print(vector<int>& ar){
    int maxi = max(ar);
    vector<int> counts(maxi+1);
    int size = ar.size();
for(int i = 0;i<size;i++){
   counts[ar[i]]++;
}
    vector<int> counts1 = counts;
    int size1 = counts.size();
for(int j = 1;j<size1;j++){
 counts[j]+=counts[j-1];

}
    
//     for(int j = 0;j<size1;j++){
//  cout<<counts1[j]<<' ';

// }
//    cout<<'\n';
    int s = counts[1];
    for(int y = 0;y<size;y++){
        cout<<(counts[ar[y]]-counts1[ar[y]])<<' ';
        counts[ar[y]]++;
            
    }
}
//Ex 3 Hard Countig sort with objects
int max(vector<pair<int, string>>& ar){
int maxi = 0;
    int size = ar.size();
    for(int i = 0;i<size;i++){
        if(maxi < ar[i].first) maxi = ar[i].first;
}
    return maxi;
}
void sort(vector<pair<int, string>>& ar){
    int size=ar.size();
    vector<pair<int, string>> ar1(size);
    int size1 = max(ar);
    vector<int> counts(size1+1);
    for(int i = 0;i<size;i++){
counts[ar[i].first]++;
    }
    for(int i = 1;i<size1+1;i++){
    counts[i] += counts[i-1];
    }
    for(int i = size-1;i>=0;i--){
ar1[counts[ar[i].first]-1] = ar[i];
        counts[ar[i].first]--;
    
    }
    
    for(int y = 0;y<size;y++){
    cout<<ar1[y].first<<' '<<ar1[y].second<<'\n';
    }
    
}
int main() {
    vector<pair<int, string>> ar = {{1, "hshs"}, {2, "kjshjhs"}, {1, "ksjs"}, {3, "hjaa"}, {2, "lsjs"}};
    sort(ar);

//4SUM problem 
/Quick sort & Insertion sort
 void InsertionSort(vector<int>& ar){
        int n = ar.size();
        for(int i = 1;i<n;i++){
            int j= i-1;
            int key = ar[i];
            while(j>= 0 && ar[j]>key){
                ar[j+1] = ar[j];
                j--;
            }
            ar[j+1] = key;
        }
    }
    int partition(vector<int>& ar, int low, int high){
        int pivot = ar[high];
        int i = low;
        for(int j = low;j<high;j++){
           if(ar[j]<=pivot) {
            swap(ar[j], ar[i]);
            i++;
           }

        }
        swap(ar[i], ar[high]);
        return i;

    }
    void quicksort(vector<int>& ar, int low, int high){
        if(low < high){
        int pi = partition(ar, low, high);
        quicksort(ar, low, pi-1);
        quicksort(ar, pi+1, high);
        }

    }
    bool isInThere(vector<vector<int>>& ar, vector<int>& ar1){
        for(int i = 0;i<ar.size();i++){
            if(ar[i] == ar1) return 1;
        }
        return 0;
    }
     vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
       // InsertionSort(nums);

       quicksort(nums, 0, nums.size()-1);
       int n = nums.size();
       for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            //if()
           long targ = (long)target - (long)nums[i] - (long)nums[j];
            
            int start = j;
            int end = n-1;
            while(start < end){
                if(start == i || start == j) {start++;continue;}
               if(end == i || end == j) {end--;continue;}
                long sum = nums[start] + nums[end];
                if(sum > targ) end--;
                else if(sum == targ){
                     vector<int> vec = {nums[i], nums[j], nums[start], nums[end]};
                if(!isInThere(result,vec))
                { result.push_back(vec);}
                start++; end--;
                }
                else start++;
            }


        }
//zadachi leetcode
1/
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return sqrt(a[0]* a[0] + a[1]*a[1]) < sqrt(b[0]*b[0]+b[1]*b[1]);
        });
        vector<vector<int>> result;
        for(int i = 0;i<k;i++){
               result.push_back(points[i]);
        }
        return result;
    }
2/Arrow balloons 
int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
       });

       int cnt = 1;
       vector<int> current = points[0];
       for(int i = 1;i<points.size();i++){
           while(i < points.size() && (current[1] >= points[i][0] || current[0] >= points[i][1])){
            
            current = {max(current[0], points[i][0]), min(current[1], points[i][1])};
            i++;
           }
           if(i == points.size()) break;
           cnt++;
           current = points[i];


       } 
       return cnt;
3/Insert Interval
/My solution - 50% tests passed
class Solution {
public:
void Sort(vector<vector<int>>& intervals){
   sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
   });


}
bool isThere(vector<vector<int>>& intervals, vector<int>& ar){
    for(int i = 0;i<intervals.size();i++){
        if(intervals[i] == ar) return 1;
    }
    return 0;
}
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
             int size = intervals.size();
                  vector<vector<int>> result; 
             if(size == 0) {
                result.push_back(newInterval);
                return result;}
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0]<b[0];
        });
   
        int i = 0;
        while(i < size && ((newInterval[0] > intervals[i][0] && newInterval[0]>intervals[i][1])||(newInterval[1]<intervals[i][0]&&newInterval[1]<intervals[i][1]))){
            result.push_back(intervals[i]);
            i++;

        }
        
       // cout<<i;
        if(i == size){result.push_back(newInterval);Sort(result);return result;}
        //if(i == size && size == 1) {result.push_back({min(newInterval[0], intervals[0][0]), max(newInterval[1], intervals[0][1])});return result;}
        vector<int> current = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
        
        if(size == 1){result.push_back(current);  Sort(result);return result;}
        for(;i<size;i++){
               
            if(current[0]<=intervals[i][0]&&current[1]>=intervals[i][1]) {
                current =  {min(current[0], intervals[i][0]), max(current[1], intervals[i][1])};
                if(!isThere(result, current)){result.push_back(current);}
                continue;}
            
            while(i < size && ((current[1]<= intervals[i][1]&&current[1] >= intervals[i][0])
            ||(current[0]<=intervals[i][1]&&current[0]>=intervals[i][0]))){
                
               // cout<<intervals[i][0]<<' '<<intervals[i][1];
                current = {min(current[0], intervals[i][0]), max(current[1], intervals[i][1])};
                i++;
                cout<<current[0]<<' '<<current[1];
            }
          
          //  if(i == size) break;
            if(!isThere(result, current)){result.push_back(current);}
            if(i == size-1)result.push_back(intervals[i]);
            i++;


        }
        // while(i < size && (intervals[i][0]<newInterval[0] && intervals[i][1]<newIntervals[0])||(intervals[i][0]>newInterval[1] && intervals[i][0]>newIntervals[1])){
        //     result.push_back(intervals[i]);i++;
        // }
        // if(i == size - 1) result.push_back(newInterval);
        // else{
        //  current = intervals[i];
        //  i++;
        //  for(;i < size;i++){
        //     while(i< size && (current[0]<= intervals[i][1] || current[1] >= intervals[i][0])){
        //         current = {min(current[0], intervals[i][0]), max(current[1], intervals[i][1])};
        //         i++;
        //     }
        //     result.push_back(current);
        //  }
          

        Sort(result);
        return result;
      
    }
};

/cahtGpt solution 
void Sort(vector<vector<int>>& intervals){
   sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
   });


}
bool isThere(vector<vector<int>>& intervals, vector<int>& ar){
    for(int i = 0;i<intervals.size();i++){
        if(intervals[i] == ar) return 1;
    }
    return 0;
}
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
             int size = intervals.size();
                  vector<vector<int>> result; 
             if(size == 0) {
                result.push_back(newInterval);
                return result;}
        Sort(intervals);
   
        int i = 0;
        while(i < size && ((newInterval[0] > intervals[i][0] && newInterval[0]>intervals[i][1])||(newInterval[1]<intervals[i][0]&&newInterval[1]<intervals[i][1]))){
            result.push_back(intervals[i]);
            i++;

        }
          vector<int> current = newInterval;    
     
    
            while(i < size && current[0]<=intervals[i][1] && current[1]>=intervals[i][0]){
                
            
                current = {min(current[0], intervals[i][0]), max(current[1], intervals[i][1])};
                i++;
                cout<<current[0]<<' '<<current[1];
            }
            result.push_back(current);
            while(i < size){
                result.push_back(intervals[i]);
                i++;
            }     


          

        Sort(result);
        return result;
      
    }
Radix Sort
int max(vector<int>& ar){
    int maxo = 0;
    for(int i = 0;i<ar.size();i++){
        if(maxo< ar[i]) maxo =ar[i];
    }
    int expo = 0;
    while(maxo){
        expo++;
        maxo /=10;
    }
    return expo;
}
int power(int base, int stepen){
    int c= 1;
    for(int i = 0;i<stepen;i++){
        c*=base;
    }
    return c;
}
void countingSort(vector<int>& ar, int expo){
    vector<int> counts(10);
    for(int i = 0;i<ar.size();i++){
        int digit = (ar[i]/expo) % 10;
        counts[digit]++;
        
    }
    for(int i = 1;i<10;i++){
        counts[i]+=counts[i-1];
    }
    vector<int> output(ar.size());
    for(int j = ar.size() - 1;j>=0;j--){
        int digit = (ar[j] / expo) % 10;
        output[counts[digit] - 1] = ar[j];
        counts[digit]--;
    }
    for(int y = 0;y<ar.size();y++){
        ar[y] = output[y];
    }
    
}
void RadixSort(vector<int>& ar){
    int expo = max(ar);
    for(int i = 1;i<power(10, expo);i*=10){
        countingSort(ar, i);
    }
}

//zad ice cream
 int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0;
        int i = 0;
        sort(costs.begin(), costs.end());

        for(int i = 0;i<costs.size();i++){
            coins-=costs[i];
            if(coins<0)break;
            cnt++;
        }
  
     return cnt;
    }

//zad
  vector<int> sortArrayByParityII(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int size = nums.size();
        vector<int> Odd;
        vector<int> Even;
        for(int i = 0;i<nums.size();i++){
           if(nums[i]%2 == 0) Even.push_back(nums[i]);
           else Odd.push_back(nums[i]);
        }
        int k=0;
        int h = 0;
        for(int j = 0;j<size;j++){
           if(j%2 == 0) nums[j] = Even[k++];
           else nums[j] = Odd[h++];

        }
        return nums;

//zad - Kontrolno 1
int max(vector<int>& ar, int N){
    int maxi =0;
    for(int i = 0;i<N;i++){
        if(ar[i]> maxi) maxi = ar[i];
    }
    return maxi;
}
vector<int> Result(vector<int>& ar, int N){
    vector<int> result(N);
    int maxEl = max(ar, N);
    vector<int> counts(maxEl+1);
    for(int i = 0;i<N;i++){
        counts[ar[i]]++;
    }
    vector<int> Helper = counts;
    for(int i = 1;i<maxEl+1;i++){
        counts[i]+=counts[i-1];
        
    }
    // for(int h = 0;h<maxEl+1;h++){
    //     counts[h]-=Helper[h];
    // }
//counting sort s ideqta che toi ni pokazva do koi idx shte ni byde syotvetnoto chislo
//count[i]+=count[i-1]
//2-3 tova oznachava che do idx = 2 shte imame dvojki => ot idx = 3 do kraq na masiva chislata shte sa po-golemi
//za da namerim kolko na broj sa chislata po-golemi ot dadeno chislo prosto vadim ot broq na vsichki elementi  - idx, do kojto
//ni stiga syotvetnoto chislo v counting sorta
//primer ako 2->3 a size na vectora e 10 tova oznachava che na pozicii - 4,....10 imame chisla po-golemi ot 2 - demek
//prosto Vadim ot 10 - 3 = 7 chisla > 2

    for(int u = 0;u<N;u++){
        result[u] =N - counts[ar[u]];
    }
    
      for(int u = 0;u<N;u++){
        cout<<result[u]<<' ';
    }
    return result;
    
    
    
}
int main(){
    int N;
    cin>>N;
    vector<int> ar(N);
    for(int i = 0;i<N;i++){
        cin>>ar[i];
    }
    Result(ar, N);
    
    return 0;
}
