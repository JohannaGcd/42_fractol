# 42_fractol
 This project is about creating fractals. You should create at least two types of fractals, the Mandelbrot and the Julia sets.

This README describes how I would approach the subject if I were to do it again, and details some of the tricky parts I encountered while building my program and learning how to use a graphical library.

## Part 1: Introduction to fractals

This [Medium article](url), in conjuntion with these two videos ([One](url) , [Two](url)) give a good overview of the mathematical concepts behinds fractols and are one of the best resources out there to understand how to modelize your fractal! 
https://github.com/JohannaGcd/42_fractol/blob/main/README.md
## Part 2: Introduction to graphical libraries

A. MinilibX vs MLX42
I used the MLX42 library, which was advised to me as an alternative to minilibx, which is pretty buggy. MLX42 is an open-source project, built on top of minilibx, which was originally written by a student from Codam. You can check whether your campus accepts MLX42 and more details as to why MLX42 is superior to minilibx here.

B. How to compile
As specified in the MLX42 documentation, use the following lines:

```git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build # build here refers to the outputfolder.
cmake --build build -j4 # or do make -C build -j4```

In your Makefile, it would look like this:

$(LIBS_TARGET_MLX):
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build && cmake --build $(MLX_DIR)/build -j4



C. My library gives me leaks
Part 3: Fractol - My method with pseudo code
