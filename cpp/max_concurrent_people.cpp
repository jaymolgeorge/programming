// max. number of people overlapping between times

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(vector<vector<int>>& intervals) {

sort(intervals.begin(), intervals.end());

int max_overlap = 1;
int prev_overlap_start = intervals[0][0];
int prev_overlap_end = intervals[0][1];
int prev_overlap_count = 1;
int new_overlap_count = 1;
int overlap = 0;
if (intervals.size() <= 1) return max_overlap;

for (int i = 1 ; i < intervals.size(); i++) {
  if (intervals[i][0] < intervals[i-1][1]) {
    new_overlap_count = 2;
  }

  if (intervals[i][0] < prev_overlap_end) {
    prev_overlap_count++;
    prev_overlap_start = intervals[i][0];
    prev_overlap_end = min(intervals[i][1], prev_overlap_end);
   }
  if (intervals[i][0] >= prev_overlap_end) {
  prev_overlap_start = intervals[i][0];
  prev_overlap_end = intervals[i][1];
  prev_overlap_count= 1;
}
  overlap = max(prev_overlap_count, new_overlap_count);

  max_overlap = max(overlap, max_overlap);
  prev_overlap_count = overlap;
  new_overlap_count = 1;
}
return max_overlap;
}
 



int main() {
	vector<vector<int>> intervals1 {{1,4},
	                               {2,5},
	                               {3,8}};
	
	vector<vector<int>> intervals2 {{1,4},
	                         
	                               {2,3},
	                               {5,10},
	                               {6,11},
	                               {7,9}};
	                               
	vector<vector<int>> intervals {{1,4},
	                                {2,7},
	                                {6,11},
	                               {5,10},
	                               {2,3},
	                               {7,9}};
	cout << minDistance(intervals) << endl;
	for (auto item: intervals) {
	    cout << item[0] << " " << item[1] << endl;
	}
	return 0;
}

/* 

4 - max. overlap
sorted array below
1 4
2 3
2 7
5 10
6 11
7 9
*/

