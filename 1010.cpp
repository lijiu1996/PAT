#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
long long change(string n, long long radix) {
	long long ans = 0;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] >= '0'&&n[i] <= '9')
			ans = ans * radix + (n[i] - '0');
		else if (n[i] >= 'a' && n[i] <= 'z')
			ans = ans * radix + (n[i] - 'a') + 10;
	}
	return ans;
}
long long find_radix(string n, long long num) {
	char it = *max_element(n.begin(), n.end());
	long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
	long long high = max(num, low);
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long t = change(n, mid);
		if (t < 0 || t > num) high = mid - 1;
		else if (t == num) return mid;
		else low = mid + 1;
	}
	return -1;
}
int main() {
	string n1, n2, num2;
	long long tag, radix ,num1;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 1) {
		num1 = change(n1, radix);
		num2 = n2;
	}
	else {
		num1 = change(n2, radix);
		num2 = n1;
	}	//num1为十进制数，num2为未转化的字符串
	long long  rad = 2, flag = 0, n = 0;
	while (n<=num1) {
		n = change(num2, rad);
		if(n<0){
		  break;
		}
		else if (n == num1) {
			flag = 1;
			break;
		}
    else
      rad++;
  }
	if(flag==1 && rad<=3147483647 && rad>=2) printf("%lld", rad);
	else printf("Impossible");
	return 0;
}