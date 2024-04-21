#ifndef __$SORT$_$C$__
#define __$SORT$_$C$__

#include "sort.h"



_extern_c_beg_

void __array_quick_sort(void* target, int ele_size,sort_comp_func* compare,int start,int stop){
    if(start>=stop) return;
    if(stop-start==1){
        // asume bigger return true
        if(compare($offset(target,ele_size*start),$offset(target,ele_size*stop),ele_size) >0) 
            $swap($offset(target,ele_size*start),$offset(target,ele_size*stop),ele_size);
        return;
    }
        int r_edge = stop;
        int std_start = start;
        int std_stop = start;
        do{
            int comp_res =compare($offset(target,ele_size*(std_stop+1)),$offset(target,ele_size*std_stop),ele_size) ;
            if(comp_res>0){   // bigger
                $swap($offset(target,ele_size*(std_stop+1)),$offset(target,ele_size*r_edge),ele_size);
                r_edge--;
            }
            else if(comp_res == 0){
                std_stop++;
            }
            else{
                $swap($offset(target,ele_size*(std_stop+1)),$offset(target,ele_size*std_start),ele_size);
                std_start++;
                std_stop++;
            }
        }while(std_start <r_edge);
    
    if(stop>std_stop+1) __array_quick_sort(target,ele_size,compare,std_stop+1,stop);
    if(std_start-1>start) __array_quick_sort(target,ele_size,compare,start,std_start-1);
}

void array_quick_sort(void* target, int ele_size, int ele_count,sort_comp_func* compare){
    if(!ele_count)return;
    if(ele_count == 1)return;
    if(ele_count == 2){
        if(compare(target,$offset(target,ele_size),ele_size) > 0) 
            $swap(target,$offset(target,ele_size),ele_size);
        return;
    }
    __array_quick_sort(target,ele_size,compare,0,ele_count-1);
    return;
}


void array_transform(void* target, int ele_size, int ele_count, void(*func)(void*)){
    for(int i=0;i< ele_count;i++){
        func(target);
        target+=ele_size;
    }
}
static int __lower_upper_diff = 'A'-'a';


void $tolower(void* ch){
    if($deref(char,ch) <= 'Z' && $deref(char,ch) >='A'){
        $deref(char,ch) -= __lower_upper_diff;
    }
}
void $toupper(void* ch){
    if($deref(char,ch) <= 'z' && $deref(char,ch) >='a'){
        $deref(char,ch) += __lower_upper_diff;
    }
}

_extern_c_end_

#endif