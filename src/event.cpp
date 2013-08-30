#include "event.h"
#include <stdio.h>

//this should be initialized by main.cpp as soon as the program starts.
Display* display;

//actually creates an XWindows event  :)
void sendevent( xevent e ) {
	    printf("KREL %d, KPRESS %d, BREL %d, BPRESS %d, WARP %d \n",KREL, KPRESS, BREL, BPRESS, WARP);
//    if (e.value1 == 0 && e.value2 == 0) return;
    if (e.type == WARP) {
        XTestFakeRelativeMotionEvent(display, e.value1, e.value2, 0);
    }
    else {
        if (e.type == KREL || e.type == KPRESS) {
	    printf("evalue1 %d, evalue2 %d, evalue 3 %d, evalue4 %d\n",e.value1,e.value2,e.value3,e.value4);
            XTestFakeKeyEvent(display, e.value1, (e.type == KPRESS), 0);
	    if (e.value2 != 0){
		XTestFakeKeyEvent(display, e.value2, (e.type == KPRESS), 0);
	    }
	    if (e.value3 != 0){
		XTestFakeKeyEvent(display, e.value3, (e.type == KPRESS), 0);
	    }
	    if (e.value4 != 0){
		XTestFakeKeyEvent(display, e.value4, (e.type == KPRESS), 0);
	    }

        }
        else if (e.type == BREL || e.type == BPRESS) {
            XTestFakeButtonEvent(display, e.value1, (e.type == BPRESS), 1);
        }
    }
    XFlush(display);

}
