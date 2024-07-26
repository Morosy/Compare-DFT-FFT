CC := gcc
CFLAGS := -lm
PYTHON := python
SCRIPT := output_random_square.py
START := 4
END := 18

all: setup run

DFT_time: DFT_time.c
	$(CC) $< -o $@ $(CFLAGS)

setup:
	mkdir -p input output
	touch output/DFT_time.csv

run:
	for number in $$(seq $(START) $(END)); do \
		$(PYTHON) -u $(SCRIPT) $$number; \
	done
	rm -f output/DFT_time.csv; \
	make DFT_time; \
	for number in $$(seq $(START) $(END)); do \
		./DFT_time input/signal-$$number.csv; \
	done

clean:
	$(RM) DFT_time
