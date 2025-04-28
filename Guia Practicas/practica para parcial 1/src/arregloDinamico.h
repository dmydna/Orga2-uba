

typedef struct str_array {
  uint8_t size;
  uint8_t capacity;
  char** data;
} str_array_t;

str_array_t* strArrayNew(uint8_t capacity);

uint8_t strArrayGetSize(str_array_t* a);

char* strArrayGet(str_array_t* a, uint8_t i);

char* strArrayRemove(str_array_t* a, uint8_t i);

void strArrayDelete(str_array_t* a);
