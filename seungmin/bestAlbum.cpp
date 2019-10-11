//
// Created by 이승민 on 2019-10-11.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

bool cmp(const tuple <string, int, int> &p1, const tuple <string, int, int> &p2){

    if(get<0>(p1) == get<0>(p2)){
        if(get<1>(p1) > get<1>(p2)){
            return true;
        }
        else{
            return false;
        }
    }
    else if(get<0>(p1) > get<0>(p2)){
        return false;
    }
    else{
        return true;
    }
}

bool cm(const pair <string, int> &p1, const pair <string, int> &p2){
    if(p1.second > p2.second){
        return true;
    }
    else{
        return false;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    vector <int> answer;
    vector <tuple<string, int, int>> v;


   for (int i = 0; i < genres.size(); ++i) {

       v.push_back(make_tuple(genres[i], plays[i], i));
   }

    sort(v.begin(), v.end(), cmp);

    vector <pair<string, int>> v1;
    v1.push_back(make_pair(get<0>(v[0]), get<1>(v[0])));

    int index = 0;
    for (int i = 1; i < v.size(); ++i) {
        if(v1[index].first == get<0>(v[i])){
            v1[index].second += get<1>(v[i]);
        }
        else{
            index += 1;
            v1.push_back(make_pair(get<0>(v[i]), get<1>(v[i])));
        }
    }

    sort(v1.begin(), v1.end(), cm);

    for (int i = 0; i < v1.size(); ++i) {
        int count = 0;
        for (int j = 0; j < v.size(); ++j) {
            if(v1[i].first == get<0>(v[j])){
                answer.push_back(get<2>(v[j]));
                count += 1;
            }
            if(count == 2){
                break;
            }
        }
    }

    return answer;
}

int main(){

    //vector <string> generes = {"classic", "pop", "classic", "classic", "pop"};
    //vector <int> plays = {500, 600, 150, 800, 2500};

    vector <string> generes = {"classic", "pop", "classic", "classic", "pop", "zazz", "zazz"};
    vector <int> plays = {500, 600, 150, 800, 2500, 2100, 1000};

    vector <int> result = solution(generes, plays);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }


    return 0;
}