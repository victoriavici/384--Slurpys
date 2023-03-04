#include <iostream>
#include <vector>
using namespace std;

bool slumps(string slovo) {
	if (slovo != "") {
		if (slovo.at(0) == 'D' || slovo.at(0) == 'E') {
			for (int i = 1; i < slovo.size() - 1; i++)
			{
				if (slovo.at(i) != 'F') {
					if (i == 1) {
						return false;
					}
					return slumps(slovo.substr(i));
					
				}
			}

			if (slovo.at(slovo.size() - 1) == 'G' || slovo.at(slovo.size() - 1 == 'F')) {
				return true;
			}
		}
	}
	return false;
}

bool slimp(string slovo) {
	if (slovo == "") {
		return false;
	}
	if (slovo.at(0) == 'A') {
		if (slovo.size() == 2) {
			if (slovo == "AH") {
				return true;
			}
			return false;
		}
		if (slovo.size() == 3) {
			if (slovo == "AHC") {
				return false;
			}
		}
		do {
			slovo.erase(0,1);
		} while (!(slovo.at(0) != 'B' || slovo.size() == 1));
		
		int poz = slovo.find_last_of('C');
		if (poz == -1) {
			return false;
		}
		slovo.erase(poz,1);
		string pom = slovo.substr(0, poz);

		if (slumps(slovo)) {
			return true;
		}

		if (slimp(slovo)) {
			return true;
		}
	}
	return false;
}

bool slurpy(string slovo) {
	int poz = slovo.find_last_of("C");
	if (poz == -1) {
		poz = slovo.find("H");
	}
	if (poz == -1) {
		return false;
	}
	return slimp(slovo.substr(0, poz + 1)) && slumps(slovo.substr(poz + 1));
}

int main() {

	long long input;
	cin >> input;
	vector<string> v;
	string pom;
	for (long long i = 0; i < input; i++)
	{
		cin >> pom;
		v.push_back(pom);
	}
	cout << "SLURPYS OUTPUT" << endl;
	for (long long i = 0; i < input; i++)
	{
		if (slurpy(v.at(i))) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	v.clear();
	return 0;
}