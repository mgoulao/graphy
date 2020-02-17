SOURCES = vertex.cpp edge.cpp graph.cpp 
SOURCES += algorithms/astar.cpp
SOURCES += main.cpp 

DIST_DIR = ../dist/
NAME = graphy

# g++
OBJS = $(SOURCES:%.cpp=%.o)
CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS =
TARGET = $(DIST_DIR)$(NAME)

# Emscripten
EMCC = em++
EMFLAGS = -D __EMSCRIPTEN__ -std=c++11 -Wall
EMLDFLAGS = --bind
EMTARGET = $(DIST_DIR)$(NAME)_module.js
WASM = $(DIST_DIR)$(NAME)_module.wasm

all: $(TARGET)
wasm: $(EMTARGET)

main.o: main.cpp graph.hpp
graph.o: graph.cpp graph.hpp vertex.hpp edge.hpp
edge.o: edge.cpp vertex.hpp edge.hpp
vertex.o: vertex.cpp vertex.hpp
algorithms/astar.o: algorithms/astar.cpp graph.hpp

$(OBJS):
ifeq ($(MAKECMDGOALS),wasm)
	@echo $@
	$(EMCC) $(EMFLAGS) -c -o $@ $< 
else
	$(CC) $(CFLAGS) -c -o $@ $< 
endif

# g++

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(LDFLAGS)

# wasm

$(EMTARGET): $(OBJS)
	$(EMCC) $(EMFLAGS) -o $(EMTARGET) $^ $(EMLDFLAGS)

clean: 
	@echo
	@echo ----  Cleaning project ...  ----
	@echo 
	rm -f $(TARGET) $(OBJS) $(EMTARGET) $(WASM)
	@echo
	@echo ----  Very nice!  ----

cleanObjects: 
	@echo
	@echo ----  Cleaning objects ...  ----
	@echo 
	rm -f $(OBJS)
	@echo
	@echo ----  Very nice!  ----
