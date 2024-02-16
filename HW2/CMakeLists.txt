cmake_minimum_required(VERSION 3.27)
project(HW2 C)

set(CMAKE_C_STANDARD 99)

add_executable(HW2 main.c
        Airport.c
        Airport.h
        AirportManager.c
        AirportManager.h
        Plane.c
        Plane.h
        Date.c
        Date.h
        Flight.c
        Flight.h
        Airline.c
        Airline.h
        Functions.c
        Functions.h
        generalStrings.c)
