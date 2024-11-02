#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::remove

// 观察者接口
class Observer {
public:
    virtual void update(int state) = 0;
};

// 主题类
class Subject {
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() {
        for (auto observer : observers) {
            observer->update(state);
        }
    }

    void setState(int state) {
        this->state = state;
        notify();
    }

private:
    std::vector<Observer*> observers;
    int state;
};

// 具体观察者
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(int state) override {
        std::cout << "Observer " << name << " received update: state = " << state << std::endl;
    }

private:
    std::string name;
};

int main() {
    Subject subject;

    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setState(1);  // 主题状态改变，通知观察者
    subject.setState(2);  // 再次改变状态，通知观察者

    return 0;
}


/*
输出：
Observer Observer1 received update: state = 1
Observer Observer2 received update: state = 1
Observer Observer1 received update: state = 2
Observer Observer2 received update: state = 2
*/