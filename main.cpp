#include<iostream>
#include<string>
#include"User.h"
#include"MovieChart.h"

using namespace std;

int main(){
	MovieChart *movieChart = new MovieChart;
	while (1){
		cout << "Please enter a command (Create, Update, View, Login, Logout, or Quit):" << endl;
		string cmd;
		getline(cin, cmd);
		if (cmd == "Create"){
			movieChart->create();
		}
		else if (cmd == "Update"){
			movieChart->update();
		}
		else if (cmd == "View"){
			movieChart->view();
		}
		else if (cmd == "Login"){
			movieChart->login();
		}
		else if (cmd == "Logout"){
			movieChart->logout();
		}
		else if (cmd == "Quit"){
			break;
		}
		else{
			cout << "INVALID COMMAND" << endl;
		}

	}
	return 0;
}