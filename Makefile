TARGET = so-tetris

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
BIN_DIR = bin

# Arquivos de origem, objetos e cabeçalhos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
HEADERS = $(wildcard $(INCLUDE_DIR)/*.hpp)

# Bibliotecas da SFML (flags de linkagem)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Regra padrão
all: $(BIN_DIR)/$(TARGET)

# Regra para o executável
$(BIN_DIR)/$(TARGET): $(OBJECTS) main.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@ $(SFML_LIBS)

# Regra para os objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar os arquivos gerados
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

run:
	./$(BIN_DIR)/$(TARGET)

.PHONY: all clean
