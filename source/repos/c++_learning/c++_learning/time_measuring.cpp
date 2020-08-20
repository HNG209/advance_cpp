#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
class timer {
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> time;
	double count;
public:
	timer() : time(0),count(0.0){
		//empty constructor
	}
	void start_timing() {
		start = std::chrono::high_resolution_clock::now();//start from now
	}
	void delay(const std::chrono::seconds& time) {
		//dừng chương trình chạy trong khoảng thời gian xác định
		std::this_thread::sleep_for(time);
	}
	void delay(const std::chrono::milliseconds& time) {//overloaded method
		std::this_thread::sleep_for(time);
	}
	void delay(const std::chrono::microseconds& time) {//overloaded method
		std::this_thread::sleep_for(time);
	}
	double return_time() {//if you need the time for calculating purposes
		end = std::chrono::high_resolution_clock::now();
		time = end - start;
		double count = time.count() * 1000.0;
		return count;
	}
	auto end_timing() {
		end = std::chrono::high_resolution_clock::now();
		time = end - start;
		this->count = time.count();
		return this;//return the object
		//kết thúc bấm giờ,sẽ trả về thời gian và lưu vào count
		//muốn in ra thì phải trỏ tới 2 phương thức bên dưới
	}
	inline void to_seconds() {//print out the time in seconds format
		cout << "run time:" << this->count << "s\n";
	}
	inline void to_milliseconds() {//print out the time in milliseconds format
		cout << "run time:" << this->count * 1000.0 << "ms\n";
	}
	~timer() {
		//empty destructor
	}
};
void print() {
	timer time;
	time.start_timing();
	printf("wait the minutes!");
	time.delay(10s);
	printf("ok that's it^^");
	//time.delay(10s);//uncomment this to see if it actually affected
	time.end_timing()->to_seconds();//print to see if it ouput approximately 1000ms
}
void print_and_delay() {
	timer time;
	time.start_timing();//bắt đầu tính giờ
	for (int i = 0; i < 10; i++) {
		//print out hello world every 2 seconds
		printf("hello world\n");//printf for better performance
		time.delay(1s);//delay for 2 seconds
	}
	//time.end_timing()->to_seconds();//dừng tính giờ và in ra
	//time.end_timing()->to_milliseconds();//định dạng millis giây
	cout << "run time:" << time.end_timing()->return_time();
}
int main() {
	print_and_delay();
	return 0;
}