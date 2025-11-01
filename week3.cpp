zad1/
bool isPerfectSquare(int num) {
        int l = 1;
        int r= num;
        long m = l +(r-l)/2;
        while(l < r){
            m = l + (r-l) / 2;
            if(m * m > num){
                r = m;
            }
            else if(m*m <num){
                l = m+1;
            }
            else return true;
        }

        return m*m == num;
    }
zad2/
  int findPeakElement(vector<int>& nums) {
       int l = 0;
       int r = nums.size() - 1;
       if(nums.size() == 1) return 0;
       if(nums.size() == 2) return nums[0]>nums[1] ? 0 : 1;
       while(l<=r){
         int m = l + (r-l)/2;
 
         if(m == 0 || m == nums.size()-1) {
           return m;
         }
         else if(nums[m] > nums[m+1] && nums[m] > nums[m-1]){
            return m;
         }
         else if(nums[m] < nums[m+1]){
            l = m+1;
         }
         else{
           r = m;
         }

       }
       return -1;
    }
//Ternary Search
int ternarySearch(vector<int>& ar, int left, int right, int target){
    if(left > right) return -1;
 
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right-left) / 3;
 
    if(ar[mid1] == target) return mid1;
    if(ar[mid2] == target) return mid2;
 
    if(target < ar[mid1]){
        return ternarySearch(ar, left, mid1-1, target);
    }
    else if(target>ar[mid2]){
        return ternarySearch(ar, mid2+1, right, target);
    }
    else if(target > ar[mid1] && target < ar[mid2]){
        return ternarySearch(ar, mid1+1,mid2-1, target);
    }
 
}
//Jump Search
int JumpSearch(vector<int>& ar, int target){
    int n = ar.size();
    int prev = 0;
    int step = floor(sqrt(n));
    while(ar[min(step, n)-1] < target){
        prev = step;
        step+= floor(sqrt(n));
        if(prev >= n) return -1;
 
    }
    for(int i = prev;i<min(step, n)-1;i++){
        if(ar[i] == target) return i;
    }
    return -1;
 
}

//Homework
zad1
#include <iostream>
using namespace std;


long long pow3(int p){
    long long res = 1;
    for(int i = 0;i<p;i++){
        res*=3;
    }
    return res;
}



int getDepth(long long pos, int P){
    int depth = 1;
    long long l = 0;
    long long r = pow3(P) - 1;

    while(l < r){
        long long third = (r-l+1)/3;
        long long mid1 = l+third;
        long long mid2 = r-third;
 
        if(pos >= mid1 && pos <= mid2) return depth;
        else if(pos < mid1) {
            r = mid1-1;
        }
        else {l=mid2+1;}
        depth++;
 
    }
    return depth;
}


