#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

string &multiple_one(string &answer, string &arr) {
	int tmp = 0;
	int i=0;
	string tmp_str;
	int sizing = arr.size();
	int maxsize1 = answer.size();
	for (;i < maxsize1 + sizing - 1; i++) {
		for (int j=max(0, i - maxsize1 + 1); j <= min(i, sizing - 1); j++){
			tmp += (answer[i - j] - '0') * (arr[j] - '0');
		}
		if (i - sizing + 1 > 0) {
			answer[i - sizing] = tmp_str[i%sizing];
			tmp_str[i%sizing] = tmp % 10 + '0';
		} else {
			tmp_str.push_back(tmp % 10 + '0');
		}
		tmp =  tmp / 10;
	}
	answer[maxsize1 - 1] = tmp_str[(maxsize1 - 1)%sizing];
	int k = 1;
	while (k < sizing) {
		answer.push_back(tmp_str[(i + k)%sizing]);
		k++;
	}
	while (tmp) {
		answer.push_back(tmp % 10 + '0');
		tmp = tmp / 10;
		i++;
	}
	return answer;
}

string &multiple(string &answer) {
	int tmp = 0;
	int i=0;
	string tmp_str;
	int maxsize1 = answer.size();
	for (;i < maxsize1 * 2 - 1; i++) {
		for (int j=max(0, i - maxsize1 + 1); j <= min(i, maxsize1 - 1); j++){
			tmp += (answer[i - j] - '0') * (answer[j] - '0');
		}
		if (i - maxsize1 + 1 > 0) {
			answer[i - maxsize1] = tmp_str[i - maxsize1];
			tmp_str[i - maxsize1] = tmp % 10 + '0';
		} else {
			tmp_str.push_back(tmp % 10 + '0');
		}
		tmp =  tmp / 10;
	}
	answer[maxsize1 - 1] = tmp_str[maxsize1 - 1];
	for (int j = 0; j < maxsize1 - 1; j++) {
		answer.push_back(tmp_str[j]);
	}
	while (tmp) {
		answer.push_back(tmp % 10 + '0');
		tmp = tmp / 10;
		i++;
	}
	return answer;
}

string &power(int b, string &answer, string &arr) {
	if (b == 2) return multiple_one(answer, arr);
	else return multiple_one(power(b-1, answer, arr), arr);
}

int main() {
	string arr;
	string answer;
	int b;
	fastio;
	cin >> arr >> b;
	reverse(arr.begin(), arr.end());
	int dot_pos = arr.find('.');
	arr.erase(remove(arr.begin(), arr.end(), ('.')), arr.end());
	dot_pos *= b;
	answer = arr;

	answer = power(b, answer, arr);
	for (int i=answer.size()-1; i >= 0; i--) {
		if (i == dot_pos - 1) cout << ".";
		cout << answer[i];
	}
	cout << endl;
}




// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// //kks227님 출처
// //bigInteger 덧셈 구현
// string Add(string &s1, string &s2)
// {
// 	string result(max(s1.size(), s2.size()), '0');
// 	bool carry = false;
// 	for (int i = 0; i < result.size(); i++)
// 	{
// 				int temp = carry;
// 				carry = false;

// 				if (i < s1.size())
// 						temp += s1[s1.size() - i - 1] - '0';
// 				if (i < s2.size())
// 						temp += s2[s2.size() - i - 1] - '0';
// 				if (temp >= 10)
// 				{
// 						carry = true;
// 						temp -= 10;
// 				}
// 				result[result.size() - i - 1] = temp + '0';
// 	}
// 	if (carry)
// 				result.insert(result.begin(), '1');
// 	return result;
// }

// //bigInteger 곱셈 구현
// string Multiply(string &s1, string &s2)
// {
// 	string result = "0";
// 	for (int i = 0; i < s2.size(); i++)
// 	{
// 				string line(s1);
// 				int carry = 0;
// 				for (int j = s1.size() - 1; j >= 0; j--)
// 				{
// 						int temp = carry;
// 						carry = 0;
// 						temp += (s1[j] - '0')*(s2[s2.size() - i - 1] - '0');
// 						if (temp >= 10)
// 						{
// 								carry = temp / 10;
// 								temp %= 10;
// 						}
// 						line[j] = temp + '0';
// 				}
// 				if (carry > 0)
// 						line.insert(line.begin(), carry + '0');
// 				line += string(i, '0');
// 				result = Add(result, line);
// 	}
// 	return result;
// }

// //bigInteger 지수승 구현
// string power(string &s1, int p)
// {
// 	if (p == 1)
// 				return s1;

// 	string result = power(s1, p - 1);
// 	result = Multiply(result, s1);
// 	return result;
// }

// int main(void)
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	string A;
// 	int B;
// 	cin >> A >> B;

// 	//소수점 위치를 찾고
// 	string::iterator finder = find(A.begin(), A.end(), '.');
// 	int idx = 0;
// 	//소수점을 지워준다
// 	if (finder != A.end())
// 	{
// 				idx = A.end() - finder - 1;
// 				A.erase(finder);
// 	}
// 	//소수점이 추가될 위치를 저장하고
// 	idx *= B;

// 	string result = power(A, B);
// 	//소수점이 존재한다면 소수점을 추가해준다
// 	if (idx > 0)
// 				result.insert(result.end() - idx, '.');
// 	cout << result << "\n";
// 	return 0;
// }


