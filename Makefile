RPI_BLINK_EXAMPLE_SOURCE = rpi/blink.c
RPI_BLINK_EXAMPLE_EXE = rpi/blink

# Build targets
all: $(RPI_BLINK_EXAMPLE_EXE)

$(RPI_BLINK_EXAMPLE_EXE): $(RPI_BLINK_EXAMPLE_SOURCE)
	gcc -o $(RPI_BLINK_EXAMPLE_EXE) $(RPI_BLINK_EXAMPLE_SOURCE)

clean:
	rm $(RPI_BLINK_EXAMPLE_EXE)

# Run targets
run_blink_example: $(RPI_BLINK_EXAMPLE_EXE)
	$(PWD)/$(RPI_BLINK_EXAMPLE_EXE)

# RPI CAN setup targets
setup_can:
	bash rpi_can_setup.sh
