#include <stdio.h>

struct timeval
{
    unsigned long secs;
    long msecs;
};

struct input_event
{
    struct timeval time;
    unsigned short type;
    unsigned short code;
    unsigned int value;
};

int main()
{
    FILE *kbd = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    struct input_event event;

    while (1)
    {
        fread(&event, sizeof(struct input_event), 1, kbd);
        if (event.type != 0x01)
            continue;

        if (event.value == 0x01)
        {
            printf("PRESSED %#x (%d)\n", event.code, event.code);
        }
        else if (event.value == 0x00)
        {
            printf("RELEASED %#x (%d)\n", event.code, event.code);
        }
    }

    return 0;
}