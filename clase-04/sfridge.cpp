#include <bits/stdc++.h>
#include <climits>
#include <string>
using namespace std;

bool isFound(int n, vector<int> &numbers){
    for(int i = 0; i < numbers.size(); ++i)
        if(numbers[i] == n)
            return true;

    return false;
}

int main(){
    string n;
    string numbers;
    vector<int> v;
    string min = string(18, '9');
    cin >> n;

    for(int i = 0; i < n.length(); ++i)
        v.push_back(n[i] - '0');

    sort(v.begin(), v.end());

    for(int i = 0; i < n.length(); ++i)
        numbers += to_string(v[i]);

    for(int i = 1; i < 9; ++i){
        if(!isFound(i, v))
            if(to_string(i) < min){
                min = to_string(i);
            }
    }
    for(int i = 0; i < numbers.length(); ++i){
        if(i == 0 && numbers[0] == '0')
            continue;

        for (int j = i; j < numbers.length() - 1; j++) {
            string test = numbers.substr(0, j+1);
            vector<int> testV = v;
            testV.erase(testV.begin() + i, testV.begin() + j + 1);

            for(int x = 0; x <= 9; ++x){
                if(!isFound(x, testV)){
                    string s = test + to_string(x);
                    if(s < min){
                        min = s;
                        break;
                    }
                }
            }
        }
    }

    min.erase(0, min.find_first_not_of('0'));
    cout << min << endl;
    return 0;
}