int main() {
    int P, N;
   cin>>P>>N;
 
    for(int i = 0;i<N;i++){
        long long num;
        cin>>num;
        cout<<getDepth(num-1,P)<<'\n';
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int pow1(int base, int stepen){
    int cnt = 1;
 for(int i = 0;i<stepen;i++){
     cnt *= base;
}
    return cnt;
 }
void splitSweets(vector<int>& ar, int depth, int left, int right){
    //int size = ar.size();
    if(left > right)return;
    int len = right - left + 1;
    if(len == 1){
       ar[left] = depth;
        return;
    }
 
    //{
        // if(left >=0 && left <= size){ar[left] = depth;}
        // else if(right >=0 && right <= size){
        //   ar[right] = depth;
        // } return;}
    int mid1 = left + len/3 -1;
    int mid2 = right-len/3 + 1;
 
    for(int y = mid1+1;y<mid2;y++){
        ar[y] = depth;
    }
  //  if(mid2 == mid1){
     //   ar[mid1] = depth;
   // }
 
    splitSweets(ar, depth+1, left, mid1);
    splitSweets(ar, depth+1, mid2, right);
 
}
int main() {
    int N;
    int P;
    cin>>P>>N;
    vector<int> guests(N);
 
    for(int i = 0;i<N;i++){
        cin>>guests[i];
    }
 
    int size = pow1(3, P);
     vector<int> guestsHelper(size);
    int d = 1;
    splitSweets(guestsHelper, d, 0, size-1);
//     for(int i = 0;i<size;i++){
 
//         cout<<guestsHelper[i]<<'\n';
 
//     }

    for(int i = 0;i<N;i++){
 
        cout<<guestsHelper[guests[i]-1]<<'\n';
 
    }
 
 
}
//zad2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t lowerBound(const vector<long long>& ar, long long target){
    size_t low = 0;
    size_t high = ar.size();

    while(low<high){
        size_t mid = low+(high-low)/2;
        if(ar[mid] < target){
            low = mid+1;
}
        else high = mid;
 
    }
    return low;
}
size_t upperBound(const vector<long long>& ar, long long target){
    size_t low = 0;
    size_t high = ar.size();
 
    while(low<high){
        size_t mid = low+(high-low)/2;
        if(ar[mid] <= target){
 
            low =mid+1;
}
        else high = mid;
 
    }
    return low;
}
int main() {
    int N;
    int Q;
    cin>>N>>Q;
    vector<long long> ar(N);
    for(int i = 0;i<N;i++){
        cin>>ar[i];
    }
    sort(ar.begin(), ar.end());
 
    for(int j = 0;j<Q;j++){
        long long n,m;
        cin>>n>>m;
        if(n>m) {cout<<0<<'\n';continue;}
       // if(n>m) swap(n,m);
    //    cout<<upperBound(ar, m)<<'\n';
        cout<<upperBound(ar, m) - lowerBound(ar, n)<<'\n';
    }
 }

//zad 3 HW
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canSplit(vector<int>& ar,int N, int k, long long maxSum){
    **long long currentSum = 0;**

    **int teams = 1;**

    

    **for(int i = 0;i<N;i++){**

        **if(ar\[i] + currentSum > maxSum){**

          **teams++;**

          **currentSum = ar\[i];**  

            **if(teams > k) return false;**

        **}**

        **else{**

           **currentSum+=ar\[i];**

            

        **}**

        

        

    **}**

    **return true;**




}
int max(vector<int>& ar, int N){
    **int maxi = 0;**

    **for(int i = 0;i<N;i++){**

      **if(maxi < ar\[i]) maxi = ar\[i];**

    **}**

    **return maxi;**

}
int main() {
    **int N;**

    **int T;**

    **cin>>N>>T;**

    **vector<int> ar(N);**

    

    **long long sumMax = 0;**

  

    

    **for(int i = 0;i<N;i++){**

        **cin>>ar\[i];**

        **sumMax += ar\[i];**

    **}**

// sort(ar.begin(), ar.end());
      **long long sumMin = max(ar, N);**

    **long long low = sumMin;**

    **long long high = sumMax;**

    

    **while(low<high){**

long long mid = low+(high-low)/2;
    **if(canSplit(ar, N, T, mid)){**

       **high = mid;**

    **}**

        **else{**

low = mid+1;}
    **}**

    **cout<<low;**

    

    **return 0;**

}
//zad - max distance
 bool canPlace(vector<int>& ar, int minSpace, int ballsCount){
        int lastPlaced = ar[0];
        int total = 1;
        for(int i = 0;i<ar.size();i++){
        if(ar[i] - lastPlaced >= minSpace){
            lastPlaced = ar[i];
            total++;
 
        }
       }
       return (total >= ballsCount);

    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0;
        int r = position.back() - position[0];
        int ans = 0;
        while(l<=r){
           int mid= l +(r-l)/2;
           if(canPlace(position,mid, m)){
            l = mid+1;
           }
           else{
            r= mid-1;
           }
        }
        return r;
    }

//zadachi - seminar Terziev
1/ int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
           int m = l +(r-l) /2;
           if(nums[m] == target) return m;
           else if(nums[m]>target) r = m-1;
           else l = m+1;
        }

        return -1;
    }
