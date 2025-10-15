//zad anketa

#include <iostream>
void swap(int& a, int& b){
    int h = a;
    a = b;
    b = h;
}
void SelectionSort(int ar[], int n){
    
for(int i = 0;i<n-1;i++){
    int minidx = i;
    for(int j = i+1;j<n;j++){
        if(ar[minidx] > ar[j]){
            minidx = j;
        }
    }
    if(minidx != i){
        swap(ar[i], ar[minidx]);
    }
}
}
bool areThereTwoEqNums(int ar[], int n){
    SelectionSort(ar, n);
   
    for(int h = 0;h<n-1;h++){
        if(ar[h] == ar[h+1]){
            return true;
        }
    }
    return false;
}
int main()
{
    int ar[5] = {22, 33, 22, 11,1};
   
    std::cout<<areThereTwoEqNums(ar, 5);

    return 0;
}

zadachi week 1 prac
1/

bool isThereSumTarget(int ar[],int n, int target) {
	SelectionSort(ar, n);
	int start = 0;
	int end = n-1;
	while(start <= end) {
		if(ar[start] + ar[end] == target) {
			return true;
		}
		else if(ar[start] + ar[end] > target) {
			end--;
		}
		else {
			start++;
		}
	}
	return false;
}

int maxProfit(int ar[], int n){
    int maxi = 0;
    int min =ar[0];
    
    for(int h = 0;h<n;h++){
        if(maxi < ar[h]){
            maxi = ar[h];
        }
        if(min > ar[h]){
            min = ar[h];
        }
    }
    return (maxi - min);
}


int len(char text[]){
    int count = 0;
    int i = 0;
    while(text[i] != '\0'){
        count++;
        i++;
    }
    return count;
}
int longestStringUniqueSymbols(char text[]){
    int letters[26] = {};
    int n = len(text);
    bool flag = false;
    int l = 0;
    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){
            letters[text[j] - 'a']++;
            if(letters[text[j]-'a'] > 1){
        
                if(l < j-i) l = j-i;
                break;
                
            }
        }

        for(int i = 0;i < 26;i++){
        letters[i] = 0;
            
        }

    }
    return l;
}


bool UniqueSymbols(char text[], int start, int end){
    int letters[26] = {};
    for(int i = start;i<= end;i++){
        letters[text[i] - 'a']++;
        if(letters[text[i] - 'a'] > 1){
            return false;
        }
    }
    return true;
}
int longestStringUniqueSymbolsFaster(char text[]){
    int letters[26] = {};
    int n = len(text);
    int l = 0;
    int start = 0;
    int end = 0;
    while(end <= n){
        if(UniqueSymbols(text, start, end)){
            end++;
        }
        else{
            if(l < end-start) l = end-start;
            start++;
        }
    }
   

    
    return l;
}

//rain blocks
int quantityFilledWater(int ar[], int n){
    int left = 0;
    int right = n-1;
    int quantity = 0;
    int maxi = 0;
    while(left <= right){
   
       
        if(ar[left] <= ar[right]){
            
            if(maxi < ar[left]) maxi = ar[left];
            quantity += maxi - ar[left];
         
            left++;
        }
        else{
    
            if(maxi < ar[right]) maxi = ar[right];
            quantity += maxi - ar[right];
            right--;
        }
    }
    return quantity;
    
}
//zad longest seq


#include <iostream>
int len(char text[]){
    int count = 0;
    int i = 0;
    while(text[i] != '\0'){
        count++;
        i++;
    }
    return count;
}
int longestStringUniqueSymbols(char text[]){
    int letters[26] = {};
    int n = len(text);
    bool flag = false;
    int l = 0;
    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){
            letters[text[j] - 'a']++;
            if(letters[text[j]-'a'] > 1){
        
                if(l < j-i) l = j-i;
                break;
                
            }
        }

        for(int i = 0;i < 26;i++){
        letters[i] = 0;
            
        }

    }
    return l;
}
bool UniqueSymbols(char text[], int start, int end){
    int letters[26] = {};
    for(int i = start;i<= end;i++){
        letters[text[i] - 'a']++;
        if(letters[text[i] - 'a'] > 1){
            return false;
        }
    }
    return true;
}
int longestStringUniqueSymbolsFaster(char text[]){
    int letters[26] = {};
    int n = len(text);
    int l = 0;
    int start = 0;
    int end = 0;
    while(end <= n){
        if(UniqueSymbols(text, start, end)){
            end++;
        }
        else{
            if(l < end-start) l = end-start;
            start++;
        }
    }
   

    
    return l;
}

