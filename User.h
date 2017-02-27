#ifndef User_H
#define User_H
#include<string>
#include<iostream>

using std::string;

class User{
private:
	string *movies;
	string username;
	string password;
public:
	string fname;
	string lname;
	int age;
	User(string fname, string lname, int age, string username, string password){
	this->fname = fname;
	this->lname = lname;
	this->age = age;
	this->username = username;
	this->password = password;
	this->movies = new string[5];
	string* m;
	m = new string[5];
	m = movieList();
	for (int i = 0; i<5; i++){
		m[i] = "\n";
	}
}
	User(){}
	bool authenticate(string new_password){
	return this->password == password;
}
	string getUsername(){
	return this->username;
}
	void setPassword(string new_password){
	this->password = new_password;
}
	string *movieList(){
	return this->movies;
}
};



#endif