protoc -I=./ --cpp_out=./ addressbook.proto

g++ main_read.cc addressbook.pb.cc -I/usr/include -lprotobuf -o main_read
