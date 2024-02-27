#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char del){
    // declaring temp string to store the curr "word" upto del
      string temp = "";
      vector<string> res;

      for(int i=0; i<(int)str.size(); i++){
        // If cur char is not del, then append it to the cur "word", otherwise
          // you have completed the word, print it, and start a new word.
         if(str[i] != del){
            temp += str[i];
        }
          else{
            res.push_back(temp);
              temp = "";
        }
    }
       
    res.push_back(temp);
    return res;
}

int convert(string timePoint){
    vector<string> splited = split(timePoint, ':');
    return stoi(splited[0]) * 3600 + stoi(splited[1]) * 60 + stoi(splited[2]);
}

int totalNumberSubmissions = 0;
int totalNumberFailedSubmissions = 0;
unordered_map<string, pair<int, int>> userInfo; // user: (points, errors)
int numberOfSubmissionsPeriod[200000] = {};
vector<int> ans;
unordered_map<string, map<string, int>> userPoint;

int get_point(string userId){
    int ans = 0;
    for (auto i : userPoint[userId]){
        ans += i.second;
    }
    return ans;
}

void get_input(){
    while(1){
        string userId;
        cin >> userId;
        if (userId == "#"){
            break;
        }
        string problemId;
        string timePoint;
        string status;
        int point;

        cin >> problemId >> timePoint >> status >> point;
        if (userPoint.find(userId) == userPoint.end()){
            userPoint[userId][problemId] = point;
        }
        else if (userPoint[userId].find(problemId) == userPoint[userId].end()){
            userPoint[userId][problemId] = point;
        }
        else {
            userPoint[userId][problemId] = max(userPoint[userId][problemId], point);
        }
        if (userInfo.find(userId) == userInfo.end()){
            userInfo[userId] = make_pair(point, 0);
        }
        else{
            userInfo[userId].first += point;
        }
        if (status == "ERR"){
            userInfo[userId].second += 1;
            totalNumberFailedSubmissions += 1;
        }
        totalNumberSubmissions += 1;
        numberOfSubmissionsPeriod[convert(timePoint)] += 1;
    }
    int temp = 0;
    for (int i = 0; i < 200000; i++){
        temp += numberOfSubmissionsPeriod[i];
        numberOfSubmissionsPeriod[i] = temp;
    }
    while (1){
        string command;
        cin >> command;
        if (command == "#"){
            break;
        }
        if (command == "?total_number_submissions"){
            ans.push_back(totalNumberSubmissions);
        }
        else if (command == "?number_error_submision"){
            ans.push_back(totalNumberFailedSubmissions);
        }
        else if (command == "?number_error_submision_of_user"){
            string userId;
            cin >> userId;
            ans.push_back(userInfo[userId].second);
        }
        else if (command == "?total_point_of_user"){
            string userId;
            cin >> userId;
            ans.push_back(get_point(userId));
        }
        else if (command == "?number_submission_period"){
            string fromTime;
            string toTime;
            cin >> fromTime >> toTime;
            ans.push_back(numberOfSubmissionsPeriod[convert(toTime)] - numberOfSubmissionsPeriod[convert(fromTime) - 1]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    get_input();
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
}
