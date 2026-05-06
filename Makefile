CXX = g++
CXXFLAGS = -std=c++20

.PHONY: run clean help
run:
	@if [ -z "$(p)" ]; then echo "Usage: make run p=n [args=\"...\"]"; exit 1; fi
	@$(CXX) $(CXXFLAGS) -DSOLUTION_HEADER="\"p$(p)/Solution.hpp\"" main.cpp -o solution
	@./solution ${args}

clean:
	@rm -rf solution

help:
	@echo "Commands: (make + command)"
	@echo " - run p=n [args=\"x y z\"]"
	@echo " - clean"
	@echo " - help"

