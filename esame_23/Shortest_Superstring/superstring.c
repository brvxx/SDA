#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
   
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}

char* SolveSuperstring(const char** v, size_t v_size) {

    bool* prese = calloc(v_size, sizeof(bool));
    int size = (int)v_size; 

    // ricerca delle due stringhe con sovrapposizione maggiore

    int b1 = 0; 
    int b2 = 0; 
    int overlap; 
    int best_overlap = -1; 

    for (int i = 0; i < (int)v_size; ++i) {
        for (int j = i + 1; j < (int)v_size; ++j) {
            char* tmp = Overlap(v[i], v[j], &overlap); 
            free(tmp); 
            if (overlap > best_overlap) {
                best_overlap = overlap; 
                b1 = i; 
                b2 = j; 
            }
        }
    }

    char* super_str = Overlap(v[b1], v[b2], &overlap); 
    prese[b1] = true; 
    prese[b2] = true; 
    size -= 2; 

    // applicazione dell'algoritmo greedy

    for (int k = size; k > 0; --k) {
        int b3 = 0;
        best_overlap = -1; 
        
        for (int q = 0; q < (int)v_size; ++q) {
            if (prese[q]) {
                continue; 
            }
            char* tmp = Overlap(super_str, v[q], &overlap); 
            free(tmp);
            if (overlap > best_overlap) {
                best_overlap = overlap;
                b3 = q;
            }
        }
        // aggiorno la superstringa 
        char* tmp = super_str; 
        super_str = Overlap(super_str, v[b3], &overlap); 
        free(tmp);

        prese[b3] = true; 
    }

    free(prese); 
    return super_str; 
}