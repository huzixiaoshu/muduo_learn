add_executable ( atomic_unittest Atomic_unittest.cc )
#target_link_libraries(timestamp_unittest  muduo_base)

add_executable ( BlockingQueue_bench_unittest  BlockingQueue_bench.cc )
target_link_libraries(BlockingQueue_bench_unittest  muduo_base)

add_executable ( BlockingQueue_unittest  BlockingQueue_test.cc )
target_link_libraries(BlockingQueue_unittest  muduo_base)

add_executable ( boundedblockingqueue_unittest  BoundedBlockingQueue_test.cc )
target_link_libraries(boundedblockingqueue_unittest  muduo_base)

add_executable ( exception_test Exception_test.cc )
target_link_libraries(exception_test  muduo_base)

add_executable ( mutex_test Mutex_test.cc )
target_link_libraries(mutex_test  muduo_base)

add_executable ( thread_test Thread_test.cc )
target_link_libraries(thread_test  muduo_base)

add_executable ( ThreadPool_unittest ThreadPool_test.cc )
target_link_libraries(ThreadPool_unittest  muduo_base)

add_executable ( timestamp_unittest Timestamp_unittest.cc )
target_link_libraries(timestamp_unittest  muduo_base)
