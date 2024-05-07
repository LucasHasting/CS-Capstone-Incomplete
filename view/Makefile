CXX = g++
CXXFLAGS = -std=c++14 -Wall -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lwt -lwthttp -Wl,-rpath,/usr/local/lib

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = risk_tracker
PID_FILE = $(TARGET).pid

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

stop:
	@echo "Stopping $(TARGET)..."
	@if [ -f $(PID_FILE) ]; then \
		kill `cat $(PID_FILE)`; \
		rm -f $(PID_FILE); \
		echo "$(TARGET) stopped."; \
	else \
		echo "$(TARGET) is not running."; \
	fi

start:
	@echo "Starting $(TARGET)..."
	./$(TARGET) & echo $$! > $(PID_FILE)
	@echo "$(TARGET) started."