2/int mySqrt(int x) {
        if(x == 1 || x == 0) return x;
    int low = 1;
    int right = x;
    while(low <= right){
        long mid =low + (right - low) / 2;
        long n = mid * mid;
        if( n > x) {
            right = mid-1;
        }
        else if(n == x) return mid;
        else low =mid+1;
    }
    return floor(right);

    }
3/    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        while(low < high){
            int mid = low +(high - low)/2;
            if(!isBadVersion(mid)){
                low = mid+1;
            }
            else high = mid;
 
        }
        return low;
    }
4/ int searchInsert(vector<int>& nums, int target) {
       int low = 0;
       int high = nums.size() - 1;
       while(low<=high){
        int mid = low +(high - low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid]> target) {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

       }
       return low;

    }

5/Puncakes
bool canMakeNpancakes(vector<int>& times, long long N, int P, long long curTime){
long long sum = 0;
    for(int i = 0;i<P;i++){
sum += curTime / times[i];
    }
    return (sum>= N);
}
long long leastTime(vector<int>& times, long long N, int P){
    sort(times.begin(), times.end());
long long low = 0;
    long long high = times[P-1]*N;
    while(low <= high){
        long long mid = low + (high - low)/2;
    if(canMakeNpancakes(times, N, P, mid)){
        high = mid-1;
}
        else{
           low = mid+1;
        }
 
    }
    return low;


}
int main() {
    long long N;
    int P;
    cin>>N>>P;
    vector<int> times(P);
    for(int i = 0;i<P;i++){
     cin>>times[i];
    }
    cout<<leastTime(times, N, P);

6/int peakIndexInMountainArray(vector<int>& arr) {
        int high = arr.size() - 1;
        int low = 0;
        int size = arr.size();
              while(low <= high){
 
            int mid = low+(high - low)/2;
 
            if(arr[mid]<arr[mid+1]){
                low = mid+1;
            }
 
              else if(arr[mid]> arr[mid+1] && arr[mid] > arr[mid-1]) return mid;
 
            else if(arr[mid]>arr[mid+1]){
                high = mid-1;
            }
 
        }
        return -1;
 
    }
7/
2D matrix find element
reshenie 1
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int cols = matrix[0].size();
        int row = -1;
        while(low <=high){
            int mid = low + (high - low) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][cols-1]){
                row = mid; break;
            }
            else if(target < matrix[mid][0]){
                high = mid-1;
            }
            else if(target > matrix[mid][cols-1]){
                low = mid+1;
            }
        }
        if(row == -1) return false;

        int l = 0;
        int r = cols-1;

        while(l<=r){
            int m = l +(r-l)/2;
            if(target == matrix[row][m]) return true;
            else if(target > matrix[row][m]) l=m+1;
            else r = m-1;
         }
         return false;
     }

reshenie 2
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        int high = n*m - 1;
        while(low <= high){
            int mid = low +(high-low)/2;
            int x = (mid / m);
            int y = mid % m;
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] > target){
                high = mid-1;
            }
            else low = mid+1;
        }
         return false;
     }
8/int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high){
 

             int mid = low + (high - low) / 2;
             if(nums[mid]>nums[high]) low = mid+1;
             else high = mid;

        }
        return nums[low];
    }

9/ maxProduct subarray - 50%
int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int low = 0;
        int high = low;
        int maxProduct = nums[0];
        int size = nums.size();
        while(low < size && high < size){
            int currpr=nums[low];
            for(int i = low+1;i<=high;i++){
                currpr*=nums[i];
            }
            if(currpr >= maxProduct) {maxProduct = currpr;high++;}
            else low++;


        }
        return maxProduct;

    }
10/
 int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
 
        while(low<= high){

            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            if(nums[low]<=nums[mid]){
                if(nums[low] <= target&&target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid]<=nums[high]){
                if(nums[mid]<target&&target<=nums[high]){
                  low=mid+1;
                }
                else high = mid-1;
            }
        }
        return -1;
    }

