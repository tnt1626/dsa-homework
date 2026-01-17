#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Guest {
    char name;
    int floor, room;
    struct Guest *next;
} Guest;

typedef struct {
    Guest *guest;
} Leader;

void init(Leader *list) {
    list->guest = NULL;
}

Guest* makeNode(char name, int floor, int room) {
    Guest *newGuest = (Guest *)malloc(sizeof(Guest));
    if(newGuest != NULL) {
        newGuest->name = name;
        newGuest->floor = floor;
        newGuest->room = room;
        newGuest->next = NULL;
    }
    return newGuest;
}

void insertHead(Leader *list, char name, int floor, int room) {
    Guest *newNode = makeNode(name, floor, room);
    newNode->next = list->guest;
    list->guest = newNode;
}

Guest *insertTail(Leader *list, char name, int floor, int room) {
    if(list->guest == NULL) {
        insertHead(list, name, floor, room);
        return;
    }
    Guest *node = list->guest;
    while(node->next != NULL) {
        node = node->next;
    }
    Guest *newNode = makeNode(name, floor, room);
    node->next = newNode;
    return newNode;
}

Guest* deleteHead(Guest *head) {
    if(head == NULL) {
        return head;
    }
    Guest *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void freeList(Leader *list) {
    while(list->guest != NULL) {
        list->guest = deleteHead(list->guest);
    }
}

void freeAll(Leader leader[]) {
    for(int i = 0; i < 10; i++) {
        freeList(&leader[i]);
    }
}

void createGroup(Leader leader[], char groups[][16]) {
    for(int i = 0; i < 10; i++) {
        int len = strlen(groups[i]);
        init(&leader[i]);
        for(int j = len - 1; j >= 0; j--) {
            insertHead(&leader[i], groups[i][j], 0, 0);
        }
    }
}

// Vấn đề 1
void insertGuest(int status[][12], Guest *guests[][12], Leader leader[]) {
    for(int i = 0; i < 10; i++) {
        int indexRoom = 0;
        while(indexRoom < 12 && status[0][indexRoom] == 1) {
            indexRoom++;
        }
        Guest *head = leader[i].guest;
        head->floor = 0;
        head->room = indexRoom;
        guests[0][indexRoom] = head;
        status[0][indexRoom] = 1;
    }

    int floor = 0, room = 0;
    for(int i = 0; i < 10; i++) {
        Guest *current = leader[i].guest->next;
        while(current) {
            while(floor < 17 && room < 12 && status[floor][room] == 1) {
                room++;
                if(room == 12) {
                    room = 0;
                    floor++;
                }
            }
            
            if(floor >= 17) {
                return;
            }

            current->floor = floor;
            current->room = room;
            guests[floor][room] = current;
            status[floor][room] = 1;

            room++;
            if(room == 12) {
                room = 0;
                floor++;
            }

            current = current->next;
        }
    }
}

// Vấn đề 2
void getInfo(Guest *guests[][12]) {
    int leaderRoom;
    printf("Nhập phòng của đoàn trưởng: ");
    scanf("%d", &leaderRoom);
    if(guests[0][leaderRoom] == NULL) {
        printf("Đây không phải là phòng của đoàn trưởng\n");
        return;
    }
    Guest *guest = guests[0][leaderRoom];
    int count = 1;
    while(guest) {
        printf("%d. Name:%3c, Floor:%3d, Room:%3d\n", count, guest->name, guest->floor, guest->room);
        guest = guest->next;
        count++;
    }
}


// Vấn đề 3
void insertNewGuest(Guest *guests[][12], Leader leader[]) {
    int room, floor;
    printf("Nhập tầng và phòng muốn check in: ");
    scanf("%d %d", &floor, &room);
    if(guests[floor][room] != NULL) {
        printf("Phòng này đã có khách\n");
        return;
    }
    int group;
    printf("Nhập đoàn muốn check in: ");
    scanf("%d", &group);
    char name;
    printf("Nhập tên người muốn check in:");
    scanf(" %c", &name);
    Guest *newNode = insertTail(&leader[group], name, floor, room);
    guests[floor][room] = newNode;
    printf("Check in thành công\n");
}

// Vấn đề 4
Guest* deleteWithFloorAndRoom(Guest *guest, int floor, int room) {
    if(guest == NULL) {
        return NULL;
    }
    if(guest->floor == floor && guest->room == room) {
        return deleteHead(guest);
    }
    guest->next = deleteWithFloorAndRoom(guest->next, floor, room);
    return guest;
}

void deleteGuest(Leader leader[], Guest *guests[][12]) {
    int floor, room;
    printf("Nhập tầng và phòng của khách muốn check out: ");
    scanf("%d %d", &floor, &room);
    for(int i = 0; i < 10; i++) {
        leader[i].guest = deleteWithFloorAndRoom(leader[i].guest, floor, room);
    }
    guests[floor][room] = NULL;
}

// Vấn đề 5
void checkOutGroup(Leader leader[], Guest *guests[][12], int status[][12]) {
    int indexGroup;
    printf("Nhập đoàn muốn check out: ");
    scanf("%d", &indexGroup);
    Guest *temp = leader[indexGroup].guest;
    while(temp) {
        int floor = temp->floor, room = temp->room;
        status[floor][room] = 0;
        guests[floor][room] = NULL;
        temp = temp->next;
    }
    freeList(&leader[indexGroup]);
}


int main() {
    int status[17][12] = {
        {0,0,0,1,0,0,0,1,0,0,1,0},
        {0,0,1,1,0,0,1,0,0,1,1,1},
        {0,1,0,0,1,1,0,1,0,0,1,0},
        {1,0,1,0,0,0,1,0,1,0,1,1},
        {0,0,1,1,0,1,0,0,0,1,0,0},
        {1,1,1,0,1,0,1,1,0,0,1,1},
        {1,0,0,1,0,0,1,0,1,1,0,0},
        {0,0,1,0,0,1,0,1,0,0,1,1},
        {0,1,0,0,0,0,1,0,1,1,0,1},
        {0,0,1,1,1,0,0,1,0,0,1,0},
        {1,0,1,0,0,1,0,0,0,0,0,1},
        {0,1,0,0,1,0,1,1,0,0,1,1},
        {1,0,0,1,0,0,0,0,1,1,0,1},
        {0,0,1,0,1,0,1,0,0,0,1,0},
        {1,0,0,1,0,1,0,1,1,0,0,1},
        {1,0,1,0,0,0,1,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,1,1}
    };
    char groups[10][16] = {
        // Đoàn 1 (12)
        {'A','B','S','E','F','J','K','L','S','W','Q','A','\0','\0','\0'},
        // Đoàn 2 (10)
        {'T','M','K','L','J','S','A','Q','C','S','\0','\0','\0','\0','\0'},
        // Đoàn 3 (9)
        {'H','J','S','S','A','S','M','Q','D','\0','\0','\0','\0','\0','\0'},
        // Đoàn 4 (13)
        {'S','A','Q','D','A','S','S','A','Q','D','S','Q','A','\0','\0'},
        // Đoàn 5 (15)
        {'Q','S','A','Q','E','D','F','S','S','A','S','X','V','B','F','\0'},
        // Đoàn 6 (14)
        {'H','A','V','A','N','T','H','A','O','T','T','H','U','S','\0'},
        // Đoàn 7 (12)
        {'P','H','L','A','M','D','S','A','T','T','H','U','\0','\0','\0'},
        // Đoàn 8 (15)
        {'P','P','N','H','U','N','G','S','V','E','L','E','V','E','N','\0'},
        // Đoàn 9 (10)
        {'L','P','T','R','U','O','N','G','D','S','\0','\0','\0','\0','\0'},
        // Đoàn 10 (10)
        {'C','H','G','I','A','O','K','D','L','H','\0','\0','\0','\0','\0'}
    };

    Guest *guests[17][12];
    for(int i = 0; i < 17; i++) {
        for(int j = 0; j < 12; j++) {
            guests[i][j] = NULL;
        }
    }
    Leader leader[10];
    createGroup(leader, groups);
    insertGuest(status, guests, leader);
    getInfo(guests);
    freeAll(leader);
    return 0;
}

// Đây chỉ là 1 lời giải đã bỏ qua các giá trị nhập sai, nếu có sai sót hãy báo lại nha