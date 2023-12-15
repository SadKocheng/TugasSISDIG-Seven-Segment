#include <stdio.h>

void BinaryConv(int num) {
    int biner[4] = {0, 0, 0, 0};
    for (int i = 0; i < num; i++) {
        int carry = 1;

        for (int j = 3; j >= 0; j--) {
            biner[j] += carry;

            if (biner[j] > 1) {
                biner[j] = 0;
            } else {
                carry = 0;
            }
        }
    }

    printf("The binary code of %d is ", num);
    for (int j = 0; j < 4; j++) {
        printf("%d ", biner[j]);
    }
    printf("\n\n");
}

void SegmentH(int length, int width) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            printf("  ");
        }
        for (int j = 0; j < length; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void SegmentVLeft(int length, int width) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void SegmentVRight(int length, int width) {
    for (int i = 0; i < length; i++) {
        printf("                  ");
        for (int j = 0; j < width; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void SegmentVBoth(int length, int width) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            printf("* ");
        }
        for (int j = 0; j < length; j++) {
            printf("  ");
        }
        for (int j = 0; j < width; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void DrawSegment(int Segment[], int length) {
    if (Segment[0] == 1) {
        SegmentH(7, 2);
    }
    if (Segment[1] == 1 && Segment[5] == 1) {
        SegmentVBoth(7, 2);
    } else if (Segment[1] == 1 && Segment[5] == 0) {
        SegmentVRight(7, 2);
    } else if (Segment[1] == 0 && Segment[5] == 1) {
        SegmentVLeft(7, 2);
    }

    if (Segment[6] == 1) {
        SegmentH(7, 2);
    } else {
        for (int j = 0; j < length; j++) {
            printf("  ");
        }
        printf("\n");
    }

    if (Segment[2] == 1 && Segment[4] == 1) {
        SegmentVBoth(7, 2);
    } else if (Segment[2] == 1 && Segment[4] == 0) {
        SegmentVRight(7, 2);
    } else if (Segment[2] == 0 && Segment[4] == 1) {
        SegmentVLeft(7, 2);
    }

    if (Segment[3] == 1) {
        SegmentH(7, 2);
    }
}

int main() {
    int num;

    printf("Insert a number : ");
    scanf("%d", &num);

    BinaryConv(num);

    int Segment[7];

    switch (num) {
        case 0:
            Segment[0] = 1; Segment[1] = 1; Segment[2] = 1; Segment[3] = 1; Segment[4] = 1; Segment[5] = 1; Segment[6] = 0;
            break;
        case 1:
            Segment[0] = 0; Segment[1] = 1; Segment[2] = 1; Segment[3] = 0; Segment[4] = 0; Segment[5] = 0; Segment[6] = 0;
            break;
        case 2:
            Segment[0] = 1; Segment[1] = 1; Segment[2] = 0; Segment[3] = 1; Segment[4] = 1; Segment[5] = 0; Segment[6] = 1;
            break;
        case 3:
            Segment[0] = 1; Segment[1] = 1; Segment[2] = 1; Segment[3] = 1; Segment[4] = 0; Segment[5] = 0; Segment[6] = 1;
            break;
        case 4:
            Segment[0] = 0; Segment[1] = 1; Segment[2] = 1; Segment[3] = 0; Segment[4] = 0; Segment[5] = 1; Segment[6] = 1;
            break;
        case 5:
            Segment[0] = 1; Segment[1] = 0; Segment[2] = 1; Segment[3] = 1; Segment[4] = 0; Segment[5] = 1; Segment[6] = 1;
            break;
        case 6:
            Segment[0] = 1; Segment[1] = 0; Segment[2] = 1; Segment[3] = 1; Segment[4] = 1; Segment[5] = 1; Segment[6] = 1;
            break;
        case 7:
            Segment[0] = 1; Segment[1] = 1; Segment[2] = 1; Segment[3] = 0; Segment[4] = 0; Segment[5] = 0; Segment[6] = 0;
            break;
        case 8:
            Segment[0] = 1; Segment[1] = 1; Segment[2] = 1; Segment[3] = 1; Segment[4] = 1; Segment[5] = 1; Segment[6] = 1;
            break;
        case 9:
            Segment[0] = 1; Segment[1] = 1; Segment[2] = 1; Segment[3] = 1; Segment[4] = 0; Segment[5] = 1; Segment[6] = 1;
            break;
        default:
            printf("Invalid!\n");
            return 1;
    }

    DrawSegment(Segment, 7);

    return 0;
}
