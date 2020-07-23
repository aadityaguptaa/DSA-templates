/*
You have an empty sequence, and you will be given N  queries. Each query is one of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.
Input Format

The first line of input contains an integer,N . The next N lines each contain an above mentioned query. (It is guaranteed that each query is valid.)

Constraints
1 <= N <= 10^5
1 <= x <= 10^9
1 <= type <= 3


Output Format

For each type 3 query, print the maximum element in the stack on a new line.

Sample Input

10
1 97
2
1 20
2
1 26
1 20
2
3
1 91
3

Sample Output

26
91

*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin >> t;
    stack<long long int> s;
    stack<long long int> track;
    long long int max;
    for(long long int i = 0; i < t; i++){
        long long int a;
        cin >> a;
        if(a == 1){
            long long int b;
            cin >> b;
            if(s.empty()){
                s.push(b);
                track.push(b);
            }else{
                if(b > track.top()){
                    track.push(b);
                    s.push(b);
                }else{
                    s.push(b);
                    track.push(track.top());
                }
            }
        }else if(a == 2){
            s.pop();
            track.pop();
        }else{
            cout << track.top() << endl;
        }
    }
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Approach:

    -Create another another Stack(call it as track) which will keep track of maximum in the given Stack(call it as main).
    -When you insert an element in the main stack for the first time ( means it is empty), insert it in the track Stack as well.
    -Now onwards when you insert a new element(say it is x) in the main Stack, peek() the element from the track Stack ( say it is ‘a‘). Compare x and a and which ever is greater, insert it into track Stack.
    -When you pop the element from the main stack, pop from the track Stack as well
    -So to get to know the maximum element in the main Stack, peek the element in the track Stack. .
*/
