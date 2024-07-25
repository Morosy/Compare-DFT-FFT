CC := gcc
CFLAGS := -lm
PYTHON := python
SCRIPT := output_random_square.py
START := 10
END := 20

all: run

FFT_time: FFT_time.c
	$(CC) -o $@ $< $(CFLAGS)

run:
	for number in $$(seq $(START) $(END)); do \
		$(PYTHON) -u $(SCRIPT) $$number; \
	done
	rm -f input/FFT_time.csv; \
	make FFT_time
	for number in $$(seq $(START) $(END)); do \
		./FFT_time input/signal-$$number.csv; \
	done

clean:
	$(RM) FFT_time
