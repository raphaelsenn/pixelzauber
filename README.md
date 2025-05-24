# pixelzauber
Implementing a bunch image processing algorithms for .PGM and .PPM files from scratch in C++.


## Kernels (Filters)

All images shown were produced as outputs of image processing algorithms implemented in this repository.
| Operation       | Kernel                                       | Output Image                     |
|-----------------|-----------------------------------------------|----------------------------------|
| Identity        | `[ [0 0 0], [0 1 0], [0 0 0] ]` | ![Identity](res/lena.png)        |
| Box Blur         | `1/9*[ [1 1 1], [1 1 1], [1 1 1] ]` | ![Blur](res/lena_box_blur.png) |
| Sharpen         | `[ [0 -1 0], [-1 5 -1], [0 -1 0] ]` | ![Sharpen](res/lena_sharp.png) |
| Edge Detection X-Direction | `[ [-1, 0, 1], [-2, 0, 2], [-1, 0, 1] ]` | ![Edges](res/lena_edge_x.png) |
| Edge Detection Y-Direction | `[ [-1, -2, -1], [0, 0, 0], [1, 2, 1] ]` | ![Edges](res/lena_edge_y.png) |

```c++
#include "./src/Mat2d.hpp"

int main() {

    // loading lena
    Mat2d<int> lena;
    lena.readPGM("lena.pgm");

    // defining a kernel for sharpening
    Mat2d<int> kernel = Mat2d<int>({
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}});

    Mat2d<int> lena_sharp = applyFilter(lena, kernel).clip(0, lena.maxVal());
    lena_sharp.writePGM("lena_sharp.pgm"); 
    return 0;
}
```

## Synthetic Noise

All images shown were produced as outputs of image processing algorithms implemented in this repository.
| Noise       | Output Image                     |
|------------|----------------------------------|
| Original Image | ![Original Lena](./res/lena.png) |
| Additive gaussian noise with mean = 0, standard deviation = 20 | ![Lena Gaussian Noise](./res/lena_gauss_noise.png) |

## Image Difference

Let $I^{(1)}$, $I^{(2)}$ $\in \mathbb{R}^{N}_{+}$ be two gray scale images. The difference of $I^{(1)}$, $I^{(2)}$ can be defined as:

$$
I^{(1)} - I^{(2)} \coloneqq \left| I^{(1)} - I^{(2)} \right|
$$

The difference of two images can be used to detect moving objects in a static scene.

#### Example: Detecting Moving Objects in a static Scene
Left: Image I1, Middle: Image I2, Right: Absolute difference |I1 − I2| between Image I1 and Image I2

| Noise       | Output Image                     |
|------------|----------------------------------|
| Image I1 | ![Image I1](./res/motion01.png) |
| Image I2 | ![Image I2](./res/motion02.png) |
| Difference of I1 and I2| ![Image I2](./res/motion01_diff_motion02.png) |

<p style="text-align: left; font-style: italic; font-size: 90%;">
  Image taken from <em>University of Southern California</em>,<br>
  "motion05.512 and motion06.512",<br>
  <a href="https://sipi.usc.edu/database/database.php?volume=sequences" target="_blank">
    https://sipi.usc.edu/database/database.php?volume=sequences
  </a>
</p>

```c++
#include "./src/Mat2d.hpp"

int main() {
  Mat2d<int> frame_1;
  Mat2d<int> frame_2;
  frame_1.readPGM("./pgm/motion05.pgm");
  frame_2.readPGM("./pgm/motion06.pgm");
  Mat2d<int> diff = (frame_1 - frame_2).clip(0, frame_1.maxVal());
  diff.writePGM("motion_difference.pgm");
}
```

## Citations

```bibtex
@misc{lena_image,
  title        = {Lena Image},
  note         = {Accessed: 1972},
}
```