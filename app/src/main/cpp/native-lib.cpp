#include <jni.h>
#include <stdlib.h>
#include <string>

#if defined(__clang__) || defined (__GNUC__)
# define ATTRIBUTE_NO_SANITIZE_ADDRESS __attribute__((no_sanitize_address))
#else
# define ATTRIBUTE_NO_SANITIZE_ADDRESS
#endif

void *p;

static void leak(){
    p = malloc(7);
    p = 0; // The memory is leaked here.
}

//ATTRIBUTE_NO_SANITIZE_ADDRESS
static int use_after_free(){
    int *array = new int[100];
    delete [] array;
    return array[0];  // BOOM
}

static int heap_overflow(){
    int *array = new int[100];
    array[0] = 0;
    int res = array[100];  // BOOM
    delete [] array;
    return res;
}

// RUN: clang -O -g -fsanitize=address %t && ./a.out
int stack_overflow() {
    int stack_array[100];
    stack_array[1] = 0;
    return stack_array[100];  // BOOM
}

int global_array[100] = {-1};
static int globle_overflow(){
    return global_array[100];  // BOOM
}

// RUN: clang -O -g -fsanitize=address %t && ./a.out
// By default, AddressSanitizer does not try to detect
// stack-use-after-return bugs.
// It may still find such bugs occasionally
// and report them as a hard-to-explain stack-buffer-overflow.

// You need to run the test with ASAN_OPTIONS=detect_stack_use_after_return=1

int *ptr;
__attribute__((noinline))
static void FunctionThatEscapesLocalObject() {
    int local[100];
    ptr = &local[0];
}

static int use_after_return(){
    FunctionThatEscapesLocalObject();
    return ptr[0];
}


// RUN: clang -O -g -fsanitize=address -fsanitize-address-use-after-scope \
//    use-after-scope.cpp -o /tmp/use-after-scope
// RUN: /tmp/use-after-scope

// Check can be disabled in run-time:
// RUN: ASAN_OPTIONS=detect_stack_use_after_scope=0 /tmp/use-after-scope

volatile int *p1 = 0;
static int use_after_scope(){
    {
        int x = 0;
        p1 = &x;
    }
    *p1 = 5;
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_github_sgwhp_asansample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    use_after_free();
    heap_overflow();
    stack_overflow();
    globle_overflow();
    use_after_return();
    use_after_scope();
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
