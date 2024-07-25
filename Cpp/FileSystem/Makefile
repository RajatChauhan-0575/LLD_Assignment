all: fs
fs: main.cpp
	clang -lstdc++ -g -O3 main.cpp Entities/Dir.cpp Entities/File.cpp Entities/EntryFactory.cpp Services/filesystem.cpp -o filesystem
clean: 
	rm -rf filesystem