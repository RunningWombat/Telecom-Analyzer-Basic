/**
 * [analytics.c]
 * Function: getCongestedTowerCount
 * Purpose: Counts how many towers have dropped calls exceeding a specific threshold.
 * Parameters:
 *   - logs (LogEntry[]): The array of log entries.
 *   - count (int): The total number of entries in the logs array.
 *   - threshold (int): The limit for failed calls.
 * Example: int count = getCongestedTowerCount(logs, 100, 5);
 * Effects: None. 
 * Return: (int) The number of unique towers exceeding the threshold.
 */
 #include "telecom.h"
 
int getCongestedTowerCount(LogEntry logs[], int count, int threshold) {
    
    int con_count = 0;
    // drp_count array tracks number of dropped calls for each tower
    int drp_count[MAX_LOGS] = {0};
    
    // Counts number of dropped calls for each tower ID
    for (int i = 0; i < count; i++) {
        if (logs[i].successCode == 0) {
            drp_count[logs[i].towerID]++;
        }
    }
    
    // Checks if each tower ID's number of drops exceeds threshold amount
    for (int j = 0; j < MAX_LOGS; j++) {
        if (drp_count[j] > threshold) {
            con_count++;
        }
    }
    
    // Return number of tower ID's which exceeded threshold        
    return con_count;
}
