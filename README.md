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

## Citations

```bibtex
@misc{lena_image,
  title        = {Lena Image},
  note         = {Accessed: 1972},
}
```