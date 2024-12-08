
//============================== ABU ZAFOR - 1331 =================

//============================== AHAD HOSSAIN -1406  =================

//============================== ABDUL AZIZ - 1210 =================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define RESET "\033[0m"    // Reset to default color
#define RED "\033[31m"     // Red
#define GREEN "\033[32m"   // Green
#define YELLOW "\033[33m"  // Yellow
#define BLUE "\033[34m"    // Blue
#define CYAN "\033[36m"    // Cyan
#define MAGENTA "\033[35m" // Magenta
#define WHITE "\033[37m"   // White

// Constants
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define MAX_SEATS 24
#define MAX_ROUTES 10
#define MAX_BUSES 10

// File Names
#define USER_FILE "users.txt"
#define ADMIN_FILE "admin.txt"

// Data Structures
typedef struct
{
    int route_id;
    char route_name[100];
} Route;

typedef struct
{
    int bus_id;
    char name[50];
    int seats[MAX_ROUTES][MAX_SEATS]; // Seat status for all routes
} Bus;

// Global Variables
Route routes[MAX_ROUTES] = {
    {1, "Dhaka to Rajshahi"},
    {2, "Dhaka to Chittagong"},
    {3, "Rajshahi to Dhaka"},
    {4, "Chittagong to Dhaka"}};
int total_routes = 4;

Bus buses[MAX_BUSES];
int total_buses = 0;

// Function Prototypes
// Part of Abdul Ahad
void mainMenu();
void adminMenu();
void userMenu();
void registerUser();
int loginUser();
int loginAdmin();
void viewRegisteredUsers();
void deleteUserAccount();
void initializeBuses();

// Part of Abu Zafor


void displayRoutes();
void displaySeats(Bus *selectedBus, int route_id);
void selectBusAndSeat();
void selectSeat(Bus *selectedBus, int route_id, const char *date);
void cancelReservation();
void adminCancelReservation();
void saveSeatStatus();
void loadSeatStatus();
void viewUserHistoryByPhoneNumber(const char *phone_number);


// Part of Abdul Aziz
void viewUserDetails();
void addRoute();
void removeRoute();
void addBus();
void removeBus();
void processPayment(int total_price, int *seats, int seat_count, int route_id, const char *name, const char *customer_name, const char *phone_number, const char *date);
int isValidDate(const char *date);
void displayCancellationPolicy();

// Main Function
int main()
{
    initializeBuses();
    mainMenu();
    return 0;
}

