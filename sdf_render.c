#include <math.h>
#include <stdio.h>

float lerp(float c, float c_start, float c_end, float steps) {
    if (steps == 0.0f) return c_start;
    float t = c / steps;
    // C = c_start + t * (c_end - c_start)
    return c_start + t * (c_end - c_start);
    
}

int main() {
    const int width = 1280;
    const int height = 720;
    int total = 0;
    FILE *fptr = fopen("output.ppm", "w");

    if (fptr != NULL) { // make it stretch across 2d 
        fprintf(fptr, "P3\n%d %d\n255\n", width, height);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                total +=1;
                fprintf(fptr, "%d %d %d\n", (int)lerp(j, 255, 0, width), 0, (int)lerp(i, 0, 255, (float)height));
            }
        }
        fclose(fptr);
        return 1;
    }
    printf("Failed to create file.");
    return 0;
}