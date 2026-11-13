/**
 * [search.c]
 * Function: countUserLogs
 * Purpose: Finds how many log entries exist for a specific user.
 * Parameters:
 *   - logs (LogEntry[]): The array of log entries.
 *   - count (int): The total number of entries in the logs array.
 *   - targetUID (char *): The user ID to search for.
 * Example: int found = countUserLogs(logs, 100, "UID-1001");
 * Effects: None.
 * Return: (int) The number of entries found for that user.
 */
  #include "telecom.h"
 
int countUserLogs(LogEntry logs[], int count, char *targetUID) {
    int entry_count = 0;
    
    for (int i = 0; i < count; i++) {
        
        if (strcmp(logs[i].userID, targetUID) == 0) {
            entry_count++;
        }
    }
    
    return entry_count;
}