// Main Menu
void mainMenu()
{
    int choice;
    system("cls");

    do
    {

        printf("\n===============================================\n");
        printf("          BUS TICKET RESERVATION SYSTEM         \n");
        printf("            [Loiben Nki Solution LTD ]             \n");
        printf("===============================================\n");
        printf("Please choose an option:\n");
        printf("  1. Register as User\n");
        printf("  2. Login as User\n");
        printf("  3. Login as Admin\n");
        printf("  4. View Available Routes\n");
        printf("  5. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            registerUser();
            break;
        case 2:
            system("cls");
            if (loginUser())
            {
                system("cls");
                printf("Login Successfull");
                userMenu();
            }
            else
            {
                printf("Invalid credentials! Try again.\n");
                            getchar();
                     printf("Press enter to continue...");
                     getchar();
                     system("cls");
            }
            break;
        case 3:
            system("cls");
            if (loginAdmin())
            {
                system("cls");
                adminMenu();
            }
            else
            {
                printf("Invalid admin credentials! Try again.\n");
                getchar();
                    printf("Press enter to continue...");
                    getchar();
                system("cls");
            }
            break;
        case 4:
            system("cls");
            displayRoutes();
            break;
        case 5:
            system("cls");
            printf("Thank you for using the system. Goodbye!\n");
            break;
        default:
            system("cls");
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

// Admin Menu
void adminMenu()
{
    int choice;
    do
    {
        printf("\n=== Admin Menu ===\n");
        printf("1. View Registered Users\n");
        printf("2. Delete User Account\n");
        printf("3. Add New Bus\n");
        printf("4. Remove Bus\n"); 
        printf("5. Add New Route\n");
        printf("6. Remove Route\n");
        printf("7. Cancel User Ticket\n");
        printf("8. View User Details\n"); 
        printf("9. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            viewRegisteredUsers();
            break;
        case 2:
            system("cls");
            deleteUserAccount();
            break;
        case 3:
            system("cls");
            addBus();
            break;
        case 4:
            system("cls");
            removeBus(); 
            break;
        case 5:
            system("cls");
            addRoute(); 
            break;
        case 6:
            system("cls");
            removeRoute();
            break;
        case 7:
            system("cls");
            adminCancelReservation();
            break;
        case 8:
             system("cls");
            char phone_number[15];
            printf("Enter User phone number to view history: ");
            scanf("%s", phone_number);
            viewUserHistoryByPhoneNumber(phone_number); // Call the new function
            break;
        case 9:
            system("cls");
            return;
        default:
            system("cls");
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
}

// User Menu
void userMenu()
{
    int choice;

    do
    {
        printf("\n=================================\n");
        printf("          === User Menu ===      \n");
        printf("=================================\n");
        printf("1. View Available Routes         \n");
        printf("2. Book a Ticket                 \n");
        printf("3. Cancel Reserved Ticket        \n");
        printf("4. View Reservation History       \n"); // New option
        printf("5. Back to Main Menu             \n");
        printf("=================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            displayRoutes();
            break;
        case 2:
            system("cls");
            selectBusAndSeat();
            break;
        case 3:
            system("cls");
            cancelReservation();
            userMenu();
            break;
        case 4:
            system("cls");
            char phone_number[15];
            printf("Enter your phone number to view history: ");
            scanf("%s", phone_number);
            viewUserHistoryByPhoneNumber(phone_number); // Call the new function
            break;
        case 5:
            system("cls");
            return;
        default:
            system("cls");
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
}


// Register User
void registerUser ()
{
    char username[MAX_USERNAME], password[MAX_PASSWORD];
    FILE *file = fopen(USER_FILE, "a+"); 
    if (!file)
    {
        printf("Error opening user file.\n");
        return;
    }

    char file_username[MAX_USERNAME], file_password[MAX_PASSWORD];

    // Input new user details
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    while (fscanf(file, "%s %s", file_username, file_password) != EOF)
    {
        if (strcmp(username, file_username) == 0)
        {
            printf("Username already exists! Please choose a different username.\n");
            fclose(file);
            getchar();
            printf("Press enter to continue...");
            getchar();
            system("cls");
            return;
        }
    }

    // Write new user details to file
    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("Registration successful!\n");
}

// Login User
int loginUser ()
{
    char username[MAX_USERNAME], password[MAX_PASSWORD];
    char file_username[MAX_USERNAME], file_password[MAX_PASSWORD];
    FILE *file = fopen(USER_FILE, "r");
    if (!file)
    {
        printf("Error opening user file.\n");
        return 0;
    }

    // Input user credentials
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    while (fscanf(file, "%s %s", file_username, file_password) != EOF)
    {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0)
        {
            fclose(file);
            return 1; // Login successful
        }
    }

    fclose(file);
    return 0; // Login failed
}

// Login Admin
int loginAdmin()
{
    char username[MAX_USERNAME], password[MAX_PASSWORD];
    char file_username[MAX_USERNAME], file_password[MAX_PASSWORD];
    FILE *file = fopen(ADMIN_FILE, "r");
    if (!file)
    {
        printf("Error opening admin file.\n");
        return 0;
    }

    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    while (fscanf(file, "%s %s", file_username, file_password) != EOF)
    {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

// View Registered Users
void viewRegisteredUsers()
{
    char username[MAX_USERNAME], password[MAX_PASSWORD], email[100];
    FILE *file = fopen(USER_FILE, "r");
    if (!file)
    {
        printf("Error opening user file.\n");
        return;
    }

    printf("\n=== Registered Users ===\n");
    printf("%-20s %-20s %-30s\n", "Username", "Password", "Email");
    printf("-------------------------------------------------------------\n");
    
    while (fscanf(file, "%s %s %s", username, password, email) != EOF)
    {
        printf("%-20s %-20s %-30s\n", username, password, email);
    }
    fclose(file);

    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

// Delete User Account
void deleteUserAccount()
{
    char username[MAX_USERNAME], password[MAX_PASSWORD], email[100];
    char target_username[MAX_USERNAME];
    FILE *file = fopen(USER_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp)
    {
        printf("Error processing user file.\n");
        return;
    }

    printf("Enter username to delete: ");
    scanf("%s", target_username);

    // Check if the user exists
    int found = 0;
    while (fscanf(file, "%s %s %s", username, password, email) != EOF)
    {
        if (strcmp(username, target_username) == 0)
        {
            found = 1; // User found
            printf("User  '%s' found with email '%s'. Please confirm deletion (yes/no): ", target_username, email);
            char confirmation[4];
            scanf("%s", confirmation);
            if (strcmp(confirmation, "yes") == 0)
            {
                printf("Deleting user '%s'...\n", target_username);
                continue; // Skip writing this user to the temp file
            }
            else
            {
                printf("Deletion of user '%s' cancelled.\n", target_username);
            }
        }
        else
        {
            fprintf(temp, "%s %s %s\n", username, password, email); // Write other users to temp file
        }
    }

    fclose(file);
    fclose(temp);

    // Replace the original user file with the temp file
    remove(USER_FILE);
    rename("temp.txt", USER_FILE);

    if (found)
    {
        printf("User  '%s' deleted successfully.\n", target_username);
    }
    else
    {
        printf("User  '%s' not found.\n", target_username);
    }

    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}





// Function to display routes with an improved interface
void displayRoutes()
{
    printf(CYAN "\n===============================================\n" RESET);
    printf(YELLOW "              AVAILABLE ROUTES                 \n" RESET);
    printf(CYAN "===============================================\n" RESET);

    // Check if routes are available
    if (total_routes == 0)
    {
        printf(RED "\nNo routes available at the moment.\n" RESET);
        printf(CYAN "===============================================\n" RESET);
        return;
    }

    printf(MAGENTA "%-5s %-30s\n" RESET, "ID", "ROUTE NAME");
    printf(CYAN "-----------------------------------------------\n" RESET);

    // Display each route
    for (int i = 0; i < total_routes; i++)
    {
        printf(GREEN "%-5d " RESET BLUE "%-30s\n" RESET, routes[i].route_id, routes[i].route_name);
    }

    printf(CYAN "===============================================\n" RESET);
}

// Select Bus and Seat
void selectBusAndSeat()
{
    int route_choice, bus_choice;
    char date[11]; // Format: DD/MM/YYYY

    displayRoutes();
    printf("Select a route by entering its ID: ");
    scanf("%d", &route_choice);
    system("cls");

    if (route_choice < 1 || route_choice > total_routes)
    {
        system("cls");
        printf(RED "Invalid route selection.\n" RESET);
        return;
    }

    // Date selection with validation
    while (1)
    {
        printf("Enter the date of travel (DD/MM/YYYY): ");
        scanf("%s", date);

        if (isValidDate(date))
        {
            break; // Date is valid
        }
        else
        {
            printf(RED "Invalid date format! Please use DD/MM/YYYY.\n" RESET);
        }
    }
    system("cls");

    printf(CYAN "\n===============================================\n" RESET);
    printf(YELLOW "               AVAILABLE BUSES                 \n" RESET);
    printf(CYAN "===============================================\n" RESET);

    printf(MAGENTA "%-5s %-30s\n" RESET, "ID", "BUS NAME");
    printf(CYAN "-----------------------------------------------\n" RESET);

    for (int i = 0; i < total_buses; i++)
    {
        printf(GREEN "%-5d " RESET BLUE "%-30s\n" RESET, i + 1, buses[i].name);
    }

    printf("Select a bus by entering its ID: ");
    scanf("%d", &bus_choice);
    system("cls");

    if (bus_choice < 1 || bus_choice > total_buses)
    {
        system("cls");
        printf(RED "Invalid bus selection.\n" RESET);
        return;
    }

    selectSeat(&buses[bus_choice - 1], route_choice, date);
}

// Display Seats
void displaySeats(Bus *selectedBus, int route_id)
{
    printf("\n=====================================================\n");
    printf("  Seats for Bus: " YELLOW "'%s' " RESET "on Route: " CYAN "'%s'\n" RESET,
           selectedBus->name, routes[route_id - 1].route_name);
    printf("=====================================================\n");
    printf("  " RED "RESERVED: X   " GREEN "AVAILABLE: O\n" RESET);
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < MAX_SEATS; i += 2)
    {
        // Print two seats per row
        if (i + 1 < MAX_SEATS)
        {
            printf("  Seat %2d [%s]    Seat %2d [%s]\n",
                   i + 1, selectedBus->seats[route_id - 1][i] ? RED "X" RESET : GREEN "O" RESET,
                   i + 2, selectedBus->seats[route_id - 1][i + 1] ? RED "X" RESET : GREEN "O" RESET);
        }
        else
        {
            // Print the last seat if it’s a single
            printf("  Seat %2d [%s]\n",
                   i + 1, selectedBus->seats[route_id - 1][i] ? RED "X" RESET : GREEN "O" RESET);
        }
    }
    printf("=====================================================\n\n");
}

// Initialize Buses
void initializeBuses() {
    // Predefined buses
    strcpy(buses[0].name, "Hanif Enterprise");
    strcpy(buses[1].name, "National Travels");
    strcpy(buses[2].name, "Desh Travels");
    strcpy(buses[3].name, "Grameen Travels");
    total_buses = 4;

    // Initialize seat availability
    for (int i = 0; i < total_buses; i++) {
        buses[i].bus_id = i + 1;
        memset(buses[i].seats, 0, sizeof(buses[i].seats)); // Initialize seats to 0 (available)
    }

    // Load seat status from file
    loadSeatStatus();
}


// Seat Reservation
void selectSeat(Bus *selectedBus, int route_id, const char *date)
{
    int seats[4], seat_count = 0, price;
    char customer_name[100];
    char phone_number[15];

    if (route_id == 1 || route_id == 3)
        price = 570;
    else
        price = 800;

    // Collect Passenger details
    while (1)
    {
        printf("Enter your name: ");
        getchar(); // Clear the newline from the input buffer
        fgets(customer_name, sizeof(customer_name), stdin);
        customer_name[strcspn(customer_name, "\n")] = '\0';

        // Validate customer name (only alphabetic characters)
        int valid_name = 1;
        for (int i = 0; customer_name[i] != '\0'; i++)
        {
            if (!isalpha(customer_name[i]) && customer_name[i] != ' ')
            {
                valid_name = 0;
                break;
            }
        }
        if (valid_name)
        {
            break; // Name is valid
        }
        else
        {
            printf(RED "Invalid name! Please use only alphabetic characters.\n" RESET);
        }
    }

    while (1)
    {
        printf("Enter your phone number (11 digits): ");
        scanf("%s", phone_number);

        // Validate phone number (must be 11 digits)
        if (strlen(phone_number) == 11)
        {
            int valid_phone = 1;
            for (int i = 0; i < 11; i++)
            {
                if (!isdigit(phone_number[i]))
                {
                    valid_phone = 0;
                    break;
                }
            }
            if (valid_phone)
            {
                break; // Phone number is valid
            }
        }
        printf(RED "Invalid phone number! It must be exactly 11 digits.\n" RESET);
    }

    system("cls");

    // Display seats and allow seat selection
    displaySeats(selectedBus, route_id);

    while (seat_count < 4)
    {
        int seat_number;
        printf("Enter seat number to reserve (or 0 to finish): ");
        scanf("%d", &seat_number);
        system("cls");

        if (seat_number == 0)
            break;
        if (seat_number < 1 || seat_number > MAX_SEATS || selectedBus->seats[route_id - 1][seat_number - 1])
        {
            printf(RED "Invalid or already reserved seat. Try again.\n" RESET);
            continue;
        }

        selectedBus->seats[route_id - 1][seat_number - 1] = 1;
        seats[seat_count++] = seat_number;
        printf(GREEN "Seat %d reserved successfully.\n" RESET, seat_number);
         getchar();
        printf("Press enter to continue...");
        getchar();
        system("cls");

        displaySeats(selectedBus, route_id);
    }

    // Check if no seats were reserved
    if (seat_count == 0)
    {
        printf(RED "No seats were reserved. Returning to the user menu.\n" RESET);
        userMenu();
        return; // Ensure to return after calling userMenu
    }

    system("cls");
    processPayment(seat_count * price, seats, seat_count, route_id, selectedBus->name, customer_name, phone_number, date);
    saveSeatStatus();
}

// Reserve Ticket Cancellation function
void cancelReservation()
{
    int route_id, bus_id, seat_number;

    displayCancellationPolicy();

    // Display available routes
    displayRoutes();
    printf("Enter the Route ID of your reservation: ");
    scanf("%d", &route_id);

    if (route_id < 1 || route_id > total_routes)
    {
        printf("Invalid Route ID. Please try again.\n");
        return;
    }
    system("cls");

    // Display available buses
    printf("\nAvailable Buses:\n");
    for (int i = 0; i < total_buses; i++)
    {
        printf("%d. %s\n", i + 1, buses[i].name);
    }
    printf("Enter the Bus ID of your reservation: ");
    scanf("%d", &bus_id);

    if (bus_id < 1 || bus_id > total_buses)
    {
        printf("Invalid Bus ID. Please try again.\n");
        return;
    }
    system("cls");

    // Display seat status for the selected route and bus
    Bus *selectedBus = &buses[bus_id - 1];
    printf("\nSeats for Route: %s, Bus: %s\n", routes[route_id - 1].route_name, selectedBus->name);
    for (int i = 0; i < MAX_SEATS; i++)
    {
        if (i % 5 == 0)
            printf("\n");
        printf("Seat %2d: %-9s ", i + 1, selectedBus->seats[route_id - 1][i] == 0 ? "Available" : "Reserved");
    }
    printf("\n");

    // Prompt user to cancel a reserved seat
    printf("Enter the seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seat_number);

    if (seat_number < 1 || seat_number > MAX_SEATS)
    {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (selectedBus->seats[route_id - 1][seat_number - 1] == 0)
    {
        printf("Seat %d is not reserved. No action taken.\n", seat_number);
    }
    else
    {
        // Cancel the reservation
        selectedBus->seats[route_id - 1][seat_number - 1] = 0; // Mark the seat as available
        printf("Reservation for Seat %d on Route '%s' and Bus '%s' has been successfully canceled.\n",
               seat_number, routes[route_id - 1].route_name, selectedBus->name);
        
        // Save the updated seat status to the file
        saveSeatStatus();
    }

    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

void adminCancelReservation()
{
    int bus_choice, route_choice, seat_number;

    // Display available buses
    if (total_buses == 0)
    {
        printf("No buses available to modify reservations.\n");
        return;
    }

    printf("\n=== Cancel Reservation (Admin) ===\n");
    printf("\nAvailable Buses:\n");
    for (int i = 0; i < total_buses; i++)
    {
        printf("%d. %s\n", i + 1, buses[i].name);
    }

    printf("\nSelect a bus by entering its number: ");
    scanf("%d", &bus_choice);

    // Validate bus choice
    if (bus_choice < 1 || bus_choice > total_buses)
    {
        printf("Invalid bus selection.\n");
        return;
    }
    system("cls");

    // Display available routes
    printf("\nAvailable Routes:\n");
    for (int i = 0; i < total_routes; i++)
    {
        printf("%d. %s\n", i + 1, routes[i].route_name);
    }

    printf("\nSelect a route by entering its number: ");
    scanf("%d", &route_choice);

    // Validate route choice
    if (route_choice < 1 || route_choice > total_routes)
    {
        printf("Invalid route selection.\n");
        return;
    }
    system("cls");

    // Display seats for the selected bus and route
    printf("\nSeat status for '%s' on route '%s':\n", buses[bus_choice - 1].name, routes[route_choice - 1].route_name);
    for (int i = 0; i < MAX_SEATS; i++)
    {
        if (i % 5 == 0)
            printf("\n");
        printf("Seat %2d: %-9s ", i + 1, buses[bus_choice - 1].seats[route_choice - 1][i] == 0 ? "Available" : "Reserved");
    }

    printf("\n\nEnter the seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seat_number);

    // Validate seat number
    if (seat_number < 1 || seat_number > MAX_SEATS)
    {
        printf("Invalid seat number.\n");
        return;
    }

    // Check if the seat is already reserved
    if (buses[bus_choice - 1].seats[route_choice - 1][seat_number - 1] == 0)
    {
        printf("Seat %d is already available. No action needed.\n", seat_number);
    }
    else
    {
        // Cancel the reservation
        buses[bus_choice - 1].seats[route_choice - 1][seat_number - 1] = 0; // Mark the seat as available
        printf("Reservation for seat %d on '%s' (route '%s') has been successfully canceled.\n",
               seat_number, buses[bus_choice - 1].name, routes[route_choice - 1].route_name);
        
        // Save the updated seat status to the file
        saveSeatStatus();
    }

    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}


void saveSeatStatus() {
    FILE *file = fopen("seat_data.txt", "w");
    if (!file) {
        printf("Error opening seat data file for writing.\n");
        return;
    }

    for (int j = 0; j < total_routes; j++) { // Loop through routes
    for (int i = 0; i < total_buses; i++) { // Loop through buses
        for (int k = 0; k < MAX_SEATS; k++) { // Loop through seats
            fprintf(file, "%d %d %d %d\n", i + 1, j + 1, k + 1, buses[i].seats[j][k]);
        }
    }
}

    fclose(file);
    printf("Seat status saved successfully.\n");
}



void loadSeatStatus() {
    FILE *file = fopen("seat_data.txt", "r");
    if (!file) {
        printf("No seat data file found. Initializing with default values.\n");
        return; // If the file doesn't exist, we can just return
    }

    int bus_id, route_id, seat_number, status;
    while (fscanf(file, "%d %d %d %d", &bus_id, &route_id, &seat_number, &status) != EOF) {
        if (bus_id > 0 && bus_id <= total_buses && route_id > 0 && route_id <= total_routes && seat_number > 0 && seat_number <= MAX_SEATS) {
            buses[bus_id - 1].seats[route_id - 1][seat_number - 1] = status;
        }
    }

    fclose(file);
    printf("Seat status loaded successfully.\n");
}


void viewUserHistoryByPhoneNumber(const char *phone_number)
{
    char line[256];
    FILE *file = fopen("details.txt", "r");
    if (!file)
    {
        printf("Error opening details file.\n");
        return;
    }

    printf("\n=== Reservation History for Phone Number: %s ===\n", phone_number);
    printf("========================================\n");

    int found = 0; // Flag to check if any records are found

    // Read and display each line from the details file
    while (fgets(line, sizeof(line), file))
    {
        // Check if the line contains the phone number
        if (strstr(line, phone_number) != NULL)
        {
            found = 1; // Set flag to true if a record is found
            printf("%s", line); // Print the line containing the phone number

            // Print the next few lines to show the reservation details
            for (int i = 0; i < 7; i++) // Assuming 4 lines of details follow the phone number
            {
                if (fgets(line, sizeof(line), file) != NULL)
                {
                    printf("%s", line);
                }
            }
            printf("========================================\n");
        }
    }

    if (!found)
    {
        printf("No reservation history found for phone number: %s\n", phone_number);
    }

    fclose(file);
    printf("========================================\n");
    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

// Add New Bus
void addBus()
{
    if (total_buses >= MAX_BUSES)
    {
        printf("Maximum number of buses reached.\n");
        return;
    }

    char bus_name[100];
    printf("\n=== Add New Bus ===\n");
    printf("Enter the new bus name (with spaces if needed): ");
    getchar(); // To consume any leftover newline from previous inputs
    fgets(bus_name, sizeof(bus_name), stdin);

    // Remove the trailing newline from fgets input
    size_t len = strlen(bus_name);
    if (bus_name[len - 1] == '\n')
    {
        bus_name[len - 1] = '\0';
    }

    buses[total_buses].bus_id = total_buses + 1;
    strcpy(buses[total_buses].name, bus_name);
    memset(buses[total_buses].seats, 0, sizeof(buses[total_buses].seats)); // Initialize seats
    total_buses++;

    printf("Bus '%s' added successfully!\n", bus_name);

    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

void removeBus()
{
    if (total_buses == 0)
    {
        printf("No buses available to remove.\n");
        return;
    }

    printf("\n=== Remove Bus ===\n");
    printf("Available Buses:\n");
    for (int i = 0; i < total_buses; i++)
    {
        printf("%d. %s\n", i + 1, buses[i].name);
    }

    int bus_choice;
    printf("Enter the bus number to remove: ");
    scanf("%d", &bus_choice);

    if (bus_choice < 1 || bus_choice > total_buses)
    {
        printf("Invalid bus selection. Try again.\n");
        return;
    }

    // Shift buses to remove the selected one
    for (int i = bus_choice - 1; i < total_buses - 1; i++)
    {
        buses[i] = buses[i + 1];
    }

    total_buses--; // Decrease the total number of buses
    printf("Bus removed successfully.\n");
    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

void addRoute()
{
    if (total_routes >= MAX_ROUTES)
    {
        printf("\nMaximum number of routes reached. Cannot add more routes.\n");
        return;
    }

    char route_name[100];
    printf("\n=== Add New Route ===\n");
    printf("Enter the new route name (with spaces if needed): ");
    getchar(); // To consume any leftover newline from previous inputs
    fgets(route_name, sizeof(route_name), stdin);

    // Remove the trailing newline from fgets input
    size_t len = strlen(route_name);
    if (route_name[len - 1] == '\n')
    {
        route_name[len - 1] = '\0';
    }

    // Assign a new route ID and save the route
    routes[total_routes].route_id = total_routes + 1;
    strcpy(routes[total_routes].route_name, route_name);
    total_routes++;

    printf("Route '%s' added successfully with Route ID %d!\n", route_name, total_routes);
    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

void removeRoute()
{
    if (total_routes == 0)
    {
        printf("\nNo routes available to remove.\n");
        return;
    }

    int route_id;
    printf("\n=== Remove Route ===\n");
    printf("Available Routes:\n");
    displayRoutes(); // Displays all available routes
    printf("Enter the Route ID to remove: ");
    scanf("%d", &route_id);

    // Validate Route ID
    if (route_id < 1 || route_id > total_routes)
    {
        printf("Invalid Route ID. Please try again.\n");
        return;
    }

    // Remove the selected route and shift remaining routes
    for (int i = route_id - 1; i < total_routes - 1; i++)
    {
        routes[i] = routes[i + 1];
    }
    total_routes--; // Decrease the total number of routes

    printf("Route with ID %d removed successfully.\n", route_id);

    // Update IDs to maintain consistency
    for (int i = 0; i < total_routes; i++)
    {
        routes[i].route_id = i+1 ;
    }

    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

// Process Payment
void processPayment(int total_price, int *seats, int seat_count, int route_id, const char *bus_name, const char *customer_name, const char *phone_number, const char *date)
{
    int payment_choice;
    printf("\n" CYAN "========================================\n" RESET);
    printf("        " GREEN "Payment and Ticket Details\n" RESET);
    printf(CYAN "========================================\n" RESET);

    printf(BLUE "Passenger Name: " RESET "%s\n", customer_name);
    printf(BLUE "Phone Number : " RESET "%s\n", phone_number);
    printf(BLUE "Travel Date  : " RESET "%s\n", date); // Show the travel date
    printf(BLUE "Bus Name     : " RESET "%s\n", bus_name); // Show the bus name
    printf(BLUE "Route Name   : " RESET "%s\n", routes[route_id - 1].route_name); // Show the route name
    printf(CYAN "----------------------------------------\n" RESET);

    printf(GREEN "Total Price      : " RESET "%d Taka\n", total_price);
    printf(BLUE "Seats Booked     : " RESET);

    for (int i = 0; i < seat_count; i++)
    {
        printf("%d%s", seats[i], (i < seat_count - 1) ? ", " : "");
    }

    // Select payment method
    printf("\n" CYAN "========================================\n" RESET);
    printf("Select Payment Method:\n");
    printf("1. Mobile Banking\n");
    printf("2. Bank Card\n");
    printf("Enter your choice: ");
    scanf("%d", &payment_choice);

    system("cls");

    if (payment_choice == 1)
    {
        int mobile_choice;
        printf("Select Mobile Banking Option:\n");
        printf("1. Bkash\n");
        printf("2. Nagad\n");
        printf("3. Rocket\n");
        printf("Enter your choice: ");
        scanf("%d", &mobile_choice);
        system("cls");

        switch (mobile_choice)
        {
        case 1:
            printf("You have selected Bkash for payment.\n");
            break;
        case 2:
            printf("You have selected Nagad for payment.\n");
            break;
        case 3:
            printf("You have selected Rocket for payment.\n");
            break;
        default:
            printf("Invalid choice! Payment failed.\n");
            return;
        }

        // Dummy transaction authentication
        char transaction_pin[6];
        printf("Enter your transaction PIN (4 digits): ");
        scanf("%s", transaction_pin);

        // Simulate PIN validation (for demonstration purposes, we assume "1234" is the correct PIN)
        if (strcmp(transaction_pin, "1234") != 0)
        {
            printf(RED "Invalid transaction PIN! Payment failed.\n" RESET);
            return;
        }
        printf(GREEN "Transaction PIN validated successfully!\n" RESET);
    }
    else if (payment_choice == 2)
    {
        char card_number[20];
        char expiration_date[8]; // Format: MM/YYYY
        char cvv[5];

        printf("Enter your card number: ");
        scanf("%s", card_number);

        printf("Enter expiration date (MM/YYYY): ");
        scanf("%s", expiration_date);

        printf("Enter CVV: ");
        scanf("%s", cvv);

        // Here you can add additional validation for card details if needed
        printf("You have selected Bank Card for payment.\n");
        printf("Processing payment with card number: %s\n", card_number);
        // Simulate payment processing...
    }
    else
    {
        printf("Invalid choice! Payment failed.\n");
        return;
    }

    // Assuming the payment is successful

    printf("\n" CYAN "========================================\n" RESET);
    printf("        " GREEN "Payment and Ticket Details\n" RESET);
    printf(CYAN "========================================\n" RESET);

    printf(BLUE "Passenger Name: " RESET "%s\n", customer_name);
    printf(BLUE "Phone Number : " RESET "%s\n", phone_number);
    printf(BLUE "Travel Date  : " RESET "%s\n", date); // Show the travel date
    printf(BLUE "Bus Name     : " RESET "%s\n", bus_name); // Show the bus name
    printf(BLUE "Route Name   : " RESET "%s\n", routes[route_id - 1].route_name); // Show the route name
    printf(CYAN "----------------------------------------\n" RESET);

    printf(GREEN "Total Price      : " RESET "%d Taka\n", total_price);
    printf(GREEN "Payment Status   : " RESET YELLOW "Successful\n" RESET);
    printf(CYAN "----------------------------------------\n" RESET);
    printf(BLUE "Seats Booked     : " RESET);

    for (int i = 0; i < seat_count; i++)
    {
        printf("%d%s", seats[i], (i < seat_count - 1) ? ", " : "");
    }

    printf("\n" CYAN "========================================\n" RESET);
    printf("Thank you for your payment!\n");
    printf("Have a safe journey!\n");

    FILE *file = fopen("details.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "Passenger Name: %s\n", customer_name); // Ensure username is saved
        fprintf(file, "Phone Number : %s\n", phone_number);
        fprintf(file, "Travel Date  : %s\n", date);
        fprintf(file, "Total Price      : %d Taka\n", total_price);
        fprintf(file, "Seats Booked     : ", seats);
        
        for (int i = 0; i < seat_count; i++)
        {
            fprintf(file, "%d%s", seats[i], (i < seat_count - 1) ? ", " : "");
        }
        
        fprintf(file, "\nBus Name: %s\n", bus_name);
        fprintf(file, "Route Name: %s\n", routes[route_id - 1].route_name);
        fprintf(file, "----------------------------------------\n");
        fclose(file);
    }


    else
    {
        printf("Error opening file to save details.\n");
    }

    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

int isValidDate(const char *date)
{
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3)
    {
        return 0;
    }

    if (month < 1 || month > 12)
    {
        return 0;
    }

    if (day < 1 || day > 31)
    {
        return 0;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            return 0;
        }
    }

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {

            if (day > 29)
            {
                return 0;
            }
        }
        else
        {
            if (day > 28)
            {
                return 0;
            }
        }
    }

    return 1;
}

void displayCancellationPolicy()
{
    printf("=============================================\n");
    printf("              Ticket Cancellation Policy      \n");
    printf("=============================================\n");
    printf("Dear Passenger,\n\n");
    printf("Thank you for reaching out regarding ticket cancellations.\n\n");
    printf("Please note the following:\n");
    printf("1. If you cancel your tickets at least 24 hours before the scheduled event,\n");
    printf("   you will be eligible for a refund.\n");
    printf("2. Refunds will be processed within 2 business days.\n");
    printf("3. Cancellations made within 24 hours of the event are NOT eligible for a refund.\n\n");
    printf("We appreciate your understanding.\n");
    printf("If you have further questions, feel free to contact our support team.\n\n");
    printf("Best regards,\n");
    printf("[Loiben Nki Solution LTD ]\n");
    printf("[+8801700000000]\n");
    printf("=============================================\n");

    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

// Function to view user details from details.txt
void viewUserDetails()
{
    char line[256];
    FILE *file = fopen("details.txt", "r");
    if (!file)
    {
        printf("Error opening details file.\n");
        return;
    }

    printf("\n=== User Details ===\n");
    printf("========================================\n");

    // Read and display each line from the details file
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
    printf("========================================\n");
    getchar();
    printf("Press enter to continue...");
    getchar();
    system("cls");
}

// for save