int quantityFilledWater(int ar[], int n){
    int left = 0;
    int right = n-1;
    int quantity = 0;
    int maxi = 0;
    while(left <= right){
   
       
        if(ar[left] <= ar[right]){
            
            if(maxi < ar[left]) maxi = ar[left];
            quantity += maxi - ar[left];
            //std::cout<<quantity<<' '<<left<<'\n';
            left++;
        }
        else{
    
            if(maxi < ar[right]) maxi = ar[right];
            quantity += maxi - ar[right];
            right--;
        }
    }
    return quantity;
    
}
int power(int base, int stepen){
    int count = 1;
    for(int i = 0;i<stepen;i++){
        count *= base;
    }
    return count;
}
int lenNum(long num){
    int count = 0;
    while(num){
        num /=10;
        count++;
    }
    return count;
}
int* longArConverter(long num, int len){
    
    int* ar = new int[len];
    
    for(int i = 0;i<len;i++){
        ar[i] = (num / power(10, len-i-1)) % 10;
       // std::cout<<ar[i]<<' ';
    }
    return ar;
 }
void printLongestSequence(long num){
    int len = lenNum(num);
    int* ar = longArConverter(num, len);
    
    int start = 0;
    int finalStart = 0;
    int finalEnd = 0;
    int end = 0;
    int maxi = 0;
 
    for(int i = 0;i<len-1;i++){
        if(ar[i] < ar[i+1]){
            end++;
            
        }
        
        else{
        
            if(maxi < end-start+1) {
                maxi = end-start+1;
                finalStart = start;
                finalEnd = end;
            }
            end++;
            start = end;
        }
        
    }
    for(int y = finalStart;y<=finalEnd;y++){
        std::cout<<ar[y]<<' ';
    }
}
int main()
{
	//int ar[6] = {1, 0, 3, 1,2, 7};
	long num = 12123413;
	
	printLongestSequence(num);
   // char ar[78] = "affadagghsgshgsastyxdfuiwqaa";
	//std::cout<<quantityFilledWater(ar, 6);

	return 0;
}

//zadachi week 1 SDA - 2023

//1
#include <iostream>
int len(char text[]){
    int count = 0;
    int i = 0;
    while(text[i] != '\0'){
        count++;
        i++;
    }
    return count;
}
int countSymbols(char word[], int N, char symbol){
    int ln = len(word);

    int count = 0;
    for(int i = 0;i<N;i++){
        if(word[i % ln] == symbol) count++;
    }
    return count;
    
}

//zad terziev nuli
void swap(int& a, int& b){
    int h = a;
    a = b;
    b = h;
}
void moveNulls(int* ar, int n){
    int read = 0;
    int write = 0;
  
   while(true){
       if(read == n-1 || write == n-1){
           break;
       }
      while(ar[read] != 0){
         read++;
     }   
    
     write = read;
     while(ar[write] == 0){
         write++;
     }
     
     swap(ar[read], ar[write]);
    
   }
    
    
}
//2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(char& a, char& b){
int help = a;
a = b;
b = help;
}
void SelectionSort(vector<char>& letters){
    int len = letters.size();
for(int i = 0;i<len - 1;i++){
    int minidx = i;
    for(int j = i+1;j<len;j++){
        if(letters[minidx] > letters[j]) minidx = j;
}
    if(minidx != i){
swap(letters[minidx], letters[i]);
    }
}
}
void printSortedKStudents(){
    int size;
    cin>>size;
    int K;
    cin>>K;
    char buffer[size+1];
    cin.ignore();
    cin.getline(buffer, size+1);
    vector<int> letters(26);
    vector<char> finalLetters;
    for(int j = 0;j<size;j++){
        if(buffer[j] >= 'a' && buffer[j] <= 'z') continue;
        letters[buffer[j] - 'A']++;
}
     for(int j = 0;j<26;j++){
        if(letters[j]>=K) finalLetters.push_back('A' + j);
}
    SelectionSort(finalLetters);
    int lenprim = finalLetters.size();
    for(int h = 0;h<lenprim;h++){
        cout<<finalLetters[h];
}
    
    
}
int main() {
    
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        printSortedKStudents();
        cout<<'\n';
}
    return 0;
}
//3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int pow(int base, int stepen){
    int count = 1;
