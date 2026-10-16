#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
    void *handle = dlopen("./libcalc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen 실패: %s\n", dlerror());
        return 1;
    }

    int    (*add)(int, int)      = dlsym(handle, "add");
    int    (*subtract)(int, int) = dlsym(handle, "subtract");
    int    (*multiply)(int, int) = dlsym(handle, "multiply");
    double (*divide)(int, int)   = dlsym(handle, "divide");

    if (!add || !subtract || !multiply || !divide) {
        fprintf(stderr, "dlsym 실패: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    printf("10 + 5 = %d\n", add(10, 5));
    printf("10 - 5 = %d\n", subtract(10, 5));
    printf("10 * 5 = %d\n", multiply(10, 5));
    printf("10 / 5 = %.2f\n", divide(10, 5));

    dlclose(handle);
    return 0;
}
