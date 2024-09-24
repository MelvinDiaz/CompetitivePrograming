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
    string stringNumbers;
    cin >> stringNumbers;
    vector<int> numbers(stringNumbers.length(), 0);

    for(int i = 0; i < stringNumbers.length(); ++i)
        numbers[i] = stringNumbers[i] - '0';

    sort(numbers.begin(), numbers.end());

    for(int i = 0; i < stringNumbers.length(); ++i)
         stringNumbers[i] = numbers[i] + '0';


    long long min = INT_MAX;

    for(int i = 1; i < 9; ++i){
        if(!isFound(i, numbers))
            if(i < min)
                min = i;
    }

    for(int i = 0; i < stringNumbers.length(); ++i){
        if(i == 0 && stringNumbers[0] == '0')
            continue;
        for(int j = i; j < stringNumbers.length(); j++){
            string testNumber;
            testNumber = stringNumbers.substr(0, j + 1);
            vector<int> auxVector = numbers;
            auxVector.erase(auxVector.begin() + i, auxVector.begin() + j + 1);
                for(int x = 0; x <= 9; ++x){
                    if(!isFound(x, auxVector)){
                        string auxString = testNumber + to_string(x);
                        long long auxNumber = stoll(auxString);
                        if(auxNumber < min){
                            min = auxNumber;
                            break;
                        }
                   }
                }
        }
    }
    cout << min << "\n";

    return 0;
}
