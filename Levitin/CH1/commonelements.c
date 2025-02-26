#include <stdio.h>

int main(void) {
    printf("Find common elements in list: ");
    int listX[4] = {2, 5, 5, 5};
    int listY[6] = {2, 2, 3, 5, 5, 7};

    int sizeX = sizeof(listX) / sizeof(listX[0]);
    int sizeY = sizeof(listY) / sizeof(listY[0]);

    int common[sizeX + sizeY];
    int k = 0;

    if (sizeX <= sizeY) {
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                if (listX[i] == listY[j]) {
                    common[k] = listX[i];
                    k++;
                    break; // Avoid counting the same element multiple times
                }
            }
        }
    }

    printf("Common elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", common[i]);
    }
    printf("\n");

    return 0;
}