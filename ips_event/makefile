ifeq ($(CROSSCOMPILE),)
CC        := gcc
CXX       := g++
AR        := ar
LD        := ld
else
CC        := $(CROSSCOMPILE)-gcc
CXX       := $(CROSSCOMPILE)-g++
AR        := $(CROSSCOMPILE)-ar
LD        := $(CROSSCOMPILE)-ld
endif

PLATFORM=$(shell msg=`$(CC) -dM -E - < /dev/null`;if [ "`echo $${msg}|grep -i x86`" != "" ];then echo x86;elif [ "`echo $${msg}|grep -i arm`" != "" ];then echo arm;else echo unknow;fi )

ifeq ($(PLATFORM),unknow)
$(error PLATFORM is unknow!)
else ifeq ($(PLATFORM),x86)
	head_arch := ./include/x86
else ifeq ($(PLATFORM),arm)
	head_arch := ./include/arm
endif

obj_flag=-fPIC -c
ld_flag=-shared 
C_FLAGS ?= -Wall -g -g3 -gdwarf-2
cdir=$(notdir $(shell pwd))

head=-I ./include

ifneq ($(head_arch),)
head+= -I $(head_arch)
endif

ifneq ($(OS_HEAD_INCLUDE),)
head+= -I $(OS_HEAD_INCLUDE)
endif

ifeq ($(OS_LIB_PATH),)
lib_path=-L ./lib
else
lib_path=-L ./lib -L $(OS_LIB_PATH)
endif

ifeq ($(OS_RPATH),)
ld_rpath:=-Wl,-rpath ./lib
else
ld_rpath:=-Wl,-rpath $(OS_RPATH)
endif
ld_lib=-lpthread -lcurl $(OS_LDFLAGS)
src=$(wildcard ./src/*.c)
obj=$(patsubst %.cpp,%.o,$(patsubst %.c,%.o,$(src)))
std=gnu99
target=$(cdir)

$(target):$(obj)
	$(CC) $(C_FLAGS) $^ $(head) $(lib_path) -o $@ $(ld_lib) $(ld_rpath)

%.o:%.c
	$(CC) $(C_FLAGS) $^ $(obj_flag) $(head) $(lib_path) -o $@ $(ld_lib) -std=$(std)

%.o:%.cpp
	$(CXX) $(C_FLAGS) $^ $(obj_flag) $(head) $(lib_path) -o $@ $(ld_lib)

.PHINE:clean
clean:
	@rm ./src/*.o -rf
	@rm $(target) -rf
