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

static void SolveSuperstringRec(const char** v, size_t v_size, int i, int* vcurr, int* vbest, bool* presi, int* best_overlap) {
    if (i == 2) {
        int overlap = 0; 
        char* tmp = Overlap(v[vcurr[0]], v[vcurr[1]], &overlap); 
        free(tmp); 
        if (overlap > *best_overlap) {
            *best_overlap = overlap; 
            memcpy(vbest, vcurr, 2 * sizeof(int));
        }
        return; 
    }

    for (int j = 0; j < (int)v_size; ++j) {
        if (!presi[j]) {
            vcurr[i] = j; 
            presi[j] = true; 

            SolveSuperstringRec(v, v_size, i + 1, vcurr, vbest, presi, best_overlap); 

            presi[j] = false;
        }
    }
}

char* SolveSuperstring(const char** v, size_t v_size) {

   int* vcurr = calloc(2, sizeof(int));
   int* vbest = calloc(2, sizeof(int));
   bool* presi = calloc(v_size, sizeof(bool));

   int best_overlap = -1;

   SolveSuperstringRec(v, v_size, 0, vcurr, vbest, presi, &best_overlap);
   free(vcurr);

   char* super_str = Overlap(v[vbest[0]], v[vbest[1]], &best_overlap);

   int size = (int)v_size; 
   presi[vbest[0]] = true; 
   presi[vbest[1]] = true; 
   size -= 2; 

   free(vbest); 

   // applicazione dell'algoritmo greedy

   for (int k = size; k > 0; --k) {
       int index_best = 0;
       int overlap = 0; 
       best_overlap = -1;

       for (int q = 0; q < (int)v_size; ++q) {
           if (presi[q]) {
               continue;
           }
           char* tmp = Overlap(super_str, v[q], &overlap);
           free(tmp);
           if (overlap > best_overlap) {
               best_overlap = overlap;
               index_best = q;
           }
       }
       // aggiorno la superstringa 
       char* tmp = super_str;
       super_str = Overlap(super_str, v[index_best], &overlap);
       free(tmp);

       presi[index_best] = true;
       --size;
   }

   free(presi);
   return super_str;
}