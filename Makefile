TARGET = Tetris-RayLib4DC.elf
OBJS = Tetris-RayLib4DC.o romdisk.o ball.o  # Add ball.o to the object list
KOS_ROMDISK_DIR = romdisk

CXX = kos-c++
CC = kos-cc

all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

clean: rm-elf
	-rm -f $(OBJS)

rm-elf:
	-rm -f $(TARGET) romdisk.*

# Use 'kos-c++' for linking when working with C++ code
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) -lraylib -lGL -lm -lkosutils

run: $(TARGET)
	$(KOS_LOADER) $(TARGET)

dist: $(TARGET)
	-rm -f $(OBJS) romdisk.img
	$(KOS_STRIP) $(TARGET)
