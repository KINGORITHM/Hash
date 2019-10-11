//
// Created by 이승민 on 2019-10-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;

    vector <vector<string>> v;
    vector <string> k;

    for (int j = 0; j < clothes.size(); ++j) {
        vector <string>::iterator it;
        it = find(k.begin(), k.end(), clothes[j][1]);

        if(it == k.end()){
            k.push_back(clothes[j][1]);
            vector <string> temp;

            for (int i = 0; i < clothes.size(); ++i) {
                if(clothes[j][1] == clothes[i][1]){
                    temp.push_back(clothes[i][0]);
                }
            }
            v.push_back(temp);
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        answer *=(v[i].size() + 1);
    }
    answer -= 1;
    return answer;
}

int main(){


    vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    //vector<vector<string>> clothes = {{"crow_mast", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}};

    cout << solution(clothes);
    return 0;
}