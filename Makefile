CXX = g++
CXXFLAGS = -std=c++20
p ?=
args ?=

.PHONY: run help averages
run:
	@if [ -z "$(p)" ]; then echo "Usage: make run p=n [args=\"...\"]"; exit 1; fi
	@$(CXX) $(CXXFLAGS) -DSOLUTION_HEADER="\"Problems/p$(p)/Solution.hpp\"" main.cpp -o output
	@./output $(args)
	@rm output

help:
	@echo "Commands: (make + command)"
	@echo " - run p=n [args=\"x y z\"]"
	@echo " - clean"
	@echo " - help"

averages:
	@$(CXX) $(CXXFLAGS) get_averages.cpp -o get_averages
	@./get_averages $(p)
	@rm get_averages
	@echo "Averages stored in averages.csv"