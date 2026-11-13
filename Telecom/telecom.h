#ifndef TELECOM_H
#define TELECOM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define MAX_LOGS 2000
#define MAX_ID_LEN 20
#define CALL_RATE 0.05
#define DATA_RATE 0.10
#define TAX_RATE 1.13

/* Struct Definition */
typedef struct {
    char userID[MAX_ID_LEN];
    int duration;        // In seconds
    float dataUsage;     // In Megabytes
    int towerID;         // Integer identifier
    int successCode;     // 1 for Success, 0 for Dropped
} LogEntry;

/* Function Prototypes & Design Recipes */

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
int loadLogs(char *filename, LogEntry logs[]);

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
int saveReport(char *filename, LogEntry logs[], int count, int filterCode);

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
int getCongestedTowerCount(LogEntry logs[], int count, int threshold);

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
double getHighestBilledUser(LogEntry logs[], int count, char *resultUID);

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
int countUserLogs(LogEntry logs[], int count, char *targetUID);

#endif
