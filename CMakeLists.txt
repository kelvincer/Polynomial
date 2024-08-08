cmake_minimum_required(VERSION 3.5)

project(Deitel-Polynomial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Deitel-Polynomial main.cpp
    polynomial.h polynomial.cpp
    polynomialterm.h polynomialterm.cpp)

include(GNUInstallDirs)
install(TARGETS Deitel-Polynomial
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