for(int y = 0;y<stepen;y++){
    count*=base;
}
return count;
}
int countOnes(int num){
    int count = 0;
    while(num){
        count += num & 1;
        num = num >> 1;
}
    return count;
}
bool checkBit(int num, int k){
    num = num>>k;
    return num & 1;
}
int minMax(int ar[],int N, int num){
    int max = 0;
    int min = -1;
   
  
    for(int i = 0;i<N;i++){
        if(checkBit(num, i)){
            if(ar[N-i-1] > max) max = ar[N-i-1];
            if(ar[N-i-1] < min||min == -1) min = ar[N-i-1];
}
}
    return max-min;
}
int minDiff(int ar[], int N, int K){
    if(K > N){
        return -1; 
    }
   
    int minDiffer = -1;
    int limit = pow(2, N);
    for(int i=0;i<limit;i++){
        if(K == countOnes(i)){
          
            int diff = minMax(ar, N, i);
            if(diff < minDiffer || minDiffer == -1) minDiffer = diff;
        }
}
    return minDiffer;
    
}
int main() {
    int N, K;
    cin>>N;
    cin>>K;
    int ar[N];
    for(int i = 0;i<N;i++){
        cin>>ar[i];
    }
    //cout<<minMax(ar, N, 15);
    cout<<minDiff(ar, N, K);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(int& a, int& b){
    int h = a;
    a = b;
    b = h;
}
void SelectionSort(int* ar, int N){
    for(int i = 0;i<N-1;i++){
        int minidx = i;
        for(int j =i+1;j<N;j++){
            if(ar[minidx] > ar[j]) minidx = j;
        }
        if(minidx != i){
            swap(ar[minidx], ar[i]);
        }
    }
    // for(int y = 0;y<N;y++){
    //     cout<<ar[y]<<' ';
    // }
}

int minDiff(int ar[], int N, int K){
    SelectionSort(ar, N);
    int min = -1;
    for(int i = 0;i<N-K+1;i++){
        int diff = ar[i+K-1] - ar[i];
        if(min==-1 || min>diff) min = diff;
    }
    return min;
}
int main() {
    int N, K;
    cin>>N;
    cin>>K;
    int ar[N];
    for(int i = 0;i<N;i++){
        cin>>ar[i];
    }
    //cout<<minMax(ar, N, 15);
    cout<<minDiff(ar, N, K);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

//2022
//1
int removedSymbols(char text[], int size){
    int count = 1;
    for(int i = 0;i<size-1;i++){
        if(text[i] != text[i+1]) count++;
    }
    return size - count;
}

int main() {
    int Q;
    cin>>Q;
    for(int i = 0;i< Q;i++){
        int size;
        cin>>size;
        cin.ignore();
        char buffer[size+1];
        
        cin.getline(buffer, size+1);
        cout<<removedSymbols(buffer, size)<<'\n';
}
    
}
//2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int maxProfit(int ar[], int N){
    int buyIdx = 0;
    int sellIdx = 0;
    int profit = 0;
    while(true){
  
      while(buyIdx < N-1 && ar[buyIdx] > ar[buyIdx+1]){
          buyIdx++;
      }
      
      if(buyIdx == N-1) break;
      sellIdx = buyIdx+1;
      while(sellIdx < N-1 && ar[sellIdx] < ar[sellIdx+1]){
          sellIdx++;
      }
    
      profit += ar[sellIdx] - ar[buyIdx];
      if(sellIdx == N-1) break;
      buyIdx = sellIdx + 1;
     
    }
    return profit;
}
int main() {
    int ar[6] = {7,1,2,4,2,8};
    std::cout<<maxProfit(ar, 6);
    return 0;
}

//3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(int& a, int& b){
    int h = a;
    a = b;
    b = h;
}
void SelectionSort(int* ar, int N){
    for(int i = 0;i<N-1;i++){
        int minidx = i;
        for(int j =i+1;j<N;j++){
            if(ar[minidx] > ar[j]) minidx = j;
        }
        if(minidx != i){
            swap(ar[minidx], ar[i]);
        }
    }
  
}
int firstPositiveMissingNumber(int ar[], int N){
    SelectionSort(ar, N);
    for(int i = 0;i<N-1;i++){
        if(ar[i] >= 0 && ar[i+1] - ar[i] > 1){
return ar[i]+1;
        }
    }
    return ar[N-1] + 1;
    
}
int main() {
    int N;
    cin>>N;
    int ar[N];
    for(int i =0;i<N;i++){
        cin>>ar[i];
}
    cout<<firstPositiveMissingNumber(ar, N);
   
    return 0;
}
int firstPositiveMissingNumber(vector<int> ar, int N){
    sort(ar.begin(), ar.end());
    for(int i = 0;i<N-1;i++){
        if(ar[i] < 0 && ar[i+1] > 0){
            if(ar[i+1] > 1) return 1;
        }
        if(ar[i] >= 0 && ar[i+1] - ar[i] > 1){
            return ar[i]+1;
        }
    }
    return ar[N-1] + 1;
    
}

