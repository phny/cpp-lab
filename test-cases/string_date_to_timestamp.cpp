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

int main() {

	string s{"2019-08-22T10:55:23.000Z"};
	std::tm t{};
	std::istringstream ss(s);

	ss >> std::get_time(&t, "%Y-%m-%dT%H:%M:%S");
	if (ss.fail()) {
		throw std::runtime_error{"failed to parse time string"};
	}   
	std::time_t time_stamp = mktime(&t);	
    cout << time_stamp << endl;
	
	return 0;
}

