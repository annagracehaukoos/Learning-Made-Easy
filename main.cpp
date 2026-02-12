#include <iostream>
#include "AVL.h"
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	AVL tree;
	string line;
	while (getline(cin, line)) {
		istringstream iss(line);
		string command;
		iss >> command;
		if (command == "insert") {
			string name, id;
			iss.ignore(50, '"');
			getline(iss, name, '"');
			iss >> id;
			tree.insertNameID(name, id);
		} else if (command == "remove") {
			string id;
			iss >> id;
			tree.remove(id);
		} else if (command == "search") {
			char followingChar;
			iss >> ws >> followingChar;
			if (followingChar == '"') {
				string name;
				getline(iss, name, '"');
				tree.searchName(name);
			} else {
				string token;
				iss.putback(followingChar);
				iss >> token;
				bool is_id;
				if ((is_id = (token.length() == 8))) {
					for (auto i = token.begin(); i != token.end(); i++) {
						if (!isdigit(*i)) {
							is_id = false;
							break;
						}
					}
				}
				if (is_id) {
					tree.searchID(token);
				} else {
					tree.searchName(token);
				}
			}
		} else if (command == "printInorder") {
			tree.printInorder();
		} else if (command == "printPreorder") {
			tree.printPreorder();
		} else if (command == "printPostorder") {
			tree.printPostorder();
		} else if (command == "printLevelCount") {
			tree.printLevelCount();
		} else if (command == "removeInorder") {
			int number;
			if (iss >> number) {
				tree.removeInorder(number);
			} else {
				cout << "unsuccessful" << endl;
			}
		}
	}
	return 0;
}
