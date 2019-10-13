#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;
unordered_map<string, vector<pair<int, int>>> um;

bool compare(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first) 
		return a.second < b.second; // 재생횟수가 같을 때는 고유번호 낮은순	
	else 
		return a.first > b.first;  // 재생횟수 내림차순	
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	
	for (int i = 0; i < genres.size(); i++)
		um[genres[i]].push_back(pair<int, int>(plays[i], i));

	unordered_map<string, vector<pair<int, int>>>::iterator it = um.begin();

	for (it; it != um.end(); it++) {
		vector<pair<int, int>> temp = it->second;
		sort(temp.begin(), temp.end(), compare);
		for (int i = 0; i < it->second.size(); i++) {
			printf("%d\n", temp[i].second);
		}
		
	}
	
	return answer;
}

int main() {
	vector<string> v = { "classic","pop","classic","classic","pop" };
	
	vector<int> plays = { 500,600,150,800,2500 };
	vector<int> ans;

	ans = solution(v, plays);

	return 0;
}