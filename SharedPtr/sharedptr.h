//
// Created by msldk on 05/09/2023.
//

#ifndef EXERCISE1_SHAREDPTR_H
#define EXERCISE1_SHAREDPTR_H

template<typename T>
class SharedPtr {
public:
    explicit SharedPtr(T* ptr) : ptr_(ptr), count_(new int(1)) {
    }

    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), count_(other.count_) {
        ++(*count_);
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            if (--(*count_) == 0) {
                delete ptr_;
                delete count_;
            }
            ptr_ = other.ptr_;
            count_ = other.count_;
            ++(*count_);
        }
        return *this;
    }

    // Dereference operator overload
    T& operator*() const {
        return *ptr_;
    }

    // Arrow operator overload
    T* operator->() const {
        return ptr_;
    }

    // Get count
    size_t getCount() const {
        return *count_;
    }

    // Check if pointer is valid using explicit bool operator overload
    explicit operator bool() const {
        return ptr_ != nullptr;
    }

    // Comparison operator overload
    bool operator==(const SharedPtr& other) const {
        return ptr_ == other.ptr_;
    }

    ~SharedPtr() {
        if (--(*count_) == 0) {
            delete ptr_;
            delete count_;
        }
    }

private:
    T *ptr_;
    int *count_;
};

#endif //EXERCISE1_SHAREDPTR_H
