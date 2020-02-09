#include <iostream>
using namespace std;

// 2941번 : 크로아티아 알파벳

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int res = 0;
	string input;
	cin >> input;

	int total_size = input.length();

	string chroatia[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	for (string tmp : chroatia) {
		if (input.find(tmp) != string::npos) {	// 크로아티아 알파벳이 있을 경우
			//cout << "Detected : " << tmp << endl;
			int tmp_size = tmp.length();
			int count = 0;
			string str = input;
			while (str.find(tmp) != string::npos) {
				int start = str.find(tmp);
				if (tmp == "z=" && start != 0) {
					string check = str.substr(start - 1, 3);
					//cout << "Check : " << check << endl;
					if (check == "dz=") {
						res--;
						count--;
					}
				}
				res++;
				count++;

				if (start + tmp_size < str.length())
					str = str.substr(start + tmp_size);
				else
					break;
			}
			total_size -= count * tmp_size;
			//cout << "Found : " << tmp << " * " << count << endl;
			//cout << total_size << endl;
		}
	}
	cout << res + total_size << endl;

	return 0;
}