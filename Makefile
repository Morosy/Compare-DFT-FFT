CC := gcc
CFLAGS := -lm
PYTHON := python
SCRIPT := output_random_signal.py

all: setup run

DFT: DFT.c
	$(CC) $< -o $@.exe $(CFLAGS)

FFT: FFT.c
	$(CC) $< -o $@.exe $(CFLAGS)

setup:
	mkdir -p input output

run:
	$(PYTHON) -u $(SCRIPT); \
	make DFT
	make FFT
	./DFT.exe \
	./FFT.exe \

clean:
	$(RM) DFT.exe FFT.exe
