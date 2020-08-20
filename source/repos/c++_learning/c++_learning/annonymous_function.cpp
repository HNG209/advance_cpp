#include<iostream>
#include "timer.h"
using namespace Timer;
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
auto swap2 = [](int& a, int& b) -> void {
	int temp = a;
	a = b;
	b = temp;
};
auto hack_NASA = [](void) -> void {
	timer time;
	time.start_timing();
	for (int i = 0; i <= 100; i += 10) {
		cout << "NASA hacking in progress:" << i << "%\n";
		time.delay(300ms);
	}
	auto now = time.end_timing()->return_time();
	printf_s("NASA hacked successfully!time elapsed:%fl seconds", now);
};
int main() {
	hack_NASA();
	return 0;
}