/*
** Filename: mandelmovie.c
** Created: 11/22/2026
** Author: Noah Rethwisch
** Assignment Name: Lab 11 - Multiprocessing
** Section Number: 111
** Purpose: call mandel 50 times and generate images with a specified number of
** children
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int children = 1;
    int frames = 50;
    char command[] = "./mandel -x -.38 -y -.665 -s ";
    char outputparam[] = " -o mandel";
    char output[400];
    double scale = .05;
    char c;
    // read in the number of children using getopt
    while((c=getopt(argc,argv,"c:"))!=-1){
        switch(c){
        case 'c':
            children = atoi(optarg);
            // make sure the children are the right number
            if((children < 1) || (children > 50)){
                printf("invalid child number");
                return -1;
            }
            break;
        }
    }
    while(frames > 0){
        // making sure we don't have more children than frames
        if(frames < children){
            children = frames;
        }
        for(int i=0; i<children; i++){
            pid_t id = fork();
            if(id == 0){
                // changing scale for the children
                double s = scale + (frames-i)*.01;
                // create a command to make an image with ./mandel
                snprintf(output, sizeof(output),"%s%lf%s%i%s",command,s,outputparam,(frames-i),".jpg");
                system(output);
                exit(0);
            }
        }
        // wait for all children to be done
        for(int i=0; i<children; i++){
        wait(NULL);
        }
        frames-=children;
    }
    // make a video and delete mandel images
    system("ffmpeg -i mandel%d.jpg mandel.mp4");
    system("rm mandel*.jpg");
    return 0;
}
