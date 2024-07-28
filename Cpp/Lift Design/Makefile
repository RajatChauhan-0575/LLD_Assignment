all: fs
fs: main.cpp
	clang -std=c++17 -lstdc++ -g -O3 main.cpp Entities/Lift.cpp Entities/LiftController.cpp Strategies/LiftMoveByOrder.cpp Strategies/LiftMoveBySortedFloor.cpp -o LiftDesign
clean: 
	rm -rf LiftDesign