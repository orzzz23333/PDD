#include "main.h"
#include "client.h"

int main() {
    printf("+---------------------------------------------------+\n");
    printf("|Welcome to Account and Product Management Subsystem|\n");
    printf("+---------------------------------------------------+\n");
    Client c;
    c.methodList();
    return 0;
}