11/    bool canEatBananas(vector<int>& piles, int h, int minEatenBananas){
        int hours = 0;
        for(int i = 0;i<piles.size();i++){
            hours += piles[i]/minEatenBananas;
            if(piles[i]%minEatenBananas!= 0){
             hours+= 1;
            }

        }
        // cout<<minEatenBananas<<'\n';
        // cout<<hours<<'\n';
        return (hours > h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int size = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = low+(high-low)/2;
            if(canEatBananas(piles, h, mid)){
 
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;

    }

12/LARGEST SUM OF A SUBARRAY
bool canSplitK(vector<int>& nums, int k, int minVal){
        **int teams = 1;**

        **int sum = nums\[0];**

        **for(int i = 1;i<nums.size();i++){**

           **if(sum + nums\[i]>minVal){**

            **sum = nums\[i];**

            **teams++;**

             **if(teams > k) return false;**

           **}**

           **else{**

            **sum+=nums\[i];**

           **}**

          

        **}**

        **return true;**

    **}**

    **int splitArray(vector<int>\& nums, int k) {**

      **//  sort(nums.begin(), nums.end());**

        **int low = \*max\_element(nums.begin(), nums.end());**

        **int high = 0;**

        **for(int i = 0;i<nums.size();i++){**

            **high+=nums\[i];**

        **}**

    

        **while(low < high){**

            **int mid = low + (high - low) / 2;**

            **if(!canSplitK(nums, k, mid)){**

                **low = mid+1;**

            **}**

            **else high=mid;**

        **}**

        **return low;**



    **}**

13/Counting smaller numbers
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = *max_element(nums.begin(), nums.end());
        vector<int> counts(size+1);
         vector<int> helper(size+1);
         vector<int> finali(nums.size());
        for(int i = 0;i<nums.size();i++){
            counts[nums[i]]++;
        }
        helper = counts;
        for(int i=1;i<counts.size();i++){
            counts[i]+=counts[i-1];
        }
        for(int i = 0;i<nums.size();i++){
            finali[i] = counts[nums[i]] - helper[nums[i]];
        }
 
        return finali;

    }
14/Counting small els on the right - solution Leetcode
 void merge(int left, int mid, int right, vector<pair<int, int>>& arr, vector<int>& count){
        vector<pair<int, int>> temp(right - left+1);
        int i = left;
        int j = mid+1;
        int k = 0;

        while( i<= mid && j <= right){
            if(arr[i].first <= arr[j].first){
                temp[k++] = arr[j++];
            }
            else{
                count[arr[i].second] += (right - j+1);
                temp[k++] = arr[i++];
            }
        }
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j<= right){
            temp[k++] = arr[j++];
        }
        for(int i = left;i<=right;i++){
            arr[i]=temp[i-left];
        }

    }
    void mergeSort(int left, int right, vector<pair<int,int>>& ar, vector<int>& count){
        if(left >= right) return;

        int mid = left+(right-left)/2;
        mergeSort(left, mid, ar, count);
        mergeSort(mid+1, right, ar, count);
        merge(left, mid, right, ar, count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<pair<int, int>> temp;

        for(int i = 0;i<size;i++){
            temp.push_back({nums[i], i});
        }
        vector<int> count(size, 0);

        mergeSort(0, size-1, temp, count);

        return count;
    }

15/  bool checkInclusion(string s1, string s2) {
        vector<int> c1(26);
        vector<int> c2(26);

        for(int i = 0;i<s1.length();i++){
            c1[s1[i]-'a']++;
        }
 
        for(int j = 0;j<s2.length();j++){
            c2[s2[j]-'a']++;
        }
 
        for(int o = 0;o<26;o++){
            if(c1[o]>c2[o]) return false;
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        if(s1.length()> s2.length()) return false;
        vector<int> c1(26);
 

        for(int i = 0;i<s1.length();i++){
            c1[s1[i]-'a']++;
        }
 
 
        for(int i = 0;i<=s2.length()-s1.length();i++){
            vector<int> c2(26);
            for(int j = 0;j<s1.length();j++){
              c2[s2[i+j]-'a']++;
            }
            if(c1 == c2) return true;
        }

 
 
        return false;

16/ 70% correctness
 string reorganizeString(string s) {
        int len = s.length();
        string noS = "";
        if(len == 1) return s;
        int start = 1;
        int swapper = 0;
        while(start < len && swapper < len){
            while(start < len && s[start-1]!=s[start])start++;
            if(start == len-1)break;
            swapper = start;
 
            while(swapper < len && s[start]==s[swapper])swapper++;
            swap(s[start], s[swapper]);
            start++;
            //cout<<s<<'\n';
        }
        cout<<s;
        if(s[len-1] == s[len-2]){
            string d = s;
            for(int i = 0;i<s.length()-1;i++){
                s[i+1] = d[i];
            }
            s[0] = d[len-1];
        }
        for(int i=1;i<len;i++){
            if(s[i] == s[i-1]) return "";
        }
 
        return s;
    }
//solution
 string reorganizeString(string s) {
    int len = s.length();
    vector<int> cnt(26);
    int i = 0;
    int mostFrequent = 0;
    for(char c : s){
        if(++cnt[c-'a']>cnt[mostFrequent]){
            mostFrequent = c-'a';
        }
    }
    if(2 * cnt[mostFrequent] > len + 1) return "";

    while(cnt[mostFrequent]){
        s[i] = mostFrequent + 'a';
        i += 2;
        cnt[mostFrequent]--;
    }
    for(int j = 0;j<26;j++){
       while(cnt[j]){
        if(i >= len) i = 1;
        s[i] = j+'a';
        cnt[j]--;
        i+=2;
       }
 
 
    }
    return s;
 
 
    }

17/ int power(int base, int stepen){
        int cnt = 1;
        for(int i = 0;i<stepen;i++){
            cnt *= base;
        }
        return cnt;
    }
    int countOnes(int number, int k){
        int cnt = 0;

        while(number){
            if(number & 1) cnt++;
            number = number >> 1;
        }
        return (cnt == k);
    }
    bool checkbIT(int num, int k){
        num = num>>k;
        return num & 1;
    }
    double calculateCurrent(vector<int>& nums, int num, int k){
        double sum = 0;
        int size = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(checkbIT(num, i)) sum += nums[size-i-1];
 
        }
         cout<<sum<<'\n';
        return sum/k;

    }
    double findMaxAverage(vector<int>& nums, int k) {
     int n = nums.size();
     int high = power(2, n);
     double maxi = 0;
     for(int i = 0;i<high;i++){
        if(countOnes(i, k)){
            double current = calculateCurrent(nums, i, k);
            if(current > maxi) maxi = current;
        }
 
     }
     return maxi;
    }
//chat gpt genius solution
 double findMaxAverage(vector<int>& nums, int k) {
     int n = nums.size();
     double windowsSum = 0;
 
     for(int i = 0;i<k;i++){
        windowsSum += nums[i];
     }
     double maxi = windowsSum;
     for(int i = k;i<n;i++){
        windowsSum += nums[i] - nums[i-k];
        maxi = max(maxi, windowsSum);
     }
     return maxi/k;
    }

18/int sumUnique(vector<int>& ar1, vector<int>& ar2, int N, int M){
  int n1 = *max_element(ar1.begin(), ar1.end());
   int m1 = *max_element(ar2.begin(), ar2.end());
    int l = m1 < n1 ? m1 : n1;
    vector<int> c1(l+1);
    vector<int> c2(l+1);
  for(int i = 0;i<N;i++){
      c1[ar1[i]]++;
}
    for(int i = 0;i<M;i++){
c2[ar2[i]]++;}
    long long sum = 0;
    for(int i = 0;i<=l;i++){
        if(c1[i]>0 && c2[i]> 0){
sum += i;}
}
    return sum;
 
}
int main() {
    int N;
    cin>>N;
    vector<int> one(N);
    for(int i = 0;i<N;i++){
       cin>>one[i];
    }
    int M;
    cin>>M;
    vector<int> two(M);
    for(int y = 0;y< M;y++){
        cin>>two[y];
    }
    cout<<sumUnique(one, two, N, M);
