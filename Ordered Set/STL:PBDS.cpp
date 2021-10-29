// Time: Fri Oct 29 14:31:08 2021
// User: Nikhar Manchanda aka N.F
#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// Comparators -> less<int> , greater<int> ,less_equal<int>, greater_equal<int> Last 2 behaves as indexed multiset

//			data_type,null_type, less<data_type>
// EG. for pair<int,int> we use
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set_for_pairs;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//                        Allowed Operations
// 1).find_by_order(idx) |	Returns itr for value at an idx  |(returns iterator)
// 2).order_of_key(key)  |  Returns no. of elements < key    |(returns number of keys less than a key)
// 3).upper_bound(key)	 |	Returns first	element>key  			 |(returns Key)
// 4).lower_bound(key)   |  Returns first element >=key 		 |(returns Key)
// 5).erase(key)	       |  Removes key from set             |(erases key if present)
/*------------------------------------------------------------*/
signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ordered_set A; // declaration
	// Inserting elements - 1st query
	A.insert(1);
	A.insert(10);
	A.insert(2);
	A.insert(7);
	A.insert(2);  // ordered set only contains unique values

	// A contains
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	cout << endl;

	// finding kth element - 4th query
	cout << "0th element: " << *A.find_by_order(0) << endl;
	cout << "1st element: " << *A.find_by_order(1) << endl;
	cout << "2nd element: " << *A.find_by_order(2) << endl;
	cout << "3rd element: " << *A.find_by_order(3) << endl;
	cout << endl;

	// finding number of elements smaller than X - 3rd query
	cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; // 2
	cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
	cout << "No. of elems smaller than 1: " << A.order_of_key(1) << endl; // 0
	cout << endl;

	// lower bound -> Lower Bound of X = first element >= X in the set
	cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
	cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
	cout << endl;

	// Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
	cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
	cout << endl;

	// // Remove elements - 2nd query
	A.erase(1);
	A.erase(11); // element that is not present is not affected

	// A contains
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;


	ordered_set_for_pairs B;
	B.insert({1, 2});
	B.insert({7, 22});
	B.insert({4, 11});
	B.insert({15, 49});
	B.insert({91, 18});

	// B contains
	cout << "B : \n";
	for (auto i : B)
		cout << "First Value of Pair:" << i.first << "    Second Value of Pair:" << i.second << endl;
	cout << endl;


	return 0;

}
