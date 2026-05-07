CXX = g++
CXXFLAGS = -std=c++20

.PHONY: run help
run:
	@if [ -z "$(p)" ]; then echo "Usage: make run p=n [args=\"...\"]"; exit 1; fi
	@$(CXX) $(CXXFLAGS) -DSOLUTION_HEADER="\"Problems/p$(p)/Solution.hpp\"" main.cpp -o output
	@./output ${args}
	@rm output

help:
	@echo "Commands: (make + command)"
	@echo " - run p=n [args=\"x y z\"]"
	@echo " - clean"
	@echo " - help"