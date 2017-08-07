all: vectorAdd

vectorAdd: vectorAdd.o
	nvcc -o vectorAdd vectorAdd.o

vectorAdd.o: vectorAdd.cu
	nvcc -I../common/inc -c vectorAdd.cu -o vectorAdd.o
