#include "../functions.h"

void resizeArray(long long newSize) {
   db = (DB*)realloc(db, newSize * sizeof(DB));
}
