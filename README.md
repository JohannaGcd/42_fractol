# 42_fractol

## Task
This project renders two types of fractals, the Mandelbrot and the Julia sets.

## What I learned
This was my first introduction to graphics programming. I learned:
* How to leverage an external library to open a window and render an image;
* To display colors;
* And event handling (scrolling, pressing keys, exiting etc).
* I also learned about suppression files (to silence leaks in the library, MLX42);
* And, although I didn't use that method, I learned about git submodules for the first time.
 
## How to build to program
Run the following command to clone the repository: and build the executable:
```
git clone git@github.com:JohannaGcd/42_fractol.git && cd 42_fractol
```
Clone the MLX42 library:
```
git clone https://github.com/codam-coding-college/MLX42.git
```
Build the executable:
```
make
```

### How to run the program
Run the executable with the fractal as an argument, such as:
```
./fractol mandelbrot
```
For Julia set, provide two additional parameters:
```
./fractol julia <value1> <value2>
```
### Controls
* Use the mouse wheel to zoom in and out.
* Use the arrow keys to move UP, DOWN, LEFT or RIGHT.
* Press '+' to change colors. 
* Press 1 and 2 to switch between fractal types. 
* Press ESC to close the window and quit the program.


![Screenshot from 2024-07-19 15-10-14](https://github.com/user-attachments/assets/e54ff045-affb-4ed5-9b8a-cd47782f8056)
![Screenshot from 2024-07-19 15-13-08](https://github.com/user-attachments/assets/d0699782-f909-497f-bae3-11904e03d945)
