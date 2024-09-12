CC = g++
CFLAGS = -I include -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security \
	-Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor \
	-Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing \
	-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -fexceptions -pipe

LDFLAGS = -lm

SOURCES_DIR = src
OBJECTS_DIR = bin
BUILD_DIR = build

EXECUTABLE = qsort
EXECUTABLE_PATH = $(BUILD_DIR)/$(EXECUTABLE)

SOURCE_FILES = $(wildcard $(SOURCES_DIR)/*.c)
OBJECT_FILES = $(subst $(SOURCES_DIR), $(OBJECTS_DIR), $(SOURCE_FILES:.c=.o))

all: $(EXECUTABLE_PATH)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)

$(EXECUTABLE_PATH): $(OBJECT_FILES) $(BUILD_DIR)
	$(CC) $(LDFLAGS) $(OBJECT_FILES) -o $@

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(OBJECTS_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -fr $(OBJECTS_DIR) $(BUILD_DIR)
