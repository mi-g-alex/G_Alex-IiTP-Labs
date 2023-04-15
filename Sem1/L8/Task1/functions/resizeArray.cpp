#include "../functions.h"

void resizeArray(long long newSize) {
   a = (Data*)realloc(a, newSize * sizeof(Data));
}
