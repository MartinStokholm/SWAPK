#include <iostream>
#include <utility>

int main() {
    std::cout << "Hello, World!" << std::endl;

    class Monkey {
    public:
        Monkey(int age, std::string name) : age_(age), name_(std::move(name)) {
            std::cout << "Monkey created" << std::endl;
        }

        Monkey() : age_(0) {
            std::cout << "Default Monkey created" << std::endl;
        }

        ~Monkey() {
            std::cout << "Monkey killed" << std::endl;
        }

    private:
        int age_;
        std::string name_;
    };

    class MonkeyHouse {
    public:
        MonkeyHouse() {
            std::cout << "MonkeyHouse created" << std::endl;
        }

        ~MonkeyHouse() {
            std::cout << "MonkeyHouse destroyed" << std::endl;
        }

        void getMonkey(int index) {
            std::cout << monkeys_[index].name_ << std::endl;
        }

        void addMonkey(const Monkey& monkey) {
            monkeys_[monkeyCount_++] = monkey;
        }

    private:
        Monkey monkeys_[10];
        int monkeyCount_ = 0;
    };

    MonkeyHouse monkeyHouse;
    Monkey monkey(10, "Bob");
    monkeyHouse.addMonkey(monkey);


    return 0;
}
