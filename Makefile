CXX = g++
CXXFLAGS = -I/usr/include/eigen3

# cpp 파일들을 찾아서 실행 파일 이름 생성 (.cpp 확장자 제거)
SRCS = $(wildcard *.cpp)
TARGETS = $(SRCS:.cpp=)
BINDIR = bin

# 기본 타겟: 모든 실행 파일 생성
all: $(BINDIR) $(addprefix $(BINDIR)/, $(TARGETS))

# 각 cpp 파일을 독립적인 실행 파일로 컴파일
$(BINDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 청소
clean:
	rm -f $(BINDIR)

.PHONY: all clean
