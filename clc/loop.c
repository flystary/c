#include <stdio.h>

void loop() {

    int a = 10;
    
    do {
        printf("%d\n", a);
        a = a + 1;
    }while(a < 20);
}


int main() {

    loop();
    return 0;
}
