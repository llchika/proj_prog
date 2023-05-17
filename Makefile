# Compiler flags
CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11

# Directories
src_dir=src
inc_dir=-Iinclude -Iinclude/entity -Iinclude/game -Iinclude/graphics -Iinclude/utils
obj_dir=obj
lib_dir=lib
bin_dir=bin

# Files
src=$(shell find $(src_dir) -name '*.cpp')
obj=$(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.o,$(src))

# Executable
exe=$(bin_dir)/Main

# Libraries
LIBS=-L$(lib_dir) `pkg-config --libs sdl2 SDL2_gfx SDL2_image`

# Recipes
all:$(exe)

$(exe): $(obj)
	$(CXX) $(CXXFLAGS) -o $(exe) $(obj) $(LIBS)

$(obj_dir)/%.o: $(src_dir)/%.cpp | $(obj_dir)
	$(CXX) $(CXXFLAGS) $(inc_dir) -c -o $@ $<

$(obj_dir):
	mkdir -p $(obj_dir)

clean:
	-rm -f obj/*.o
	-rm -f obj/*/*.o