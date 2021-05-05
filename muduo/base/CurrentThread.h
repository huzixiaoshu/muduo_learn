// Author:Shuo Chen
// learn : huzixiaohu
// data:2021/04/21
#ifndef MUDUO_BASE_CURRENTTHREAD_H
#define MUDUO_BASE_CURRENTTHREAD_H

#include "muduo/base/Types.h"

namespace muduo
{
  namespace CurrentThread
  {
    // internal
    // _thread修饰的变量是线程局部存储的
    extern __thread int t_cachedTid;   
    extern __thread char t_tidString[32];
    extern __thread int t_tidStringLength;
    extern __thread const char* t_threadName;
    void cacheTid();

    inline int tid()
    {
      if(__builtin_expect(t_cachedTid == 0,0 ))  //t_cachedTid 为0的概率大
      {
        cacheTid();
      }
      return t_cachedTid;
    }
    inline const char* tidString()  //for logging
    {
      return t_tidString;
    }
    inline int tidStringLength()   //for logging
    {
      return t_tidStringLength;
    }
    inline const char* name()
    {
      return t_threadName;
    }
    bool isMainThread();

    void sleepUsec(int64_t usec);  //for testing

    string stackTrace(bool demangle);

  } // namespace CurrentThread
  

} // namespace muduo
#endif //MUDUO_BASE_CURRENTTHREAD_H