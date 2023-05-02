# Fract-ol 🎇🌌

## Introduction
Fractol is a 42 school project that involves creating a program that can generate and display different types of fractals. The project aims to introduce students to the world of fractals and help them gain experience in graphics programming.

## GRADE PROJECT ✅
- 100/125 📋
- [**Subject**](https://github.com/nunovaladao/42_fract-ol_lev2/blob/main/extras/en.subject.pdf) 

## Installation

1. Clone the repository via
```bash
git clone https://github.com/nunovaladao/42_fract-ol_lev2.git
```

2. Move into the repository directory:
```bash
cd 42_fract-ol_lev2
```

3. Choose the folder you want, according to your operating system 
```bash
cd fract-ol_linux
or
cd fract-ol_mac
```

4. Inside the folder you chose, compile the program by running `make`, if you need to give permissions to the minilibx library, just go into the folder and do `chmod 777 ./configure`!
```bash
make
```

## Usage
To run this program you can simply place the executable and see what the options are:

Example usage: 
```bash
./fractol 
```
Output: 
```bash
Run:

  1) ./fractol <fractal>

  2) For Julia you can set diferent paramaters to change the fractal:
	2.1) ./fractol <fractal> cx cy

Note: pick some values (between -2 and 2) for the constant c, this determines the shape of the Julia Set!

Fractal options:

  - Julia
  - Mandelbrot
```
## Fractal - Mandelbrot
To run the fractal `Mandelbrot`:
```bash
./fractol Mandelbrot  
```

Output:
![Mandelbrot](https://github.com/nunovaladao/42_fract-ol_lev2/blob/main/extras/Screenshot_Mandel.png)

## Fractal - Julia
To run the fractal `Julia`:
```bash
./fractol Julia  
```
- Note: for Julia you can add two more arguments to determine the shape of the fractal (between -2.0 and 2.0);

```bash
./fractol Julia cx cy   
```
Example usage: 
```bash
./fractol Julia 0.2001 -0.8 
```

Output:

![Julia](https://github.com/nunovaladao/42_fract-ol_lev2/blob/main/extras/Sreenshot_Julia.png)

### Note: For the two fractals, you can also `zoom in` and `zoom out` with the mouse! 

## Conclusion
After completing the fractal project at 42, I was able to improve my programming skills in C and enhance my understanding of the mathematics behind generating fractals. I learned how to use graphic libraries to represent these complex geometric figures and explore different techniques to create impressive fractals. This project was a valuable opportunity to enhance my problem-solving skills and challenge myself at a more advanced level of programming. Overall, I am pleased with the final result of the project and excited to apply the knowledge gained to future projects.

## Useful links

- https://harm-smits.github.io/42docs/libs/minilibx
- https://github.com/nmei-42/42-Fractol/blob/master/minilibx/README.md
- https://lodev.org/cgtutor/juliamandelbrot.html
- https://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/

## Note:

[**Coding Norm**](https://github.com/nunovaladao/42_fract-ol_lev2/blob/main/extras/en_norm.pdf) - All students must follow the 42 code writing standards. This standard is applied to many projects in the course.
##
Nuno Valadão | nsoares-@student.42porto.com

