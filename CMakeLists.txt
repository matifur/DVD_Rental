cmake_minimum_required(VERSION 3.25)
project(DVD_Rental)

set(CMAKE_CXX_STANDARD 17)

add_executable(DVD_Rental main.cpp DVD_Database.h Movie.h admin_running.h client_running.h RentalRecord.h)
