# Lab 11: Multiprocessing
## Purpose:
  Demonstrate multiprocessing by generating a video of the mandelbrot set and play it with ffmpeg
## Implementation:
  My implementation uses getopt to parse the input for our number of children. Upon getting our children count, we loop for the number of frames, making sure that our number of children is less than the number of remaining frames. If the number of remaining frames is less than our number of children, we will decrease our number of children to the remaining amount of frames. We will then fork for our number of children, having each child make a new image with a different scale and filename corresponding to its value i, as well as the current frame count. after each round of children is done, we will decrement frames for the number of children we have. We will then use ffmpeg to generate an mp4 using our mandel images, and then as an added quality of life addition, it will remove all the mandel images.
## Results
![Graphed Results](graph.jpg)
