all:
	g++ -Iinclude src/main.cpp src/ids.cpp src/modelos.cpp src/persistencia.cpp -o main && ./main