int main() {
    const size_t MAXNUMSIZE = 1e6+2;
    bool check[MAXNUMSIZE];
    for(size_t j = 0;j<MAXNUMSIZE;j++){
        check[j] = true;
}

    int N;
    cin>>N;
    for(size_t i = 0;i<N;i++){
        int input;
        cin>>input;
        if(input > 0 && input<MAXNUMSIZE){
            check[input] = false;
}
    }
    for(int i = 1;i<MAXNUMSIZE;i++){
        if(check[i]) {cout<< i;break;}
}

  
}

//2021
//1
int len(char buffer[]){
    int i = 0;
    while(buffer[i]!= '\0'){
i++;
    }
    return i;
}
void print(char buffer[], char symbol){
    vector<int> positions;
    int ln=len(buffer);
  for(int i = 0;i<ln;i++){
      if(buffer[i] == symbol){
          positions.push_back(i);
      }
  }
  
  bool flag = false;
  int size = positions.size();
  if(size == 1 && positions[0] == 0){
      flag = true;
      for(int i = 0;i<ln;i++){
          cout<<i<<' ';
      }
  }
  if(flag) return;
  if(positions[0] != 0){
      for(int i = positions[0];i>=0;i--){
          cout<<i<<' ';
      }
  }
  for(int i = 0;i<size-1;i++){
      if(positions[0] == 0) cout<<0<<' ';
      int diff = positions[i+1] - positions[i] - 1;
      for(int i = 1;i<=diff/2;i++){
          cout<<i<<' ';
      }
      if(diff%2==1)cout<<diff/2+1<<' ';
      for(int i = diff/2;i>=0;i--){
          cout<<i<<' ';
      }
  }
  if(positions[size-1] !=ln-1){
      for(int i = 1;i<=ln-1-positions[size-1];i++){
          cout<<i<<' ';
      }
  }
  
  
    
}
//MIN DISTANC DIIJKSTRA 1D#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int len(string buffer){
    int i = 0;
    while(buffer[i]!= '\0'){
i++;
    }
    return i;
}
void print(string buffer, char symbol){
    vector<int> positions;
    
    int ln=len(buffer);
  vector<int> finalPositions(ln);
  for(int i = 0;i<ln;i++){
      if(buffer[i] == symbol){
          positions.push_back(i);
       
        }
    }
    if(positions.empty())return;
  
  int j = 0;
  for(int i = 0;i<ln;i++){
      finalPositions[i] = abs(positions[j] - i);
      if(positions[j] == i){if(j< positions.size()-1)j++;}
  }
    

  for(int i = ln-1;i>=0;i--){
      finalPositions[i] = min(abs(positions[j] - i), finalPositions[i]);
      if(positions[j] == i){if(j>0) j--;}
  }
  
    for(int y = 0;y<ln;y++){
       cout<<finalPositions[y]<<' ';
   }
  
    
}
    
