// Maximum sub-array sum
#include <iostream>
#include <climits>
#include <vector>
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

int main(){
    int N, inp;
    vector<int> A;
    cout << "Enter size of the array";
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> inp;
        A.push_back(inp);
    }
    cout << mSSA(A);
    return 0;
}
