CXXFLAGS = -Wall -std=c++11

OBJECTS = books ch10_drill ch10_files sum_ints ch17_drill Link ch18_drill \
			ch18_arrays ch18_vectors ch18_ex skip_list

all: $(OBJECTS)

clean:
	rm -f $(OBJECTS)