int main() {
    string s;
    getline(cin,s);
    char symbol;
    cin>>symbol;
    print(s, symbol);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

//2
int main() {
    string s;
    getline(cin, s);
    
    int N;
    cin>>N;
    
    char symbol;
    cin>>symbol;
    
    int count = 0;
    int finalCount = 0;
        int ln = s.length();
    for(int i = 0;i<ln;i++){
        if(s[i] == symbol)count++;
    }

    finalCount += count * (N/ln);
    
   int extra = N%ln;
    for(int j = 0;j<extra;j++){
if(s[j] == symbol) finalCount++;}
    cout<<finalCount;
    return 0;
}

//3
int main() {
    int N;
    cin>>N;
    int n = 1e7;
    bool check[n];
    
    for(int i = 0;i<N;i++){
        int input;
        cin>>input;
        if(input > 0){
            check[input] = true;
}}
        for(int i = 1;i<n;i++){
            if(!check[i]){
                cout<<i;
                break;
            }
        }

     
    return 0;
}
2024
//1
int findPermutationDifference(string s, string t) {
        int len = s.length();
        int count = 0;
        for(int i = 0;i<len;i++){
            char symbol = s[i];
         
            for(int j = 0;j<len;j++){
                if(symbol == t[j]) count+=abs(j-i);
            }
        }
        return count;
        }
};
//2
int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(int i = 0;i<jewels.length();i++){
            for(int j = 0;j<stones.length();j++){
                if(jewels[i] == stones[j])count++;
            }
        }
        return count;
    }
//3
bool canAliceWin(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        int sum = 0;
        for(int h=0;h<nums.size();h++){
            sum+=nums[h];
        }
        for(int i = 0;i<nums.size();i++){
            if(1 <= nums[i]&& nums[i]<=9){
                sum1+=nums[i];
            }
            else if(10<=nums[i] && nums[i]<=99){
                sum2+=nums[i];
            }
    
        }
        return(sum1>sum-sum1 || sum2>sum-sum2);
    }
//4
bool isThere(vector<int>& nums, int num){
        for(int i = 0;i<nums.size();i++){
            if(nums[i] ==num)return 1;
        }
        return 0;
    }

    vector<vector<int>> findMatrix(vector<int>& nums) {
         

        vector<vector<int>> vec;

        for(int i = 0;i<nums.size();i++){
            int j = 0;
            while(true){
                if(vec.size() == j)vec.push_back({});
                if(!isThere(vec[j], nums[i])) {vec[j].push_back(nums[i]);break;}
                j++;
            }
        }
        return vec;
    }
//5

    bool isInPair(vector<pair<int, vector<int>>>& helper, int num){
        for(int i = 0;i<helper.size();i++){
            if(helper[i].first == num) return 1;
        }
        return 0;
    }
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> vec;
        vector<pair<int, vector<int>>> helper;
        for(int i = 0;i<groupSizes.size();i++){
            vector<int> indx;
            for(int j = 0;j<groupSizes.size();j++){
                if(groupSizes[i] == groupSizes[j]){
                    indx.push_back(j);
                } 
            }
            if(!isInPair(helper, groupSizes[i]))helper.push_back({groupSizes[i], indx});
        }
    

        int k = 0;
        for(int i = 0;i<helper.size();i++){
            vec.push_back({});
            for(int j = 0;j<helper[i].second.size();j++){
                if(j % helper[i].first == 0 && j != 0) {
                    k++;
                    vec.push_back({});
                    }
                vec[k].push_back(helper[i].second[j]);
          
         
            }
            k++;
        }
        // for(int i = 0;i<vec.size();i++){
        //     for(int j = 0;j<vec[i].size();j++){
        //         cout<<vec[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
    
        return vec;
    }

zadachi - seminar 1
1//
 int singleNumber(vector<int>& nums) {
        int finali = nums[0];
        for(int i = 1;i<nums.size();i++){
           finali=finali^nums[i];
        }
        return finali;
    }
