# Compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Directories
src_dir = src
inc_dir = include
obj_dir = obj
lib_dir = lib

# Files
src = $(wildcard $(src_dir)/*.cpp)
obj = $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.o,$(src))

# Executable
exe = Main

# Libraries
LIBS = -L$(lib_dir)

# Recipes
all: $(exe)

$(exe): $(obj)
	$(CXX) $(CXXFLAGS) -o $(exe) $(obj) $(LIBS)

$(obj_dir)/%.o: $(src_dir)/%.cpp | $(obj_dir)
	$(CXX) $(CXXFLAGS) -I$(inc_dir) -c -o $@ $<

$(obj_dir):
	mkdir -p $(obj_dir)

clean:
	rm -rf $(obj_dir)/*.o $(exe)
