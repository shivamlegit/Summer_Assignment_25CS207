#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 50

// Define a structure for a Seat/Ticket
struct Seat {
    int seatNumber;
    int isBooked; 
    char passengerName[50];
};

int main() {
    struct Seat theater[TOTAL_SEATS];
    int choice;

    // Initialize all seats as available (0)
    for (int i = 0; i < TOTAL_SEATS; i++) {
        theater[i].seatNumber = i + 1;
        theater[i].isBooked = 0; 
        strcpy(theater[i].passengerName, ""); // Empty name initially
    }

    // Infinite loop for the menu
    while (1) {
        printf("\n--- Ticket Booking System ---\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. View Seat Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // View available seats
                printf("\n--- Available Seats ---\n");
                int availableCount = 0;
                for (int i = 0; i < TOTAL_SEATS; i++) {
                    if (theater[i].isBooked == 0) {
                        printf("%02d ", theater[i].seatNumber);
                        availableCount++;
                        // Print a new line every 10 seats for readability
                        if (availableCount % 10 == 0) {
                            printf("\n");
                        }
                    }
                }
                printf("\nTotal available seats: %d\n", availableCount);
                break;

            case 2:
                // Book a ticket
                {
                    int seatSelection;
                    printf("Enter the seat number you want to book (1-%d): ", TOTAL_SEATS);
                    scanf("%d", &seatSelection);

                    // Validate seat input
                    if (seatSelection < 1 || seatSelection > TOTAL_SEATS) {
                        printf("Invalid seat number!\n");
                    } else {
                        int index = seatSelection - 1; // Array is 0-indexed
                        
                        if (theater[index].isBooked == 1) {
                            printf("Sorry, Seat %d is already booked.\n", seatSelection);
                        } else {
                            // Clear input buffer
                            getchar(); 
                            
                            printf("Enter passenger name: ");
                            fgets(theater[index].passengerName, 50, stdin);
                            // Remove trailing newline
                            theater[index].passengerName[strcspn(theater[index].passengerName, "\n")] = 0; 
                            
                            theater[index].isBooked = 1;
                            printf("Seat %d successfully booked for %s!\n", seatSelection, theater[index].passengerName);
                        }
                    }
                }
                break;

            case 3:
                // Cancel a ticket
                {
                    int seatSelection;
                    printf("Enter the seat number to cancel booking (1-%d): ", TOTAL_SEATS);
                    scanf("%d", &seatSelection);

                    if (seatSelection < 1 || seatSelection > TOTAL_SEATS) {
                        printf("Invalid seat number!\n");
                    } else {
                        int index = seatSelection - 1;
                        
                        if (theater[index].isBooked == 0) {
                            printf("Seat %d is not currently booked.\n", seatSelection);
                        } else {
                            // Reset the seat
                            theater[index].isBooked = 0;
                            strcpy(theater[index].passengerName, "");
                            printf("Booking for Seat %d has been successfully canceled.\n", seatSelection);
                        }
                    }
                }
                break;

            case 4:
                // View specific seat details
                {
                    int seatSelection;
                    printf("Enter seat number to check (1-%d): ", TOTAL_SEATS);
                    scanf("%d", &seatSelection);

                    if (seatSelection < 1 || seatSelection > TOTAL_SEATS) {
                        printf("Invalid seat number!\n");
                    } else {
                        int index = seat