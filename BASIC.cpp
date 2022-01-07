#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> splitToArray(string passStr) {
	istringstream iss(passStr);
	vector<string> instruction;
	for (string s; iss >> s;) { instruction.push_back(s); }
	return instruction;
}

void printToConsole(vector<string> passInput) {
	passInput.erase(passInput.begin());
	copy(passInput.begin(), passInput.end(), ostream_iterator<string>(cout, " "));
}

int main() {
	//Variables
	string userInput;
	bool openEdit = false;
	bool running = true;
	bool edit = true;
	bool goRan = false;
	bool valid;
	int goline;
	string commands[7] = {"PRINT","?","HELP","EXIT","GOTO","GOSUB","RETURN"};
	int pass = 0;
	int cmdLen = commands->size();
	vector<string> userInstruct;
	vector<vector<string>> instructCache;
	vector<vector<string>> rtCache;
	//Startup
	cout << "		**** COMMODORE 64 BASIC V2 **** \n";
	cout << "	4G RAM SYSTEM	4294771200 BASIC BYTES FREE";
	//Main Section
	while (running == true) {
		valid = false;
		cout << "\n READY. \n";
		getline(cin, userInput);
		userInstruct = splitToArray(userInput);
		runPass:int execLen = userInstruct.size();
		//CMD handling
		for (int i = 0; i <= cmdLen; i++) {
			if (commands[i] == userInstruct[0]) { valid = true; }
			else { continue; }
		}
		try
		{
			if (valid == true) {
				if (userInstruct[0] == commands[0] || userInstruct[0] == commands[1]) {
					printToConsole(userInstruct);
				}
				else if (userInstruct[0] == commands[4]) {
					for (int j = 0; j < instructCache.size(); j++) {
						if (userInstruct[1] == instructCache[j][0]) {
							userInstruct = rtCache[j];
							pass = j;
							goto runPass;
						}
						else { continue; }
					}
				}
				else if (userInstruct[0] == commands[5]) {
					for (int k = 0; k < instructCache.size(); k++) {
						if (userInstruct[1] == instructCache[k][0]) {
							goRan = true;
							userInstruct = rtCache[k];
							goline = pass;
							pass = k;
							goto runPass;
						}
						else { continue; }
					}
				}
				else if (userInstruct[0] == commands[6]) {
					if (goRan == true) {
						userInstruct = rtCache[goline + 1];
						pass = goline + 1;
						goRan = false;
						goto runPass;
					}
					else { cout << "\n ?RETURN WITHOUT GOSUB ERROR IN LINE"; }
				}
				else if (userInstruct[0] == commands[3]) { running = false; }
			}
			else if (userInput == "~") {
				pass = 0;
				openEdit = true;
				while (edit == true) {
					cout << "> ";
					getline(cin, userInput);
					vector<string> writeCache = splitToArray(userInput);
					if (userInput == "RUN") {
						rtCache = instructCache;
						for (int l = 0; l < instructCache.size(); l++) {
							rtCache[l].erase(rtCache[l].begin());
						}
						userInstruct = rtCache[pass];
						edit = false;
						goto runPass;
					}
					else if (userInput == "SAVE") {/*Handle later*/ }
					else if (userInput == "~") { throw(valid); }
					else {
						instructCache.push_back(writeCache);
						writeCache.clear();
						continue;
					}
				}
			}
			else { throw(valid); }
		}
		catch (bool syntaxError)
		{
			cout << "?Syntax Error \n";
			openEdit = false;
			pass = rtCache.size();
			continue;
		}
		if (openEdit == true) {
			if (pass < rtCache.size()) {
				pass++;
				userInstruct.clear();
				userInstruct = rtCache[pass];
				goto runPass;
			}
			else if (pass >= rtCache.size()) {
				openEdit = false;
				userInput = "";
				userInstruct.clear();
				instructCache.clear();
				rtCache.clear();
				continue;
			}
		}
		else { continue; }
	}
	return EXIT_SUCCESS;
}