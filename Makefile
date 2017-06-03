CXX = g++ 
# CXX = clang++
RM = rm

# ========== Directories ==========
SRCDIR := ./src
OBJDIR := .
BINDIR := .

# ============  Flags  ============
CXXFLAGS = -std=c++11  -O2


# ============ Targets ============

all:  UnitTests


%:	$(SRCDIR)/%.cpp
	$(CXX) -std=c++11 -o $(BINDIR)/$@  $^  -lpthread  -lgtest


clean:  UnitTests
	$(RM) $^

.PHONY: all


