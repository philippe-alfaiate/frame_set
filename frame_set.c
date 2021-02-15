#include "frame_set.h"

void add_pixel(Frame *f, uint8_t x, uint8_t y, int16_t value)
{
    if(x < 8 && y < 8 && x >= 0 && y >= 0)
    {
        f->frame[x][y] = value;
    }
}

void add_cube(Frame *f, uint8_t x, uint8_t y, uint8_t size)
{
    int i,j;
    for(i=0;i < size;i++)
    {
        for(j=0;j < size;j++)
        {
            add_pixel(f, x+i, y+j, NEAR);
        }
    }
}


void print_frame(Frame *f)
{
    int i,j;
    for(i=0;i < 8;i++)
    {
        for(j=0;j < 8;j++)
        {
            printf("%4d ", f->frame[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_frame_graph(Frame *f)
{
    int i,j;
    
    for(i=0;i < 8;i++)
    {
        if(i==3)
        {
            printf("----------------\n");
        }
        for(j=0;j < 8;j++)
        {
            printf("|");
            if(f->frame[i][j] >= TOO_FAR)
            {
                printf(" ");
            }
            else if(f->frame[i][j] <= NEAR)
            {
                printf("X");
            }
            else
            {
                printf("?");
            }
        }
        printf("|\n");
    }
    printf("\n");
}


void move_cube_AB_10(FrameSet10 *s)
{
    int y = 3;
    for(int i=0;i<10;i++)
    {
            add_cube(&s->set[i],i - 2,y,3);
    }
}

void print_set(FrameSet10 *s)
{
    for (int i = 0; i < 10; i++)
    {
        print_frame_graph(&s->set[i]);
    }
}

void move_cube_BA_10(FrameSet10 *s)
{
    int y = 3;
    int pos = 7;
    for(int i=0;i<10;i++)
    {
            add_cube(&s->set[i],pos ,y,3);
            pos--;
    }
}