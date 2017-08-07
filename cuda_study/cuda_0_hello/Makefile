all: helloWorld

helloWorld: helloWorld.o
	nvcc -o helloWorld helloWorld.o

helloWorld.o: helloWorld.cu
	nvcc -c helloWorld.cu -o helloWorld.o
