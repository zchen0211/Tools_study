all: tmpl

tmpl: tmpl.o
	nvcc -o tmpl tmpl.o

tmpl.o: gather.cu
	nvcc -I../common/inc -c gather.cu -o tmpl.o
