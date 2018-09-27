TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bubble.cpp \
    insertion.cpp \
    organizer.cpp \
    Merge.cpp \
    sortAlgo.cpp

HEADERS += \
    bubble.h \
    insertion.h \
    organizer.h \
    algorithm.h \
    Merge.h \
    sortAlgo.h

DISTFILES += \
    ../../Desktop/CSE 3353 data/cse 3353 lab1 graphs.pdf \
    ../../Desktop/CSE 3353 data/20 unique.xlsx \
    ../../Desktop/CSE 3353 data/partial sort.xlsx \
    ../../Desktop/CSE 3353 data/random.xlsx \
    ../../Desktop/CSE 3353 data/reverse order.xlsx \
    ../../Desktop/CSE 3353 data/size 10 raw table (1).xlsx \
    ../../Desktop/CSE 3353 data/size 1000 raw table.xlsx \
    ../../Desktop/CSE 3353 data/size 10000 raw table.xlsx \
    ../../Desktop/CSE 3353 data/size 100000 raw table.xlsx
