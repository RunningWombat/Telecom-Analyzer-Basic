/**
 * [billing.c]
 * Function: getHighestBilledUser
 * Purpose: Identifies the User ID responsible for the largest total bill in the dataset.
 * Parameters:
 *   - logs (LogEntry[]): The array of log entries in the logs array.
 *   - count (int): The total number of entries.
 *   - resultUID (char *): Buffer to store the found User ID.
 * Example: double billedAmount = getHighestBilledUser(logs, 100, topUserBuffer);
 * Effects: Copies the highest billed User ID into resultUID.
 * Return: (double) The bill amount for the highest-billed user.
 */
 #include "telecom.h"
 
double getHighestBilledUser(LogEntry logs[], int count, char *resultUID) {
    
    double highest_bill = 0;
    
    for (int i = 0; i < count; i++) {
        
        // Reset total duration/data for each new userID
        int total_duration = 0;
        float total_data = 0;
        
        for (int j = 0; j < count; j++) {
            
            // Checks if log[j] is the same as log[i], 0 means they're identical
            if (strcmp(logs[i].userID, logs[j].userID) == 0) {
                
                // Increment total duration/data of user by row
                total_duration += logs[j].duration;
                total_data += logs[j].dataUsage;
            }
        }
        
        // Bill calculation using the last user's total duration and dataUsage
        double bill = TAX_RATE * ((total_duration * CALL_RATE) + (total_data *DATA_RATE));
        
        // Checks if last id's bill is the largest, if yes, set as new highest and copy current userID to resultUID
        if (bill > highest_bill) {
            highest_bill = bill;
            strcpy(resultUID, logs[i].userID);
        }
    }
    
    return highest_bill;
}
