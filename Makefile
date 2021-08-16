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
	echo "dtoverlay=mcp2515-can0,oscillator=${OSC_FREQ},interrupt=${INT_PIN}" | sudo tee -a /boot/config.txt

enable_can_interface:
	sudo /sbin/ip link set can0 up type can bitrate $(BAUD_RATE)
