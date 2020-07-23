/*
Skyline Real Estate Developers is planning to demolish a number of old, unoccupied buildings and construct a shopping mall in their place. Your task is to find the largest solid area in which the mall can be constructed.

There are a number of buildings in a certain two-dimensional landscape. Each building has a height, given by h[i]. If you join  adjacent buildings, they will form a solid rectangle of area .

For example, the heights array . A rectangle of height  and length  can be constructed within the boundaries. The area formed is .

Function Description

Complete the function largestRectangle int the editor below. It should return an integer representing the largest rectangle that can be formed within the bounds of consecutive buildings.

largestRectangle has the following parameter(s):

h: an array of integers representing building heights
Input Format

The first line contains , the number of buildings.
The second line contains  space-separated integers, each representing the height of a building.

Constraints

Output Format

Print a long integer representing the maximum area of rectangle formed.

Sample Input

5
1 2 3 4 5
Sample Output

9
Explanation

An illustration of the test case follows.
image
*/

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    stack<int> s;
    int l = h.size();
    int max_area = 0;
    int tp;
    long area;
    int i = 0;
    while(i < l){
        if(s.empty() || h[i] >= h[s.top()]){
            s.push(i++);
        }else{
            tp = s.top();
            s.pop();
            area = h[tp] * (s.empty() ? i :
                                   i - s.top() - 1);
            if (max_area < area)
                max_area = area;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area = h[tp] * (s.empty() ? i :
                                i - s.top() - 1);

        if (max_area < area)
            max_area = area;
    }

    return max_area;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

/*
The above answers have given the best O(n) solution in code, however, their explanations are quite tough to comprehend. The O(n) algorithm using a stack seemed magic to me at first, but right now it makes every sense to me. OK, let me explain it.

First observation:

To find the maximal rectangle, if for every bar x, we know the first smaller bar on its each side, let's say l and r, we are certain that height[x] * (r - l - 1) is the best shot we can get by using height of bar x. In the figure below, 1 and 2 are the first smaller of 5.

OK, let's assume we can do this in O(1) time for each bar, then we can solve this problem in O(n)! by scanning each bar.

enter image description here

Then, the question comes: for every bar, can we really find the first smaller bar on its left and on its right in O(1) time? That seems impossible right? ... It is possible, by using a increasing stack.

Why using an increasing stack can keep track of the first smaller on its left and right?

Maybe by telling you that an increasing stack can do the job is not convincing at all, so I will walk you through this.

Firstly, to keep the stack increasing, we need one operation:

while x < stack.top():
    stack.pop()
stack.push(x)
Then you can check that in the increasing stack (as depicted below), for stack[x], stack[x-1] is the first smaller on its left, then a new element that can pop stack[x] out is the first smaller on its right.

enter image description here

Still can't believe stack[x-1] is the first smaller on the left on stack[x]?

I will prove it by contradiction.

First of all, stack[x-1] < stack[x] is for sure. But let's assume stack[x-1] is not the first smaller on the left of stack[x].

So where is the first smaller fs?

If fs < stack[x-1]:
    stack[x-1] will be popped out by fs,
else fs >= stack[x-1]:
    fs shall be pushed into stack,
Either case will result fs lie between stack[x-1] and stack[x], which is contradicting to the fact that there is no item between stack[x-1] and stack[x].
Therefore stack[x-1] must be the first smaller.

Summary:

Increasing stack can keep track of the first smaller on left and right for each element. By using this property, the maximal rectangle in histogram can be solved by using a stack in O(n).

Congratulations! This is really a tough problem, I'm glad my prosaic explanation didn't stop you from finishing. Attached is my proved solution as your reward :)
*/
