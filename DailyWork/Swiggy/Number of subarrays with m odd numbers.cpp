#include <bits/stdc++.h>
using namespace std;
 
int countSubarrays(int a[], int n, int m)
{
    int count = 0;
    int prefix[n + 1] = { 0 };
    int odd = 0;

    for (int i = 0; i < n; i++)
    {
 
        prefix[odd]++;
 
        if (a[i] & 1)
            odd++;

        if (odd >= m)
            count += prefix[odd - m];
    }
 
    return count;
}
 

int main()
{
    int a[] = { 2, 2, 5, 6, 9, 2, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    int m = 2;
 
    cout << countSubarrays(a, n, m);
 
    return 0;
}


//////////////////////////////////////////////  DIFFERENT SOLUTION FIND ONLINE

template<typename T> 
vector<int> suffix_array(const T &S) {
    int n = S.size();
    vector<int> sa;
    for (int i = n - 1; i >= 0; --i) {
        sa.push_back(i);
    }
    stable_sort(sa.begin(), sa.end(), [&](int a, int b) { return S[a] < S[b]; });

    vector<int> classes(n);
    for (int i = 0; i < n; ++i) {
        classes[i] = S[i];
    }
    for (int len = 1; len < n; len *= 2) {
        vector<int> c = classes;
        for (int i = 0; i < n; i++) {
            classes[sa[i]] =
                i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2]
                    ? classes[sa[i - 1]]
                    : i;
        }
        vector<int> cnt(n);
        iota(cnt.begin(), cnt.end(), 0);
        vector<int> s = sa;
        for (int i = 0; i < n; i++) {
            int s1 = s[i] - len;
            if (s1 >= 0)
                sa[cnt[classes[s1]]++] = s1;
        }
    }
    return sa;
}
template<typename T>
vector<int> lcp_array(const T &s) {
    int n = s.size();
    vector<int> sa = suffix_array(s);
    vector<int> rank(n);
    for (int i = 0; i < n; i++)
        rank[sa[i]] = i;
    vector<int> lcp(n - 1);
    for (int i = 0, h = 0; i < n; i++) {
        if (rank[i] < n - 1) {
            for (int j = sa[rank[i] + 1]; s[i + h] == s[j + h]; ++h)
				;
            lcp[rank[i]] = h;
            if (h > 0)
                --h;
        }
    }
    return lcp;
}
vector<int> odd_boundary(vector<int> &v,int n,int k){
	/// Function for getting right boundary for each index for at most k odd elements
	vector<int> ret(n);
	for(int i = n-1, j = n - 1; i >= 0; i--){
		k -= v[i] % 2;
		while(k < 0) {k += v[j--] % 2;}
		ret[i] = j + 1;
	}
	return ret;
}
int get_distinct(vector<int> &v,int n,int k){
	auto vv = odd_boundary(v,n,k);
	auto lcp = lcp_array(v);
	auto sfx = suffix_array(v);
	int ans = 0;
	for(int i=0; i < n; i++){
		ans += min(vv[sfx[i]], n) - sfx[i];
	}
	for(int i=0; i <n-1; i++){
		ans -= min(vv[sfx[i]] - sfx[i], lcp[i]);
	}
	return ans;
}

int32_t main()
{
   int n,k; 
   n = rand() % 100 + 10, k = rand() % 50 +  5;
   vector<int> v(n); 
   for(int i=0; i<n; i++) 
   		v[i] = rand() % 18 + 1;
   auto dis = get_distinct(v,n,k);
   cout << "Total Distinct subarrays = " << dis << "\n";
}


//////////////////////////////////////////////  

def evenSubarray(arr, k):
    res = set()
    left, right, odd_num = 0, 0, 0
    while right < len(arr):
        if arr[right] % 2 == 1:
            odd_num += 1

        while odd_num > k and left < right:
            if arr[left] % 2 == 1:
                odd_num -= 1
            left += 1

        for left_start in range(left, right + 1):
            res.add(",".join(map(str, arr[left_start:right + 1])))

        right += 1

    return len(res)

///////////////////////////////////////////////////



def distinct_subarrays(nums,K):
    ans = 0
    n = len(nums)
    for i in range(n):
        temp2 = []
        k = 0
        check = set()
        for j in range(i,n):
            if i == 0:
                if nums[j]%2 == 1:
                    temp2.append(1)
                else:
                    temp2.append(0)
                if temp2[k] <= K and nums[j] not in check:
                    ans+=1
                    check.add(nums[j])
            else:
                if nums[j]%2 == 1:
                    temp2.append(temp1[k]+1)
                else:
                    temp2.append(temp1[k])
                if temp2[k] <= K and tuple(nums[k:j+1]) not in check:
                    ans+=1
                    check.add(tuple(nums[k:j+1]))
            k+=1
        temp1 = list(temp2)
    
    return ans

////////////////////////////////////////////////////////////////

Possible O(n) time solution: use Ukkonen's algorithm to build the suffix tree to count distinct subarrays, (treat as string);
precompute a prefix array for current number of odd elements.

However, I would say Ukkonen's algorithm is an overkill. Personally I would vote for the O(N^2) solution with 
sliding window and hashset.


//////////////////////////////////////////////////////////////////


public static int DistinctSubKOdds(int[] numbers, int k)
    {
        if(k == 0)
        {
            return 0;
        }
        
        bool[] IsOdd = new bool[numbers.Length];        
        for(int i = 0; i < numbers.Length; i++)
        {
            IsOdd[i] = numbers[i] % 2 != 0;
        }       
                
        HashSet<string> subs = new HashSet<string>();
        for(int i = 0; i < numbers.Length; i++)
        {
            StringBuilder sb = new StringBuilder();            
            int oddCount = 0;            
            
            for(int j = i; j < numbers.Length; j++)
            {                
                if(IsOdd[j])
                {
                    oddCount++;
                    if(oddCount > k)       
                    {
                        break;     
                    }
                }                
                sb.Append($"{numbers[j]},");
                subs.Add(sb.ToString());
            }
        }
        
        foreach(var item in subs)
        {
           Console.WriteLine(item);
        }
              
        return subs.Count;
    }