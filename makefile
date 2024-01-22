# INSTRUCTIONS:
# 'mingw32-make'                build executable file 'Program.exe'
# 'mingw32-make build-and-run'  build and run executable file
# 'mingw32-make run'            run executable file
# 'mingw32-make .bin/Main.o'    build object file 'Main.o' into .bin folder
# 'mingw32-make rebuild'        clean and subsequently compile all
# 'mingw32-make clean'          removes every objects and executable files

#====================================================#
#                  EDITABLE OPTIONS                  #
#====================================================#
# Compiler
CXX          := g++
DEBUG        := -g
COMPILER_VER := --std=c++20

TARGET	     := program.exe
BIN_DIR	     := bin

HEADER_DIR   := shape2d/include
SOURCE_DIR   := shape2d/library

#====================================================#
#     YOU CAN EDIT IF YOU KNOW WHAT YOU'RE DOING     #
#====================================================#
# Flags
CXXFLAGS     := -c -Wall $(DEBUG) -I./$(HEADER_DIR) $(COMPILER_VER)
LDFLAGS      :=

HEADERS	     := $(wildcard $(HEADER_DIR)/*.hpp)
SOURCES	     := $(wildcard $(SOURCE_DIR)/*.cpp) $(BIN_DIR)/main.cpp

#====================================================#
#        DO NOT ALLOW EDITING BELOW THIS LINE        #
#====================================================#
.PHONY: build build-and-run rebuild run clean remove-dir

#===< VARIABLES >=========#
EXECUTABLE   := $(BIN_DIR)/$(TARGET)
OBJECTS      := $(SOURCES:%.cpp=%.o)                                # Replace *.cpp into *.o file
OBJECTS_PATH := $(patsubst $(SOURCE_DIR)/%,$(BIN_DIR)/%,$(OBJECTS)) # Appprefix .bin to *.o file into .bin/*.o

#===< LINKER >============#
build:			$(EXECUTABLE)
$(EXECUTABLE):	$(OBJECTS_PATH)
	@$(CXX) $(LDFLAGS) -o $(EXECUTABLE) $(OBJECTS_PATH)
	@echo Linked file - $(subst /,\,$(CURDIR)/$(EXECUTABLE))
	@echo Build successful!!!

#===< COMPILER >==========#
$(BIN_DIR)/%.o:	$(SOURCE_DIR)/%.cpp	$(HEADERS)	| $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ $<
	@echo Compiled file - $(subst /,\,$(CURDIR)/$@)

$(BIN_DIR)/main.o:	main.cpp		$(HEADERS)	| $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ $<
	@echo Compiled file - $(subst /,\,$(CURDIR)/$@)

#===< MISCELLANEOUS >=====#
$(BIN_DIR):
	@mkdir $(BIN_DIR)
	@echo Created directory - $(subst /,\,$(CURDIR)/$(BIN_DIR))

rebuild:		clean	build
build-and-run:	build	run
run:
	@$(EXECUTABLE)

clean:
	@del /s							\
		$(subst /,\,$(EXECUTABLE))	\
		$(subst /,\,$(OBJECTS_PATH))
	@echo Clean done

remove-dir:
	@rmdir /s /q $(BIN_DIR)
	@echo Removed directory - $(subst /,\,$(CURDIR)/$(BIN_DIR))
