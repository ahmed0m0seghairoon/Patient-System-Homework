// Ahmed Mohammed Seghairoon Elsheikh (2210213575)
// 2210213575@ogrenci.karabuk.edu.tr
// homework github repo https://github.com/ahmed0m0seghairoon/Patient-System-Homework

#include<stdio.h>
#include<stdlib.h>

#define MAX_PATIENTS_COUNT 5

// 1- Define a struct included patient name, age, and a set of illness information
enum Condition {stable, serious, critical};

struct Illness
{
    char name[256];
    enum Condition condition;
};

struct Patient
{
    int id;
    char name[256];
    int age;
    struct Illness illness;
};

typedef struct Patient Patient;

char* getCondition(enum Condition condition){
    switch (condition)
    {
        case stable:return "stable";
        case serious:return "serious";
        case critical:return "critical";
    }
}

void printPatient(Patient patient){
    printf("patient (%d) %s (age %d) have %s and is in %s condition\n", 
                    patient.id, patient.name, patient.age, patient.illness.name, getCondition(patient.illness.condition));
}

int main()
{
    // 2- Insert a number of patients
    Patient patients[MAX_PATIENTS_COUNT] = {
        {1,"ahmed mohammed",20,{"cold", stable}},
        {2,"peter parker",24,{"fever", stable}},
        {3,"bruce Banner",54,{"malaria", serious}},
        {4,"tony stark",51,{"covid", critical}},
        {5,"steve rogers",49,{"cancer", critical}},
    };

    // 3- Find any patient who has got some key data

    // print all the patients in critical condition
    printf("printing all patients in critical condition\n");
    for(int i = 0; i < MAX_PATIENTS_COUNT; i++){
        if (patients[i].illness.condition == critical)
            printPatient(patients[i]);
    }

    // 5- Modify a patient record.
    // print the patient with id = 2 and update his age
    printf("\nupdating the age and printing the patient where id = 2\n");
    for(int i = 0; i < MAX_PATIENTS_COUNT; i++){
        if (patients[i].id == 2){
            patients[i].age = 23;
            printPatient(patients[i]);
        }
    }

    // 4 - Delete a patient record.
    // delete patient 2 peter parker
    printf("\ndeleting patient where id = 2\n");
    for (int i = 1; i < MAX_PATIENTS_COUNT; i++) {
                patients[i] = patients[i + 1];
    }

    // 6 - List all patients info
    // print all the patients
    printf("\nprinting all the patients\n");
    for(int i = 0; i < MAX_PATIENTS_COUNT - 1; i++){
            printPatient(patients[i]);
    }

    // 7 - Store a formatted listing of all patients records in a text file
    FILE* filePtr;
    filePtr = fopen("table.txt", "wb");

    fprintf(filePtr,"| %-3s | %-15s | %-5s | %-10s | %-10s |\n",
                    "id","name", "age", "illness", "condition");

    for (int i = 0; i < MAX_PATIENTS_COUNT - 1; i++)
    {
        fprintf(filePtr,"| %-3d | %-15s | %-5d | %-10s | %-10s |\n", 
                    patients[i].id, patients[i].name, patients[i].age, patients[i].illness.name, getCondition(patients[i].illness.condition));
    }
    fclose(filePtr);
    

    return 0;
}