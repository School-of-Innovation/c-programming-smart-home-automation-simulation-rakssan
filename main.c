/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */
#include <stdio.h>

void initializeSystem(int rooms, int light[], int temp[], int motion[], int security[]);
void toggleLight(int room, int light[]);
void readTemperature(int room, int temp[]);
void detectMotion(int room, int motion[]);
void controlSecurityLock(int room, int security[]);
void analyzeHouseStatus(int rooms, int light[], int temp[], int motion[], int security[]);
void autoLock(int rooms, int motion[], int security[]);
void temperatureAlert(int rooms, int temp[]);
void energySavingMode(int rooms, int light[]);

int main() {
    int rooms;

    // Get number of rooms from the user
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);

    // Declare arrays to store device states for each room
    int light[rooms], temp[rooms], motion[rooms], security[rooms];
    
    // Initialize the system
    initializeSystem(rooms, light, temp, motion, security);

    // Menu-driven program
    int choice;
    while(1) {
        printf("\n===== Smart Home Menu =====\n");
        printf("1. Toggle Light\n");
        printf("2. Read Temperature\n");
        printf("3. Check Motion Sensor\n");
        printf("4. Lock/Unlock Security System\n");
        printf("5. House Status Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    int room;
                    printf("Enter room number to toggle light (1-%d): ", rooms);
                    scanf("%d", &room);
                    toggleLight(room - 1, light);
                    break;
                }
            case 2:
                {
                    int room;
                    printf("Enter room number to read temperature (1-%d): ", rooms);
                    scanf("%d", &room);
                    readTemperature(room - 1, temp);
                    break;
                }
            case 3:
                {
                    int room;
                    printf("Enter room number to check motion sensor (1-%d): ", rooms);
                    scanf("%d", &room);
                    detectMotion(room - 1, motion);
                    break;
                }
            case 4:
                {
                    int room;
                    printf("Enter room number to lock/unlock security system (1-%d): ", rooms);
                    scanf("%d", &room);
                    controlSecurityLock(room - 1, security);
                    break;
                }
            case 5:
                analyzeHouseStatus(rooms, light, temp, motion, security);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        // Additional features
        autoLock(rooms, motion, security);
        temperatureAlert(rooms, temp);
        energySavingMode(rooms, light);
    }

    return 0;
}

void initializeSystem(int rooms, int light[], int temp[], int motion[], int security[]) {
    // Initialize all devices to default values
    for (int i = 0; i < rooms; i++) {
        light[i] = 0;         // Light OFF
        temp[i] = 22;         // Default temperature 22°C
        motion[i] = 0;        // No motion detected
        security[i] = 1;      // Security lock is locked
    }
    printf("Initializing system...\n");
}

void toggleLight(int room, int light[]) {
    if (light[room] == 0) {
        light[room] = 1;
        printf("Light in Room %d is now ON.\n", room + 1);
    } else {
        light[room] = 0;
        printf("Light in Room %d is now OFF.\n", room + 1);
    }
}

void readTemperature(int room, int temp[]) {
    printf("Temperature in Room %d: %d°C\n", room + 1, temp[room]);
}

void detectMotion(int room, int motion[]) {
    if (motion[room] == 1) {
        printf("Motion detected in Room %d.\n", room + 1);
    } else {
        printf("No motion detected in Room %d.\n", room + 1);
    }
}

void controlSecurityLock(int room, int security[]) {
    if (security[room] == 1) {
        security[room] = 0;
        printf("Room %d security system is now UNLOCKED.\n", room + 1);
    } else {
        security[room] = 1;
        printf("Room %d security system is now LOCKED.\n", room + 1);
    }
}

void analyzeHouseStatus(int rooms, int light[], int temp[], int motion[], int security[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s Motion, %s\n",
            i + 1,
            light[i] == 1 ? "ON" : "OFF",
            temp[i],
            motion[i] == 1 ? "Motion Detected" : "No Motion",
            security[i] == 1 ? "Locked" : "Unlocked");
    }
}

void autoLock(int rooms, int motion[], int security[]) {
    static int noMotionCount = 0;
    int allNoMotion = 1;
    
    // Check for rooms with no motion
    for (int i = 0; i < rooms; i++) {
        if (motion[i] == 1) {
            allNoMotion = 0;
            break;
        }
    }

    if (allNoMotion) {
        noMotionCount++;
    } else {
        noMotionCount = 0;
    }

    // If no motion for 5 consecutive checks, lock all doors
    if (noMotionCount >= 5) {
        for (int i = 0; i < rooms; i++) {
            security[i] = 1;  // Lock doors
        }
        printf("\nAuto-lock activated due to no motion detected for 5 inputs.\n");
    }
}

void temperatureAlert(int rooms, int temp[]) {
    for (int i = 0; i < rooms; i++) {
        if (temp[i] > 30) {
            printf("Warning: Room %d temperature is above 30°C!\n", i + 1);
        }
    }
}

void energySavingMode(int rooms, int light[]) {
    int allLightsOn = 1;
    for (int i = 0; i < rooms; i++) {
        if (light[i] == 0) {
            allLightsOn = 0;
            break;
        }
    }
    
    if (allLightsOn) {
        printf("Energy Saving Alert: All lights are ON for too long. Consider turning them OFF.\n");
    }
}