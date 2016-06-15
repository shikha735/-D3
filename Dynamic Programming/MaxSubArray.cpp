// Maximum sub-array sum
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force approach - O(n^3)
int maxSumSubArr(vector<int> A){
    int sum = 0, ans = INT_MIN, n = A.size();
	// iterating for sub arrays of all sizes
	for(int subArrSize = 1;subArrSize <= n; ++subArrSize){
		// iterating for all the sub array start indices
		for(int start_index =0; start_index < n;++start_index){
			if(start_index + subArrSize > n) // if sub array exceeds array size limits
				break;
			// calculating sum of elements in the array
			sum = 0;
			for(int i=start_index;i<(start_index+subArrSize);i++)
				sum += A[i];
			ans = max(sum, ans);
		}
	}
	return ans;
}
// A better approach - O(n^2)
int mSSA(vector<int> A){
    int sum = 0, ans = INT_MIN, n = A.size();
	// iterating for sub arrays of all sizes
	for(int start_index =0; start_index < n;++start_index){
		// iterating for all the sub array start indices
		sum = 0;
		for(int subArrSize = 1;subArrSize <= n; ++subArrSize){
			if(start_index + subArrSize > n) // if sub array exceeds array size limits
				break;
            // calculating sum of elements in the array
            // adding last element of the new sub array
            sum += A[start_index + subArrSize - 1];
            ans = max(sum, ans);
		}
	}
	return ans;
}

// Divide and Conquer; Using recursion - O(nlogn)
int mSSADivideNConquer(int A[], int n){
    if(n == 1){
        return A[0];
    }
    int m = n/2;
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0, ans;
    int leftMSS = mSSADivideNConquer(A,m);
    int rightMSS = mSSADivideNConquer(A+m,n-m);
    for(int i=m;i<n;i++){
        sum += A[i];
        rightSum = max(sum,rightSum);
    }
    sum = 0;
    for(int i=m-1;i>=0;i--){
        sum += A[i];
        leftSum = max(sum,leftSum);
    }
    ans = max(leftMSS,rightMSS);
    return max(ans,leftSum+rightSum);
}

// Kadane's algorithm - with variation for array with all elements -ve - O(n)
int mSSAKadane(vector<int> A){
    int ans = A[0], sum = A[0];
    for(int i=1;i<A.size();i++){
        sum = max(A[i],sum+A[i]);
        ans = max(ans,sum);
    }
    return ans;
}

int main(){
    int N, inp;
    vector<int> A;
    cout << "Enter size of the array";
    cin >> N;
    int B[N];
    for(int i=0;i<N;i++){
        cin >> inp;
        A.push_back(inp);
        B[i] = inp;
    }
    // cout << mSSADivideNConquer(B,N);
    cout << mSSAKadane(A);
    return 0;
}
