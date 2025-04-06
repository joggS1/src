#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <string.h>

void server(void) {
    int rcvid;         // Identifier for client response
    int chid;          // Channel identifier
    char message[512]; // Message buffer
    char response[512]; // Response buffer

    printf("Server started.\n");

    chid = ChannelCreate(0); // Create a channel
    if (chid == -1) {
        perror("Failed to create channel");
    }
    int j = 0; // Initialize variable j
    response[j] = '\0'; // Ensure null-termination
    
    printf("Channel ID: %d\n", chid);
    printf("PID: %d\n", getpid());

    while (1) {
        // Receive and print message
        rcvid = MsgReceive(chid, message, sizeof(message), NULL);
        if (rcvid == -1) {
            perror("Failed to receive message");
            continue;
        }
        printf("Message received, rcvid: %X\n", rcvid);
        printf("Message: \"%s\"\n", message);

        // Process message to remove consonants (Latin alphabet)
        j = 0;
        for (int i = 0; message[i] != '\0'; i++) {
            char c = message[i];
            if (strchr("AEIOUaeiou", c) || !((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                response[j++] = c;
            }
        }
        response[j] = '\0'; // Null-terminate the response

        // Send response
        if (MsgReply(rcvid, EOK, response, strlen(response) + 1) == -1) {
            perror("Failed to send response");
        } else {
            printf("Response sent: \"%s\"\n", response);
        }
    }

    ChannelDestroy(chid); // Clean up resources
}

int main(void) {
    printf("Server program\n");
    server();
    return 1;
}
