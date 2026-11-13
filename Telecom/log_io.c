/**
 * [log_io.c]
 * Function: loadLogs
 * Purpose: Reads network log data from a text file into an array of LogEntry structs.
 * Parameters:
 *   - filename (char *): The path to the input text file.
 *   - logs (LogEntry[]): The array where the parsed data will be stored.
 * Example: int count = loadLogs("network_logs.csv", logs)
 * Effects: 
 *   - Opens the file and populates the array. 
 * Return: (int) The total number of logs successfully read.
 */
#include "telecom.h"
 
int loadLogs(char *filename, LogEntry logs[]) {
    
    char buffer[256];
    int count = 0;
    
    // Open up csv file for reading
    FILE * fptr = fopen(filename, "r");
    if (fptr == NULL) {
        fclose(fptr); 
        exit(1);     
    }
    
    while(fgets(buffer, sizeof(buffer), fptr) != NULL && count < MAX_LOGS) {
        
        // Skips newline + tokenizes sections of csv lines
        buffer[strcspn(buffer, "\n")] = 0;
        char *tok;
        
        // Reformats tokenized pieces of array into proper struct format (char, int, float)
        tok = strtok(buffer, ",");
        strcpy(logs[count].userID, tok);
        
        tok = strtok(NULL, ",");
        logs[count].duration = atoi(tok);
        
        tok = strtok(NULL, ",");
        logs[count].dataUsage = atof(tok);
        
        tok = strtok(NULL, ",");
        logs[count].towerID = atoi(tok);
        
        tok = strtok(NULL, ",");
        logs[count].successCode = atoi(tok);
        
        count++;
    }

    // Close the reading and return count to main.c
    fclose(fptr);
    return count;
}

/**
 * [log_io.c]
 * Function: saveReport
 * Purpose: Generates a CSV file containing logs filtered by their success status.
 * Parameters:
 *   - filename (char *): The name of the output CSV file.
 *   - logs (LogEntry[]): The array of logs to filter.
 *   - count (int): The total number of entries in the logs array.
 *   - filterCode (int): The successCode to filter by (1 for success, 0 for dropped).
 * Example: int successCount = saveReport("success.csv", logs, 100, 1);
 * Effects: Creates/overwrites a CSV file. No terminal output.
 * Return: (int) The total number of filtered entries written to the file.
 */
int saveReport(char *filename, LogEntry logs[], int count, int filterCode) {
    
    int suc_count = 0;
    
    // Opens up success / dropped files for overwriting
    FILE * fptr = fopen(filename, "w");
        if (fptr == NULL) {
            fclose(fptr); 
            exit(1); 
        }
    // Checks each log for success code, if matching to filterCode (0 or 1), prints log details to csv file
    for (int i = 0; i < count; i++) {
        if (logs[i].successCode == filterCode) {
            
            fprintf(fptr, "%s,", logs[i].userID);
            fprintf(fptr, "%d,", logs[i].duration);
            // sets float to 1 decimal place to match network_logs style
            fprintf(fptr, "%.1f,", logs[i].dataUsage);
            fprintf(fptr, "%d,", logs[i].towerID);
            fprintf(fptr, "%d\n", logs[i].successCode);
            
            suc_count++;      
        }
    }
    
    fclose(fptr);
    // Returns success count since function is int type and needs an integer returned
    return suc_count;
}
