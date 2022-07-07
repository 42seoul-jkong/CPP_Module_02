# Any copyright is dedicated to the Public Domain.
# https://creativecommons.org/publicdomain/zero/1.0/

.SUFFIXES: .cpp .o .hpp .h .tpp
.PHONY: all clean cleanobj cleanbin re

CXX = c++
RM = rm -f

OBJECTS_DIR = objs/

ifndef TARGET
	TARGET = a.out
endif
ifndef SRCS
	SRCS = 
endif
OBJS = $(addprefix $(OBJECTS_DIR), $(SRCS:.cpp=.o))

CXX_SANITIZER_FLAGS = address undefined
CXXFLAGS += $(addprefix -fsanitize=, $(CXX_SANITIZER_FLAGS))
LDFLAGS += $(addprefix -fsanitize=, $(CXX_SANITIZER_FLAGS))

CXX_WARNING_FLAGS = all extra error
CXXFLAGS += $(addprefix -W, $(CXX_WARNING_FLAGS))

CXX_STANDARD_FLAGS = c++98
CXXFLAGS += $(addprefix -std=, $(CXX_STANDARD_FLAGS)) -pedantic

CXX_DEBUG_FLAGS = g3
CXXFLAGS += $(addprefix -, $(CXX_DEBUG_FLAGS))

all: $(TARGET)
clean: cleanobj cleanbin
cleanobj:	;	$(RM) -r $(OBJECTS_DIR)
cleanbin:	;	$(RM) $(TARGET)
re: clean	;	make all

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJS): | $(OBJECTS_DIR)

$(addprefix $(OBJECTS_DIR), %.o): %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)
