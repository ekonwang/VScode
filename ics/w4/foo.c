int count = 0;

int foo(int p){
    if(p == 0) return 0;
    if(p == 1) return 1;
    count++;
    return foo(p-1) + foo(p-2);
}