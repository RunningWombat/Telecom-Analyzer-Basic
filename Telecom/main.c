#include "telecom.h"

int main() {
    LogEntry logs[MAX_LOGS];
    int count = 0;
    int choice = 0;
    char targetUID[MAX_ID_LEN];
    int threshold;

    // Task 1: Initial Data Load
    count = loadLogs("network_logs.csv", logs);
    if (count <= 0) {
        printf("Error: Could not load logs or file is empty.\n");
        return 1;
    }

    do {
        printf("\n--- Telecom Network Log Analyzer ---\n");
        printf("1. Generate Reports (Success/Dropped/Stats)\n");
        printf("2. Check Network Health (Congested Towers)\n");
        printf("3. Search User Activity\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                saveReport("success.csv", logs, count, 1);
                saveReport("dropped.csv", logs, count, 0);
                printf("Reports generated successfully.\n");
                break;

            case 2:
                printf("Enter congestion threshold: ");
                scanf("%d", &threshold);
                int congested = getCongestedTowerCount(logs, count, threshold);
                printf("Congested Towers: %d\n", congested);
                break;

            case 3:
                printf("Enter User ID to search: ");
                scanf("%s", targetUID);
                int userLogs = countUserLogs(logs, count, targetUID);
                printf("Found %d records for user %s.\n", userLogs, targetUID);
                break;

            case 4:
                printf("Exiting analyzer...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
