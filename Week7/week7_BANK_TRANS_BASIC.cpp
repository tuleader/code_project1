#include <bits/stdc++.h>
using namespace std;
set<string> accounts;
map<string, vector<tuple<string, string, int>>> transactions;
int number_of_transactions = 0;
int total_money = 0;
vector<string> getInput(){
    while (1){
        string sender;
        string receiver;
        int amount;
        string timepoint;
        string atm;
        cin >> sender;
        if (sender == "#"){
            cin.ignore();
            break;
        }
        cin >> receiver;
        cin >> amount;
        cin >> timepoint;
        cin >> atm;
        accounts.insert(sender);
        accounts.insert(receiver);
        transactions[sender].push_back(make_tuple(receiver, timepoint, amount));
        number_of_transactions += 1;
        total_money += amount;
    }
    vector<string> lines;
    while (1){
        string line;
        getline(cin, line);
        if (line == "#"){
            break;
        }
        lines.push_back(line);
    }
    return lines;
}
int total_money_from(string account){
    int ans = 0;
    for (auto i : transactions[account]){
        ans += get<2>(i);
    }
    return ans;
}
vector<string> split(string str, char del){
    string temp = "";
    vector<string> ans;
    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != del){
            temp += str[i];
        }
        else{
            ans.push_back(temp);
            temp = "";
        }
    }
    ans.push_back(temp);
    return ans; 
}
int is_time_valid(string time1, string time2){
    vector<string> t1 = split(time1, ':');
    vector<string> t2 = split(time2, ':');
    if (t1 == t2){
        return 0;
    }
    return 1;
    for (int i = 0; i < 3; i++){
        if (stoi(t1[i]) < stoi(t2[i])){
            return 1;
        }
        else if (stoi(t1[i]) > stoi(t2[i])){
            return 0;
        }
    }
    return 0;
}
int inspect_cycle(string account, int k){
    stack<tuple<string, string, int, set<string>>> receivers;
    int ans = 0;
    if (!transactions[account].size()){
        return ans;
    }
    for (auto i : transactions[account]){
        string receiver = get<0>(i);
        string timepoint = get<1>(i);
        set<string> a = {receiver};
        receivers.push(make_tuple(receiver, timepoint, 1, a));
    }
    while (!receivers.empty()){
        tuple<string, string, int, set<string>> transaction = receivers.top();
        receivers.pop();
        string receiver = get<0>(transaction);
        string timepoint = get<1>(transaction);
        set<string> visited = get<3>(transaction);
        int curr = get<2>(transaction);
        if (curr > k){
            continue;
        }
        if (receiver == account && curr == k){
            ans = 1;
            break;
        }
        for (auto next : transactions[receiver]){
            if (is_time_valid(timepoint, get<1>(next)) && visited.find(get<0>(next)) == visited.end()){
                set<string> temp = visited;
                temp.insert(get<0>(next));
                receivers.push(make_tuple(get<0>(next), get<1>(next), curr + 1, temp));
            }
        }
    }
    return ans;
}
int main(){
    vector<string> queries = getInput();
    for (auto query : queries){
        stringstream ss(query);
        string command;
        ss >> command;
        if (command == "?list_sorted_accounts"){
            for (auto account : accounts){
                cout << account << " ";
            }
            cout << '\n';
            continue;
        }
        if (command == "?number_transactions"){
            cout << number_of_transactions << '\n';
            continue;
        }
        if (command == "?total_money_transaction"){
            cout << total_money << "\n";
            continue;
        }
        if (command == "?total_money_transaction_from"){
            string account;
            ss >> account;
            cout << total_money_from(account) << "\n";
        }
        if (command == "?inspect_cycle"){
            string account;
            int k;
            ss >> account;
            ss >> k;
            cout << inspect_cycle(account, k) << '\n';
        }
    }
}
