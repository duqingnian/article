#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Singleton {
public:
	// 获取单例实例
	static Singleton& getInstance() {
		static Singleton instance; // 局部静态变量，线程安全
		return instance;
	}

	// 禁用拷贝构造函数和赋值操作符
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	// 示例成员函数
	void showMessage() {
		std::cout << "Hello from Singleton!" << std::endl;
	}

private:
	Singleton() {} // 私有构造函数
};

int main() {
	// 创建线程向单例发送请求
	std::vector<std::thread> threads;

	for (int i = 0; i < 5; ++i) {
		threads.emplace_back([]() {
			Singleton::getInstance().showMessage();
			});
	}

	// 等待所有线程完成
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}