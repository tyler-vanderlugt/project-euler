PROBLEM_COUNT := $(shell find Problems -maxdepth 1 -type d -name "p*" | wc -l)
p ?=
args ?=

CXX = g++

CXXFLAGS = -std=c++20
override CXXFLAGS += -DPROBLEM_COUNT=$(PROBLEM_COUNT)

.PHONY: run help averages new
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

new:
	@$(CXX) $(CXXFLAGS)  make_new.cpp -o make_new
	@./make_new
	@rm make_new