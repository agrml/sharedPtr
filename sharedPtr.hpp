#include <gtest/gtest.h>

#include <iostream>


template<typename T>
class SharedPtr
{
public:
    SharedPtr() = default;
    explicit SharedPtr(T* const pVal);
    SharedPtr(const SharedPtr& other);
    ~SharedPtr();

    T& operator*();
    T* operator->();

    template<class U>
    friend bool operator==(const SharedPtr<U> &lhs, const SharedPtr<U> &rhs);

private:
    T* pVal_{nullptr};
    size_t* pCnt_{nullptr};

    FRIEND_TEST(Internals, defaultConstructor);
    FRIEND_TEST(Internals, fromPtr);
};


// ==================Implementation======================

template<typename T>
T& SharedPtr<T>::operator*()
{
    return *pVal_;
}

template<typename T>
T* SharedPtr<T>::operator->()
{
    return &*pVal_;
}

template<typename U>
bool operator==(const SharedPtr<U>& lhs, const SharedPtr<U>& rhs)
{
    return lhs.pVal_ == rhs.pVal_;
}

template<typename T>
SharedPtr<T>::SharedPtr(T* const pVal) : pVal_(pVal),
                                         pCnt_(new size_t{1}) {}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other) : pVal_(other.pVal_),
                                                  pCnt_(other.pCnt_)
{
    ++*pCnt_;
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
    if (pCnt_ == nullptr) {
        return;
    }
    if (pVal_ == nullptr || *pCnt_ == 0) {
        std::cout << "err" << std::endl;
    }
    if (--*pCnt_ == 0) {
        delete pVal_;
        delete pCnt_;
    }
}

