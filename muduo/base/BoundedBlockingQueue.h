// Author:Shuo Chen
// learn : huzixiaohu
// data:2021/05/07

#ifndef MUDUO_BASE_BOUNDEDBLOCKINGQUEUE_H
#define MUDUO_BASE_BOUNDEDBLOCKINGQUEUE_H

#include "muduo/base/Condition.h"
#include "muduo/base/Mutex.h"

#include <boost/circular_buffer.hpp>
#include <assert.h>

namespace muduo
{

template<typename T>
class BoundedBlockingQueue : noncopyable
{
public :
explicit  BoundedBlockingQueue(int maxSize)
: mutex_(),
  notEmpty_(mutex_),
  notFull_(mutex_),
  queue_(mutex_)
  {
  }
  void put(const T& x)
  {
      MutexLockGuard lock(mutex_);
      while(queue_.full())
      {
          notFull_.wait();
      }
      assert(!queue_.full());
      queue_.push_back(x);
      notEmpty_.notify();
  }
  



private:
mutable MutexLock  mutex_;
Condition  notEmpty_ GUARDED_BY(mutex_);  //GUARDED_BY 是为了保证线程安全，使用该属性必须先锁定mutex——
Condition  notFull_  GUARDED_BY(mutex_);
boost::circular_buffer<T> queue_  GUARDED_BY(mutex_);

}

}//namespace muduo








#endif//MUDUO_BASE_BOUNDEDLOCKINGQUEUE_H