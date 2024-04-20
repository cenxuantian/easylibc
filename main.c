#include <stdio.h>

#include <def.h>
#include <vec.h>
#include <str.h>
#include <pair.h>
#include <list.h>
#include <stack.h>

$declare_$stack(double)


int main(int argc, char** argv){
    $stack(double)* stack = stack_new();

    stack_push_rv(stack,10.5);
    printf("%lf\n",stack_top(stack));
    stack_push_rv(stack,20.5);
    printf("%lf\n",stack_top(stack));
    stack_pop(stack);
    printf("%lf\n",stack_top(stack));

    stack_del(stack);
}


