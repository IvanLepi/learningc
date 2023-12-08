//There are four options to use structs 
//
//Option 1 No typedef, has to be defined in main
struct rect_t {
    int left;
    int top;
    int right;
    int bottom;
}

int main() 
{
    struct rect_t myRect;
    myRect.left = 1;
    ...
}

//Option 2 Defined type for a tag.
struct rect_tag {
    int left;
    int top;
    int right;
    int bottom;
};
typedef struct rect_tag rect_t;

int main()
{
    rect_t myStruct;
    myStruct.left = 1;
    ...
}

//Option 3 Alternative to Option 2 where we can typedef inside of a statement
typedef struct rect_tag {
    int left;
    int top;
    int right;
    int bottom;
} rect_t;

int main() {
    rect_t myRect = 1;
    ...
}

//Option 4 No tag --- cant refrence itself
typedef struct rect_tag {
    int left;
    int top;
    int right;
    int bottom;
};

int main() 
    {
        rect_tag myRect = 1;
        ...
    }
/*
 * Heads up about typedef: The use of typedefs is somewhat controversial in some
 * programming circles. In the context of structs, there are those who believe
 * that it is important not to abstract the struct away from a type.
 * They believe that programmers should always know when a particular variable
 * is a struct and when it is not. Similarly, they believe that programmers
 * should always be aware of the actual types of the data they use lest they
 * fall prey to typing errors that could have been otherwise avoided.
 * Use typedefs when the abstraction simplifies rather than obfuscates your code.
 */

//typedef
typedef unsigned int rgb_t; //'typedef unsigned char rgb_t' only change needed

rgb_t getRedForPixel(int x, int y) {...}
rgb_t getGreenForPixel(int x, int y) {...}
rgb_t getBlueForPixel(int x, int y) {...}

int main(void){
    rgb_t red, green, blue;
    red = getRedValue();
    green = getGreenValue();
    ...
}


/*
 * Enumerated types
 */

enum threat_level_t {
    LOW,
    GUARDED,
    ELEVATED,
    HIGH,
    SEVERE
};

void printThreat(enum threat_level_t threat) {
    switch (threat) {
        case LOW:
            printf("Green/Low.\n");
            break;
       case GUARDED:
            printf("Blue/Guarded.\n");
            break;

        case ELEVATED:
            printf("Yellow/Elevated.\n");
            break;

        case HIGH:
            printf("Orange/High.\n");
            break;

        case SEVERE:
            printf("Red/Severe.\n");
            break;
        }
    }

void printShoes(enum threat_level_t currThreat) {
    if (currThreat >= ELEVATED) {
        printf("Remove your shoes");
    } else
         {
             printf("leave the shoes on");
         }
}

int main(void) {
    enum threat_level_t myThreat = HIGH;
    printf("Current threat level is: \n");
    printThreat(myThreat);
    printShoes(myThreat);
    return 0;
}


