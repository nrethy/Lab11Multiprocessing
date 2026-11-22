# Lab 11: Multiprocessing
## Purpose:
### Demonstrate multiprocessing by generating a video of the mandelbrot set and play it with ffmpeg
## Implementation:
### My implementation uses getopt to parse the input for our number of children, after this we loop for the number of frames. We first check that our number of frames is greater than the number of children, as if it isn't we will need to decrease our number of child processes to our number of remaining frames. After this we loop forking
