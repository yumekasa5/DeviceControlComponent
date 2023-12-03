#ifndef SINGLETONBASE_H
#define SINGLETONBASE_H

#include <memory>

template <class T>
class SingletonBase{
public:
    static T &singleton(){
        static typename T::singleton_ptr_t s_singleton(T::createInstance());
        return getReference(s_singleton);
    }

private:
    typedef std::unique_ptr<T> singleton_ptr_t;

    inline static T *createInstance() {return new T();}
    inline static T &getReference(const singleton_ptr_t &ptr){
        return *ptr;
    }

protected:
    SingletonBase(){}

private:
    SingletonBase(const SingletonBase &) = delete;
    SingletonBase &operator=(const SingletonBase &) = delete;
    SingletonBase(SingletonBase &&) = delete;
    SingletonBase &operator=(SingletonBase &&) = delete;
};

#endif // SINGLETONBASE_H
