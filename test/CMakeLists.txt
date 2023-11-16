add_executable(LsT ListTest.cpp)
add_executable(SnT SongT.cpp)
add_executable(CDT CDTest.cpp ../src/CD.cpp)
add_executable(QuT QueueTest.cpp ../src/Queue.cpp)

add_test(LsT LsT)
add_test(SnT SnT)
add_test(CDT CDT)
add_test(QuT QuT)
