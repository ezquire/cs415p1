CFLAGS = -g -Wall -Werror - Wpedantic

srcs = $(wildcard /*.cpp)

objs = $(srcs:.cpp=.o)

all : task1 task2 task3

tasks : $(objs)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean :
	rm task1 task2 task3 *~
