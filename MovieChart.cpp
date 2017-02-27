#include<iostream>
#include"MovieChart.h"


MovieChart::MovieChart() {
	num_users = 0;
	current_user = NULL;
}

void MovieChart::create(){
	string fn, ln, un, pwd;
	int a;

	std::cout << "Please enter first name:" << std::endl;
	getline(std::cin, fn);

	std::cout << "Please enter last name:" << std::endl;
	getline(std::cin, ln);

	std::cout << "Please enter age:" << std::endl;
	std::cin >> a;
	std::cin.ignore(1000, '\n');

	std::cout << "Please enter username:" << std::endl;
	getline(std::cin, un);

	std::cout << "Please enter password:" << std::endl;
	getline(std::cin, pwd);

	User *user = new User(fn, ln, a, un, pwd);
	this->users[this->num_users] = *user;
	this->num_users++;
	std::cout<<user->getUsername()<<std::endl;
}

bool MovieChart::login() {
	string un, pwd;
	std::cout << "Please enter your username:" << std::endl;
	getline(std::cin, un);
	std::cout << "Please enter your password:" << std::endl;
	getline(std::cin, pwd);
	for (int i = 0; i < this->num_users; i++){
		User user = this->users[i];
		
		if (un == user.getUsername() && user.authenticate(pwd)){
			current_user = &this->users[i];
			
			return true;
		}
	}
	
	return false;
}

void MovieChart::logout() {
	current_user = NULL;
}

void MovieChart::update(){
	if (current_user == NULL){
	std::cout<<"Please login before continuing."<<std::endl;
		return;
	}
	std::cout << "Please enter which attribute to update (Password, Favorites):" << std::endl;
	string cmd;
	getline(std::cin, cmd);
	if (cmd == "Password"){
		std::cout << "Please input your new Password" << std::endl;
		string p;
		getline(std::cin, p);
		current_user->setPassword(p);
	}
	else if (cmd == "Favorites"){
		std::cout << "Please input your new 5 Favorite Movies" << std::endl;
		string *movieList = current_user->movieList();
		for (int i = 0; i<5; i++){
			string m;
			getline(std::cin, m);
			movieList[i] = m;
		}
	}
}

void MovieChart::view() {
	if (current_user == NULL) {
	std::cout<<"Please login before continuing."<<std::endl;
		return;
	}
	std::cout << "First name:" << current_user->fname << std::endl;
	std::cout << "Last name:" << current_user->lname << std::endl;
	std::cout << "Age:" << current_user->age << std::endl;
	std::cout << "Username:" << current_user->getUsername() << std::endl;
	std::cout << "Favorite Movies" << std::endl;
	string *movieList = current_user->movieList();
	for (int i = 0; i<5; i++) {
		string movie = movieList[i];
		std::cout << movie << std::endl;
	}
}
