
#ifndef d
    typedef
    enum direction {DESC, ASC} DIRECTION;
#endif

#ifndef f
    typedef
    enum flavor {SELECTION_SORT, BUBBLE_SORT, INSERT_SORT} FLAVOR;
#endif

void sort(int *, DIRECTION, FLAVOR);

void sort1(int *, DIRECTION);                     //selection-sort
void sort2(int *, int, DIRECTION);                //selection-sort
void sort3(int *, DIRECTION);                     //bubble-sort
void sort4(int *, DIRECTION);                     //insert-sort




#ifndef ANSI_C_SORT_H
#define ANSI_C_SORT_H

#endif //ANSI_C_SORT_H
