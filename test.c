# include "include/philosopher.h"

int main()
{
    struct timeval tv;
    struct timeval te;
    time_t  start_time;
    time_t  end_time;

    gettimeofday(&tv, NULL);
    usleep(1000);
    gettimeofday(&te, NULL);

    start_time = (tv.tv_usec / 1000);
    end_time = (te.tv_usec / 1000);
    
    printf("start_time is %ld\n", start_time);
    printf("end_time is %ld\n", end_time);
    printf("val is %ld\n", end_time - start_time);
    // printf("tv_sec is %ld\n tv_usec is %d\n", tv.tv_sec, tv.tv_usec);
    // // printf("tv_sec is %ld\n", (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    // printf("te_sec is %ld\n te_usec is %d\n", te.tv_sec, te.tv_usec);
    // printf("sec is %ld\n usec is %d\n", (te.tv_sec - tv.tv_sec), (te.tv_usec - tv.tv_usec)/1000);
    // printf("ms is %ld\n", ((te.tv_sec * 1000) + (te.tv_usec / 1000) - (tv.tv_sec *1000 + tv.tv_usec / 1000)));
    return (0);
}