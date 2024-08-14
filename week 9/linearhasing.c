#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Define a structure for the hash table entry
typedef struct {
    int key;
    int value;
} Entry;

// Define a structure for the hash table
typedef struct {
    Entry *entries[MAX_SIZE];
    int size;
} HashTable;

// Function to initialize the hash table
void initHashTable(HashTable *ht) {
    ht->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        ht->entries[i] = NULL;
    }
}

// Function to calculate hash value
int hash(int key) {
    return key % MAX_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable *ht, int key, int value) {
    int index = hash(key);
    Entry *entry = (Entry *)malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;

    // Linear probing to handle collisions
    while (ht->entries[index] != NULL) {
        index = (index + 1) % MAX_SIZE;
    }

    ht->entries[index] = entry;
    ht->size++;
}

// Function to search for a key in the hash table
int search(HashTable *ht, int key) {
    int index = hash(key);
    int count = 0;

    // Linear probing to handle collisions
    while (ht->entries[index] != NULL && count < MAX_SIZE) {
        if (ht->entries[index]->key == key) {
            return ht->entries[index]->value;
        }
        index = (index + 1) % MAX_SIZE;
        count++;
    }

    return -1; // Key not found
}

// Function to display the hash table
void display(HashTable *ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (ht->entries[i] != NULL) {
            printf("Key: %d, Value: %d\n", ht->entries[i]->key, ht->entries[i]->value);
        } else {
            printf("Slot %d is empty\n", i);
        }
    }
}

int main() {
    HashTable ht;
    initHashTable(&ht);

    int key, value, choice;

    do {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insert(&ht, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                value = search(&ht, key);
                if (value != -1) {
                    printf("Value found: %d\n", value);
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 3:
                display(&ht);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

