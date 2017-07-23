ROOT=$(shell pwd)
SERVER=$(ROOT)/server
CLIENT=$(ROOT)/client
LOG=$(ROOT)/log
COMM=$(ROOT)/comm
POOL=$(ROOT)/data_pool
LIB=$(ROOT)/lib
WINDOW=$(ROOT)/window
PLUGIN=$(ROOT)/plugin
CONF=$(ROOT)/conf

SERVER_BIN=chat_system
CLIENT_BIN=chat_system

INCLUDE=-I$(POOL) -I$(LOG) -I$(COMM) -I$(LIB)/include -I$(WINDOW)
LIB_PATH=
LDFLAGS=-L$(LIB)/lib -lpthread -ljsoncpp -static

CC=g++

SERVER_OBJ=$(shell ls $(SERVER)|grep -E '\.cpp'|sed 's/\.cpp/\.o/')
SERVER_OBJ=$(shell ls $(POOL)|grep -E '\.cpp'|sed 's/\.cpp/\.o/')
SERVER_OBJ=$(shell ls $(LOG)|grep -E '\.cpp'|sed 's/\.cpp/\.o/')
SERVER_OBJ=$(shell ls $(COMM)|grep -E '\.cpp'|sed 's/\.cpp/\.o/')
CLIENT_OBJ=$(shell ls $(CLIENT)|grep -E '\.cpp'|sed 's/\.cpp/\.o/')
CLIENT_OBJ=$(shell ls $(LOG)|grep -E '\.cpp'|sed 's/\.cpp/\.o/')
CLIENT_OBJ=$(shell ls $(COMM)|grep -E '\.cpp'|sed 's/\.cpp/\.o/')
CLIENT_OBJ=$(shell ls $(WINDOW)|grep -E '\.cpp'|sed 's/\.cpp/\.o/')

.PHONY:all
all:$(SERVER_BIN) $(CLIENT_BIN)

$(SERVER_BIN):$(SERVER_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
	echo "linking [$^] to [$@] ... done"
$(CLIENT_BIN):$(CLIENT_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
	echo "linking [$^] to [$@] ... done"

%.o:$(SERVER)/%.cpp
	$(CC) -c $< $(INCLUDE)
	echo "comping [$<] to [$@] ... done"
%.o:$(POOL)/%.cpp
	$(CC) -c $< $(INCLUDE)
	echo "comping [$<] to [$@] ... done"
%.o:$(LOG)/%.cpp
	$(CC) -c $< $(INCLUDE)
	echo "comping [$<] to [$@] ... done"
%.o:$(CLIENT)/%.cpp
	$(CC) -c $< $(INCLUDE)
	echo "comping [$<] to [$@] ... done"
%.o:$(COMM)/%.cpp
	$(CC) -c $< $(INCLUDE)
	echo "comping [$<] to [$@] ... done"
%.o:$(WINDOW)/%.cpp
	$(CC) -c $< $(INCLUDE)
	echo "comping [$<] to [$@] ... done"

.PHONY:output
output:
	mkdir -p output/server
	mkdir -p output/server/log
	mkdir -p output/client
	cp $(SERVER_BIN) output/server/
	cp $(CLIENT_BIN) output/client/
	cp $(PLUGIN)/ctl_server.sh output/server
	cp -rf $(CONF) output/server

.PHONY:debug
debug:
	echo $(SERVER_OBJ)
	echo $(CLIENT_OBJ)



