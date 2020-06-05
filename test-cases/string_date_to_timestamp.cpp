/*************************************************************************
> File Name: string_date_to_timestamp.cpp
> Author: 
> Mail: 
> Created Time: 2020年05月26日 星期二 15时19分27秒
************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

string TimestampToStringDate(int64_t timestamp) {
    std::time_t t(timestamp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%F %T");
    return ss.str();
}

int main() {
    string s{"2019-08-22 10:55:23"};
    std::tm t{};
    std::istringstream ss(s);

    ss >> std::get_time(&t, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        throw std::runtime_error{"failed to parse time string"};
    }   
    std::time_t time_stamp = mktime(&t);	
    cout << time_stamp << endl;
    
    auto ret = TimestampToStringDate(time_stamp);
    cout << ret << endl;

    return 0;
}

