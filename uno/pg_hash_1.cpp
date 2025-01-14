#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> um;

	for (int i = 0; i < participant.size(); i++) 
		um[participant[i]]++;
	
	for (int i = 0; i < completion.size(); i++)
		um[completion[i]]--;

	for (int i = 0; i < participant.size(); i++)
		if (um[participant[i]] > 0) {
			answer = participant[i];
			break;
		}

	return answer;
}

int main() {
	vector<string> exPt = { "leo","kiki","eden" };
	vector<string> exCo = { "eden","kiki" };

	printf("%s\n", (solution(exPt, exCo)).c_str());
	return 0;
}