//
// Created by nikjan on 3/11/19.
//

#ifndef RG165_BETHEBACHELOR_CALLBACKFUNCS_H
#define RG165_BETHEBACHELOR_CALLBACKFUNCS_H

#define FIRST_VIEW (1)
#define SECOND_VIEW (2)
#define THIRD_VIEW (3)




void on_reshape(int width, int height);
void on_display(void);
void on_keyboard(unsigned char key, int x, int y);
void on_timer(int value);
void init_callbacks(void);


#endif
