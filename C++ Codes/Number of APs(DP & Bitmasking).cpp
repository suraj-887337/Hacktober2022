

#include<bits/stdc++.h>

using namespace std;
#define max_size 10000
#define m 1000000007

int AP_subsequence(int arr[], int size) {
   int count = 0;
   int max_val = INT_MAX;
   int min_val = INT_MIN;
   int arr_2[size];
   int arr_3[max_size];

   for (int i = 0; i < size; i++) {
      max_val = min(max_val, arr[i]);
      min_val = max(min_val, arr[i]);
   }
   count = size + 1;
   int diff_max = max_val - min_val;
   int diff_min = min_val - max_val;
   for (int i = diff_max; i <= diff_min; i++) {
      memset(arr_3, 0, sizeof arr_3);
      for (int j = 0; j < size; j++) {
         arr_2[j] = 1;
         if (arr[j] - i >= 1) {
            if (arr[j] - i <= 1000000) {
               arr_2[j] += arr_3[arr[j] - i];
            }
         }
         count = (count+arr_2[j] - 1)%m;
         arr_3[arr[j]] = (arr_3[arr[j]] + arr_2[j])%m;
      }
   }
   return count%m;
}
 
int main(){
 
    int N;
    cin >> N;

    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << AP_subsequence(arr, N);
   
    return 0;
}
