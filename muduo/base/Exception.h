// Author:Shuo Chen
// learn : huzixiaohu
// data:2021/04/21

#ifndef MUDUO_BASE_EXCEPTION_H
#define MUDUO_BASE_EXCEPTION_H

#include "muduo/base/Types.h"
#include <exception>

namespace muduo
{

class Exception : public std::exception
{
 public:
  Exception(string what);
  ~Exception() noexcept override = default; 

  // default copy-ctor and operator= are okay.
 //覆盖了父类的what函数,用于打印异常信息
  const char* what() const noexcept override
  {
    return message_.c_str();
  }

  const char* stackTrace() const noexcept
  {
    return stack_.c_str();
  }

 private:
  string message_;
  string stack_;
};

}  // namespace muduo

#endif  // MUDUO_BASE_EXCEPTION_H
