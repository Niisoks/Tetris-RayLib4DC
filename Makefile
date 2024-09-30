TARGET = Tetris-RayLib4DC.elf
OBJS = src/Tetris-RayLib4DC.o romdisk.o src/grid/grid.o src/colors/colors.o src/position/position.o src/blocks/block.o src/game/game.o src/sound/soundManager.o src/vmu/vmuManager.o
KOS_ROMDISK_DIR = romdisk

CXX = kos-c++
CC = kos-cc

all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

clean: rm-elf
	-rm -f $(OBJS)

rm-elf:
	-rm -f $(TARGET) romdisk.*

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) -lraylib -lGL -lm -lkosutils -lADX

run: $(TARGET)
	$(KOS_LOADER) $(TARGET)

dist: $(TARGET)
	-rm -f $(OBJS) romdisk.img
	$(KOS_STRIP) $(TARGET)
