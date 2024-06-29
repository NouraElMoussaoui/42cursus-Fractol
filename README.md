# Overview
This project is about creating graphically beautiful fractals.
The term fractal was first used by mathematician Benoit Mandelbrot in 1974. He based
it on the Latin word fractus which means "broken" or "fractured".
A fractal is an abstract mathematical object, like a curve or a surface, which pattern
remains the same at every scale.
Various natural phenomena – like the romanesco cabbage – have some fractal features.
# Features
  * Generate Mandelbrot fractal
  * Generate Julia fractal with customizable parameters
  * Interactive window with MiniLibX

# Getting Started
## How to Run

### To compile the program, use the provided Makefile:
 * make
### To run the program, use the following command:
 * Mandatory Part: ./fractol [type] [parameters]
 * Bonus Part: ./fractol_bonus [type] [parameters]
Where:
  * type is either "Mandelbrot" or "Julia"
  * parameters are the parameters for the Julia set (only required for Julia)
# Code Overview
The main function of the program is in main.c. It initializes the MiniLibX library and the fractal parameters, then calls the appropriate function to generate the fractal based on the command line arguments.
The args function handles the command line arguments. If the user specifies "Mandelbrot", it calls the mandelbrot function. If the user specifies "Julia" and provides valid parameters, it calls the julia function.
The mandelbrot and julia functions generate the respective fractals. They use the MiniLibX library to create an image, then iterate over each pixel in the image, calculating the color based on the fractal formula.

# MinilibX library
The MiniLibX library is a simple graphics library used in the context of the 42 School curriculum. It provides basic functionalities like creating a window, managing events (like key presses or mouse clicks), and drawing pixels.
## How to use it in this Project: 
  1. Installation: First, you need to install the MiniLibX library. The installation process may vary depending on your operating system.
  2. Linking: you need to link the MiniLibX library. In the Makefile, this is done with the -lmlx flag in the LBXFLAGS variable.
  3. Creating a Window: You can create a window using the mlx_new_window function. This function takes the MLX pointer, width, and height of the window, and the title of the window as arguments.
  4. Managing Events: MiniLibX can manage events like key presses, mouse clicks, and expose events. You can set up your functions to handle these events using mlx_key_hook, mlx_mouse_hook, and mlx_expose_hook respectively.
  5. Drawing Pixels: You can draw pixels using the mlx_pixel_put function. This function takes the MLX pointer, the window pointer, the x and y coordinates, and the color as arguments.
  6. Starting the Loop: Finally, you need to start the MiniLibX loop using the mlx_loop function. This function takes the MLX pointer as an argument and will start the event loop.
