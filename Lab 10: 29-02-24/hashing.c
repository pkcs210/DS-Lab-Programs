#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define HT_SIZE 10

typedef struct {
    int key;
    char name[50];
} EmployeeRecord;

typedef struct {
    int key;
    int address;
} HashTableEntry;

HashTableEntry hashTable[HT_SIZE];

int hashFunction(int key) {
    return key % HT_SIZE;
}

void initializeHashTable() {
    for (int i = 0; i < HT_SIZE; i++) {
        hashTable[i].key = -1;
        hashTable[i].address = -1;
    }
}

void insertRecord(EmployeeRecord record) {
    int hashIndex = hashFunction(record.key);

    while (hashTable[hashIndex].key != -1) {
        hashIndex = (hashIndex + 1) % HT_SIZE;
    }

    hashTable[hashIndex].key = record.key;
    hashTable[hashIndex].address = hashIndex;
}

int searchRecord(int key) {
    int hashIndex = hashFunction(key);

    while (hashTable[hashIndex].key != key && hashTable[hashIndex].key != -1) {
        hashIndex = (hashIndex + 1) % HT_SIZE;
    }

    if (hashTable[hashIndex].key == key) {
        return hashIndex;
    } else {
        return -1;
    }
}

void displayRecord(int index) {
    if (index != -1) {
        printf("Employee Record Found:\n");
        printf("Key: %d\n", hashTable[index].key);
        printf("Address: %d\n", hashTable[index].address);
    } else {
        printf("Employee Record Not Found.\n");
    }
}

int main() {
    int choice, key;
    EmployeeRecord records[MAX_EMPLOYEES];
    int numRecords = 0;

    initializeHashTable();

    do {
        printf("\nEmployee Record Management System\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numRecords < MAX_EMPLOYEES) {
                    printf("Enter employee key: ");
                    scanf("%d", &records[numRecords].key);
                    printf("Enter employee name: ");
                    scanf("%s", records[numRecords].name);
                    insertRecord(records[numRecords]);
                    numRecords++;
                    printf("Record inserted successfully.\n");
                } else {
                    printf("Maximum number of records reached.\n");
                }
                break;
            case 2:
                printf("Enter employee key to search: ");
                scanf("%d", &key);
                int index = searchRecord(key);
                displayRecord(index);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