2/
  vector<int> plusOne(vector<int>& digits) {
        vector<int> finalDigits;
        int i = digits.size()- 1;
        bool flag = false;
    while(digits[i]+1 == 10){
        digits[i] = 10;
        if(i > 0) i--;
        flag = true;
        
    }

    if(digits[i] != 10) digits[i]++;
    if(digits[0]== 10)
     {finalDigits.push_back(1);digits[0] = 0;}
    for(int i = 0;i<digits.size();i++){
        if(digits[i] == 10) digits[i] = 0;
        finalDigits.push_back(digits[i]);
    }
    return finalDigits;
    }
3/
void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(k == 0 || size == 0) return;
        vector<int> newVec(size);
        k = k%size;
      
        for(int i = 0;i<k;i++){
            newVec[i] = nums[size-k+i];
        }
        for(int j = k;j<size;j++){
            newVec[j] = nums[j-k];
        }
         nums = newVec;
    }
4/
 void rotate(vector<vector<int>>& matrix) {
        vector<int> help;
        int size = matrix.size();
        for(int i = size - 1;i>=0;i--){
           for(int j = 0;j<size;j++){
              help.push_back(matrix[i][j]);
           }
        }

        int k =0;
        for(int i = 0;i<size;i++){
           for(int j = 0;j<size;j++){
              matrix[j][i] = help[k++];
           }
        }
}
5/
int maxArea(vector<int>& height) {
       int maxArea = 0;
       for(int i = 0;i<height.size()-1;i++){
        for(int j = i+1;j<height.size();j++){
            int area = min(height[i], height[j]) * (abs(j-i));
            if(area > maxArea) maxArea = area;
        }
       } 
       return maxArea;
    }

int maxArea(vector<int>& height) {
       int maxArea = 0;
       int start = 0;
       int size = height.size();
       int end = size - 1;
       while(start<=end){
        int area = (end-start)*min(height[start], height[end]);
        if(area > maxArea) maxArea = area;
        if(height[start]>height[end]){
            end--;
        }
        else{
            start++;
        }

       }
       return maxArea;
    }

6/zadacha partial merge subsets minimal diff between sums

int pow(int base, int stepen){
    int count = 1;
    for(int i = 0;i<stepen;i++){
        count *= base;
    }
    return count;
}
bool checkbit(int num, int k){
    num = num >> k;
    return num & 1;
}

int findPartialSum(int ar[], int num, int n){
    int sum = 0;
 for(int i = 0;i<n;i++){
     if(checkbit(num, i)) sum+=ar[n-i-1];
 }    
 return sum;
}
int findMinDiff(int ar[], int n){
    int size = pow(2, n);
    int totalSum =0;
    for(int i = 0;i<n;i++){
        totalSum += ar[i];
    }
    int minSum = totalSum;
    int minNum = 0;
    for(int j = 1;j<size;j++){
        
        int sumP = abs(totalSum-2* findPartialSum(ar,j, n));
        if(sumP<minSum) {minSum = sumP;minNum = j;}
    }cout<<minNum;
    
    return minSum;
} 

7/Number of islands
   bool isValid(pair<int, int> crd, int n, int m){
        return ( crd.first >= 0 && crd.first <= m-1 && crd.second >= 0 && crd.second <= n-1);
    }
    bool isInPairs(vector<pair<int, int>>& pairs, pair<int, int> crd){
        for(int i = 0;i<pairs.size();i++){
            if(pairs[i] == crd) return 1;
            }
    
    return 0;
    }
    bool hasOne(vector<pair<int, int>>& pairs,int x, int y, int n, int m){
        vector<pair<int,int>> nbs = {{x-1, y}, {x+1,y}, {x, y-1}, {x, y+1}};
        const int CountNbs = 4;
        for(int i = 0;i<CountNbs;i++){
            if(isValid(nbs[i], n, m)){
                if(isInPairs(pairs, nbs[i])) return 1;
            }
        }
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> addresses;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    addresses.push_back({i, j});
                }
            }
        }
        int countIslands = 1;
        for(int k = 0;k<addresses.size();k++){
            if(!hasOne(addresses, addresses[k].first, addresses[k].second,n,m)) countIslands++;
        }
        return countIslands;
    }
    
    }
