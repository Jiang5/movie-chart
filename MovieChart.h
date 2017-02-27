#ifndef MOVIECHART_H
#define MOVIECHART_H
#include<iostream>
#include<string>
#include "User.h"

using std::string;

class MovieChart{
private:
	User users[255];
	int num_users;
	User* current_user;

public:
	MovieChart();
	void create();
	bool login();
	void logout();
	void update();
	void view();
};


#endif