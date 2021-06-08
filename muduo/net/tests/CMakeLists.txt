add_executable(channel_test Channel_test.cc)
target_link_libraries(channel_test muduo_net)

if(BOOSTTEST_LIBRARY)

add_executable(inetaddress_unittest InetAddress_unittest.cc)
target_link_libraries(inetaddress_unittest muduo_net boost_unit_test_framework)
add_test(NAME inetaddress_unittest COMMAND inetaddress_unittest)


endif()