#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> familyTrees;
int tongSoNguoi = 0;
int tongSoNguoiBorn[200000] = {};
map<string, tuple<string, string, string, char, string>> people;
map<string, string> fartherSide;
map<string, int> numberOfPeopleBornAt;
vector<int> ans;
set<string> roots;
map<string, vector<string>> Trees;
map<string, int> peopleBornAt;
set<string> distinct;
set<int> converted;
int maxUnrelated = 0;
vector<string> split(string str, char del){
    string temp = "";
    vector<string> lst;
    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != del){
            temp += str[i];
        }
        else{
            lst.push_back(temp);
            temp = "";
        }
    }
    lst.push_back(temp);
    return lst;
}
int convert(string dateOfBirth){
    vector<string> splited = split(dateOfBirth, '-');
    return stoi(splited[0]) * 900 + stoi(splited[1]) * 30 + stoi(splited[2]);
}
int LISS(string root){
    if (Trees[root].size() == 0){
        return 1;
    }
    int sizeExclude = 0;
    for (auto child : Trees[root]){
        sizeExclude += LISS(child);
    }
    int sizeInclude = 2;
    for (auto child : Trees[root]){
        for (auto grandChild : Trees[child]){
            sizeInclude += LISS(grandChild);
        }
    }
    return max(sizeExclude, sizeInclude);
}
int mostAlive(string personCode){
    int dist = 0;
    stack<pair<string, int>> stk;
    stk.push(make_pair(personCode, 0));
    while (!stk.empty()){
        auto state = stk.top();
        stk.pop();
        if (fartherSide.find(state.first) == fartherSide.end()){
            dist = state.second;
            break;
        }
        stk.push(make_pair(fartherSide[state.first], state.second + 1));
    }
    return dist;
}

void nhapDuLieu(){
    while (1){
        string personCode;
        cin >> personCode;
        if (personCode == "*"){
            break;
        }
        string dateOfBirth;
        string fatherCode;
        string motherCode;
        char alive;
        string regionCode;
        cin >> dateOfBirth >> fatherCode >> motherCode >> alive >> regionCode;
        tongSoNguoi += 1;
        people[personCode] = make_tuple(dateOfBirth, fatherCode, motherCode, alive, regionCode);
        if (numberOfPeopleBornAt.find(dateOfBirth) == numberOfPeopleBornAt.end()){
            numberOfPeopleBornAt[dateOfBirth] = 1;
            peopleBornAt[dateOfBirth] = 1;
        }
        else {
            numberOfPeopleBornAt[dateOfBirth] += 1;
            peopleBornAt[dateOfBirth] = numberOfPeopleBornAt[dateOfBirth];
        }
        if (motherCode == "0000000" && fatherCode == "0000000"){
            roots.insert(personCode);
            continue;
        }
        if (fatherCode != "0000000"){
            Trees[fatherCode].push_back(personCode);
            roots.erase(motherCode);
        }
        else if (motherCode != "0000000"){
            Trees[motherCode].push_back(personCode);
            roots.erase(fatherCode);
        }
    }
    
    for (auto person : people){
        string fatherCode = get<1>(person.second);
        if (people.find(fatherCode) != people.end()){
            fartherSide[person.first] = fatherCode;
        }
    }
    int temp = 0;
    for (auto i : peopleBornAt){
        temp += i.second;
        peopleBornAt[i.first] = temp;
    }
    for (auto root : roots){
        maxUnrelated += LISS(root);
    }
    while (1){
        string command;
        cin >> command;
        if (command == "***"){
            break;
        }
        if (command == "NUMBER_PEOPLE"){
            ans.push_back(tongSoNguoi);
        }
        else if (command == "NUMBER_PEOPLE_BORN_AT"){
            string dateBirth;
            cin >> dateBirth;
            ans.push_back(numberOfPeopleBornAt[dateBirth]);
        }
        else if (command == "MOST_ALIVE_ANCESTOR"){
            string personCode;
            cin >> personCode;
            ans.push_back(mostAlive(personCode));
        }
        else if (command == "MAX_UNRELATED_PEOPLE"){
            ans.push_back(maxUnrelated);
        }
        else if (command == "NUMBER_PEOPLE_BORN_BETWEEN"){
            string fromDate;
            string toDate;
            cin >> fromDate >> toDate;
            int left = 0;
            auto start = peopleBornAt.lower_bound(fromDate);
            if (start != peopleBornAt.begin()){
                start--;
                left = start->second;
            }
            
            int right = 0;
            auto end = peopleBornAt.upper_bound(toDate);
            end--;
            right = end->second;
            ans.push_back(right - left);
        }
    }
}

int main(){
    nhapDuLieu();
    for (auto i : ans){
        cout << i << '\n';
    }
}
