#include "frame_set.h"


int main(){

    FrameSet10 set = {EMPTY_SET};

    move_cube_BA_10(&set);
    print_set(&set);

    return 0;
}