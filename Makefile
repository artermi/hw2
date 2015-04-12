target = hw2
CFLAG = -O2 -Wall
CPPFLAGS = -O2 -std=c++11 -Wall
name = demo

all:$(target)

%: %.cpp
	g++ $(CPPFLAGS) $< -o $(name)

hw2: main.cpp functions.cpp theDATA.cpp functions.h theDATA.h
	g++ $(CPPFLAGS) main.cpp functions.cpp theDATA.cpp functions.h theDATA.h -o $(name)

clean:
	rm -rf $(target)
	
run:
	./demo
