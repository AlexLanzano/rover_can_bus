#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

int main(int argc, char **argv)
{
    int socket_fd, error;
    struct ifreq socket_config;
    struct sockaddr_can socket_address;
    struct can_frame frame;

    // Create CAN bus socket file descriptor
    socket_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (socket_fd < 0) {
        perror("Failed to create CAN socket");
        return socket_fd;
    }

    // Set interface name and get the interface index
    strncpy(socket_config.ifr_name, "can0", IFNAMSIZ);
    ioctl(socket_fd, SIOCGIFINDEX, &socket_config);

    // Set the socket address configuration
    memset(&socket_address, 0, sizeof(struct sockaddr_can));
	socket_address.can_family = AF_CAN;
	socket_address.can_ifindex = socket_config.ifr_ifindex;

    // Bind the socket to our CAN interface
    error = bind(socket_fd, (struct sockaddr *)&socket_address, sizeof(struct sockaddr_can));
    if (error) {
        perror("Failed to bind socket to address");
        return error;
    }

    // Set the frame id, data length, and initial byte in the data buffer
    frame.can_id = 0;
    frame.can_dlc = 1;
    frame.data[0] = 0;

    for (uint32_t i = 0; i < 10; i++) {

        // Send the frame over the CAN bus
        error = write(socket_fd, &frame, sizeof(struct can_frame));
        if (error < 0) {
            perror("Failed to send CAN frame");
        }

        // Toggle the byte between 1 and 0 in the data buffer, telling the teensy to turn on/off the LED
        frame.data[0] ^= 1;

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}
