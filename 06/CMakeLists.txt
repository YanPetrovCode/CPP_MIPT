set(TARGET "calculator")
#TAGET = calculator

project(${TARGET} CXX)

set(SOURCES
calculator.cpp
token.cpp
variable.cpp
 )

 add_executable(${TARGET} ${SOURCES})

 install(TARGETS ${TARGET})