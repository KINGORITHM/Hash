//
// Created by 이승민 on 2019-10-08.
//

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& str1, const string& str2) {

    if (str1.length() >= str2.length()) {
        return false;
    }
    else {
        return true;
    }
}

bool change_string(vector <string> phone_book, int i) {

    for (int j = i + 1; j < phone_book.size(); ++j) {

        if (phone_book[j].substr(0, phone_book[i].length()) == phone_book[i]) {
            return false;
        }
    }

    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), cmp);

    for (int i = 0; i < phone_book.size() - 1; ++i) {
        if (!change_string(phone_book, i))
        {
            answer = false;
            return answer;
        }
    }

    return answer;
}

int main() {

    vector <string> phone_book = { "119", "97674223", "1195524421" };

    cout << solution(phone_book);
    return 0;
}