# Fract'ol

![Fract'ol](/images/fractals.png)

Fract'ol is a School 21 project. The goal is to create fractal renderer.

Note that this project only supports **macOS and Linux (not tested)**.

[`fract_ol.en.pdf`](/subject/fract_ol.en.pdf) is the task file.

## Installation

Clone repository then navigate to the created directory and run the following command:

```
make
```

## How to run program?

You can run the project with the following command:

```
./fractol <name>
```

For example, you can specify julia (case sensitive) fractal:

```
./fractol julia
```

![Julia](/images/julia.png)

Multi-window mode is also supported. For example, you can run the following command to launch two windows:

```
./fractol <name> <name>
```

You can specify up to 7 fractal names for one launch.
There are 7 different fractals are avaliable:

* mandelbrot
* celtic_mandelbrot
* julia
* burningship
* perpendicular_burningship
* mandelbar
* celtic_mandelbar

## Controls

You can use H key for the help menu which contains a list of controls.

![Controls](/images/controls.png)
