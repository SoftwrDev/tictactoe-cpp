MAIN_FILE=main
OUTPUT_FILE=bin/tictactoe

INC_TICTACTOE=tictactoe

.PHONY: prepare
prepare:
	@mkdir -p includes && \
	 mkdir -p src && \
	 mkdir -p bin

.PHONY: tictactoe.o
tictactoe.o:
	@g++ -I includes -c src/tictactoe.cpp

.PHONY: build
build: clear_old_build prepare tictactoe.o 
	@g++ -I includes $(INC_TICTACTOE).o $(MAIN_FILE).cpp -o  $(OUTPUT_FILE) && \
	make clear

.PHONY: clear
clear:
	@rm -f *.o || true && \
	 rm -f *out || true

.PHONY: clear_old_build
clear_old_build:
	@rm -fr bin || true

.PHONY: debug
debug:
	@g++ -I includes -g src/$(INC_TICTACTOE).cpp $(MAIN_FILE).cpp