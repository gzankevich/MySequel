add_executable(mysequel main.cpp queryMode.cpp mysqlConnector.cpp windowInterface.cpp queryInputWindow.cpp queryOutputWindow.cpp outputMessageBuffer.cpp)
target_link_libraries(mysequel ncurses mysqlclient z crypt nsl m)
