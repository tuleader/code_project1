#include <bits/stdc++.h>

using namespace std;

unordered_map<string, map<string, int>> shop_orders; // shopId: {customerId: price}
unordered_map<string, int> shop_revenue;
// map<string, int> revenueTime;
int total_revenue = 0;
int total_orders = 0;
vector<int> ANS;
long long profit_time[100000] = {};
vector<string> split(string str, char del){
    string temp = "";
    vector<string> ans;
    for(int i=0; i < (int)str.size(); i++){
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
int convert(string t){
    vector<string> timepoint = split(t, ':');
    return (stoi(timepoint[0]) * 3600 + stoi(timepoint[1])*60 + stoi(timepoint[2])); 
}
int is_greater(string start, string end){
    if (start == end){
        return 1;
    }
    vector<string> time1 = split(start, ':');
    vector<string> time2 = split(end, ':');
    for (int i = 0; i < 3; i++){
        if (stoi(time1[i]) < stoi(time2[i])){
            return 1;
        }
        else if (stoi(time1[i]) > stoi(time2[i])){
            return 0;
        }
    }
    return 0;
}
long long get_total_revenue_period(string start, string end){
    long long ans = 0;
    ans = profit_time[convert(end)] - profit_time[convert(start) - 1];
    return ans;
}
void get_input(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    while (1){
        string customerId;
        string productId;
        string shopId;
        int price;
        string timepoint;
        
        cin >> customerId;
        if (customerId == "#"){
            cin.ignore();
            break;
        }
        cin >> productId;
        cin >> price;
        cin >> shopId;
        cin >> timepoint;
        total_revenue += price;
        total_orders += 1;
        profit_time[convert(timepoint)] += price;
        if (shop_revenue.find(shopId) == shop_revenue.end()){
            shop_revenue.insert({shopId, price});
        }
        else{
            shop_revenue[shopId] += price;
        }
        if (shop_orders.find(shopId) == shop_orders.end()){
            map<string, int> temp;
            shop_orders.insert({shopId, temp});
        }
        if (shop_orders[shopId].find(customerId) == shop_orders[shopId].end()){
            shop_orders[shopId].insert({customerId, price});
        }
        else{
            shop_orders[shopId][customerId] += price;
        }
    }
    long long curr = profit_time[0];
    for (int i = 1; i < 100000; i++){
        curr += profit_time[i];
        profit_time[i] = curr;
    }
    while (1){
        string command;
        cin >> command;
        if (command == "#"){
            break;
        }
        if (command == "?total_revenue_in_period"){
            string start;
            string end;
            cin >> start >> end;
            ANS.push_back(get_total_revenue_period(start, end));
            continue;
        }
        if (command == "?total_number_orders"){
            ANS.push_back(total_orders);
            continue;
        }
        if (command == "?total_revenue"){
            ANS.push_back(total_revenue);
            continue;
        }
        if (command == "?revenue_of_shop"){
            string shopId;
            cin >> shopId;
            ANS.push_back(shop_revenue[shopId]);
            continue;
        }
        if (command == "?total_consume_of_customer_shop"){
            string customerId;
            string shopId;
            cin >> customerId;
            cin >> shopId;
            ANS.push_back(shop_orders[shopId][customerId]);
            continue;
        }
        
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    get_input();
    int len = ANS.size();
    for (int i = 0; i < len; i++){
        cout << ANS[i] << '\n';
    }
    return 0;
}
