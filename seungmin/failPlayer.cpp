//
// Created by 이승민 on 2019-10-16.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
string solution(vector <string> participant, vector<string> completion){

    string answer ="";
    unordered_map <string, int> m;

    for(int i = 0; i < completion.size(); i++) {
        if (m.count(completion[i]) == 0){
            m.insert(make_pair(completion[i], 1));
        }
        else{
            m[completion[i]] += 1;
        }
    }

    for(int i = 0; i < participant.size(); i++) {

        if(m[participant[i]] > 0){
            m[participant[i]] -= 1;
        }
        else {
            answer = participant[i];
            break;
        }
    }

    return answer;
}

int main(){
    vector <string> participant = { "leo", "kiki", "eden" };
    vector <string> completion = { "eden", "kiki" };

    string result;
    result = solution(participant, completion);

    cout << result;

    return 0;
}