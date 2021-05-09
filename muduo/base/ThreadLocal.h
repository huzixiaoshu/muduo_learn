// Author:Shuo Chen
// learn : huzixiaohu
// data:2021/05/09

#ifndef MUDUO_BASE_THREADLOCAL_H
#define MUDUO_BASE_THREADLOCAL_H

#include "muduo/base/Mutex.h"
#include "muduo/base/noncopyable.h"

#include <pthread.h>

namespace muduo
{

template<typename T> 
class ThreadLocal : noncopyable
{
 public:
  ThreadLocal()
  {
      MCHECK(pthread_key_create(&pkey_, &ThreadLocal::destructor));
  }
  ~ThreadLocal()
  {
      MCHECK(pthread_key_delete(pkey_));
  }

  T& value()
  {
    T* perThreadValue  = static_cast<T*> (pthread_getspecific(pkey_));
    if(!perThreadValue)
    {
        T* newobj = new T ();
        MCHECK(pthread_setspecific(pkey_,newobj));
        perThreadValue = newobj;
    }
    return *perThreadValue;
  }
 private:

  static void destructor(void* x)
  {
      T* obj =static_cast<T*>(x);
      typedef char T_must_be_complete_type[sizeof(T)==0?-1:1];
      T_must_be_complete_type dummy; (void)dummy;
      delete obj;
  }

 private:
 pthread_key_t pkey_;
};

}//namespcae muduo

#endif //MUDUO_BASE_THREADLOCAL_H