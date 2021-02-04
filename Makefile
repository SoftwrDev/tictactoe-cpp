.PHONY: build
build: clean
	@mkdir -p build && \
	 cd build && \
	 cmake .. && \
	 make && \
	 cd .. && \
	 mkdir -p bin && \
	 cp build/tictactoe bin && \
	rm -r build

.PHONY: clean
clean:
	@rm -rf build || true && \
	 rm -rf bin || true && \
	 rm -rf tests/build || true 

.PHONY: test
test: clean
	@cd tests && \
	 mkdir -p build && \
	 cd build && \
	 cmake .. > /dev/null && \
	 make > /dev/null && \
	 ./test && \
	 cd .. && \
	 rm -r build